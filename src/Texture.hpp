//
// Created by artamonovoleg on 13.10.2020.
//

#pragma once

#include <string>

class Texture
{
    public:
        unsigned int _rendererID;
        std::string _filePath;
        unsigned char* _localBuffer;
        int _width, _height, _BPP;
    public:
        Texture(const std::string& path);
        ~Texture();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

        inline int GetWidth() const;
        inline int GetHeight() const;
};

