#include "Keyboard.h"
#include <iostream>




Keyboard::Keyboard(GLFWwindow * window)
{
	glfwSetWindowUserPointer(window, this);

	glfwSetKeyCallback(window, key_callback);


	key_map_.emplace(-1, std::make_unique<Button>());
	key_map_.emplace(32, std::make_unique<Button>());
	key_map_.emplace(39,  std::make_unique<Button>());
	key_map_.emplace(59,  std::make_unique<Button>());
	key_map_.emplace(61,  std::make_unique<Button>());
	key_map_.emplace(96,  std::make_unique<Button>());
	key_map_.emplace(161,  std::make_unique<Button>());
	key_map_.emplace(162,  std::make_unique<Button>());

	for (int i = 45; i < 57; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 65; i < 93; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 256; i < 269; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 280; i < 284; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 290; i < 314; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 320; i < 336; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
	for (int i = 340; i < 348; ++i)
	{
		key_map_.emplace(i,  std::make_unique<Button>());
	}
}

ButtonInterface * const Keyboard::GetKey(int glfw_key)
{
	return key_map_[glfw_key].get();
}
