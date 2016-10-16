#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::translate(float x, float y, float z, float speed)
{
    translate(Vector3(x, y, z), speed);
}

void Transform::translate(Vector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos * speed);
    m_position = pos;
}

void Transform::rotate(float angle, Vector3 axis, float speed)
{
    m_modelMat = glm::rotate(m_modelMat, angle, axis);
}

void Transform::moveTo(float x, float y, float z, float speed)
{
    m_modelMat = glm::translate(m_modelMat, Vector3(x, y, z));
    m_position = Vector3(x, y, z);
}

void Transform::moveTo(Vector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos);
    m_position = pos;
}

void Transform::setPosition(Vector3 pos) 
{
    m_position = pos;
    m_modelMat = glm::translate(m_modelMat, pos);
}

void Transform::setRotation(Quaternion rot)
{
    m_rotation = rot;
}

Vector3 &Transform::position() const
{
    return m_position;
}

Quaternion &Transform::rotation() const
{
    return m_rotation;
}

mat4 &Transform::modelMat() const
{
    return m_modelMat;
}
