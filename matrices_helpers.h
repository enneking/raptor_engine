#pragma once
#include <Eigen\Geometry>

class MatricesHelpers
{
public:

	static void LookAt(Eigen::Vector3f const & eye, Eigen::Vector3f const & center, Eigen::Vector3f const &  up, Eigen::Matrix4f & result);
	static void PerspectiveProjection(float fov, float aspect, float near, float far, Eigen::Matrix4f & result);
};

