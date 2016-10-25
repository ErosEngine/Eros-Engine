#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION // To prevent link errors
#include "Engine/Developer/FileSystem/stb_image.h"
#include <GL/glew.h>

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

typedef unsigned char *ubyteptr;

Texture LoadTextureFromFile(const char *fileName)
{
    Texture retTexture;
    retTexture.fileName = fileName;
    ubyteptr texPtr = stbi_load(fileName, &retTexture.width, &retTexture.height, &retTexture.comp, STBI_rgb);
    
    glGenTextures(1, &retTexture.texture);
    glBindTexture(GL_TEXTURE_2D, retTexture.texture);
    glTexImage2D
    (
        GL_TEXTURE_2D,
        0, GL_RGB, 
        retTexture.width, 
        retTexture.height,
        0, GL_RGB,
        GL_UNSIGNED_BYTE,
        texPtr
    );
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    STBI_FREE(texPtr);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return retTexture;
}
