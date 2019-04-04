#include "settings.h"
#include "engine.h"


Settings::Settings()
{
	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_F1)->AddSlot(this, &Settings::ToggleFullScreeen);
}


void Settings::ToggleFullScreeen(const bool &val, const bool &old_val)
{
	if (val == false)
		return;

	auto window = rpt::Engine::GetInstance()->GetDisplaySystem()->GetWindow();
	if(!is_fullscreen_)
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, GLFW_DONT_CARE);
	else
		glfwSetWindowMonitor(window, NULL, 0, 0, 1920, 1080, GLFW_DONT_CARE);

	is_fullscreen_ = !is_fullscreen_;
}