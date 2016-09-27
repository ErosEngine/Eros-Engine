#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include "Coordinates.h"
#include "Engine/Shaders/Shader.h"
#include <glm/glm.hpp>

struct Camera
{
    Camera();
    
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
    
    float speed;
    float yRot;
    float xRot;
    float prevX;
    float prevY;    
    float fov;
    float zNear;
    float zFar;
    float width;
    float height;
    float sensitivity;
    float aspect;
    
    bool isFirstMouse;
    
    glm::mat4 getViewMatrix();
    glm::mat4 getPerspective();
    Matrix4x4 getWorldToViewMatrix();
    
    // ALL TRANSFOMATIONS ARE RELATIVE
    void mouseUpdate(int x, int y);
    void strafeRight();
    void strafeLeft();
    void moveForward();
    void moveDownward();
    void moveUp();
    void moveBack();
    void updatePerspective(float fov, float width, float height, 
                           float zNear, float zFar, float aspect_);
    
};

#endif // CAMERA_H
