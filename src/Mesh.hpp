//
// Created by user on 04.11.2020.
//

#pragma once

#include <utility>
#include <vector>
#include "Vertex.hpp"

class Mesh
{
    private:

    public:
        std::vector<Vertex> m_Vertices;
        std::vector<unsigned int> m_Indices;
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
            : m_Vertices(std::move(vertices)), m_Indices(std::move(indices)){}
};