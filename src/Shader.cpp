//
// Created by user on 11.10.2020.
//

#include "Shader.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    std::ifstream gShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    gShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // if geometry shader path is present, also load a geometry shader
        if(geometryPath != nullptr)
        {
            gShaderFile.open(geometryPath);
            std::stringstream gShaderStream;
            gShaderStream << gShaderFile.rdbuf();
            gShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();
    // 2. compile shaders
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    // if geometry shader is given, compile geometry shader
    unsigned int geometry;
    if(geometryPath != nullptr)
    {
        const char * gShaderCode = geometryCode.c_str();
        geometry = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometry, 1, &gShaderCode, NULL);
        glCompileShader(geometry);
        checkCompileErrors(geometry, "GEOMETRY");
    }
    // shader Program
    _rendererID = glCreateProgram();
    glAttachShader(_rendererID, vertex);
    glAttachShader(_rendererID, fragment);
    if(geometryPath != nullptr)
        glAttachShader(_rendererID, geometry);
    glLinkProgram(_rendererID);
    checkCompileErrors(_rendererID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    if(geometryPath != nullptr)
        glDeleteShader(geometry);
}

Shader::~Shader()
{
    glDeleteProgram(_rendererID);
}

GLint Shader::getUniformLocation(const std::string &name) const
{
    if (_uniformLocationCache.find(name) != _uniformLocationCache.end())
        return _uniformLocationCache[name];

    GLint location = glGetUniformLocation(_rendererID, name.c_str());
    _uniformLocationCache[name] = location;
    return location;
}

void Shader::Bind() const
{
    glUseProgram(_rendererID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetVec3(const std::string &name, const glm::vec3 &vec) const
{
    glUniform3fv(getUniformLocation(name), 1, &vec[0]);
}

void Shader::SetVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(getUniformLocation(name), x, y, z);
}

void Shader::SetUniform1i(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(_rendererID, name.c_str()), value);
}

void Shader::checkCompileErrors(unsigned int shader, const std::string &type)
{
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}




