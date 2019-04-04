#include "box_model.h"


BoxModel::BoxModel(Eigen::Vector3f pos_) : model_matrix_(Eigen::Matrix4f::Identity())
{
//	model_matrix_ = Eigen::Vector4f(1.0f, 1.0f, 1.0f, 1.0f).matrix().asDiagonal();
}

const Eigen::Matrix4f * const BoxModel::GetModelMatrix() const
{
	return &model_matrix_;
}
