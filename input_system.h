#pragma once

#include "keyboard.h"
#include "mouse.h"

#include "non_copyable.h"

/**
* InputManager based on GLFW
* Key functions may not register all
* keys if the polling in the Game-Loop
* runs to slow.
*
* Callback functions are implemented
* here and may be used if the key
* functions fail.
*/




	class InputSystem : public NonCopyable
	{
	public:
		InputSystem(GLFWwindow *window);

		Keyboard * const GetKeyboard();
		Mouse * const GetMouse();

	protected:

	private:
		Keyboard keyboard_;
		Mouse mouse_;
	};
