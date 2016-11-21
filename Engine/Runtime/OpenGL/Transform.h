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
    
    void translate(float x, float y, float z, float speed = 1.0f);
    void translate(GVector3 pos, float speed = 1.0f);
    void rotate(float angle, GVector3 axis, float speed = 1.0f);
    void moveTo(float x, float y, float z, float speed = 1.0f);
    void moveTo(GVector3 pos, float speed = 1.0f);
    
    
    // NOTE(kiecker): Using the getters and setters because I 
    // will need the accessors to do stuff when they are changed
    void setPosition(GVector3 pos);
    void setRotation(Quaternion rot);
    
    GVector3 getPosition() const; 
    Quaternion getRotation() const;
    glm::mat4 getModelMat() const;
    
private:
    
    GVector3 m_position;
    Quaternion m_rotation;
    
    mat4 m_modelMat;
};

#endif // TRANSFORM_H
