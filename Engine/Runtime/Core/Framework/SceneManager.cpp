#include "SceneManager.h"
#include "../../OpenGL/OGLModel.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QHash>


SceneManager::SceneManager()
{
	
}

void SceneManager::initialize(RenderingApi api)
{
}

Scene *SceneManager::getActiveScene()
{
	return &m_scenes[m_activeScene];
}

void SceneManager::setScene(int scene)
{
	m_activeScene = scene;
}

void SceneManager::cleanSelectedScene(int scene)
{
	Scene *pScene = &m_scenes[scene];
	
	pScene->m_meshComponents;
	
	for (std::vector<IDrawableComponent *>::iterator it = pScene->m_meshComponents.begin(); 
		 it != pScene->m_meshComponents.end(); ++it)
	{
		delete *it;
		it = pScene->m_meshComponents.erase(it);
	}
}

void SceneManager::cleanAllScenes()
{
	for (uint i = 0; i < m_scenes.size(); ++i)
	{
		cleanSelectedScene(i);
	}
}
