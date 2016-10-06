#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::translate(float x, float y, float z, float speed)
{
    
}

void Transform::translate(Vector3 pos, float speed)
{
    
}

void Transform::rotate(float angle, Vector3 axis, float speed)
{
    
}

void Transform::moveTo(float x, float y, float z, float speed)
{
    
}

void Transform::moveTo(Vector3 pos, float speed)
{
    
}

void Transform::setPosition(Vector3 pos) 
{
    
}

void Transform::setRotation(Quaternion rot)
{
    
}

Vector3 Transform::position() const
{
    return m_position;
}

Quaternion Transform::rotation() const
{
    return m_rotation;
}

mat4 Transform::modelMat() const
{
    return m_modelMat;
}
