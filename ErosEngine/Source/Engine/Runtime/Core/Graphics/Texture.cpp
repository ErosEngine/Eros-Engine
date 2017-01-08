#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION // To prevent link errors
#include "Engine/Developer/FileSystem/stb_image.h"

/*
    EXAMPLE TEXTURE SHADER
    
    #version 430
    
    in vec2 texCoords;
    uniform Sampler2D Sint32ex; // send in texture
    
    out vec4 color; // send out color
    
    void main(void)
    {
        color = vec4(texture(Sint32ex, texCoords), 1.0f);
    }
*/

typedef unsigned char *ubyteptr;

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
}

bool Texture::LoadFromFile(const char *fileName)
{
    this->fileName = fileName;
    ubyteptr texPtr = stbi_load(fileName, &width, &height, &comp, STBI_rgb);
    
    if (!texPtr)
    {
        return false;
    }
    else
    {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D
        (
            GL_TEXTURE_2D,
            0, GL_RGB, 
            width, 
            height,
            0, GL_RGB,
            GL_UNSIGNED_BYTE,
            texPtr
        );
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
        STBI_FREE(texPtr);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    return true;
}

bool Texture::IsEmpty()
{
    return (texture != 0);
}
