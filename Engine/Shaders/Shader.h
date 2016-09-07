#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <QDebug>
#include "Engine/OpenGL/Coordinates.h"
#include <glm/gtc/matrix_transform.hpp>

#define EROS_VERTEX_SHADER 1
#define EROS_FRAG_SHADER 2


using std::string;

class SubShader
{
    
public:
    
    explicit SubShader(const short &shaderType = 5) : m_shaderType(shaderType) { /* ... */ }
    
    GLuint subShaderProgram;
    
    void bind();
    bool compile();
    
    string getData() const;
    void setData(const string &value);
    
private:
    
    string m_data;
    
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
    
    void setUniformV4f(const char *variableName, Vector4 &data);
    void setUniformV3f(const char *variableName, Vector3 &data);
    void setUniformV2f(const char *variableName, Vector2 &data);
    void setUniformInt(const char *variableName, int data);
    void setUniformM44(const char *variableName, Matrix4x4 &data);
    void setUniformM44(const char *variableName, glm::mat4 &data);
    
};

#endif // SHADER_H
