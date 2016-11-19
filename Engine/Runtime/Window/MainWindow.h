#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <SDL_video.h>
#include <QDebug>


class MainWindow_SDL
{
public:
    explicit MainWindow_SDL();
    
    void Start();
    
private:
    
    enum GameState
    {
        RUNNING,
        ENDING
    };
    
    void GameStart();
    void GameLoop();
    void GameEnd();
    
    SDL_Window *m_window;
    GameState m_state;
    
};




#endif // MAINWINDOW_H
