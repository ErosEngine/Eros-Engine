#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <QDebug>
#include "Engine/Geometry/Coordinates.h"

#define EROS_VERTEX_SHADER 1
#define EROS_FRAG_SHADER 2

using std::string;

class SubShader
{
    
public:
    
    explicit SubShader(const short &shaderType = 5) : m_shaderType(shaderType) { /* ... */ }
    
    string data;
    GLuint subShaderProgram;
    
    void bind();
    bool compile();
    
private:
    
    short m_shaderType;
};

SubShader loadShaderFromFile(const char *fileName, const short &shaderType);

class Shader
{
    
    std::vector<SubShader> m_shaderList;
    
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
    
//  Not fully implemented    
//  void setUniformMT4(const char *variableName, const Matrix4 &data);
};

#endif // SHADER_H
