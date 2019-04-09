#pragma once
#include <Eigen\Core>
#include "observer.h"
#include "model.h"

class BoxModel : public Model
{
public:
	BoxModel(const Eigen::Vector3f & pos_);
	const Eigen::Matrix4f * const GetModelMatrix() const;
};

