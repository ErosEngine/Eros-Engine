#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <SDL_video.h>
#include <QDebug>

#include "ErosLib/ErosDefines.h"


class MainWindow_SDL
{
public:
    explicit MainWindow_SDL();
    
    void start();
    
    int width() { return m_height; }
    int height() { return m_height; }
    
private:
    
    enum GameState
    {
        RUNNING,
        ENDING
    };
    
    void gameStart();
    void gameLoop();
    void gameEnd();
    
    SDL_Window  * m_window;
    GameState     m_state;
    int           m_width, m_height;
    
};




#endif // MAINWINDOW_H
