#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <QDebug>
#include "../Core/Framework/Math.h"
#include <glm/gtc/matrix_transform.hpp>



#define EROS_VERTEX_SHADER GL_VERTEX_SHADER
#define EROS_FRAG_SHADER GL_FRAGMENT_SHADER

using std::string;



class OGLShader
{
    
public:
    
    GLuint subShaderProgram;
    
    void setup();
    bool compile();
    
    string shaderCode;
    GLenum shaderType;
    
    bool loadFromFile(const char *fileName, GLenum nShaderType);
    
    inline OGLShader &operator = (const OGLShader &right)
    {
        this->shaderCode = right.shaderCode;
        this->shaderType = right.shaderType;
        this->subShaderProgram = right.subShaderProgram;
        return *this;
    }
};



class OGLShaderProgram
{
    struct ShaderInformation
    {
        string varName;
        GLint varPos;
        
        bool operator == (const ShaderInformation &right);
    };
        
    
    std::vector<OGLShader>         m_shaderList;
    std::vector<ShaderInformation> m_infoList;
    
    // Note(kiecker): returns 0 if it wasn't found, 
    // so you can do: if (findInList(var)) { ... }
    int findInList(const char *name);
	
    // This might be a todo
    friend class Transform;
    
public:
    
    OGLShaderProgram();
   ~OGLShaderProgram();
    GLuint shaderProgram;
    
    void addShader(const OGLShader &shader);
    bool compile();
    void use();
    
    void setUniform(const char *variableName, const glm::vec4 &data);
    void setUniform(const char *variableName, const glm::vec3 &data);
    void setUniform(const char *variableName, const glm::vec2 &data);
	void setUniform(const char *variableName, const EVector4 &data);
    void setUniform(const char *variableName, const EVector3 &data);
    void setUniform(const char *variableName, const EVector2 &data);
    void setUniform(const char *variableName, int data);
    void setUniform(const char *variableName, float data);
    void setUniform(const char *variableName, const EMatrix4x4 &data);
    void setUniform(const char *variableName, const glm::mat4 &data);
    
};

#endif // SHADER_H
