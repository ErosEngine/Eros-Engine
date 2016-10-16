#include "Camera.h"
#include <QDebug>
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

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getPerspective()
{
    return glm::perspective(fov, aspect, zNear, zFar);
}

void Camera::mouseUpdate(int x, int y)
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

void Camera::strafeRight()
{
    position += glm::normalize(glm::cross(target, up)) * speed;
}

void Camera::strafeLeft()
{
    position -= glm::normalize(glm::cross(target, up)) * speed;
}

void Camera::moveForward()
{
    position += target * speed;
}

void Camera::moveDownward()
{
    position -= up * speed;
}
void Camera::moveUp()
{
    position += up * speed;
}

void Camera::moveBack()
{
    position -= target * speed;
}

void Camera::updatePerspective(float fov_, float width_, float height_, 
                               float zNear_, float zFar_, float aspect_)
{
    this->fov = fov_;
    this->width = width_;
    this->height = height_;
    this->zNear = zNear_;
    this->zFar = zFar_;
    this->aspect = aspect_;
}

