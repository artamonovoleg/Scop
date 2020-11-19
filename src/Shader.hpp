//
// Created by user on 11.10.2020.
//

#pragma once
#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
    private:
        // the program ID
        unsigned int _rendererID;
        mutable std::unordered_map<std::string, GLint> _uniformLocationCache;
        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        static void checkCompileErrors(unsigned int shader, const std::string& type);

        GLint getUniformLocation(const std::string& name) const;
    public:
        // constructor reads and builds the shader
        Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
        ~Shader();

        // use/activate the shader
        void Bind() const;
        void Unbind() const;
        // utility uniform functions
        void SetBool(const std::string& name, bool value) const;
        void SetInt(const std::string& name, int value) const;
        void SetFloat(const std::string& name, float value) const;
        void SetMat4(const std::string& name,const glm::mat4& mat) const;
        void SetVec3(const std::string& name, const glm::vec3& vec) const;
        void SetVec3(const std::string& name, float x, float y, float z) const;
        void SetUniform1i(const std::string& name, int value) const;
};
