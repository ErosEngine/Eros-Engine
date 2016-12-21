#ifndef TEXTURE_H
#define TEXTURE_H

#include <QString>
#include <GL/glew.h>
#include "IComponent.h"


enum TextureType
{
    DiffuseTexture = 1,
    SpecularTexture = 2
};

class Texture : public IComponent
{
public:
    
   ~Texture();
    
    QString fileName;
    
    GLuint texture = 0;
    
    int type;
    int width;
    int height;
    int comp;
    
    virtual bool loadFromFile(const char *fileName) override;
    virtual void fromExisting(const IComponent *pOther) override;    
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
