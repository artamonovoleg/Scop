#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "App.hpp"
#include "Shader.hpp"
#include "Model.hpp"

static Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
static glm::vec3 ambientLight(1.0f, 1.0f, 1.0f);
static glm::vec3 diffuseLight(1.0f, 1.0f, 1.0f);

static glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

static int         m_Width = 1920;
static int         m_Height = 600;

App::App()
{
    CreateWindow();
    SetupCallbacks();
    GLADSetup();
    ImguiSetup();
    glEnable(GL_DEPTH_TEST);
    SetupStandartSceneObjects();

    m_ObjectStandartShader = std::make_shared<Shader>("../res/shaders/vshader.vert", "../res/shaders/fshader.frag");
}

App::~App()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void App::CreateWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Width, m_Height, "Scop", nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
}

void App::SetupCallbacks()
{
    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
    {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
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
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
    {
        camera.ProcessMouseScroll(yoffset);
    });

    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
        m_Width = width;
        m_Height = height;
    });
}

void App::GLADSetup()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");
}

void App::ImguiSetup()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    m_Imgio = &io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
}

void App::SetupStandartSceneObjects()
{
    m_SceneLightShader = std::make_shared<Shader>("../res/shaders/light.vert", "../res/shaders/light.frag");
    m_SceneLightObject = std::make_shared<Model>("../res/objs/SceneLight.obj");
}

int App::LoadModel(const std::string& modelPath, const std::string& texturePath)
{
    m_LoadedObjects.push_back(std::move(Model(modelPath, texturePath)));
    return m_LoadedObjects.size() - 1;
}

void App::RemoveModel(int bind)
{
    m_LoadedObjects.erase(m_LoadedObjects.begin() + bind);
}

void App::DrawImguiLayer()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // render your GUI
    ImGui::Begin("Gui");
    ImGui::End();

    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void App::UpdateDeltaTime()
{
    float currentFrame = glfwGetTime();
    m_DeltaTime = currentFrame - m_LastFrame;
    m_LastFrame = currentFrame;
}

void App::UpdateShadersData()
{
    lightPos.x = sin(glfwGetTime());
    lightPos.z = cos(glfwGetTime());

    auto& lightingShader = *m_ObjectStandartShader;
    auto& sceneLightShader = *m_SceneLightShader;

    lightPos.x = sin(glfwGetTime());
    lightPos.z = cos(glfwGetTime());
    // be sure to activate shader when setting uniforms/drawing objects
    lightingShader.Bind();
    lightingShader.SetVec3("light.position", lightPos);
    lightingShader.SetVec3("viewPos", camera.Position);

    // light properties
    lightingShader.SetVec3("light.ambient", ambientLight);
    lightingShader.SetVec3("light.diffuse", diffuseLight);
    lightingShader.SetVec3("light.specular", 1.0f, 1.0f, 1.0f);

    // material properties
    lightingShader.SetFloat("material.shininess", 64.0f);

    lightingShader.SetVec3("material.ambient", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.SetVec3("material.diffuse", glm::vec3(0.9f, 0.9f, 0.9f));
    lightingShader.SetVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
    lightingShader.SetFloat("material.shininess", 32.0f);

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)m_Width / (float)m_Height, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    lightingShader.SetMat4("projection", projection);
    lightingShader.SetMat4("view", view);

    // world transformation
    glm::mat4 model = glm::mat4(1.0f);
    lightingShader.SetMat4("model", model);

    // also draw the lamp object
    sceneLightShader.Bind();
    sceneLightShader.SetMat4("projection", projection);
    sceneLightShader.SetMat4("view", view);
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
    sceneLightShader.SetMat4("model", model);
}

void App::ProcessInput(GLFWwindow *window, Camera& camera, float deltaTime)
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

void App::DrawFrame()
{
    UpdateDeltaTime();    
    UpdateShadersData();
    ProcessInput(m_Window, camera, m_DeltaTime);
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto& object : m_LoadedObjects)
        object.Draw(*m_ObjectStandartShader);
    
    m_SceneLightObject->Draw(*m_SceneLightShader);

    DrawImguiLayer();
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool App::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}