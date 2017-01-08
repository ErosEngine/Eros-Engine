#ifndef TEXTURE_H
#define TEXTURE_H

#include <QtCore/QString>
#include <Core/Common.h>
#include <GL/glew.h>


enum TextureType
{
    DiffuseTexture = 1,
    SpecularTexture = 2
};


/*
 * TODO: Make this more interfaceable with d3d and vulkan\
 */
class Texture
{
public:
    
   ~Texture();
    
    QString fileName;
    
    Uint32 texture = 0;
    
    Sint32 type;
    Sint32 width;
    Sint32 height;
    Sint32 comp;
    
    bool LoadFromFile(const char *fileName);    
    bool IsEmpty();
    
    inline void Bind()   { glBindTexture(GL_TEXTURE_2D, texture); }
    inline void Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
    
    inline Texture &operator = (const Texture &right)
    {
        this->texture = right.texture;
        this->type = right.type;
        this->fileName = right.fileName;
        this->width = right.width;
        this->height = right.height;
        this->comp = right.comp;
        return *this;
    }
};


#endif // TEXTURE_H
