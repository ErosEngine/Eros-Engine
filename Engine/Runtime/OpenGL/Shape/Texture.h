#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory.h>
#ifndef QSTRING_H
#include <QString>
#endif
#ifndef __glew_h__
#include <GL/glew.h>
#endif

typedef unsigned char ubyte;

class Texture
{
public:
    
    QString fileName;
    
    GLuint texture;
    
    int width;
    int height;
    int comp; // For stb compatibility
    ubyte *texPtr();
    
    Texture &operator = (Texture &right);
    
    void openTexture(const char *filename);
    
private:
    
    ubyte *m_bitmap;
};

#endif // TEXTURE_H
