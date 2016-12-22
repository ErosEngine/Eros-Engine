#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include "../Core/IComponent.h"


struct PointLight
{
	glm::vec3 position;
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	
	float constant;
	float linear;
	float quadratic;
};

struct DirectionalLight
{
    bool castShadows; // TODO(kiecker)
    float brightness;
    glm::vec3 direction;
    glm::vec3 ambientColor; // Ambient ?
    glm::vec3 specularColor;
    glm::vec3 diffuseColor;
};

struct Spotlight
{
    bool castShadows; // TODO(kiecker)
    float brightness;
    float width;
    glm::vec3 color;
    glm::vec3 direction;
    glm::vec3 specularColor;
    glm::vec3 diffuseColor;
};



#endif // LIGHT_H
