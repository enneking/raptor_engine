#include "box_view.h"


BoxView::BoxView()
{
	Eigen::Vector3f Vertices[20] =
	{
		//left edge
		Eigen::Vector3f(-1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(-1.0f, -1.0f, 1.0f),
		//right edge
		Eigen::Vector3f(1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(1.0f, -1.0f, 1.0f),
		//right back edge
		Eigen::Vector3f(1.0f, 1.0f, -1.0f),
		Eigen::Vector3f(1.0f, -1.0f, -1.0f),
		//left back edge		
		Eigen::Vector3f(-1.0f, 1.0f, -1.0f),
		Eigen::Vector3f(-1.0f, -1.0f, -1.0f),
		//left edge
		Eigen::Vector3f(-1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(-1.0f, -1.0f, 1.0f),
		//bottom edge
		Eigen::Vector3f(-1.0f, -1.0f, 1.0f),
		Eigen::Vector3f(1.0f, -1.0f, 1.0f),
		//back bottom edge
		Eigen::Vector3f(-1.0f, -1.0f, -1.0f),
		Eigen::Vector3f(1.0f, -1.0f, -1.0f),
		//fill
		Eigen::Vector3f(1.0f, -1.0f, -1.0f),
		Eigen::Vector3f(1.0f, 1.0f, -1.0f),
		//top back edge
		Eigen::Vector3f(1.0f, 1.0f, -1.0f),
		Eigen::Vector3f(-1.0f, 1.0f, -1.0f),
		// top edge
		Eigen::Vector3f(1.0f, 1.0f, 1.0f),
		Eigen::Vector3f(-1.0f, 1.0f, 1.0f)
	};

	glCreateVertexArrays(1, &vertex_array_);
	glBindVertexArray(vertex_array_);

	GLuint vertex_buffer;
	glCreateBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	shader_ = rpt::Engine::GetInstance()->GetGraphicsSystem()->GetShaderManager()->CreateShaderProg("default_shader.frag", "default_shader.vert");

}

void BoxView::Draw()
{
	glUseProgram(shader_);
	request_data_event_.Broadcast();
	glBindVertexArray(vertex_array_);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 20);
	glDisableVertexAttribArray(0);
}

EventInterface<> * const BoxView::GetRequestDataEvent()
{
	return request_data_event_.GetInterface();
}

void BoxView::SetDrawData(const Eigen::Matrix4f * const model_matrix)
{
	const auto & view_projection_matrix = rpt::Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetTransformData()->view_projection_matrix;
	Eigen::Matrix4f model_view_projection_matrix = view_projection_matrix * *model_matrix;
	glUniformMatrix4fv(0, 1, false, /*&rpt::Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->result_[0][0]);*/  &model_view_projection_matrix(0, 0));
}
