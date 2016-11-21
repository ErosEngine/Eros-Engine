#include "Primitive.h"
#include "Engine/Developer/Util/Util.h"
#include "ErosLib/Math.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

Primitive::Primitive()
{
    position = glm::vec3(0, 0, 0);
}

void Primitive::setup()
{
    m_time = 0;
    vertShader.setup();
    fragShader.setup();
    if (vertShader.compile())
    {
        qDebug() << "Vertex shader compiled" << endl;
    }
    if (fragShader.compile())
    {
        qDebug() << "fragment shader compiled" << endl;
    }
    
    
    glGenVertexArrays(1, &m_vaoId);
    glGenBuffers(1, &m_vboId);
    glGenBuffers(1, &m_eboId);
    glBindVertexArray(m_vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verts), m_verts, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    mainShader.addShader(this->fragShader);
    mainShader.addShader(this->vertShader);
    
    if (mainShader.compile())
    {
        qDebug() << "No shader compilation errors" << endl;
    }
}

void Primitive::bind()
{
    glBindVertexArray(this->vaoId());
}

void Primitive::draw()
{
    m_time += 1.0f;
    float xPos = sinf((float)m_time / 1000.0f);
    this->bind();
    mainShader.use();
    mainShader.setUniform("time", m_time / 1000.0f);
    //mainShader.SetUniform("translation", Translate(xPos));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);
    this->unbind();
}

void Primitive::unbind()
{
    glBindVertexArray(0);    
}

GLuint &Primitive::vboId()
{
    return m_vboId;
}

GLuint &Primitive::eboId()
{
    return m_eboId;
}

GLuint &Primitive::vaoId()
{
    return m_vaoId;
}

void DrawMultiplePrimitives(Primitive *prim, int numTimes)
{

}
