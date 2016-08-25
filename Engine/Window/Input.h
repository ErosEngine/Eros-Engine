#ifndef INPUT_H
#define INPUT_H

#include <SDL_events.h>


enum KeyCode
{
    Key_Space = SDLK_KP_SPACE, Key_Escape = SDLK_ESCAPE, Key_BackSpace = SDLK_BACKSPACE, Key_Caps = SDLK_CAPSLOCK,
    a = SDLK_a, b = SDLK_b, c = SDLK_c, d = SDLK_d, e = SDLK_e, f = SDLK_f, g = SDLK_g, h = SDLK_h,
    i = SDLK_i, j = SDLK_j, k = SDLK_k, l = SDLK_l, m = SDLK_m, n = SDLK_n, o = SDLK_o, p = SDLK_p,
    q = SDLK_q, r = SDLK_r, s = SDLK_s, t = SDLK_t, u = SDLK_u, v = SDLK_v, w = SDLK_w, x = SDLK_x, 
    y = SDLK_y, z = SDLK_z,
    lShift = SDLK_LSHIFT, rShift = SDLK_RSHIFT, 
    rightArrow = SDLK_RIGHT, leftArrow = SDLK_LEFT, upArrow = SDLK_UP, downArrow = SDLK_DOWN,
    f1 = SDLK_F1, f2 = SDLK_F2, f3 = SDLK_F3, f4 = SDLK_F4, f5 = SDLK_F5, f6 = SDLK_F6, f7 = SDLK_F7,
    f8 = SDLK_F8, f9 = SDLK_F9, f10 = SDLK_F10, f11 = SDLK_F11, f12 = SDLK_F13,
    KeyPad1 = SDLK_KP_1, KeyPad2 = SDLK_KP_2, KeyPad3 = SDLK_KP_3, KeyPad4 = SDLK_KP_4,
    KeyPad5 = SDLK_KP_5, KeyPad6 = SDLK_KP_6, KeyPad7 = SDLK_KP_7, KeyPad8 = SDLK_KP_8,
    KeyPad9 = SDLK_KP_9, KeyPad0 = SDLK_KP_0
};

enum MouseButton
{
    Mouse_right = SDL_BUTTON_RIGHT,
    Mouse_left = SDL_BUTTON_LEFT,
    Mouse_middle = SDL_BUTTON_MIDDLE    
};

inline void setKeyPtr()
{
}

/// @returns return true if the key is being pressed \
/// warning, fires twice when the key is pressed, reccommended for character movement
inline bool getKeyPressed(const KeyCode &key)
{
    return false;
}

/// @returns returns true if the desired key is released \
/// fires once, recommended for pause menus, etc.
inline bool getKeyReleased(const KeyCode &key)
{
    return false;
}

/// @returns returns true when the desired key is pressed \
/// fires once on press
inline bool getKeyDown(const KeyCode &key)
{
    return false;
}

/// @returns returns true when the user clicks down on the desired button \
/// fires once
inline bool getMouseDown(const MouseButton &pbutton)
{
    return false;
}

/// @returns returns true when the user releases the desired button \
/// fires once
inline bool getMouseUp(const MouseButton &pbutton)
{
    return false;
}

inline bool getMouseButtonDown(const MouseButton &pbutton)
{
    return false;
}


#endif // INPUT_H
