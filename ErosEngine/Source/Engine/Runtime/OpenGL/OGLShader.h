#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <QtCore/QDebug>
#include "Core/Common.h"
#include "Core/Math.h"
#include <glm/gtc/matrix_transform.hpp>



#define EROS_VERTEX_SHADER GL_VERTEX_SHADER
#define EROS_FRAG_SHADER GL_FRAGMENT_SHADER

using std::string;



class OGLShader
{
    
public:
    
    Uint32 subShaderProgram;
    
    void Setup();
    bool Compile();
    
    string shaderCode;
    GLenum shaderType;
    
    bool LoadFromFile(const char *fileName, GLenum nShaderType);
    
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
        Sint32 varPos;
        
        bool operator == (const ShaderInformation &right);
    };
        
    
    std::vector<OGLShader>         m_shaderList;
    std::vector<ShaderInformation> m_infoList;
    
    // Note(kiecker): returns 0 if it wasn't found, 
    // so you can do: if (findInList(var)) { ... }
    Sint32 findInList(const char *name);
	
    // This might be a todo
    friend class Transform;
    
public:
    
    OGLShaderProgram();
   ~OGLShaderProgram();
    Sint32 shaderProgram;
    
	// Add implicit creation so that we don't 
	// have to worry about null function pointers
	void Create();
    void AddShader(const OGLShader &shader);
    bool Compile();
    void UseShader();
    
    void SetUniform(const char *variableName, const glm::vec4 &data);
    void SetUniform(const char *variableName, const glm::vec3 &data);
    void SetUniform(const char *variableName, const glm::vec2 &data);
	void SetUniform(const char *variableName, const EVector4 &data);
    void SetUniform(const char *variableName, const EVector3 &data);
    void SetUniform(const char *variableName, const EVector2 &data);
    void SetUniform(const char *variableName, Sint32 data);
    void SetUniform(const char *variableName, float data);
    void SetUniform(const char *variableName, const EMatrix4x4 &data);
    void SetUniform(const char *variableName, const glm::mat4 &data);
    
};

#endif // SHADER_H
