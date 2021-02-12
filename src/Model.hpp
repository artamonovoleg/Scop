#pragma once

#include <vector>
#include <string>
#include "Mesh.hpp"

class Shader;
class Texture;

class Model
{
    private:
        std::vector<Mesh>       m_Meshes;
        std::string             m_Directory;
    public:
        Model(const std::string& filename);

        void Draw(Shader& shader, Texture& texture);
};