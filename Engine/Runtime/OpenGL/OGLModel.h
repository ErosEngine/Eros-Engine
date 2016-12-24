#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../Core/Framework/ComponentsBase.h"



class OGLModel : public IDrawableComponent
{	
public:
	
	// TODO(kiecker): determine what it will load, this function has to be
	// overloaded
	// make it load mesh from file?
	virtual bool loadFromFile(const char *fileName) override;
	
	// See the documentation at 
	// <Engine/Runtime/Core/Framework/ComponentsBase.h>
	virtual void generateBuffers() override;
	virtual void setupBuffers() override;
	
	virtual void draw() override;
	virtual void cleanup() override;
	
	virtual void *getBuffer() override;
	
	/* ---- Inherited functions ----
	void loadNewMesh(const char *fileName);
	const MeshComponent *mesh() const;
	 */
    
	
private:
	
	OpenGLBuffer m_buffer;
	
	/* -- From inherited object IDrawableComponent
	MeshComponent i_mesh;
	-- */
};


#endif // MODEL_H
