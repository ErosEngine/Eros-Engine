#ifndef TEXTURE_H
#define TEXTURE_H

#include <QString>
#include <GL/glew.h>


enum TextureType
{
    DiffuseTexture = 1,
    SpecularTexture = 2
};


/*
 * TODO(kiecker): Make this more interfaceable with d3d and vulkan
 * vulkan for certain, but d3d will be on the todo for a while
 */
class Texture
{
public:
    
   ~Texture();
    
    QString fileName;
    
    GLuint texture = 0;
    
    int type;
    int width;
    int height;
    int comp;
    
    bool loadFromFile(const char *fileName);    
    bool isEmpty();
    
    inline void bind()   { glBindTexture(GL_TEXTURE_2D, texture); }
    inline void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
    
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