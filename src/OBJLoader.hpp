//
// Created by user on 04.11.2020.
//

#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Mesh.hpp"

//class OBJLoader
//{
//    private:
//        static void Triangulate(std::vector<unsigned int>& indices)
//        {
//            indices.push_back(indices.at(indices.size() - 3));
//            indices.push_back(indices.at(indices.size() - 2));
//        }
//
//        template<typename T>
//        static void BuildVertices(std::vector<T>& fin_vertices, std::vector<float>& vertices, const std::vector<unsigned int>& indices)
//        {
//            for (unsigned int i = 0; i < indices.size(); i++)
//            {
//                fin_vertices[i] = glm::vec3(vertices[indices[i] * 3],
//                                                 vertices[indices[i] * 3 + 1],
//                                                 vertices[indices[i] * 3 + 2]);
//            }
//        }
//    public:
//        static Mesh LoadFromFile(const std::string& path)
//        {
//            std::vector<float> positions;
//            std::vector<float> textures;
//            std::vector<float> normals;
//
//            std::vector<unsigned int> positionIndices;
//            std::vector<unsigned int> textureIndices;
//            std::vector<unsigned int> normalIndices;
//
//            std::vector<Vertex> vertices;
//            std::vector<unsigned int> indices;
//
//            std::ifstream file(path);
//
//            if (file.is_open())
//            {
//                for (std::string line; std::getline(file, line);)
//                {
//                    std::istringstream in(line);
//
//                    std::string prefix;
//                    in >> prefix;
//
//                    if (prefix == "v")
//                    {
//                        float x, y, z;
//                        in >> x >> y >> z;
//                        positions.push_back(x);
//                        positions.push_back(y);
//                        positions.push_back(z);
//                    }
//                    else
//                    if (prefix == "vt")
//                    {
//                        float u, v;
//                        in >> u >> v;
//                        textures.push_back(u);
//                        textures.push_back(v);
//                    }
//                    else
//                    if (prefix == "vn")
//                    {
//                        float x, y, z;
//                        in >> x >> y >> z;
//                        normals.push_back(x);
//                        normals.push_back(y);
//                        normals.push_back(y);
//                    }
//                    else
//                    if (prefix == "f")
//                    {
//                        // check '/' and ' ' in line for check right array. counter need for choose array
//                        int counter = 0;
//                        // check amount of indices in line. cause we need only triangles
//                        int indices_count = 0;
//                        bool isTriangular = true;
//                        // save founded number here
//                        unsigned int i;
//
//                        while (in >> i)
//                        {
//                            isTriangular = !(indices_count % 3 == 0 && indices_count > 0);
//                            switch (counter)
//                            {
//                                case 0:
//                                    if (!isTriangular)
//                                        Triangulate(positionIndices);
//                                    positionIndices.push_back(i - 1);
//                                    break;
//                                case 1:
//                                    if (!isTriangular)
//                                        Triangulate(textureIndices);
//                                    textureIndices.push_back(i - 1);
//                                    break;
//                                case 2:
//                                    if (!isTriangular)
//                                        Triangulate(normalIndices);
//                                    normalIndices.push_back(i - 1);
//                                    break;
//                                default:
//                                    break;
//                            }
//                            std::cout << "\n";
//                            if (in.peek() == '/')
//                            {
//                                ++counter;
//                                in.ignore(1, '/');
//                            }
//                            else
//                            if (in.peek() == ' ')
//                            {
//                                indices_count++;
//                                counter = 0;
//                                in.ignore(1, ' ');
//                            }
//
//                            if (counter > 2)
//                                counter = 0;
//                        }
//                    }
//                }
//                file.close();
//
//                vertices.resize(positionIndices.size());
//                for (unsigned int i = 0; i < positionIndices.size(); i++)
//                {
//                    vertices[i].position = glm::vec3(positions[positionIndices[i] * 3],
//                                                       positions[positionIndices[i] * 3 + 1],
//                                                       positions[positionIndices[i] * 3 + 2]);
//                    indices.push_back(i);
//                }
//
//                for (unsigned int i = 0; i < textureIndices.size(); i++)
//                    vertices[i].texture = glm::vec2(textures[textureIndices[i] * 2], textures[textureIndices[i] * 2 + 1]);
//                for (unsigned int i = 0; i < normalIndices.size(); i++)
//                    vertices[i].normal = glm::vec3(normals[normalIndices[i] * 3],
//                                                     normals[normalIndices[i] * 3 + 1],
//                                                     normals[normalIndices[i] * 3 + 2]);
//
//                return Mesh(vertices, indices);
//            }
//            else
//            {
//                throw std::invalid_argument("FAILED TO LOAD MODEL\n");
//            }
//        }
//};


