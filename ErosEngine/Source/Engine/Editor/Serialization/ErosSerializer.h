#ifndef EROSSERIALIZER_H
#define EROSSERIALIZER_H

#include "Core/Platform.h"
#include <QXmlStreamReader>

class Scene;


class ErosSerializer
{
public:
	ErosSerializer();
	
	void OpenFile(const char *fileName);
	bool ReadScene(Scene *pOutScene);
	void WriteScene(const Scene *pInScene);
	
private:
	
	QXmlStreamReader m_streamReader;
	
};

#endif // EROSSERIALIZER_H
