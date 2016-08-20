#ifndef TEXTURE_H
#define TEXTURE_H

#include "Engine/Geometry/Coordinates.h"


typedef unsigned char ubyte;

class Texture
{
public:
    
    Texture();
    Texture(const char *fileName);

    // Returns an unsigned byte
    ubyte *getPixelPtr();
    
    int width();
    int height();
    void loadFile(const char *fileName);
    
private:
    ubyte *m_pxlPtr;
    int m_width, m_height, m_bpp;
};

#endif // TEXTURE_H
