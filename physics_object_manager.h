#pragma once
#include <vector>
#include <memory>

#include "physics_object.h"

namespace rpt {

	class PhysicsObjectManager
	{
	public:
		template<class ClassName, class ... Types>
		ClassName * CreatePhysicsObject(Types ... args);

		template<class ClassName, class ... Types>
		void CreatePhysicsObject(size_t * id, Types ... args);

		void RemovePhysicsObject(PhysicsObject *physics_object);
		void RemovePhysicsObject(size_t id);

		template<class ClassName>
		ClassName * GetPhysicsObject(size_t id);
		PhysicsObject * GetPhysicsObject(size_t id);

		void CalcPhysics();

	private:
		std::vector<std::unique_ptr<PhysicsObject>> physics_object_vec_;
	};

#include "physics_object_manager.inl"
}
