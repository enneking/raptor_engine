#include "mouse.h"



Mouse::Mouse(GLFWwindow * window) : window_(window)
{
	glfwSetCursor(window, glfwCreateStandardCursor(GLFW_ARROW_CURSOR));
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
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

ButtonInterface * const Mouse::GetLeftButton()
{
	return &left_button_;
}
ButtonInterface * const Mouse::GetRightButton()
{
	return &right_button_;
}
ButtonInterface * const Mouse::GetMiddleButton()
{
	return &middle_button_;
}

EventInterface<const double &> * const Mouse::GetWheelEventInterface()
{
	return wheel_event_.GetInterface();
}

void Mouse::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	wheel_event_.Broadcast(yoffset);
}
