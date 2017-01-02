#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::Translate(float x, float y, float z, float speed)
{
    Translate(glm::vec3(x, y, z), speed);
}

void Transform::Translate(glm::vec3 dir, float speed)
{
    m_modelMat = glm::translate(m_modelMat, dir * speed);
    m_position += dir;
    m_hasChanged = true;
}

void Transform::Rotate(float angle, glm::vec3 axis, float speed)
{
    m_modelMat = glm::rotate(m_modelMat, angle * speed, axis);
    m_hasChanged = true;
}

void Transform::MoveTo(float x, float y, float z, float speed)
{
    MoveTo(glm::vec3(x, y, z), speed);
}

void Transform::MoveTo(glm::vec3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos);
    m_position = pos;
    m_hasChanged = true;
}

void Transform::Scale(glm::vec3 newScale)
{
    m_modelMat = glm::scale(m_modelMat, newScale);
    m_hasChanged = true;
    m_scale = newScale;
}

void Transform::Scale(float nX, float nY, float nZ)
{
    Scale(glm::vec3(nX, nY, nZ));
}

void Transform::SetPosition(glm::vec3 pos) 
{
    m_position = pos;
    m_modelMat = glm::translate(m_modelMat, pos);
    m_hasChanged = true;
}

void Transform::SetRotation(glm::vec3 rot)
{
    m_rotation = rot;
    m_hasChanged = true;
}

glm::vec3 Transform::GetScale() const
{
    return m_scale;
}

glm::vec3 Transform::GetPosition() const
{
    return m_position;
}

glm::vec3 Transform::GetRotation() const
{
    return m_rotation;
}

const glm::mat4 &Transform::GetModelMat()
{
    m_hasChanged = false;
    return m_modelMat;
}

bool Transform::HasChanged() const
{
    return m_hasChanged;
}
