//
// Created by user on 13.10.2020.
//

#include "Texture.hpp"

#include <stdexcept>
#include <glad/glad.h>
#include "stb_image.h"

Texture::Texture(const std::string &path)
    : _rendererID(0), _filePath(path), _localBuffer(nullptr), _width(0), _height(0), _BPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    _localBuffer = stbi_load(path.c_str(), &_width, &_height, &_BPP, 4);

    if (!_localBuffer)
        throw std::runtime_error("Failed to open texture: " + _filePath);

    glGenTextures(1, &_rendererID);
    glBindTexture(GL_TEXTURE_2D, _rendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (_localBuffer)
        stbi_image_free(_localBuffer);
}

Texture::~Texture()
{
    glDeleteTextures(1, &_rendererID);
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, _rendererID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::GetWidth() const
{
    return _width;
}

int Texture::GetHeight() const
{
    return _height;
}



