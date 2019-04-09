#pragma once
#include "engine.h"
#include "model.h"

class BillboardSphereModel : public Model
{
public:
	BillboardSphereModel(const Eigen::Vector3f & pos);
	const Eigen::Matrix4f * const GetModelMatrix() const;
};

