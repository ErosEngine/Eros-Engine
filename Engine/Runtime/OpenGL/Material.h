#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
#include "Texture.h"


class Material
{
public:
    
    float shininess;
    Texture diffuseTexture;
    Texture specularTexture;
};

#endif // MATERIAL_H
