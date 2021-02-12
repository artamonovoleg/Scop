#pragma once

#include <vector>
#include <string>
#include "Mesh.hpp"

class Shader;
class Texture;

class Model
{
    private:
        std::vector<Mesh>           m_Meshes;
        std::shared_ptr<Texture>    m_Texture;
        std::string                 m_Directory;
    public:
        Model(const std::string& modelPath, const std::string& texturePath = "");

        void Draw(Shader& shader);
};