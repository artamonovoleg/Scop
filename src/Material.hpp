//
// Created by user on 19.11.2020.
//

#pragma once

#include <glm/glm.hpp>

struct Material
{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};