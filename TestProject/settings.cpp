#include "settings.h"
#include "engine.h"


Settings::Settings()
{
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_F1)->GetPressedEvent()->AddSlot(this, &Settings::ToggleFullScreeen);
}


void Settings::ToggleFullScreeen()
{
	auto window = Engine::GetInstance()->GetDisplaySystem()->GetWindow();
	if(!is_fullscreen_)
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, GLFW_DONT_CARE);
	else
		glfwSetWindowMonitor(window, NULL, 0, 0, 1920, 1080, GLFW_DONT_CARE);

	is_fullscreen_ = !is_fullscreen_;
}