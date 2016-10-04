#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <QString>


typedef glm::vec4 Vector4;
typedef glm::vec3 Vector3;
typedef glm::vec2 Vector2;

class Transform
{
public:
    Transform();
    
    void translate(float x, float y, float z, float speed = 1.0f);
    void translate(Vector3 pos, float speed = 1.0f);
    void rotate(float angle, Vector3 axis, float speed = 1.0f);
    void moveTo(float x, float y, float z, float speed = 1.0f);
    void moveTo(Vector3 pos, float speed = 1.0f);
    
    Vector3 position;
    Vector3 rotation;
    
private:
    
    // Note(kiecker): friend out to the shader class
    glm::mat4 modelMat;
};

#endif // TRANSFORM_H
