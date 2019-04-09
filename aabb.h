#pragma once
#include "bounding_volume.h"
#include "Eigen\Core"


class AABB : public BoundingVolume
{
public:
	AABB();

	bool IntersectionAABB(AABB other, Eigen::Vector3f * result) const;

private:
	Eigen::Vector3f min_;
	Eigen::Vector3f max_;
};

