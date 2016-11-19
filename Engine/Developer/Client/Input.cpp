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

void Input::UpdateKeys()
{
    SDL_PumpEvents();
    m_keys = (Uint8 *)SDL_GetKeyboardState(NULL);
}

void Input::UpdateEvent()
{
    (SDL_PollEvent(&m_event));
}

void Input::UpdateMouse()
{
    UpdateEvent();
    SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);
}

bool Input::GetKeyUp(KeyCode code)
{
    UpdateEvent();
    UpdateKeys();
    if (!m_keys[code] && m_event.key.state == SDL_KEYUP)
    {
        return true;
    }
    return false;
}

bool Input::GetKeyDown(KeyCode code)
{
    UpdateEvent();
    UpdateKeys();
    if (m_keys[code] && m_event.key.state == SDL_KEYDOWN)
    {
        return true;
    }
    return false;
}

bool Input::GetButtonDown(MouseButton code)
{
    return false;
}

bool Input::GetButtonUp(MouseButton code)
{
    return false;
}

MousePosition Input::GetMouse()
{
    clearMouse();
    UpdateMouse();
    return m_mousePosition;
}

