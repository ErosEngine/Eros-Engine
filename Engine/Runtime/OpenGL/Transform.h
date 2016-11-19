#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <QString>

// Hehe, I'm so evil >:D
// But in all seriousness this is more for readability
typedef glm::quat Quaternion;
typedef glm::vec4 GVector4; 
typedef glm::vec3 GVector3;
typedef glm::vec2 GVector2;
using glm::mat4;



class Transform
{
public:
    Transform();
    
    void Translate(float x, float y, float z, float speed = 1.0f);
    void Translate(GVector3 pos, float speed = 1.0f);
    void Rotate(float angle, GVector3 axis, float speed = 1.0f);
    void MoveTo(float x, float y, float z, float speed = 1.0f);
    void MoveTo(GVector3 pos, float speed = 1.0f);
    
    
    // NOTE(kiecker): Using the getters and setters because I 
    // will need the accessors to do stuff when they are changed
    void SetPosition(GVector3 pos);
    void SetRotation(Quaternion rot);
    
    GVector3 GetPosition() const; 
    Quaternion GetRotation() const;
    glm::mat4 GetModelMat() const;
    
private:
    
    GVector3 m_position;
    Quaternion m_rotation;
    
    mat4 m_modelMat;
};

#endif // TRANSFORM_H
