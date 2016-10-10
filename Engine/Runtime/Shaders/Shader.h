#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <QDebug>
#include "Engine/Runtime/OpenGL/Coordinates.h"
#include <glm/gtc/matrix_transform.hpp>

#ifndef TRANSFORM_H
#include "../OpenGL/Shape/Transform.h"
#endif

#define EROS_VERTEX_SHADER GL_VERTEX_SHADER
#define EROS_FRAG_SHADER GL_FRAGMENT_SHADER


using std::string;

class SubShader
{
    
public:
    
    explicit SubShader(const GLenum &shaderType_ = GL_INVALID_ENUM) :
        shaderType(shaderType_) { /* ... */ }
    
    GLuint subShaderProgram;
    
    void bind();
    bool compile();
    
    string shaderCode;
    GLenum shaderType;
};

SubShader loadShaderFromFile(const char *fileName, const GLenum &shaderType);

class Shader
{
    struct ShaderInformation
    {
        string varName;
        GLint varPos;
        
        bool operator == (const ShaderInformation &right);
    };
        
    typedef std::vector<ShaderInformation> ShaderInfoList;
    typedef std::vector<SubShader> Shaders;
    
    Shaders m_shaderList;
    ShaderInfoList m_infoList;
    
    // Note(kiecker): returns 0 if it wasn't found, 
    // so you can do: if (findInList(var)) { ... }
    int findInList(const char *name);
    
    friend class Transform;
    
public:
    
    Shader();
   ~Shader();
    GLuint shaderProgram;
    
    void addShader(const SubShader &shader);
    void bind();
    bool compile();
    void use();
    
    void setUniformV4f(const char *variableName, const Vector4 &data);
    void setUniformV3f(const char *variableName, const Vector3 &data);
    void setUniformV2f(const char *variableName, const Vector2 &data);
    void setUniformInt(const char *variableName, int data);
    void setUniformFloat(const char *variableName, float data);
    void setUniformM44(const char *variableName, const Matrix4x4 &data);
    void setUniformM44(const char *variableName, const glm::mat4 &data);
    
};

#endif // SHADER_H
