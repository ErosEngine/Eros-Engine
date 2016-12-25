#include "Scene.h"
#include <algorithm>


const Camera &Scene::getCamera()
{
	return m_camera;
}

RendererArgs Scene::deliverRelevantArgs()
{
	RendererArgs ret;
	ret.meshes = searchForComponents();
	return ret;
}


// helper
bool Scene::isRelevantComponent(const glm::vec3 &position)
{
	return (glm::distance(position, m_camera.position) < m_camera.zFar);
}

/**
 * @returns a standard vector of components that are in teh player's relevant chunk
 * does a standard search checking the distance from the object to the player and
 * omits objects that are farther than the set draw distance ie (player.zFar)
 * TODO(kiecker): make it a binary tree search, making it a standard search as of writing this
 *	because I wanted to get the stream moving along
*/
std::vector<IDrawableComponent *> Scene::searchForComponents()
{
	std::vector<IDrawableComponent *> retComponents;
	for (uint i = 0; i < m_meshComponents.size(); ++i)
	{
		if (isRelevantComponent(m_meshComponents[i]->transform.getPosition()))
		{
			retComponents.push_back(m_meshComponents[i]);
		}
	}
	return retComponents;
}

