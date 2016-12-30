#ifndef SCENE_H
#define SCENE_H

#include "ComponentsBase.h"
#include "../Graphics/Camera.h"


// TODO(kiecker): add shaders and textures to the args
struct RendererArgs
{
	std::vector<IDrawable *> meshes;
};

class Scene
{
	friend class SceneManager;
	
	// Temporary entity storage
	// We will store these with the assumption the textures
	// and meshes have been loaded, however we will optimize
	// the buffers and vertex arrays as we please
	std::vector<IDrawable *>	m_meshComponents;
	
	Camera	m_camera;
	
public:
    
	// Delivers meshes based on position
	RendererArgs deliverRelevantArgs();
	
	// Gets camera, duh!
	const Camera &getCamera();
	
	
private:
	
	bool isRelevantComponent(const glm::vec3 &position);
	std::vector<IDrawable *> searchForComponents();
};

#endif // SCENE_H
