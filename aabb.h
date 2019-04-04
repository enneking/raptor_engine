#pragma once
#include "bounding_volume.h"
#include "vec3.h"

namespace rpt {

	class AABB : public BoundingVolume
	{
	public:
		AABB();

		bool IntersectionAABB(AABB other, Vec3<float> * result) const;

	private:
		Vec3<float> min_;
		Vec3<float> max_;
	};

}