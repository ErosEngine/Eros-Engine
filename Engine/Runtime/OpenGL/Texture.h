#ifndef TEXTURE_H
#define TEXTURE_H

#ifndef QSTRING_H
#include <QString>
#endif
#ifndef __glew_h__
#include <GL/glew.h>
#endif


class Texture
{
public:
    
    QString fileName;
    
    GLuint texture;
    GLuint activeTexture;
    
    int width;
    int height;
    int comp;
    
    inline void bind()   { glBindTexture(GL_TEXTURE_2D, texture); }
    inline void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
    
    inline Texture &operator = (const Texture &right)
    {
        this->texture = right.texture;
        this->fileName = right.fileName;
        this->width = right.width;
        this->height = right.height;
        this->comp = right.comp;
        return *this;
    }
};

Texture LoadTextureFromFile(const char *fileName);

#endif // TEXTURE_H
