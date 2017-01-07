#ifndef COMPONENTSBASE_H
#define COMPONENTSBASE_H

#include "Core/Platform.h"

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#if defined(EROS_WINDOWS) && !defined(__d3d11_h__)
#include <d3d11.h>
#endif


class QString;

class IComponent
{
public:
	
	virtual ~IComponent() { }
	
	virtual bool LoadFromFile(const char *fileName) = 0;
	virtual void Clear() = 0;
	virtual QString ToString() = 0;
};

class IDrawable : public IComponent
{
public:
	
	virtual ~IDrawable() { }
	
};

// TODO
class IScriptComponent : public IComponent
{
public:
	
	virtual ~IScriptComponent() { }
	
};

// TODO
class IAudioComponent : public IComponent
{
public:
	
	virtual ~IAudioComponent() { }
	
};


#endif // COMPONENTSBASE_H
