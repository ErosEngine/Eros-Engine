#include <SDL.h>
#include "Engine/Runtime/OpenGL/OpenGLRenderer.h"
#include "MainWindow.h"
#include "Engine/Developer/Util/Util.h"
#include "Engine/Developer/Client/Input.h"
#include <cassert>


MainWindow_SDL::MainWindow_SDL()
{
    m_state = GameState::RUNNING;
    SDL_Init(SDL_INIT_EVERYTHING);
}

void MainWindow_SDL::start()
{
    m_window = SDL_CreateWindow
    (
        "Eros Engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1000, 600, SDL_WINDOW_OPENGL
    );
    
    // Force application failure if window is null
    assert(m_window != nullptr);
    
    SDL_GLContext context = SDL_GL_CreateContext(m_window);
    
    // Force application failure if no context
    assert(context != 0);
    
    if (SDL_GL_MakeCurrent(m_window, context) != 0)
    {
        // Force application failure if opengl context isn't made current
        assert(true);
    }
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    gameStart();    
}

void MainWindow_SDL::gameStart()
{
    GLenum GlResult = glewInit();
    if (GlResult != GLEW_OK)
    {
        qDebug() << "OpenGL failed to initialize";
    }
    else if (GlResult == GLEW_OK)
    {
        qDebug() << "OpenGL has initialized, Current version: " 
                 << ((const char *)glGetString(GL_VERSION));
    }
    gameLoop();
}

void MainWindow_SDL::gameLoop()
{
    OpenGLRenderer renderer;
    renderer.prepareRenderer();
    
    while (m_state == GameState::RUNNING)
    {
        glPushMatrix();
        renderer.renderQueue();
        
        
        
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                m_state = GameState::ENDING;
            }
            if (e.key.keysym.sym == SDLK_w)
            {
                renderer.camera->moveForward();
            }
            if (e.key.keysym.sym == SDLK_a)
            {
                renderer.camera->strafeLeft();
            }
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                m_state = GameState::ENDING;
            }
            if (e.key.keysym.sym == SDLK_s)
            {
                renderer.camera->moveBack();
            }
            if (e.key.keysym.sym == SDLK_d)
            {
                renderer.camera->strafeRight();
            }
            if (e.key.keysym.sym == SDLK_e)
            {
                renderer.camera->moveUp();
            }
            if (e.key.keysym.sym == SDLK_q)
            {
                renderer.camera->moveDownward();
            }
            if (e.type == SDL_MOUSEMOTION)
            {
                renderer.camera->mouseUpdate(e.motion.x, e.motion.y);
            }
        }
        
        SDL_GL_SwapWindow(m_window);
        glPopMatrix();
    }
    
    renderer.cleanup();
    gameEnd();
}

void MainWindow_SDL::gameEnd()
{
    SDL_DestroyWindow(m_window);
}
