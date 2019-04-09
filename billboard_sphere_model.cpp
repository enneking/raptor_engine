#include "billboard_sphere_model.h"

BillboardSphereModel::BillboardSphereModel(const Eigen::Vector3f & pos)
{
	model_matrix_ = Eigen::Matrix4f::Identity();
	model_matrix_.col(3) = Eigen::Vector4f(pos.x(), pos.y(), pos.z(), 1.0f);
}

const Eigen::Matrix4f * const BillboardSphereModel::GetModelMatrix() const
{
	return &model_matrix_;
}
