#include "Camera.h"
#include <QDebug>
#include <SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, 1.0f);
    target = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    sensitivity = 0.1f;
    prevX = 0.0f;
    prevY = 0.0f;
    xRot = 0.0f;
    yRot = 0.0f;
    speed = 0.1f;
    isFirstMouse = true;
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getPerspective()
{
    return glm::perspective(fov, aspect, zNear, zFar);
}

Matrix4x4 Camera::getWorldToViewMatrix()
{
    return Matrix4x4();
    //return LookAt(this->position, this->target, this->up);
}

void Camera::mouseUpdate(int x, int y)
{
    float xDiff = (float)x - prevX;
    float yDiff = prevY - (float)y;
    
    qDebug() << "X Diff: " << xDiff;
    qDebug() << "Y Diff: " << yDiff;
    
    float pitch = (yDiff * sensitivity);
    float yaw = (xDiff * sensitivity);
    xRot += yaw;
    yRot += pitch;
        
    if (yRot > 89.f)
        yRot = 89.f;
    
    if (yRot < -89.f)
        yRot = -89.f;
        
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(xRot)) * cos(glm::radians(yRot));
    newFront.y = sin(glm::radians(yRot));
    newFront.z = sin(glm::radians(xRot)) * cos(glm::radians(yRot));
    target = glm::normalize(newFront);
    
    // NOTE(kiecker): Once we are done
    prevX = (float)x;
    prevY = (float)y;
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


// TODO(kiecker):
void Camera::moveDownward()
{
    position -= up;
}
void Camera::moveUp()
{
    position += up;
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

