#include "Primitive.h"
#include "Engine/Util/Util.h"


Primitive::Primitive()
{
}

void Primitive::bind()
{
    vertShader.bind();
    fragShader.bind();
    if (vertShader.compile())
    {
        eDebug() << "Vertex shader compiled";
    }
    if (fragShader.compile())
    {
        eDebug() << "fragment shader compiled";
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
        eDebug() << "No shader compilation errors";
    }
    
}

void Primitive::draw()
{
    glBindVertexArray(m_vaoId);
    mainShader.use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);
    glBindVertexArray(0);
}
