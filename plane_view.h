#pragma once
#include "render_object.h"


class PlaneView : public RenderObject
{
public:
	PlaneView();

	void Draw();

private:
	GLuint vertex_array_, shader_prog_;

};

