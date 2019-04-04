#pragma once
#include "engine.h"

class Rectangle2DView : public rpt::RenderObject
{
public:
	Rectangle2DView();

	void Draw();

protected:
	GLuint vertex_array_, vertex_buffer_, shader_prog_;
};

