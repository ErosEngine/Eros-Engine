#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <QString>

// Hehe, I'm so evil >:D
// But in all seriousness this is more for readability
typedef glm::quat Quaternion;
typedef glm::vec4 Vector4; 
typedef glm::vec3 Vector3;
typedef glm::vec2 Vector2;
using glm::mat4;



class Transform
{
public:
    Transform();
    
    void translate(float x, float y, float z, float speed = 1.0f);
    void translate(Vector3 pos, float speed = 1.0f);
    void rotate(float angle, Vector3 axis, float speed = 1.0f);
    void moveTo(float x, float y, float z, float speed = 1.0f);
    void moveTo(Vector3 pos, float speed = 1.0f);
    
    
    // NOTE(kiecker): Using the getters and setters because I 
    // will need the accessors to do stuff when they are changed
    void setPosition(Vector3 pos);
    void setRotation(Quaternion rot);
    
    Vector3 position() const; 
    Quaternion rotation() const;
    glm::mat4 modelMat() const;
    
private:
    
    Vector3 m_position;
    Quaternion m_rotation;
    
    mat4 m_modelMat;
};

#endif // TRANSFORM_H
