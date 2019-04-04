#include "mouse.h"

using namespace rpt;

Mouse::Mouse(GLFWwindow * window) : window_(window)
{
	glfwSetCursor(window, glfwCreateStandardCursor(GLFW_ARROW_CURSOR));
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
}

void Mouse::GetCursorPos(double * x, double * y) const
{
	int width, height;
	glfwGetWindowSize(window_, &width, &height);
	glfwGetCursorPos(window_, x, y);
	*x = *x * 2.0 / width - 1.0;
	*y = 1.0 - *y * 2.0 / height;
}

Observer<Eigen::Vector2f>::Interface * const Mouse::GetCursorPosEventInterface()
{
	return cursor_pos_.GetInterface();
}

Observer<bool>::Interface * const Mouse::GetLeftMouseButtonEventInterface()
{
	return left_mouse_button_.GetInterface();
}
Observer<bool>::Interface * const Mouse::GetRightMouseButtonEventInterface()
{
	return right_mouse_button_.GetInterface();
}
Observer<bool>::Interface * const Mouse::GetMiddleMouseButtonEventInterface()
{
	return middle_mouse_button_.GetInterface();
}