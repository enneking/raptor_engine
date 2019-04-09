#pragma once

#include <glew.h>  
#include <GLFW/glfw3.h>
#include "camera_manager.h"

#include "non_copyable.h"


	class DisplaySystem : public NonCopyable
	{
	public:
		DisplaySystem(int width, int height, const char* title, EventInterface<float> * update_cam_event, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);

		GLFWwindow* GetWindow();
		void ResizeWindow(int width, int height);

		CameraManager * const GetCameraManager();



	private:
		GLFWwindow* window_;
		CameraManager camera_manager_;
	};
