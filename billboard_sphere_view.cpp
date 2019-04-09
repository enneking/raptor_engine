#include "billboard_sphere_view.h"

BillboardSphereView::BillboardSphereView()
{
	Eigen::Vector3f Vertices[4] =
	{
		//left edge
		Eigen::Vector3f(-1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(-1.0f, -1.0f, 1.0f),
		//right edge
		Eigen::Vector3f(1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(1.0f, -1.0f, 1.0f),
	};

	glCreateVertexArrays(1, &vertex_array_);
	glBindVertexArray(vertex_array_);

	GLuint vertex_buffer;
	glCreateBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	shader_ = Engine::GetInstance()->GetGraphicsSystem()->GetShaderManager()->CreateShaderProg("billboard_sphere.frag", "billboard_sphere.vert");
}

void BillboardSphereView::Draw()
{
	glUseProgram(shader_);
	request_data_event_.Broadcast();
	glBindVertexArray(vertex_array_);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDisableVertexAttribArray(0);
}

EventInterface<> * const BillboardSphereView::GetRequestDataEvent()
{
	return request_data_event_.GetInterface();
}

void BillboardSphereView::SetDrawData(const Eigen::Matrix4f * const model_matrix)
{
	const auto & view_projection_matrix = Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetTransformData()->view_projection_matrix;
	Eigen::Matrix4f model_view_projection_matrix = view_projection_matrix * *model_matrix;
	glUniformMatrix4fv(0, 1, false, &model_view_projection_matrix(0, 0));
	glUniformMatrix4fv(1, 1, false, &Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetTransformData()->inverse_view_matrix(0,0));
}
