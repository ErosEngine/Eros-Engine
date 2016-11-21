#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::translate(float x, float y, float z, float speed)
{
    translate(GVector3(x, y, z), speed);
}

void Transform::translate(GVector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos * speed);
    m_position = pos;
}

void Transform::rotate(float angle, GVector3 axis, float speed)
{
    m_modelMat = glm::rotate(m_modelMat, angle, axis);
}

void Transform::moveTo(float x, float y, float z, float speed)
{
    m_modelMat = glm::translate(m_modelMat, GVector3(x, y, z));
    m_position = GVector3(x, y, z);
}

void Transform::moveTo(GVector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos);
    m_position = pos;
}

void Transform::setPosition(GVector3 pos) 
{
    m_position = pos;
    m_modelMat = glm::translate(m_modelMat, pos);
}

void Transform::setRotation(Quaternion rot)
{
    m_rotation = rot;
}

GVector3 Transform::getPosition() const
{
    return m_position;
}

Quaternion Transform::getRotation() const
{
    return m_rotation;
}

mat4 Transform::getModelMat() const
{
    return m_modelMat;
}
