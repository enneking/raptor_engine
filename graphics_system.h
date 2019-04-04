#pragma once
#include "render_object_manager.h"
#include "shader_manager.h"
#include "non_copyable.h" 

namespace rpt {

	class GraphicsSystem : public NonCopyable
	{
	public:
		GraphicsSystem(EventInterface<GLFWwindow*> * draw_event);

		ShaderManager * const GetShaderManager();
		RenderObjectManager * const GetRenderObjectManager();

	private:
		RenderObjectManager render_object_manager_;
		ShaderManager shader_manager_;
	};

};
