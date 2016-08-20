#include "Shader.h"
#include <string>
#include "Engine/FileSystem/Resource.h"


void SubShader::bind()
{
    if (m_shaderType == BANE_VERTEX_SHADER)
        subShaderProgram = glCreateShader(GL_VERTEX_SHADER);
    else if (m_shaderType == BANE_FRAG_SHADER)
        subShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
    else
        qDebug() << "ERROR, SHADERTYPE NOT RECOGNIZED";
    
    const GLchar *temp_ = data.c_str();
    glShaderSource(subShaderProgram, 1, &temp_, NULL);
}

bool SubShader::compile()
{
    glCompileShader(subShaderProgram);
    GLint shaderCompOutput;
    GLchar compileOutput[512];
    QString shaderType_;
    if (m_shaderType == BANE_VERTEX_SHADER)
    {
        shaderType_ = "VERTEX SHADER"; 
    }
    if (m_shaderType == BANE_FRAG_SHADER)
    {
        shaderType_ = "FRAGMENT SHADER";
    }
    glGetShaderiv(subShaderProgram, GL_COMPILE_STATUS, &shaderCompOutput);
    
    // if the shader failed to compile
    if (shaderCompOutput == GL_FALSE)
    {
        glGetShaderInfoLog(subShaderProgram, 512, NULL, compileOutput);
        qDebug() << shaderType_ << " COMPILATION FAILED\n" << (char *)compileOutput;
        return false;
    }
    
    return true;
}


/**************************************************************************/


SubShader loadShaderFromFile(const char *_fileName, const short &shaderType)
{
    Resource resource(_fileName);
    SubShader returnShader(shaderType);
    returnShader.data = resource.getData();
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
    m_shaderList.push_back(shader);
}

void Shader::bind()
{
    for (int i = 0; i < m_shaderList.size(); ++i)
    {
        glAttachShader(shaderProgram, m_shaderList[i].subShaderProgram);
    }
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
        qDebug() << "MAINSHADER LINK FAILED";
        qDebug() << compileOutput;
        
        for (int i = 0; i < m_shaderList.size(); ++i)
        {
            glDeleteProgram(shaderProgram);
        }
        return false;
    }
    
    qDebug() << "Main Shader linkage success";
    
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

