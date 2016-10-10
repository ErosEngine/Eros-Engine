#ifndef CAMERA_H
#define CAMERA_H

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
    
    glm::mat4 getViewMatrix();
    glm::mat4 getPerspective();
    
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
