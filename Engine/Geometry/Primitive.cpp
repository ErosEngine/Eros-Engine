#include "Primitive.h"

#define PRINTGL std::cout << glGetError() << "\n";

Primitive::Primitive()
{
}

void Primitive::bind()
{
    vertShader.bind();
    fragShader.bind();
    if (vertShader.compile())
    {
        std::cout << "Vertex shader compiled\n";
    }
    if (fragShader.compile())
    {
        std::cout << "fragment shader compiled\n";
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
        PRINTGL
        std::cout << "No shader compilation errors\n";
    }
    
}

void Primitive::draw()
{
    glBindVertexArray(m_vaoId);
    mainShader.use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);
    glBindVertexArray(0);
}
