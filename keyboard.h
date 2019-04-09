#pragma once
#include <glew.h>
#include <GLFW/glfw3.h>
#include <map>

#include "observer.h"
#include "button.h"
#include "non_copyable.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


class Keyboard : public NonCopyable
{
public:
	Keyboard(GLFWwindow * window);

	ButtonInterface * const GetKey(int glfw_key);

private:
	std::map<int, std::unique_ptr<Button>> key_map_;

private:
	friend void ::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

