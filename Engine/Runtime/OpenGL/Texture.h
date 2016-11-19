#ifndef TEXTURE_H
#define TEXTURE_H

#include <QString>
#include <GL/glew.h>


enum TextureType
{
    DiffuseTexture = 1,
    SpecularTexture = 2
};

class Texture
{
public:
    
   ~Texture();
    
    QString fileName;
    
    GLuint texture;
    GLuint activeTexture;
    
    int type;
    int width;
    int height;
    int comp;
    
    bool LoadFromFile(const char *fileName);    
    
    inline void Bind()   { glBindTexture(GL_TEXTURE_2D, texture); }
    inline void UnBind() { glBindTexture(GL_TEXTURE_2D, 0); }
    
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
