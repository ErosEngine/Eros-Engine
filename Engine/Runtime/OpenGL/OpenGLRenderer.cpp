#include "OpenGLRenderer.h"


void OpenGLRenderer::prepareRenderer()
{
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
    camera->updatePerspective(60.0f, 4.0f, 3.0f, 0.1f, 100.0f, 1.33f);
    camera->width = 1000;
    camera->height = 600;
}

// TODO(kiecker): Add some logic to optimize this
void OpenGLRenderer::renderQueue()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    
    glm::mat4 currentModelView = camera->getViewMatrix();
    
    // Draw individual shapes from the queue
    for (int i = 0; i < m_shapeQueue.size(); ++i)
    {
        glUseProgram(0);
        Shape *pShape = m_shapeQueue[i];
        PointLight light = m_lights[0];
        pShape->bind();
        pShape->shader.use();
        pShape->draw(); // Drawing it one time is handled internally
        pShape->shader.setUniform("modelView",          currentModelView);
        pShape->shader.setUniform("lightPos",           light.position);
        pShape->shader.setUniform("ambientStrength",    light.ambientStrength);
        pShape->shader.setUniform("lightColor",         light.color);
        pShape->shader.setUniform("specularStrength",   light.specularStrength);
        if (pShape->transform.hasChanged())
        {
            pShape->shader.setUniform("translation", pShape->transform.getModelMat());
        }
        pShape->shader.setUniform("viewPos", camera->position);
        pShape->unbind();
        qDebug() << (int)glGetError();
    }
    for (int b = 0; b < m_instancingListQueue.size(); ++b)
    {
        // Instanced objects have to be drawn manually
        InstancingInfo *pInstInfo = &m_instancingListQueue[b];
        Shape *pShape = pInstInfo->shapePtr;
        glUseProgram(0);
        pShape->bind();
        pShape->shader.use();
        pShape->texture.bind();
        glDrawElementsInstanced(
                    GL_TRIANGLES, 
                    pShape->getMesh()->indices.size(), 
                    GL_UNSIGNED_SHORT, NULL, pInstInfo->numberTimes
        );
        pShape->shader.setUniform("modelView", currentModelView);
        pShape->unbind();
    }
    
    glPopMatrix();
}

void OpenGLRenderer::cleanup()
{
    delete camera;
    
    if (m_instancingListQueue.size() > 0)
        m_instancingListQueue.erase(m_instancingListQueue.begin(), m_instancingListQueue.end());
    
    if (m_shapeQueue.size() > 0)
        m_shapeQueue.erase(m_shapeQueue.begin(), m_shapeQueue.end());
    
    m_shapeQueue.clear();
    m_instancingListQueue.clear();
}

void OpenGLRenderer::addShapeInstanceInfo(Shape *pShape, int numTimes)
{
    InstancingInfo info;
    info.numberTimes = numTimes;
    info.shapePtr = pShape;
    m_instancingListQueue.push_back(info);
}

void OpenGLRenderer::addShapeToQueue(Shape *pShape)
{
    m_shapeQueue.push_back(pShape);
}

void OpenGLRenderer::addLightToQueue(PointLight light)
{
    m_lights.push_back(light);
}
