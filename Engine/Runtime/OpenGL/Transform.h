#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <QString>

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
    
    void translate(float x, float y, float z, float speed = 1.0f);
    void translate(glm::vec3 dir, float speed = 1.0f);
    void rotate(float angle, glm::vec3 axis, float speed = 1.0f);
    void moveTo(float x, float y, float z, float speed = 1.0f);
    void moveTo(glm::vec3 pos, float speed = 1.0f);
    
    
    // NOTE(kiecker): Using the getters and setters because I 
    // will need the accessors to do stuff when they are changed
    void setPosition(glm::vec3 pos);
    void setRotation(glm::quat rot);
    
    glm::vec3 getPosition() const; 
    glm::quat getRotation() const;
    glm::mat4 getModelMat();
    
    bool hasChanged() const;
    
private:
    
    bool      m_hasChanged;
    glm::vec3 m_position;
    glm::quat m_rotation;
    
    glm::mat4 m_modelMat;
};

#endif // TRANSFORM_H
