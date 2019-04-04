#pragma once
#include "glew.h"
#include "GLFW\glfw3.h"
#include <Eigen/Dense>
#include "non_copyable.h" 

namespace rpt {
	class RenderObject : public NonCopyable
	{
	public:
		virtual ~RenderObject() = default;
		virtual void Draw() = 0;
	};

};

