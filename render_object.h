#pragma once
#include "glew.h"
#include "GLFW\glfw3.h"
#include <Eigen/Dense>
#include "non_copyable.h" 


class RenderObject : public NonCopyable
{
	friend class RenderObjectManager;
public:
	virtual ~RenderObject() = default;

protected:
	virtual void Draw() = 0;
};


