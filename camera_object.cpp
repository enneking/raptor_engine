#include "camera_object.h"
#include "matrices_helpers.h"



rpt::CameraObject::CameraObject()
{
	transform_matrices_.projection_matrix.setZero();
	transform_matrices_.view_matrix = Eigen::Vector4f::Ones().matrix().asDiagonal();
}

void rpt::CameraObject::Update(float delta_time)
{
	MatricesHelpers::LookAt(eye_, center_, up_, transform_matrices_.view_matrix);
	MatricesHelpers::PerspectiveProjection(45.0f * 0.01745329251994329576923690768489f, 16.0f / 9.0f, 0.1f, 100.0f, transform_matrices_.projection_matrix);
	transform_matrices_.view_projection_matrix = transform_matrices_.projection_matrix * transform_matrices_.view_matrix;
}

rpt::CameraObject::TransformMatrices const * const rpt::CameraObject::GetTransformData() const
{
	return &transform_matrices_;
}


