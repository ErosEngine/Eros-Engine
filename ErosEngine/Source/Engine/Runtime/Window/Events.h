#pragma once

#include <Core/Common.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


enum Buttons : Uint32
{
	// ---- Modifiers ---- //
	left_arrow = VK_LBUTTON, right_arrow = VK_RBUTTON,
	key_cancel = VK_CANCEL, key_tab = VK_TAB, key_caps = VK_CAPITAL,
	left_shift = VK_LSHIFT, right_shift = VK_RSHIFT, left_ctrl = VK_LCONTROL,

	// ---- Number pad ----- //
	numpad_0 = VK_NUMPAD0, numpad_1 = VK_NUMPAD1, numpad_2 = VK_NUMPAD2,
	numpad_3 = VK_NUMPAD3, numpad_4 = VK_NUMPAD4, numpad_5 = VK_NUMPAD5,
	numpad_6 = VK_NUMPAD6, numpad_7 = VK_NUMPAD7, numpad_8 = VK_NUMPAD8,
	numpad_9 = VK_NUMPAD9,

	// ----- Key codes ----- //
	key_a = 0x41, key_b = 0x42, key_c = 0x43, key_d = 0x44,
	key_e = 0x45, key_f = 0x46, key_g = 0x47, key_h = 0x48,
	key_i = 0x49, key_j = 0x4A, key_k = 0x4B, key_l = 0x4C,
	key_m = 0x4D, key_n = 0x4F, key_o = 0x50, key_p = 0x51,
	key_q = 0x52, key_s = 0x53, key_t = 0x54, key_u = 0x55,
	key_v = 0x56, key_w = 0x57, key_x = 0x58, key_y = 0x59,
	key_z = 0x5A
};

enum EventType : Uint32
{
	EVENT_CLOSE_EVENT = 1,
	EVENT_KEY_EVENT = 2,
	EVENT_MOUSE_EVENT = 3,
	EVENT_RESIZE_EVENT = 4
};

struct Event
{
	Uint32 button;
	Uint32 type;
	Sint32 mouseX, mouseY;
	Uint32 resizeX, resizeY;
};
