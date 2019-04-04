#version 430

layout(location = 0) in vec3 pos_;

layout(location = 0) uniform mat4 projection_view_;

void main() {
	gl_Position = projection_view_ * vec4(pos_, 1.0f);
}