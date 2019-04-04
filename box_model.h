#pragma once
#include <Eigen\Core>
#include "observer.h"

class BoxModel
{
public:
	BoxModel(Eigen::Vector3f pos_);
	const Eigen::Matrix4f * const GetModelMatrix() const;

private:
	Eigen::Matrix4f model_matrix_;

};

