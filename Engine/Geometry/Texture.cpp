#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION // To prevent link errors
#include "Engine/FileSystem/stb_image.h"


/*
    EXAMPLE TEXTURE SHADER
    
    #version 430
    
    in vec2 texCoords;
    uniform Sampler2D inTex; // send in texture
    
    out vec4 color; // send out color
    
    void main(void)
    {
        color = vec4(texture(inTex, texCoords), 1.0f);
    }
*/


Texture::Texture()
{
    // Nothing for default constructor
}

Texture::Texture(const char *fileName)
{
    loadFile(fileName);
}

ubyte *Texture::getPixelPtr()
{
    return m_pxlPtr;
}

int Texture::width()
{
    return m_width;
}

int Texture::height()
{
    return m_height;
}

void Texture::loadFile(const char *fileName)
{
    m_pxlPtr = stbi_load(fileName, &m_width, &m_height, &m_bpp, 3);
}
