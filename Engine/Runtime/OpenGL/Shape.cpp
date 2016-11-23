#include "Shape.h"


Shape::Shape()
{
    
}

Shape::~Shape()
{
    glDeleteBuffers(1, &m_vboId);
    glDeleteBuffers(1, &m_eboId);
    glDeleteVertexArrays(1, &m_vaoId);
    delete mesh;
}

void Shape::setup()
{
    vertShader.loadFromFile("Engine/Runtime/Shaders/baseVert.vert", EROS_VERTEX_SHADER);
    fragShader.loadFromFile("Engine/Runtime/Shaders/baseFrag.frag", EROS_FRAG_SHADER);
    vertShader.setup();
    fragShader.setup();
    if (vertShader.compile())
    {
        qDebug() << "Vertex Shader compiled";
    }
    if (fragShader.compile())
    {
        qDebug() << "Frag shader compiled";
    }
    
    shader.addShader(vertShader);
    shader.addShader(fragShader);
    shader.compile();
    
    
    glGenVertexArrays(1, &m_vaoId);
    glGenBuffers(1, &m_vboId);
    glGenBuffers(1, &m_eboId);
    
    bind();
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertexes.size() * sizeof(Vertex), 
                 &mesh->vertexes[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(GLushort),
                 &mesh->indices[0], GL_STATIC_DRAW);
    
    // Note(kiecker): Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    
    // Note(kiecker): Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, normal));
    
    // Note(kiecker): Texture Coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, texCoords));
    
    shader.use();
    unbind();
}

void Shape::unbind()
{
    glBindVertexArray(0);
}

void Shape::bind()
{
    glBindVertexArray(m_vaoId);
}

void Shape::draw()
{
    bind();
    texture.bind();
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_SHORT, NULL);
    shader.use();
    unbind();
}

GLuint &Shape::vboId()
{
    return m_vboId;
}

GLuint &Shape::eboId()
{
    return m_eboId;
}

GLuint &Shape::vaoId()
{
    return m_vaoId;
}
