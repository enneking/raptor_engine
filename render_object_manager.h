#pragma once
#include "render_object.h"
#include "object_manager.h"
#include <vector>
#include "non_copyable.h" 
#include <memory>

class RenderObjectManager : public Factory<RenderObject>
{
public:
	RenderObjectManager(EventInterface<GLFWwindow*> * draw_event);

protected:
	void Draw(GLFWwindow * window);
	
};

