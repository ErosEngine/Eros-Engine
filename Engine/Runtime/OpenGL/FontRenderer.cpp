#include "FontRenderer.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_STROKER_H
#include FT_BITMAP_H
#include FT_OUTLINE_H


Font *CreateFont(const char *fileName, int _sizeX, int _sizeY)
{
     Font *retFont = new Font();
     
     retFont->sizeX = _sizeX;
     retFont->sizeY = _sizeY;
     
     if (FT_Init_FreeType(retFont->lib))
         return retFont; // This will return an empty font pointer
     
     if (FT_New_Face(*retFont->lib, fileName, 0, &retFont->face))
         return nullptr; // DON'T CREATE A USEABLE FONT IF THE FILE PATH ISN'T VALID
                         // IN AN ATTEMPT TO USE IT SHOULD CAUSE A CRASH
     
     FT_Set_Pixel_Sizes(retFont->face, retFont->sizeX, retFont->sizeY);
     
     retFont->bearingX = retFont->face->glyph->bitmap_left;
     retFont->bearingY = retFont->face->glyph->bitmap_top;
     
     // load all characters
     for (char i = 0; i < 127; ++i)
     {
        if (FT_Load_Char(retFont->face, i, FT_LOAD_RENDER))
            return nullptr; // Don't create a valid font object 
     }
     
     return retFont;
}


/****  ===== TEXT =====  ****/

Text::Text()
{
}

Text::~Text()
{
    delete m_font; // delete font when done
}

Text::Text(Font *font, const char *text)
{
    this->m_font = font;
    this->m_text += text;
}

void Text::setFont(Font *font)
{
    this->m_font = font;
}

void Text::setText(const char *text)
{
    this->m_text = text;
}

const Font *Text::font() const
{
    return this->m_font;
}

void Text::setup()
{
    if (m_font->texture == 0) // if the texture buffer wasn't generated
        glGenTextures(1, &m_font->texture);
    glBindTexture(GL_TEXTURE_2D, m_font->texture);
    glTexImage2D
    (
        GL_TEXTURE_2D,
        0, GL_RED,
        m_font->sizeX,
        m_font->sizeY,
        0, GL_RED,
        GL_UNSIGNED_BYTE,
        m_font->face->glyph->bitmap.buffer
    );
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}
