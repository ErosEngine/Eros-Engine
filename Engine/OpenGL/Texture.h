#ifndef TEXTURE_H
#define TEXTURE_H



typedef unsigned char ubyte;

class Texture
{
public:
    
    void setBuffer(ubyte *byteArr);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    
    int width();
    int height();
    ubyte *texPtr();
    
private:
    
    ubyte *m_bitmap;
};

#endif // TEXTURE_H
