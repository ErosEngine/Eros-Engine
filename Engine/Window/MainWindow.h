#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <SDL_video.h>
#include <iostream>


class MainWindow_SDL
{
public:
    explicit MainWindow_SDL();
    
    void start();
    
private:
    
    enum GameState
    {
        RUNNING,
        ENDING
    };
    
    void gameStart();
    void gameLoop();
    void gameEnd();
    
    SDL_Window *m_window;
    GameState m_state;
};




#endif // MAINWINDOW_H
