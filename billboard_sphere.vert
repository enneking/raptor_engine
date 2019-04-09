#version 430

layout(location = 0) in vec3 pos_;

layout(location = 0) uniform mat4 model_view_projection_;
layout(location = 1) uniform mat4 inverse_view_matrix;

layout(location = 0) out vec3 _pos;
layout(location = 1) out vec3 _local_pos;

void main() {
	_local_pos = pos_;
	_pos = vec3(model_view_projection_ * vec4(mat3(inverse_view_matrix) * pos_, 1.0f));
	gl_Position = vec4(_pos, 1.0f);
}