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

void Texture::setBuffer(ubyte *byteArr)
{
    this->m_bitmap = byteArr;
}
