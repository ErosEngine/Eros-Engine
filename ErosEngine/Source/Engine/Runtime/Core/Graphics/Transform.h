#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <QtCore/QString>

const glm::vec3 VEC3_UP    ( 0,  1,  0);
const glm::vec3 VEC3_RIGHT ( 1,  0,  0);
const glm::vec3 VEC3_LEFT  (-1,  0,  0);
const glm::vec3 VEC3_DOWN  ( 0, -1,  0);
const glm::vec3 VEC3_BACK  ( 0,  0, -1);
const glm::vec3 VEC3_FRONT ( 0,  0,  1);


class Transform
{
public:
    Transform();
    
    void Translate(float x, float y, float z, float speed = 1.0f);
    void Translate(glm::vec3 dir, float speed = 1.0f);
    void Rotate(float angle, glm::vec3 axis, float speed = 1.0f);
    void MoveTo(float x, float y, float z, float speed = 1.0f);
    void MoveTo(glm::vec3 pos, float speed = 1.0f);
    void Scale(glm::vec3 newScale);
    void Scale(float nX, float nY, float nZ);
    
    
    // NOTE(kiecker): Using the getters and setters because I 
    // will need the accessors to do stuff when they are changed
    void SetPosition(glm::vec3 pos);
    void SetRotation(glm::vec3 rot);
    
    glm::vec3 GetScale()    const;
    glm::vec3 GetPosition() const; 
    glm::vec3 GetRotation() const;
    
    // This will probably only be used for the renderer
    const glm::mat4 &GetModelMat(); 
    
    bool HasChanged() const;
    
private:
    
    bool      m_hasChanged;
    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
    glm::mat4 m_modelMat;
};

#endif // TRANSFORM_H
