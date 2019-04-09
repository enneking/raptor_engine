#version 430

layout(location = 0) in vec3 pos_;
layout(location = 1) in vec3 _local_pos;

layout(location = 1) uniform mat4 inverse_view_matrix;

out vec4 _color;

void main() {
	if ((pos_.x * pos_.x + pos_.y * pos_.y) > 1.0f)
		discard;

	const float sphere_offset = sqrt(1 - (_local_pos.x * _local_pos.x + _local_pos.y * _local_pos.y));
	const vec3 normal = vec3(inverse_view_matrix[2][0], inverse_view_matrix[2][1], inverse_view_matrix[2][2]);
	const vec3 sphere_pos = pos_ + normal * sphere_offset;
	const vec3 sphere_normal = vec3(_local_pos.xy, sphere_offset);

	const vec3 light_pos = vec3(0.0f, 10.0f, 0.0f);

	const vec3 light_dir = normalize(light_pos - sphere_pos);
	const float diffuse_term = max(0.0f, dot(light_dir, sphere_normal));
	const vec3 color_ambient = vec3(0.0f, 0.0f, 0.1f);
	const vec3 color_diffuse = vec3(0.0f, 0.0f, 1.0f);

	_color = vec4(color_ambient + diffuse_term * color_diffuse, 1.0f);
}