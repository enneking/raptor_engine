#include "graphics_system.h"



GraphicsSystem::GraphicsSystem(EventInterface<GLFWwindow*> * draw_event) : render_object_manager_(draw_event)
{
	std::cout << "Graphics System Initialized... \n";
}

ShaderManager * const GraphicsSystem::GetShaderManager()
{
	return &shader_manager_;
}

RenderObjectManager * const GraphicsSystem::GetRenderObjectManager()
{
	return &render_object_manager_;
}