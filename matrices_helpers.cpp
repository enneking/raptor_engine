#include "matrices_helpers.h"



void MatricesHelpers::LookAt(Eigen::Vector3f const & eye, Eigen::Vector3f const & center, Eigen::Vector3f & up, Eigen::Matrix4f & result)
{
	const Eigen::Vector3f front((center - eye).normalized());
	Eigen::Vector3f const side((front.cross(up).normalized()));
	up = side.cross(front);

	result(0,0) = side(0);
	result(0,1) = side(1);
	result(0,2) = side(2);
	result(1,0) = up(0);
	result(1,1) = up(1);
	result(1,2) = up(2);
	result(2,0) = -front(0);
	result(2,1) = -front(1);
	result(2,2) = -front(2);
	result(0,3) = -side.dot(eye);
	result(1,3) = -up.dot(eye);
	result(2,3) = front.dot(eye);
}

void MatricesHelpers::LookAt(Eigen::Vector3f const & eye, Eigen::Vector3f const & center, Eigen::Vector3f &  up, Eigen::Matrix4f & result, Eigen::Matrix4f & inverse)
{
	const Eigen::Vector3f front((center - eye).normalized());
	Eigen::Vector3f const side((front.cross(up).normalized()));
	up = side.cross(front);

	result(0, 0) = side(0);
	result(0, 1) = side(1);
	result(0, 2) = side(2);
	result(1, 0) = up(0);
	result(1, 1) = up(1);
	result(1, 2) = up(2);
	result(2, 0) = -front(0);
	result(2, 1) = -front(1);
	result(2, 2) = -front(2);
	result(0, 3) = -side.dot(eye);
	result(1, 3) = -up.dot(eye);
	result(2, 3) = front.dot(eye);

	inverse(0, 0) = side(0);
	inverse(1, 0) = side(1);
	inverse(2, 0) = side(2);
	inverse(0, 1) = up(0);
	inverse(1, 1) = up(1);
	inverse(2, 1) = up(2);
	inverse(0, 2) = -front(0);
	inverse(1, 2) = -front(1);
	inverse(2, 2) = -front(2);
	inverse(0, 3) = eye(0);
	inverse(1, 3) = eye(1);
	inverse(2, 3) = eye(2);
}

void MatricesHelpers::PerspectiveProjection(float fov, float aspect, float near, float far, Eigen::Matrix4f & result)
{
	float const tan_half_fov = std::tan(fov / 2.0f);

	result(0, 0) = 1.0f / (aspect * tan_half_fov);
	result(1, 1) = 1.0f / (tan_half_fov);
	result(3, 2) = -1.0f;
	result(2, 2) = -(far + near) / (far - near);
	result(2, 3) = -(2.0f * far * near) / (far - near);
}