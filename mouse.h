#pragma once
#include <glew.h>
#include <GLFW/glfw3.h>
#include <Eigen\Core>
#include "observer.h"

#include "non_copyable.h"
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

namespace rpt{

	class Mouse : public NonCopyable {
	public:
		Mouse(GLFWwindow * window);

		void GetCursorPos(double * x, double * y) const;

		Observer<Eigen::Vector2f>::Interface * const GetCursorPosEventInterface();

		Observer<bool>::Interface * const GetLeftMouseButtonEventInterface();
		Observer<bool>::Interface * const GetRightMouseButtonEventInterface();
		Observer<bool>::Interface * const GetMiddleMouseButtonEventInterface();

	private:
		GLFWwindow * window_;
		Observer<Eigen::Vector2f> cursor_pos_;
		Observer<bool> left_mouse_button_;
		Observer<bool> right_mouse_button_;
		Observer<bool> middle_mouse_button_;


	private:
		friend void ::cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend void ::mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	};

}