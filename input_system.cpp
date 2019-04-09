#include "input_system.h"



InputSystem::InputSystem(GLFWwindow *window)
	: keyboard_(window)
	, mouse_(window)
{
	glfwSetWindowUserPointer(window, this);
}

Keyboard * const InputSystem::GetKeyboard()
{
	return &keyboard_;
}

Mouse * const InputSystem::GetMouse()
{
	return &mouse_;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	xpos = xpos * 2.0 / width - 1.0;
	ypos = 1.0 - ypos * 2.0 / height;
	static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetMouse()->cursor_pos_ = Eigen::Vector2f(static_cast<float>(xpos), static_cast<float>(ypos));
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetKeyboard()->key_map_[key]->BroadCastPressed();
	if (action == GLFW_RELEASE)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetKeyboard()->key_map_[key]->BroadCastReleased();
	if (action == GLFW_REPEAT)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetKeyboard()->key_map_[key]->BroadCastRepeat();
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if(button == GLFW_MOUSE_BUTTON_LEFT)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetMouse()->left_button_.BroadCastPressed();
	else if (button == GLFW_MOUSE_BUTTON_RIGHT)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetMouse()->right_button_.BroadCastPressed();
	else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
		static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetMouse()->middle_button_.BroadCastPressed();
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	static_cast<InputSystem*>(glfwGetWindowUserPointer(window))->GetMouse()->wheel_event_.Broadcast(yoffset);
}