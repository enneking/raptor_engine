#pragma once
#include <glew.h>
#include <GLFW/glfw3.h>
#include <map>

#include "observer.h"

#include "non_copyable.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

namespace rpt
{
	class Keyboard : public NonCopyable
	{
	public:
		Keyboard(GLFWwindow * window);

		Observer<bool>::Interface * const GetKeyEventInterface(int glfw_key);

	private:
		std::map<int, std::shared_ptr<Observer<bool>>> key_observer_map_;

	private:
		friend void ::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}
