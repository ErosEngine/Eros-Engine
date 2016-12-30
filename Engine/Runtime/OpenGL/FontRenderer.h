#ifndef FONTRENDERER_H
#define FONTRENDERER_H

#include <QString>
#include <GL/glew.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H


struct Font
{
	GLuint texture = 0;
	FT_Library *lib;
	FT_Face face;
	FT_Bitmap bitmap;
	int sizeX, sizeY;
	int bearingX, bearingY;
	int weight;
	
	inline ~Font() // Brief cleanup
	{
		FT_Done_Face(this->face);
		FT_Done_FreeType(*lib);
		
		if (lib != nullptr)
			delete lib;
	}
};


// THIS FUNCTION NOT MEANT TO BE CALLED MORE THAN ONCE,
// serious performance loss can occur, which is why I only have pointer object creation
// to minimize the number of times that this function has to be called
// if you plan to use a font more than once, then try to pass this pointer around
// for perfomance
Font *CreateFont(const char *fileName, int _sizeX, int _sizeY);

// ------------------ Text --------------------------------

class Text
{
public:
	Text();
	Text(Font *font, const char *text);
	~Text();
	
	void setText(const char *text);
	
	void setFont(Font *font);
	const Font *font() const;
	
	void setup();
	
private:
	
    GLfloat *m_verts;   
	Font *m_font;
	QString m_text;
};





#endif // FONTRENDERER_H
