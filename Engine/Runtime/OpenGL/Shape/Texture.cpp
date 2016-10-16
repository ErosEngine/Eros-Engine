#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION // To prevent link errors
#include "Engine/Developer/FileSystem/stb_image.h"


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

// Simple function call
void Texture::openTexture(const char *filename)
{
    fileName = filename;
    
    if (m_bitmap)
    {
        delete[] m_bitmap;
    }
    
    m_bitmap = stbi_load(filename, &width, &height, &comp, STBI_rgb);
}

ubyte *Texture::texPtr()
{
    return m_bitmap;
}

Texture &Texture::operator = (Texture &right)
{
    // NOTE(kiecker): Overwrite the memory,
    // no telling yet if there will be a crash
    memcpy(right.texPtr(), this->m_bitmap, sizeof(right.texPtr()));
    
    // NOTE(kiecker): self explanitory
    this->width = right.width;
    this->height = right.height;
    return *this;
}
