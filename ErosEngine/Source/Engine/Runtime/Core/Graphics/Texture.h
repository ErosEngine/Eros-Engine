#ifndef TEXTURE_H
#define TEXTURE_H

#include <QtCore/QString>
#include <Core/Common.h>
#include <GL/glew.h>


enum TextureComp
{
	COMP_R =	1,
	COMP_RG =	2,
	COMP_RGB =	3,
	COMP_RGBA = 4
};

enum TextureFlags
{
	TextureFlag_WRAPPING_ENABLED	= 0x00000000,
	TextureFlag_WRAPPING_DISABLED	= 0x00000001,
	TextureFlag_
};

class Texture
{
public:
    
   ~Texture();
    
    QString fileName;
    
	Sint32 width;
    Sint32 height;
    Sint32 comp;
	Uint32 textureFlags;
    
    bool LoadFromFile(const char *fileName);
	void Create(Sint32 width, Sint32 height, Sint32 textureComp = COMP_RGBA);
	void CopyTexture(Texture *pOther);
	void ReadFromMemory(Byte *memory, Sint32 width, Sint32 height, Sint32 comp);
    bool IsEmpty();
	void Clear();
    
	Byte *GetBuffer() const { return m_Buffer; }

private:

	Byte *m_Buffer = NULL;

};


#endif // TEXTURE_H
