#ifndef ENTITY_H
#define ENTITY_H

#include "Scene.h"
#include "IRenderBase.h"
#include <vector>
#include <QString>


class SceneManager
{
	std::vector<Scene> m_scenes;
	int m_activeScene = 0;
	
public:
	
	SceneManager();
	
	// Load the scenes from file
	// The default scene is index 1
	// If no scene file is found then 
	// it will spit a verbose error
	void initialize(RenderingApi api);
	
	// Getters and setters for the scene
	void setScene(int scene);
	Scene *getActiveScene();
	
	void cleanSelectedScene(int scene);
	void cleanAllScenes();
	
};

#endif // ENTITY_H
