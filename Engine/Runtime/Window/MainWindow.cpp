#include <SDL.h>
#include "Engine/Runtime/Renderer/OpenGLRenderer.h"
#include "MainWindow.h"
#include "Engine/Developer/Util/Util.h"
#include "Engine/Developer/Client/Input.h"
#include <cassert>


MainWindow_SDL::MainWindow_SDL()
{
    m_state = GameState::RUNNING;
    SDL_Init(SDL_INIT_EVERYTHING);
}

void MainWindow_SDL::Start()
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
    
    GameStart();    
}

void MainWindow_SDL::GameStart()
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
    GameLoop();
}

void MainWindow_SDL::GameLoop()
{
    OpenGLRenderer renderer;
    renderer.PreGameRender();
    
    while (m_state == GameState::RUNNING)
    {
        glPushMatrix();
        renderer.DuringGameRender();
        
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                m_state = GameState::ENDING;
            }
            if (e.key.keysym.sym == SDLK_w)
            {
                renderer.camera->MoveForward();
            }
            if (e.key.keysym.sym == SDLK_a)
            {
                renderer.camera->StrafeLeft();
            }
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                m_state = GameState::ENDING;
            }
            if (e.key.keysym.sym == SDLK_s)
            {
                renderer.camera->MoveBack();
            }
            if (e.key.keysym.sym == SDLK_d)
            {
                renderer.camera->StrafeRight();
            }
            if (e.key.keysym.sym == SDLK_e)
            {
                renderer.camera->MoveUp();
            }
            if (e.key.keysym.sym == SDLK_q)
            {
                renderer.camera->MoveDownward();
            }
            if (e.type == SDL_MOUSEMOTION)
            {
                renderer.camera->MouseUpdate(e.motion.x, e.motion.y);
            }
        }
        
        SDL_GL_SwapWindow(m_window);
        glPopMatrix();
    }
    
    renderer.PostGameRender();
    GameEnd();
}

void MainWindow_SDL::GameEnd()
{
    SDL_DestroyWindow(m_window);
}
