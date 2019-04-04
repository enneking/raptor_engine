#include "plane_view.h"
#include "engine.h"


PlaneView::PlaneView()
{

	Eigen::Vector2f Vertices[4] =
	{
		Eigen::Vector2f(-1.0f, 1.0f),
		Eigen::Vector2f(-1.0f, -1.0f),
		Eigen::Vector2f(1.0f, 1.0f),
		Eigen::Vector2f(1.0f, -1.0f)
	};

	glCreateVertexArrays(1, &vertex_array_);
	glBindVertexArray(vertex_array_);

	GLuint vertex_buffer;
	glCreateBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	shader_prog_ = rpt::Engine::GetInstance()->GetGraphicsSystem()->GetShaderManager()->CreateShaderProg("default.frag", "default.vert");
}

void PlaneView::Draw()
{
	glUseProgram(shader_prog_);
	glUniformMatrix4fv(0, 1, false, &rpt::Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetTransformData()->view_projection_matrix(0,0));
	glBindVertexArray(vertex_array_);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDisableVertexAttribArray(0);
}
