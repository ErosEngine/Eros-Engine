#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>


class PointLight
{
public:
    
    glm::vec3 position;
    glm::vec3 color;
    float ambientStrength;
    float specularStrength;
    float reach;
    
};




#endif // LIGHT_H
