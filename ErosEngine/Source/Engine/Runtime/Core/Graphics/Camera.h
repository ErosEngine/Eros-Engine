#ifndef CAMERA_H
#define CAMERA_H

#include <Core/Common.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

struct Camera
{
    Camera();
    
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
    glm::vec2 prevMousePos;
    
    float speed;
    float yRot;
    float xRot;
    float fov;
    float zNear;
    float zFar;
    float width;
    float height;
    float sensitivity;
    float aspect;
    
    bool isFirstMouse;
    
    glm::mat4 GetViewMatrix();
    glm::mat4 GetPerspective();
    
    // ALL TRANSFOMATIONS ARE RELATIVE
    void MouseUpdate(Sint32 x, Sint32 y);
    void StrafeRight();
    void StrafeLeft();
    void MoveForward();
    void SprSint32Forward(float multiplier);
    void MoveDownward();
    void MoveUp();
    void MoveBack();
    void UpdatePerspective(float fov, float width,
                           float height, float zNear,
                           float zFar, float aspect_);
    
};

#endif // CAMERA_H
