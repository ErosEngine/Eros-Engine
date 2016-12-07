#include "Shader.h"
#include <iostream>
#include <QFile>
#include "Engine/Developer/Util/Util.h"



void SubShader::setup()
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

bool SubShader::loadFromFile(const char *_fileName, GLenum nShaderType)
{
    QFile file(_fileName);
    if (!file.open(QIODevice::Text | QIODevice::ReadWrite))
    {
        return false;
    }
    
    shaderType = nShaderType;
    shaderCode = file.readAll().constData();
    return true;
}



/**************************************************************************/
/**************************************************************************/


// Note(kiecker): These are just some quick util funcs

bool Shader::ShaderInformation::operator ==(const Shader::ShaderInformation &right)
{
    return (this->varName == right.varName); // Shouln't need to return more than this
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
        qDebug() << "Shader Program error :" << QString((const char *)compileOutput);
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

void Shader::setUniform(const char *variableName, const glm::vec4 &data)
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

void Shader::setUniform(const char *variableName, const glm::vec3 &data)
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

void Shader::setUniform(const char *variableName, const glm::vec2 &data)
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

void Shader::setUniform(const char *variableName, int data)
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

void Shader::setUniform(const char *variableName, float data)
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

void Shader::setUniform(const char *variableName, Texture &data)
{
    // We have to assume that they set the active texture already
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
        data.bind();
        glUniform1i(m_infoList[b].varPos, data.texture);
        data.unbind();
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        data.bind();
        glUniform1i(uniformLoc, data.texture);
        data.unbind();
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void Shader::setUniform(const char *variableName, const EMatrix4x4 &data)
{
    int b = findInList(variableName);
    if (b) // if we found the variable
    {
//      glUniformMatrix4fv(m_infoList[b].varPos, 1, GL_TRUE, &data[0][0]);
    }
    else
    {
        GLint uniformLoc = glGetUniformLocation(shaderProgram, variableName);
//      glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, &data[0][0]);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

#include <glm/gtc/type_ptr.hpp>

void Shader::setUniform(const char *variableName, const glm::mat4 &data)
{
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



