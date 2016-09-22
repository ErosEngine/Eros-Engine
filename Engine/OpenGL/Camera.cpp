#include "Camera.h"

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -1.0f);
    target = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    speed = 0.1f;
}

glm::mat4 Camera::getWorldToViewMatrixGLM()
{
    return glm::lookAt(position, position + target, up);
}

Matrix4x4 Camera::getWorldToViewMatrix()
{
    return Matrix4x4();
    //return LookAt(this->position, this->target, this->up);
}

void Camera::mouseUpdate(int x, int y)
{
    
}

void Camera::strafeRight()
{
    position += (glm::cross(target, position)) * speed;
}

void Camera::strafeLeft()
{
}

void Camera::moveForward()
{
    position += target * speed;
}

void Camera::moveDownward()
{
}

void Camera::moveUp()
{
    position.y += 1.0f * speed;
}

void Camera::moveBack()
{
    position -= target * speed;
}
