#include "Shader.h"
#include <iostream>
#include "Engine/FileSystem/Resource.h"
#include "Engine/Util/Util.h"


void SubShader::bind()
{
    this->subShaderProgram = glCreateShader(shaderType);
    
    const GLchar *temp_ = shaderCode.c_str();
    glShaderSource(subShaderProgram, 1, &temp_, NULL);
}

bool SubShader::compile()
{
    glCompileShader(subShaderProgram);
    GLint shaderCompOutput;
    GLchar compileOutput[512];
    QString shaderType_;
    if (shaderType == EROS_VERTEX_SHADER)
    {
        shaderType_ = "VERTEX SHADER"; 
    }
    if (shaderType == EROS_FRAG_SHADER)
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


SubShader loadShaderFromFile(const char *_fileName, const GLenum &shaderType)
{
    Resource resource(_fileName);
    SubShader returnShader(shaderType);
    returnShader.shaderCode = (resource.getDataConst());
    return returnShader;
}


/**************************************************************************/


// Note(kiecker): These are just some quick util funcs

bool Shader::ShaderInformation::operator ==(const Shader::ShaderInformation &left)
{
    return (this->varName == left.varName); // Shouln't need to return more than this
}

int Shader::findInList(const char *name)
{
    for (int i = 0; i < m_infoList.size(); ++i)
    {
        // Note(kiecker): string on right order to avoid warnings        
        if (m_infoList[i].varName == name) 
            return i;
    }
    return false; // <- this works o_O
}

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
        qDebug() << QString((const char *)compileOutput);
        return false;
    }
    
    
    // After compilation was successful, detach 
    for (int i = 0; i < m_shaderList.size(); ++i)
    {
        glDetachShader(shaderProgram, m_shaderList[i].subShaderProgram);
        m_shaderList.clear();
    }
    return true;
}

void Shader::use()
{
    glUseProgram(shaderProgram);
}

void Shader::setUniformV4f(const char *variableName, const Vector4 &data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform4f(m_infoList[b].varPos, data.x, data.y, data.z, data.w);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform4f(uniformLoc, data.x, data.y, data.z, data.w);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniformV3f(const char *variableName, const Vector3 &data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform3f(m_infoList[b].varPos, data.x, data.y, data.z);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform3f(uniformLoc, data.x, data.y, data.z);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniformV2f(const char *variableName, const Vector2 &data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform2f(m_infoList[b].varPos, data.x, data.y);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform2f(uniformLoc, data.x, data.y);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniformInt(const char *variableName, int data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform1i(m_infoList[b].varPos, data);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform1i(uniformLoc, data);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniformFloat(const char *variableName, float data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform1f(m_infoList[b].varPos, data);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform1f(uniformLoc, data);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniformM44(const char *variableName, const Matrix4x4 &data)
{    
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniformMatrix4fv(m_infoList[b].varPos, 1, GL_TRUE, &data.matrix[0][0]);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniformMatrix4fv(uniformLoc, 1, GL_TRUE, &data.matrix[0][0]);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

#include <glm/gtc/type_ptr.hpp>

void Shader::setUniformM44(const char *variableName, const glm::mat4 &data)
{
    qDebug() << "Hello world, I am new code!";
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniformMatrix4fv(m_infoList[b].varPos, 1, GL_FALSE, glm::value_ptr(data));
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(data));
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}



