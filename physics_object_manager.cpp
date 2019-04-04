#include "physics_object_manager.h"


using namespace rpt;



void PhysicsObjectManager::RemovePhysicsObject(PhysicsObject *physics_object)
{
	for (auto it = physics_object_vec_.begin(); it != physics_object_vec_.end(); it++)
	{
		if (it->get() == physics_object)
		{
			physics_object_vec_.erase(it);
			return;
		}
	}
}

void PhysicsObjectManager::RemovePhysicsObject(size_t id)
{
	physics_object_vec_.erase(physics_object_vec_.begin() + id);
}

void PhysicsObjectManager::CalcPhysics()
{
	auto physics_obj_vec_size = physics_object_vec_.size();
	for (size_t i = 0; i < physics_obj_vec_size; ++i)
		physics_object_vec_[i]->CalcPhysics();
}

PhysicsObject * PhysicsObjectManager::GetPhysicsObject(size_t id)
{
	return physics_object_vec_[id].get();
}