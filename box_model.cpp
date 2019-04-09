#include "box_model.h"


BoxModel::BoxModel(const Eigen::Vector3f & pos)
{
	model_matrix_ = Eigen::Matrix4f::Identity();
	model_matrix_.col(3) = Eigen::Vector4f(pos.x(), pos.y(), pos.z(), 1.0f);
}

const Eigen::Matrix4f * const BoxModel::GetModelMatrix() const
{
	return &model_matrix_;
}
