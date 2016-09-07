#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include "Coordinates.h"
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera();
    
    Vector3 position;
    Vector3 target;
    Vector3 up;
    GLfloat speed;
    
    glm::mat4 getWorldToViewMatrixGLM();
    Matrix4x4 getWorldToViewMatrix();
    
    // ALL TRANSFOMATIONS ARE RELATIVE
    void mouseUpdate(float x, float y);
    void strafeRight();
    void strafeLeft();
    void moveForward();
    void moveDownward();
    void moveUp();
    void moveBack();
    
};

#endif // CAMERA_H
