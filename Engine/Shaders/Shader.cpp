#include "Shader.h"
#include <iostream>
#include "Engine/FileSystem/Resource.h"
#include "Engine/Util/Util.h"


void SubShader::bind()
{
    if (m_shaderType == EROS_VERTEX_SHADER)
        subShaderProgram = glCreateShader(GL_VERTEX_SHADER);
    else if (m_shaderType == EROS_FRAG_SHADER)
        subShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
    
    const GLchar *temp_ = m_data.c_str();
    glShaderSource(subShaderProgram, 1, &temp_, NULL);
}

void SubShader::setData(const string &value)
{
    this->m_data = value;
}

string SubShader::getData() const
{
    return m_data;
}

bool SubShader::compile()
{
    glCompileShader(subShaderProgram);
    GLint shaderCompOutput;
    GLchar compileOutput[512];
    QString shaderType_;
    if (m_shaderType == EROS_VERTEX_SHADER)
    {
        shaderType_ = "VERTEX SHADER"; 
    }
    if (m_shaderType == EROS_FRAG_SHADER)
    {
        shaderType_ = "FRAGMENT SHADER";
    }
    glGetShaderiv(subShaderProgram, GL_COMPILE_STATUS, &shaderCompOutput);
    
    // if the shader failed to compile
    if (shaderCompOutput == GL_FALSE)
    {
        glGetShaderInfoLog(subShaderProgram, 512, NULL, compileOutput);
        qDebug() << compileOutput << endl;
        return false;
    }
    
    return true;
}


/**************************************************************************/


SubShader loadShaderFromFile(const char *_fileName, const short &shaderType)
{
    Resource resource(_fileName);
    SubShader returnShader(shaderType);
    returnShader.setData(std::string(resource.getDataConst()));
    return returnShader;
}


/**************************************************************************/


Shader::Shader()
{
    shaderProgram = glCreateProgram();
}

Shader::~Shader()
{
    
}

void Shader::addShader(const SubShader &shader)
{
    glAttachShader(shaderProgram, shader.subShaderProgram);
}

void Shader::bind()
{
}

bool Shader::compile()
{
    glLinkProgram(shaderProgram);
    GLint shaderCompOutput;
    GLchar compileOutput[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderCompOutput);
    if (shaderCompOutput == GL_FALSE)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, compileOutput);
        
        for (int i = 0; i < m_shaderList.size(); ++i)
        {
            glDeleteShader(m_shaderList[i].subShaderProgram);
        }
        glDeleteProgram(shaderProgram);
        return false;
    }
    
    
    // After compilation was successful, detach 
    for (int i = 0; i < m_shaderList.size(); ++i)
        glDetachShader(shaderProgram, m_shaderList[i].subShaderProgram);
    return true;
}

void Shader::use()
{
    glUseProgram(shaderProgram);
}

void Shader::setUniformV4f(const char *variableName, const Vector4 &data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform4f(uniformLoc, data.x, data.y, data.z, data.w);
}

void Shader::setUniformV3f(const char *variableName, const Vector3 &data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform3f(uniformLoc, data.x, data.y, data.z);
}

void Shader::setUniformV2f(const char *variableName, const Vector2 &data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform2f(uniformLoc, data.x, data.y);
}

void Shader::setUniformInt(const char *variableName, int data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform1i(uniformLoc, data);
}

void Shader::setUniformFloat(const char *variableName, float data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform1f(uniformLoc, data);
}

void Shader::setUniformM44(const char *variableName, const Matrix4x4 &data)
{
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, &data.matrix[0][0]);
}

void Shader::setUniformM44(const char *variableName, const glm::mat4 &data)
{    
    GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, &data[0][0]);
}

