#ifndef INPUT_H
#define INPUT_H

#ifndef _SDL_events_h
#include <SDL_events.h>
#endif

#include <cassert>


struct MousePosition
{
    int x, y;
};

// THIS IS FOR THE SDL WINDOW ONLY
// THE QT EDITOR HAS ITS OWN KEYEVENTS
// THAT WE WILL CONTROL MANUALLY
class Input
{
public:
    enum KeyCode
    {
        a = SDLK_a, b = SDLK_b, c = SDLK_c, d = SDLK_c, e = SDLK_e, f = SDLK_f, g = SDLK_g, h = SDLK_h,
        i = SDLK_i, j = SDLK_j, k = SDLK_k, l = SDLK_l, m = SDLK_m, n = SDLK_n, o = SDLK_o, p = SDLK_p,
        q = SDLK_q, r = SDLK_r, s = SDLK_s, t = SDLK_t, u = SDLK_u, v = SDLK_v, w = SDLK_w, x = SDLK_x,
        y = SDLK_y, z = SDLK_z, semicolon = SDLK_SEMICOLON, del = SDLK_DELETE,
        caps = SDLK_CAPSLOCK, esc = SDLK_ESCAPE, tab = SDLK_TAB,
        up = SDLK_UP, right = SDLK_RIGHT, down = SDLK_DOWN, left = SDLK_LEFT,
        comma = SDLK_COMMA, period = SDLK_PERIOD, slash = SDLK_SLASH, backSlash = SDLK_BACKSLASH,
        lShift = SDLK_LSHIFT, rShift = SDLK_RSHIFT, lCtrl = SDLK_LCTRL, rCtrl = SDLK_RCTRL,
        insert = SDLK_INSERT, prntScrn = SDLK_PRINTSCREEN, pgUp = SDLK_PAGEUP, pgDown = SDLK_PAGEDOWN,
        lAlt = SDLK_LALT, rAlt = SDLK_RALT, minus = SDLK_MINUS, equals = SDLK_EQUALS,
        leftBracket = SDLK_LEFTBRACKET, rightBracket = SDLK_RIGHTBRACKET,
        key0 = SDLK_0, key1 = SDLK_1, key2 = SDLK_2, key3 = SDLK_3, key4 = SDLK_4,
        key5 = SDLK_5, key6 = SDLK_6, key7 = SDLK_7, key8 = SDLK_8, key9 = SDLK_9,
        f1 = SDLK_F1, f2 = SDLK_F2, f3 = SDLK_F3, f4 = SDLK_F4, f5 = SDLK_F5, f6 = SDLK_F6,
        f7 = SDLK_F7, f8 = SDLK_F8, f9 = SDLK_F9, f10 = SDLK_F10, f11 = SDLK_F11, f12 = SDLK_F12
    };

    enum MouseState
    {
        mouseDown = SDL_MOUSEBUTTONDOWN,
        mouseUp = SDL_MOUSEBUTTONUP,
        mouseMotion = SDL_MOUSEMOTION,
        mouseWheel = SDL_MOUSEWHEEL
    };

    enum MouseButton
    {
        mouseLeft = SDL_BUTTON_LEFT,
        mouseRight = SDL_BUTTON_RIGHT,
        mouseMiddle = SDL_BUTTON_MIDDLE
    };

    Input();

    static Input *getInstance();

    void updateKeys();
    void updateEvent();
    void updateMouse();
    bool getKeyUp(KeyCode code);
    bool getKeyDown(KeyCode code);
    bool getButtonDown(MouseButton code);
    bool getButtonUp(MouseButton code);

    MousePosition getMouse();

    inline SDL_Event getEvent() { updateEvent(); return m_event; }

private:

    inline void clearMouse() {
        for (int i = 0; i < 3; ++i) m_mouse[i] = false; }

    Uint8 *m_keys;
    bool m_mouse[3];
    SDL_Event m_event;
    MousePosition m_mousePosition;
    MouseState m_mouseState;
    static Input *m_instance;
};


inline static bool HasQuit()
{
    return Input::getInstance()->getEvent().type == SDL_QUIT;
}

inline static bool GetKeyDown(Input::KeyCode code)
{
    return Input::getInstance()->getKeyDown(code);
}

inline static bool GetKeyUp(Input::KeyCode code)
{
    return Input::getInstance()->getKeyUp(code);
}

inline static MousePosition GetMousePosition()
{
    return Input::getInstance()->getMouse();
}

inline static bool MouseUp(Input::MouseButton button)
{
    return Input::getInstance()->getButtonUp(button);
}

inline static bool MouseDown(Input::MouseButton button)
{
    return Input::getInstance()->getButtonDown(button);
}

#endif // INPUT_H
