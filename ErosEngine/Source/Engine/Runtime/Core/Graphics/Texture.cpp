#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION // To prevent link errors
#include "Engine/Developer/FileSystem/stb_image.h"

/*
    EXAMPLE TEXTURE SHADER
    
    #version 430
    
    in vec2 texCoords;
    uniform Sampler2D Sint32ex; // send in texture
    
    out vec4 color; // send out color
    
    void main(void)
    {
        color = vec4(texture(Sint32ex, texCoords), 1.0f);
    }
*/


Texture::~Texture()
{
	Clear();
}

bool Texture::LoadFromFile(const char *fileName)
{
	Byte *buffer = stbi_load(fileName, &width, &height, &comp, STBI_rgb_alpha);
	m_Buffer = new Byte[width * height * comp];
	memcpy(m_Buffer, buffer, width * height * comp);
	STBI_FREE(buffer);
	return m_Buffer != nullptr;
}

void Texture::Create(Sint32 width, Sint32 height, Sint32 textureComp /*= COMP_RGBA*/)
{
	if (m_Buffer != nullptr)
		delete[] m_Buffer;

	this->width = width;
	this->height = height;
	this->comp = textureComp;

	m_Buffer = new Byte[width * height * textureComp];
}

void Texture::CopyTexture(Texture *pOther)
{
	if (this->m_Buffer)
	{
		delete[] m_Buffer;
	}

	width = pOther->width;
	height = pOther->height;
	comp = pOther->comp;
	Uint32 size = width * height * comp;

	memcpy(m_Buffer, pOther->GetBuffer(), size);
}

void Texture::ReadFromMemory(Byte *memory, Sint32 width, Sint32 height, Sint32 comp)
{
	if (m_Buffer)
		delete[] m_Buffer;

	m_Buffer = new Byte[width * height * comp];
	memcpy(m_Buffer, memory, width * height * comp);

	this->width = width;
	this->height = height;
	this->comp = comp;
}

bool Texture::IsEmpty()
{
	return (m_Buffer != nullptr);
}

void Texture::Clear()
{
	delete[] m_Buffer;
}
