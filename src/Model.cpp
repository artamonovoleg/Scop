#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
#include <stdexcept>
#include <unordered_map>
#include "Model.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

Model::Model(const std::string& path)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    std::vector<Vertex>         vertices;
    std::vector<unsigned int>   indices;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str())) 
        throw std::runtime_error(warn + err);


    m_Meshes.reserve(shapes.size());

    for (const auto& shape : shapes) 
    {
        std::unordered_map<Vertex, uint32_t> uniqueVertices{};
        for (const auto& index : shape.mesh.indices) 
        {
            Vertex vertex{};

            vertex.pos = {
                attrib.vertices[3 * index.vertex_index + 0],
                attrib.vertices[3 * index.vertex_index + 1],
                attrib.vertices[3 * index.vertex_index + 2]
            };

            if (!attrib.normals.empty())
            {
                vertex.normal = 
                {
                    attrib.normals[3 * index.normal_index + 0],
                    attrib.normals[3 * index.normal_index + 1],
                    attrib.normals[3 * index.normal_index + 2]
                };
            }

            vertex.texCoord = {
                attrib.texcoords[2 * index.texcoord_index + 0],
                attrib.texcoords[2 * index.texcoord_index + 1]
            };

            if (uniqueVertices.count(vertex) == 0) 
            {
                uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
                vertices.push_back(vertex);
            }

            indices.push_back(uniqueVertices[vertex]);
        }

        m_Meshes.emplace_back(Mesh(vertices, indices));
    }

}

void Model::Draw(Shader& shader, Texture& texture)
{
    texture.Bind();
    for (auto& mesh : m_Meshes)
        mesh.Draw(shader);
}