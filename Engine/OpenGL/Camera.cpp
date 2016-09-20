#include "Camera.h"

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -1.0f);
    target = glm::vec3(0.0f, 0.0f, 0.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    speed = 0.5f;
}

glm::mat4 Camera::getWorldToViewMatrixGLM()
{
    return glm::lookAt(position, target, up);
}

Matrix4x4 Camera::getWorldToViewMatrix()
{
    return Matrix4x4();
    //return LookAt(this->position, this->target, this->up);
}

void Camera::mouseUpdate(float x, float y)
{
    
}

void Camera::strafeRight()
{
    position.x += 1.0f * speed;
}

void Camera::strafeLeft()
{
    position.x -= 1.0f * speed;
}

void Camera::moveForward()
{
    position.z += 1.0f * speed;
}

void Camera::moveDownward()
{
    position.y -= 1.0f * speed;
}

void Camera::moveUp()
{
    position.y += 1.0f * speed;
}

void Camera::moveBack()
{
    position.z -= 1.0f * speed;
}
