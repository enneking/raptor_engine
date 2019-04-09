#include "display_system.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//GLFW needs this
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

DisplaySystem::DisplaySystem(int width, int height, const char* title,EventInterface<float> * update_cam_event, GLFWmonitor* monitor, GLFWwindow* share) : camera_manager_(update_cam_event)
{	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//create a new window
	window_ = glfwCreateWindow(width, height, title, monitor, share);

	//errorcheck
	if (!window_)
	{
		fprintf(stderr, "Failed to create GLFW window! \n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwMakeContextCurrent(window_);
	glfwSwapInterval(1);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}

	glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	std::cout << "Display System Initialized... \n";

}


GLFWwindow* DisplaySystem::GetWindow()
{
	return window_;
}

void DisplaySystem::ResizeWindow(int width, int height)
{
	glfwSetWindowSize(window_, width, height);
}

CameraManager * const DisplaySystem::GetCameraManager()
{
	return &camera_manager_;
}