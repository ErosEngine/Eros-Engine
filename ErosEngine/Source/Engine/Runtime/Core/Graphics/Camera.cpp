#include "Camera.h"
#include <QtCore/QDebug>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

Camera::Camera():
    position(0.0f, 0.0f, 1.0f),
    target(0.0f, 0.0f, -1.0f),
    up(0.0f, 1.0f, 0.0f),
    sensitivity(0.1f),
    prevMousePos(0.0f, 0.0f),
    xRot(0.0f),
    yRot(0.0f),
    speed(0.1f),
    isFirstMouse(true)
{
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::GetPerspective()
{
    return glm::perspective(fov, aspect, zNear, zFar);
}

void Camera::MouseUpdate(Sint32 x, Sint32 y)
{
    glm::vec2 currentMousePos(x, y);
    glm::vec2 mouseDelta = currentMousePos - prevMousePos;
    
    if (glm::length(mouseDelta) > 50.0f)
    {
        prevMousePos = currentMousePos;
        return;
    }
    glm::vec3 rightAxis = glm::cross(target, up);
    target = glm::mat3x3(
        glm::rotate(-mouseDelta.x * sensitivity, up) * 
        glm::rotate(-mouseDelta.y * sensitivity, rightAxis)
    ) * target;
    
    prevMousePos = currentMousePos;
}

void Camera::StrafeRight()
{
    position += glm::normalize(glm::cross(target, up)) * speed;
}

void Camera::StrafeLeft()
{
    position -= glm::normalize(glm::cross(target, up)) * speed;
}

void Camera::MoveForward()
{
    position += target * speed;
}

void Camera::SprSint32Forward(float multiplier)
{
    position += target * (speed * multiplier);
}

void Camera::MoveDownward()
{
    position -= up * speed;
}
void Camera::MoveUp()
{
    position += up * speed;
}

void Camera::MoveBack()
{
    position -= target * speed;
}

void Camera::UpdatePerspective(float fov_, float width_, float height_, 
                               float zNear_, float zFar_, float aspect_)
{
    this->fov = fov_;
    this->width = width_;
    this->height = height_;
    this->zNear = zNear_;
    this->zFar = zFar_;
    this->aspect = aspect_;
}

