#include "OGLShader.h"
#include <iostream>
#include <QFile>
#include "Engine/Developer/Util/Util.h"



void OGLShader::setup()
{
    this->subShaderProgram = glCreateShader(shaderType);
    
    const GLchar *temp_ = shaderCode.c_str();
    glShaderSource(subShaderProgram, 1, &temp_, NULL);
}

bool OGLShader::compile()
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

bool OGLShader::loadFromFile(const char *_fileName, GLenum nShaderType)
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

int OGLShaderProgram::findInList(const char *name)
{
    for (int i = 0; i < m_infoList.size(); ++i)
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

void OGLShaderProgram::addShader(const OGLShader &shader)
{
    m_shaderList.push_back(shader);
    glAttachShader(shaderProgram, shader.subShaderProgram);
}

bool OGLShaderProgram::compile()
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

void OGLShaderProgram::use()
{
    glUseProgram(shaderProgram);
}

void OGLShaderProgram::setUniform(const char *variableName, const glm::vec4 &data)
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

void OGLShaderProgram::setUniform(const char *variableName, const glm::vec3 &data)
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

void OGLShaderProgram::setUniform(const char *variableName, const glm::vec2 &data)
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

void OGLShaderProgram::setUniform(const char *variableName, int data)
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

void OGLShaderProgram::setUniform(const char *variableName, float data)
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

void OGLShaderProgram::setUniform(const char *variableName, Texture &data)
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

void OGLShaderProgram::setUniform(const char *variableName, const EMatrix4x4 &data)
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

void OGLShaderProgram::setUniform(const char *variableName, const glm::mat4 &data)
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

void OGLShaderProgram::setBuffer(const char *variableName, const Vector<PointLight> &light)
{
	GLuint uniformBuffer = 0;
	GLuint uniformLocation = 0;
	glGenBuffers(1, &uniformBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, uniformBuffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(PointLight), &light, GL_DYNAMIC_DRAW);
	
	uniformLocation = glGetUniformBlockIndex(this->shaderProgram, variableName);
	
	glUniformBlockBinding(this->shaderProgram, uniformLocation, uniformBuffer);
	glBindBufferBase(GL_UNIFORM_BUFFER, uniformBuffer, uniformLocation);
	
	
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void OGLShaderProgram::setBuffer(const char *variableName, const Vector<DirectionalLight> &light)
{
	GLuint uniformBuffer = 0;
	GLuint uniformLocation = 0;
	glGenBuffers(1, &uniformBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, uniformBuffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(DirectionalLight), &light[0], GL_DYNAMIC_DRAW);
	
	uniformLocation = glGetUniformBlockIndex(this->shaderProgram, variableName);
	glUniformBlockBinding(this->shaderProgram, uniformLocation, 1);
	glBindBufferBase(GL_UNIFORM_BUFFER, 1, uniformBuffer);
	
	int activeBlock;
	glGetIntegerv(GL_ACTIVE_UNIFORM_BLOCKS, &activeBlock);
	
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	glDeleteBuffers(1, &uniformBuffer);
}

// TODO
void OGLShaderProgram::setBuffer(const char *variableName, const Vector<Spotlight> &light)
{
	
}



