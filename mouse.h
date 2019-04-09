#pragma once
#include <glew.h>
#include <GLFW/glfw3.h>
#include <Eigen\Core>
#include "observer.h"
#include "event.h"
#include "button.h"

#include "non_copyable.h"
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class Mouse : public NonCopyable {
public:
	Mouse(GLFWwindow * window);

	void GetCursorPos(double * x, double * y) const;

	Observer<Eigen::Vector2f>::Interface * const GetCursorPosEventInterface();

	ButtonInterface * const GetLeftButton();
	ButtonInterface * const GetRightButton();
	ButtonInterface * const GetMiddleButton();

	EventInterface<const double &> * const GetWheelEventInterface();

private:
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

private:
	GLFWwindow * window_;
	Observer<Eigen::Vector2f> cursor_pos_;
	Button left_button_;
	Button right_button_;
	Button middle_button_;
	Event<const double &> wheel_event_;


private:
	friend void ::cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	friend void ::mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void ::scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

};
