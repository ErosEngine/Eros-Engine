#include "OpenGLRenderer.h"




void OpenGLRenderer::preGameRender()
{
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
    shape->mesh = LoadMeshFromFile("Engine/Assets/Suit/nanosuit.obj");
    if (!shape->texture.loadFromFile("Engine/Assets/Suit/arm_dif.png"))
    {
        qDebug() << "Failed to load texture, " << shape->texture.fileName;
    }
    
    shape->setup();
    camera->updatePerspective(60.0f, 4.0f, 3.0f, 0.1f, 100.0f, 1.33f);
    gPerspective = camera->getPerspective();
    camera->width = (float)windowWidth;
    camera->height = (float)windowHeight;
    shape->shader.use();
    shape->shader.setUniform("perspective", gPerspective);
    shape->shader.setUniform("translation", glm::translate(glm::mat4(), glm::vec3(2, 1, -11)));
}

void OpenGLRenderer::duringGameRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    shape->draw();
    shape->shader.setUniform("modelView", camera->getViewMatrix());
}

void OpenGLRenderer::postGameRender()
{
    delete shape;
    delete camera;
}

void OpenGLRenderer::drawShapeMulti(Shape *pShape, int numTimes)
{
    pShape->bind();
    pShape->texture.bind();
    glDrawElementsInstanced(GL_TRIANGLES, pShape->mesh->indices.size(),
                            GL_UNSIGNED_SHORT, NULL, numTimes);    
    pShape->shader.use();
    pShape->unbind();
}
