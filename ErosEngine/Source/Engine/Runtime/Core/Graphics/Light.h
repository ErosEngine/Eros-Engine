#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>


struct DirectionalLight
{
    bool castShadows;
    glm::vec3 direction;
    // Since this should be the brightest light in the scene
    // this should be the one to hold the ambient color;
    glm::vec3 ambientColor; 
    glm::vec3 diffuseColor;
    glm::vec3 specularColor;
};

struct PoSint32Light
{
    bool castShadows;
    glm::vec3 position;
    glm::vec3 ambientColor;
    glm::vec3 diffuseColor;
    glm::vec3 specularColor;
    
    float constant;
    float linear;
    float quadratic;
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
