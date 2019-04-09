#include "camera_object.h"
#include "matrices_helpers.h"



CameraObject::CameraObject()
{
	transform_matrices_.projection_matrix.setZero();
	transform_matrices_.view_matrix = Eigen::Vector4f::Ones().matrix().asDiagonal();
	transform_matrices_.inverse_view_matrix = Eigen::Vector4f::Ones().matrix().asDiagonal();
}

void CameraObject::Update(float delta_time)
{
	MatricesHelpers::LookAt(eye_.Get(), center_.Get(), up_, transform_matrices_.view_matrix, transform_matrices_.inverse_view_matrix);
	MatricesHelpers::PerspectiveProjection(45.0f * 0.01745329251994329576923690768489f, 16.0f / 9.0f, 0.1f, 10000.0f, transform_matrices_.projection_matrix);
	transform_matrices_.view_projection_matrix = transform_matrices_.projection_matrix * transform_matrices_.view_matrix;
}

CameraObject::TransformMatrices const * const CameraObject::GetTransformData() const
{
	return &transform_matrices_;
}

const Eigen::Vector3f * const CameraObject::GetPos() const
{
	return &eye_.Get();
}
