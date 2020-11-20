#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "src/Shader.hpp"
#include "src/Texture.hpp"
#include "src/Mesh.hpp"
#include "src/OBJLoader.hpp"
#include "src/Camera.hpp"


void processInput(GLFWwindow *window, Camera& camera, float deltaTime);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

Camera camera (glm::vec3(0.0f, 0.0f, 3.0f));

// camera
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);


// GL 3.0 + GLSL 130
const char* glsl_version = "#version 130";


class VertexArray
{
    private:
        unsigned int m_ID;
    public:
        VertexArray()
        {
            glGenVertexArrays(1, &m_ID);
            glBindVertexArray(m_ID);
        }

        ~VertexArray()
        {
            glDeleteVertexArrays(1, &m_ID);
        }

        void Bind() const
        {
            glBindVertexArray(m_ID);
        }

        void Unbind() const
        {
            glBindVertexArray(0);
        }

};

template <typename T>
class VertexBuffer
{
    private:
        unsigned int m_ID;
        const T* m_Data;
        const size_t m_Size;
    public:
        VertexBuffer(const T* data, size_t size)
            : m_Data(data), m_Size(size)
        {
            glGenBuffers(1, &m_ID);
            glBindBuffer(GL_ARRAY_BUFFER, m_ID);
            glBufferData(GL_ARRAY_BUFFER, m_Size * sizeof(T), m_Data, GL_STATIC_DRAW);
        }

        void Bind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_ID);
            glBufferData(GL_ARRAY_BUFFER, m_Size * sizeof(T), m_Data, GL_STATIC_DRAW);
        }

        void Unbind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
};


class VertexBuffersLayout
{
    private:
        mutable int m_Count = 0;
    public:
        VertexBuffersLayout() = default;
        ~VertexBuffersLayout() = default;

        template<typename T>
        void Push(unsigned int amount, unsigned int stride, unsigned int offset) const
        {
            glVertexAttribPointer(m_Count, amount, GL_FLOAT, GL_FALSE, stride * sizeof(T), (void *)(offset * sizeof(T)));
            glEnableVertexAttribArray(m_Count);
            m_Count++;
        }
};

int main()
{
    GLFWwindow* window = nullptr;
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    OBJLoader loader;
//--------------------------------------Setup part--------------------------------------------------------------------//
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfw window creation
    window = glfwCreateWindow(800, 600, "Scop", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cerr << "Failed to initialize GLAD" << std::endl;

    glViewport(0, 0, 800, 600);
//-----------------------------------Create render objects------------------------------------------------------------//

    /* TODO:
     * 1. Think about buffer abstraction
     * 2. Layout can take only amount and type
    */

    // load model
    Mesh mesh = loader.LoadFromFile("res/objs/spheres1.obj");
    // load model to buffers
    unsigned int vao, vbo, ebo;
    VertexArray va;
    va.Bind();
    VertexBuffer<Vertex> vb(mesh.m_Vertices.data(), mesh.m_Vertices.size());
    vb.Bind();
//    VertexBuffer<unsigned int> eb(mesh.m_Indices.data(), mesh.m_Indices.size());
//    eb.Bind();

//    glGenVertexArrays(1, &vao);
//    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
//
//    glBindVertexArray(vao);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//    glBufferData(GL_ARRAY_BUFFER, mesh.m_Vertices.size() * sizeof(Vertex), mesh.m_Vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.m_Indices.size() * sizeof(unsigned int), mesh.m_Indices.data(), GL_STATIC_DRAW);

    VertexBuffersLayout layout;
    layout.Push<float>(3, 8, 0);
    layout.Push<float>(2, 8, 3);
    layout.Push<float>(3, 8, 5);
//    // positions
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
//    glEnableVertexAttribArray(0);
//    // textures
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    // normals
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
//    glEnableVertexAttribArray(2);

    glEnable(GL_DEPTH_TEST);

    {
        // class objects need to call their destructor earlier then glfw terminates
        Shader shader("res/shaders/vshader.vert", "res/shaders/fshader.frag");
        Texture texture("res/textures/crate_1.jpg");
//--------------------------Light setup-------------------------------------------------------------------------------//
        glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
        glm::vec3 diffuseColor = lightColor * glm::vec3(0.9f);
        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.9f);
//[*}--------------------------------Application loop---------------------------------------------------------------[*]//
        while (!glfwWindowShouldClose(window))
        {
            // per-frame time logic
            auto currentFrame = static_cast<float>(glfwGetTime());
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
//---------------------------------Shader update-----------------------------------------------------------------------//
            shader.SetVec3("viewPos", camera.Position);

            shader.SetVec3("light.ambient", ambientColor);
            shader.SetVec3("light.diffuse", diffuseColor);
            shader.SetVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));

            shader.SetVec3("material.ambient", glm::vec3(1.0f, 1.0f, 1.0f));
            shader.SetVec3("material.diffuse", glm::vec3(0.9f, 0.9f, 0.9f));
            shader.SetVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
            shader.SetFloat("material.shininess", 32.0f);

            shader.SetVec3("light.position", 0.0f, 1.0f, 0.0f);

            // pass projection matrix to shader (note that in this case it could change every frame)
            glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
            shader.SetMat4("projection", projection);
            // camera/view transformation
            glm::mat4 view = camera.GetViewMatrix();
            shader.SetMat4("view", view);

            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix
            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
            float angle = 0.0f;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            shader.SetMat4("model", model);
//--------------------------------Draw part---------------------------------------------------------------------------//
            // wipe the drawing surface clear
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.5, 0.5, 0.5, 0.5);
            texture.Bind();
            shader.Bind();
//            glBindVertexArray(vao);
            va.Bind();
            glDrawElements(GL_TRIANGLES, mesh.m_Indices.size(), GL_UNSIGNED_INT, nullptr);
//-----------------------------Every frame logic----------------------------------------------------------------------//
            glfwSwapBuffers(window);
            glfwPollEvents();
            processInput(window, camera, deltaTime);
        }
//[*]---------------------------------------------------------------------------------------------------------------[*]//
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, Camera& camera, float deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    static float lastX = 800 / 2.0f;
    static float lastY = 600 / 2.0f;
    static bool firstMouse = true;

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}