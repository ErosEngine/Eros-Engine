#include "Primitive.h"
#include "Engine/Util/Util.h"


Primitive::Primitive()
{
    m_matrix.setIdentity();
}

void Primitive::bind()
{
    m_time = 0;
    vertShader.bind();
    fragShader.bind();
    if (vertShader.compile())
    {
        eDebug() << "Vertex shader compiled" << endl;
    }
    if (fragShader.compile())
    {
        eDebug() << "fragment shader compiled" << endl;
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
    mainShader.bind();
    if (mainShader.compile())
    {
        eDebug() << "No shader compilation errors" << endl;
    }
    GLfloat xPosition = 1.0f;
    m_matrix.translate(xPosition, 0.0f, 0.0f);
}

void Primitive::draw()
{
    m_time++;
    GLfloat xPosition = sinf((float)m_time / 100.0f);
    m_matrix.translate(xPosition, 0.0f, 0.0f); 
    glBindVertexArray(m_vaoId);
    mainShader.use();
    mainShader.setUniformM44("translation", m_matrix);
    qDebug() << "Error code: " << (int)glGetError();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);
    glBindVertexArray(0);
}
