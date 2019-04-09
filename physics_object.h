#pragma once
#include "bounding_volume_hierarchy.h"



	class PhysicsObject
	{
	public:
		virtual ~PhysicsObject() = default;

		virtual void CalcPhysics() = 0;

		BoundingVolumeHierarchyBase * const GetBoundingVolumeHierarchy()
		{
			return bvh_.get();
		};

	private:
		std::unique_ptr<BoundingVolumeHierarchyBase> bvh_;
	};

