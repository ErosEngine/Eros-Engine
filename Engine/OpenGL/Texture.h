#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory.h>
#ifndef QSTRING_H
#include <QString>
#endif

typedef unsigned char ubyte;

class Texture
{
public:
    
    QString fileName;
    
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
