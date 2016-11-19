#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::Translate(float x, float y, float z, float speed)
{
    Translate(GVector3(x, y, z), speed);
}

void Transform::Translate(GVector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos * speed);
    m_position = pos;
}

void Transform::Rotate(float angle, GVector3 axis, float speed)
{
    m_modelMat = glm::rotate(m_modelMat, angle, axis);
}

void Transform::MoveTo(float x, float y, float z, float speed)
{
    m_modelMat = glm::translate(m_modelMat, GVector3(x, y, z));
    m_position = GVector3(x, y, z);
}

void Transform::MoveTo(GVector3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos);
    m_position = pos;
}

void Transform::SetPosition(GVector3 pos) 
{
    m_position = pos;
    m_modelMat = glm::translate(m_modelMat, pos);
}

void Transform::SetRotation(Quaternion rot)
{
    m_rotation = rot;
}

GVector3 Transform::GetPosition() const
{
    return m_position;
}

Quaternion Transform::GetRotation() const
{
    return m_rotation;
}

mat4 Transform::GetModelMat() const
{
    return m_modelMat;
}
