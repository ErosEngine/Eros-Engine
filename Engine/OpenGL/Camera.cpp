#include "Camera.h"

Camera::Camera()
{
    
}

glm::mat4 Camera::getWorldToViewMatrixGLM()
{
    return glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Matrix4x4 Camera::getWorldToViewMatrix()
{
    return LookAt(this->position, this->target, this->up);
}

void Camera::mouseUpdate(float x, float y)
{
    
}

void Camera::strafeRight()
{
    
}

void Camera::strafeLeft()
{
    
}

void Camera::moveForward()
{
    
}

void Camera::moveDownward()
{
    
}

void Camera::moveUp()
{
    
}

void Camera::moveBack()
{
    
}
