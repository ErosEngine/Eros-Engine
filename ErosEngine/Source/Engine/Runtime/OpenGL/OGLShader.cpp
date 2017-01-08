#include "OGLShader.h"
#include <iostream>
#include <QtCore/QFile>



void OGLShader::Setup()
{
    this->subShaderProgram = glCreateShader(shaderType);
    
    const GLchar *temp_ = shaderCode.c_str();
    glShaderSource(subShaderProgram, 1, &temp_, NULL);
}

bool OGLShader::Compile()
{
    glCompileShader(subShaderProgram);
    Sint32 shaderCompOutput;
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

bool OGLShader::LoadFromFile(const char *_fileName, GLenum nShaderType)
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

bool OGLShaderProgram::ShaderInformation::operator ==(const OGLShaderProgram::ShaderInformation &right)
{
    return (this->varName == right.varName); // Shouln't need to return more than this
}

Sint32 OGLShaderProgram::findInList(const char *name)
{
    for (Sint32 i = 0; i < m_infoList.size(); ++i)
    {
        // Note(kiecker): string on right order to avoid warnings        
        if (m_infoList[i].varName == name) 
            return i;
    }
    return false; // <- this works o_O
}

OGLShaderProgram::OGLShaderProgram()
{
    shaderProgram = glCreateProgram();    
}

OGLShaderProgram::~OGLShaderProgram()
{
    
}

void OGLShaderProgram::AddShader(const OGLShader &shader)
{
    m_shaderList.push_back(shader);
    glAttachShader(shaderProgram, shader.subShaderProgram);
}

bool OGLShaderProgram::Compile()
{
    glLinkProgram(shaderProgram);
    Sint32 shaderCompOutput;
    GLchar compileOutput[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderCompOutput);
    if (shaderCompOutput == GL_FALSE)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, compileOutput);
        
        for (Sint32 i = 0; i < m_shaderList.size(); ++i)
        {
            glDeleteShader(m_shaderList[i].subShaderProgram);
        }
        glDeleteProgram(shaderProgram);
        qDebug() << "Shader Program error :" << QString((const char *)compileOutput);
        return false;
    }
    
    // After compilation was successful, detach 
    for (Sint32 i = 0; i < m_shaderList.size(); ++i)
    {
        glDetachShader(shaderProgram, m_shaderList[i].subShaderProgram);
        m_shaderList.clear();
    }
    return true;
}

void OGLShaderProgram::UseShader()
{
    glUseProgram(shaderProgram);
}

void OGLShaderProgram::SetUniform(const char *variableName, const glm::vec4 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform4f(m_infoList[b].varPos, data.x, data.y, data.z, data.w);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform4f(uniformLoc, data.x, data.y, data.z, data.w);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const glm::vec3 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform3f(m_infoList[b].varPos, data.x, data.y, data.z);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform3f(uniformLoc, data.x, data.y, data.z);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const glm::vec2 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform2f(m_infoList[b].varPos, data.x, data.y);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform2f(uniformLoc, data.x, data.y);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const EVector4 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform4f(m_infoList[b].varPos, data.x, data.y, data.z, data.w);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform4f(uniformLoc, data.x, data.y, data.z, data.w);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const EVector3 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform3f(m_infoList[b].varPos, data.x, data.y, data.z);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform3f(uniformLoc, data.x, data.y, data.z);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const EVector2 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform2f(m_infoList[b].varPos, data.x, data.y);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform2f(uniformLoc, data.x, data.y);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, Sint32 data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform1i(m_infoList[b].varPos, data);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform1i(uniformLoc, data);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, float data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniform1f(m_infoList[b].varPos, data);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniform1f(uniformLoc, data);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

void OGLShaderProgram::SetUniform(const char *variableName, const EMatrix4x4 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
//      glUniformMatrix4fv(m_infoList[b].varPos, 1, GL_TRUE, &data[0][0]);
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
//      glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, &data[0][0]);
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
    }
}

#include <glm/gtc/type_ptr.hpp>

void OGLShaderProgram::SetUniform(const char *variableName, const glm::mat4 &data)
{
    Sint32 b = findInList(variableName);
    if (b) // if we found the variable
    {
        glUniformMatrix4fv(m_infoList[b].varPos, 1, GL_FALSE, glm::value_ptr(data));
    }
    else
    {
        Sint32 uniformLoc = glGetUniformLocation(shaderProgram, variableName);
        glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(data));
        ShaderInformation i;
        i.varName = variableName;
        i.varPos = uniformLoc;
        m_infoList.push_back(i);
	}
}




