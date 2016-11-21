#include "Input.h"


Input::Input()
{
    clearMouse();
}

Input *Input::m_instance = 0;

Input *Input::getInstance()
{
    if (!m_instance)
    {
        m_instance = new Input();
    }
    return m_instance;
}

void Input::updateKeys()
{
    SDL_PumpEvents();
    m_keys = (Uint8 *)SDL_GetKeyboardState(NULL);
}

void Input::updateEvent()
{
    (SDL_PollEvent(&m_event));
}

void Input::updateMouse()
{
    updateEvent();
    SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);
}

bool Input::getKeyUp(KeyCode code)
{
    updateEvent();
    updateKeys();
    if (!m_keys[code] && m_event.key.state == SDL_KEYUP)
    {
        return true;
    }
    return false;
}

bool Input::getKeyDown(KeyCode code)
{
    updateEvent();
    updateKeys();
    if (m_keys[code] && m_event.key.state == SDL_KEYDOWN)
    {
        return true;
    }
    return false;
}

bool Input::getButtonDown(MouseButton code)
{
    return false;
}

bool Input::getButtonUp(MouseButton code)
{
    return false;
}

MousePosition Input::getMouse()
{
    clearMouse();
    updateMouse();
    return m_mousePosition;
}

