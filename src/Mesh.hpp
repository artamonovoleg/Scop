#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Vertex.hpp"

class Shader;
class Texture;

class Mesh
{
    private:
        unsigned int m_VAO, m_VBO, m_EBO;
        std::vector<Vertex>                     m_Vertices;
        std::vector<unsigned int>               m_Indices;

        void SetupMesh();
    public:

        Mesh() = default;
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

        void Draw(Shader& shader);
};