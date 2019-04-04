#include "render_object_manager.h"

using namespace rpt;

RenderObjectManager::RenderObjectManager(EventInterface<GLFWwindow*> * draw_event)
{
	draw_event->AddSlot(this, &RenderObjectManager::Draw);
}

void RenderObjectManager::Draw(GLFWwindow * window)
{
	glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto render_obj_vec_size = object_vec_.size();
	for (size_t i = 0; i < render_obj_vec_size; ++i)
		object_vec_[i]->Draw();

	glfwSwapBuffers(window);
	glfwPollEvents();
}