class OBJLoader
{
    private:
        std::vector<float> m_Positions;
        std::vector<float> m_Textures;
        std::vector<float> m_Normals;

        std::vector<unsigned int> m_PositionIndices;
        std::vector<unsigned int> m_TextureIndices;
        std::vector<unsigned int> m_NormalIndices;

        std::vector<Vertex> m_Vertices;
        std::vector<unsigned int> m_Indices;

        static void Triangulate(std::vector<unsigned int>& indices)
        {
            indices.push_back(indices.at(indices.size() - 3));
            indices.push_back(indices.at(indices.size() - 2));
        }

        enum class VerticesType
        {
            POSITIONS,
            TEXTURES,
            NORMALS
        };

        // this normalise all vertices and load to final array
        void LoadToFinal(std::vector<float>& vertices, const std::vector<unsigned int>& indices, VerticesType loadMode)
        {
            switch (loadMode)
            {
                case VerticesType::POSITIONS:
                    for (unsigned int i = 0; i < indices.size(); i++)
                    {
                        m_Vertices[i].position = glm::vec3(vertices[indices[i] * 3],
                                                           vertices[indices[i] * 3 + 1],
                                                           vertices[indices[i] * 3 + 2]);
                        m_Indices.push_back(i);
                    }
                case VerticesType::TEXTURES:
                    for (unsigned int i = 0; i < indices.size(); i++)
                        m_Vertices[i].texture = glm::vec2(vertices[indices[i] * 2], vertices[indices[i] * 2 + 1]);
                case VerticesType::NORMALS:
                    for (unsigned int i = 0; i < indices.size(); i++)
                        m_Vertices[i].normal = glm::vec3(vertices[indices[i] * 3],
                                                       vertices[indices[i] * 3 + 1],
                                                       vertices[indices[i] * 3 + 2]);
            }

        }
    public:
        OBJLoader() = default;
        ~OBJLoader() = default;

        Mesh LoadFromFile(const std::string& path)
        {
            std::ifstream file(path);
            if (file.is_open())
            {
                for (std::string line; std::getline(file, line);)
                {
                    std::istringstream in(line);

                    std::string prefix;
                    in >> prefix;

                    if (prefix == "v")
                    {
                        float x, y, z;
                        in >> x >> y >> z;
                        m_Positions.push_back(x);
                        m_Positions.push_back(y);
                        m_Positions.push_back(z);
                    }
                    else
                    if (prefix == "vt")
                    {
                        float u, v;
                        in >> u >> v;
                        m_Textures.push_back(u);
                        m_Textures.push_back(v);
                    }
                    else
                    if (prefix == "vn")
                    {
                        float x, y, z;
                        in >> x >> y >> z;
                        m_Normals.push_back(x);
                        m_Normals.push_back(y);
                        m_Normals.push_back(y);
                    }
                    else
                    if (prefix == "f")
                    {
                        // check '/' and ' ' in line for check right array. counter need for choose array
                        int counter = 0;
                        // check amount of indices in line. cause we need only triangles
                        int indices_count = 0;
                        bool isTriangular = true;
                        // save founded number here
                        unsigned int i;

                        while (in >> i)
                        {
                            isTriangular = !(indices_count % 3 == 0 && indices_count > 0);
                            switch (counter)
                            {
                                case 0:
                                    if (!isTriangular)
                                        Triangulate(m_PositionIndices);
                                    m_PositionIndices.push_back(i - 1);
                                    break;
                                case 1:
                                    if (!isTriangular)
                                        Triangulate(m_TextureIndices);
                                    m_TextureIndices.push_back(i - 1);
                                    break;
                                case 2:
                                    if (!isTriangular)
                                        Triangulate(m_NormalIndices);
                                    m_NormalIndices.push_back(i - 1);
                                    break;
                                default:
                                    break;
                            }
                            std::cout << "\n";
                            if (in.peek() == '/')
                            {
                                ++counter;
                                in.ignore(1, '/');
                            }
                            else
                            if (in.peek() == ' ')
                            {
                                indices_count++;
                                counter = 0;
                                in.ignore(1, ' ');
                            }

                            if (counter > 2)
                                counter = 0;
                        }
                    }
                }
                file.close();

                m_Vertices.resize(m_PositionIndices.size());
                LoadToFinal(m_Positions, m_PositionIndices, VerticesType::POSITIONS);
                LoadToFinal(m_Textures, m_TextureIndices, VerticesType::TEXTURES);
                LoadToFinal(m_Normals, m_NormalIndices, VerticesType::NORMALS);

                return Mesh(m_Vertices, m_Indices);
            }
            else
            {
                throw std::invalid_argument("FAILED TO LOAD MODEL\n");
            }
        }
};