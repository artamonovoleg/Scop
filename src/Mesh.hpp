#pragma once

#include <utility>
#include <vector>
#include "Vertex.hpp"

class Mesh
{
    private:

    public:
        const std::vector<Vertex>& m_Vertices;
        const std::vector<unsigned int>& m_Indices;
        Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
            : m_Vertices(vertices), m_Indices(indices){}
};