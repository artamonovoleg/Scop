#pragma once

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Camera.hpp"

class Shader;
class Model;

class App
{
    private:
        GLFWwindow* m_Window = nullptr;
        ImGuiIO*    m_Imgio = nullptr;

        std::shared_ptr<Shader> m_SceneLightShader;
        std::shared_ptr<Model> m_SceneLightObject;

        std::shared_ptr<Shader> m_ObjectStandartShader;
        std::vector<Model>  m_LoadedObjects;

        // time
        float m_DeltaTime = 0.0f;
        float m_LastFrame = 0.0f;

        void CreateWindow();
        void SetupCallbacks();
        void GLADSetup();
        void ImguiSetup();
        void SetupStandartSceneObjects();
        void DrawImguiLayer();
        void UpdateDeltaTime();
        void UpdateShadersData();
        void ProcessInput(GLFWwindow *window, Camera& camera, float deltaTime);
    public:
        App();
        ~App();
        
        int LoadModel(const std::string& modelPath, const std::string& texturePath);
        void RemoveModel(int bind);
        void DrawFrame();
        bool ShouldClose();
};