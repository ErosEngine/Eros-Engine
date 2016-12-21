#include "Transform.h"

Transform::Transform()
{
    
}

void Transform::translate(float x, float y, float z, float speed)
{
    translate(glm::vec3(x, y, z), speed);
}

void Transform::translate(glm::vec3 dir, float speed)
{
    m_modelMat = glm::translate(m_modelMat, dir * speed);
    m_position += dir;
    m_hasChanged = true;
}

void Transform::rotate(float angle, glm::vec3 axis, float speed)
{
    m_modelMat = glm::rotate(m_modelMat, angle * speed, axis);
    m_hasChanged = true;
}

void Transform::moveTo(float x, float y, float z, float speed)
{
    moveTo(glm::vec3(x, y, z), speed);
}

void Transform::moveTo(glm::vec3 pos, float speed)
{
    m_modelMat = glm::translate(m_modelMat, pos);
    m_position = pos;
    m_hasChanged = true;
}

void Transform::scale(glm::vec3 newScale)
{
    m_modelMat = glm::scale(m_modelMat, newScale);
    m_hasChanged = true;
    m_scale = newScale;
}

void Transform::scale(float nX, float nY, float nZ)
{
    scale(glm::vec3(nX, nY, nZ));
}

void Transform::setPosition(glm::vec3 pos) 
{
    m_position = pos;
    m_modelMat = glm::translate(m_modelMat, pos);
    m_hasChanged = true;
}

void Transform::setRotation(glm::vec4 rot)
{
    m_rotation = rot;
    m_hasChanged = true;
}

glm::vec3 Transform::getScale() const
{
    return m_scale;
}

glm::vec3 Transform::getPosition() const
{
    return m_position;
}

glm::vec4 Transform::getRotation() const
{
    return m_rotation;
}

const glm::mat4 &Transform::getModelMat()
{
    m_hasChanged = false;
    return m_modelMat;
}

bool Transform::hasChanged() const
{
    return m_hasChanged;
}
