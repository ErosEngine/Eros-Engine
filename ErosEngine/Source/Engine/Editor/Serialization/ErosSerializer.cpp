#include "ErosSerializer.h"
#include <QFile>
#include "Runtime/Core/Framework/Scene.h"


ErosSerializer::ErosSerializer()
{
	
}

void ErosSerializer::OpenFile(const char *fileName)
{
	QFile file(fileName);
	file.open(QIODevice::Text | QIODevice::ReadWrite);
	
	m_streamReader.setDevice(&file);
}

bool ErosSerializer::ReadScene(Scene *pOutScene)
{
	return false;
	
}

void ErosSerializer::WriteScene(const Scene *pInScene)
{
	
}
