template<class ClassName, class ... Types>
ClassName * PhysicsObjectManager::CreatePhysicsObject(Types ... args)
{
	static_assert(std::is_base_of<PhysicsObject, ClassName>::value, "ERROR in PhysicsObjectManager::CreatePhysicsObject: Template Class not derived from PhysicsObject");
	physics_object_vec_.emplace_back(std::make_unique<ClassName>(&args...));
	return static_cast<ClassName *>(physics_object_vec_.back().get());
}

template<class ClassName, class ... Types>
void PhysicsObjectManager::CreatePhysicsObject(size_t * id, Types ... args)
{
	static_assert(std::is_base_of<PhysicsObject, ClassName>::value, "ERROR in PhysicsObjectManager::CreatePhysicsObject: Template Class not derived from PhysicsObject");
	(*id) = physics_object_vec_.size();
	physics_object_vec_.emplace_back(std::make_unique<ClassName>(&args...));
}

template<class ClassName>
ClassName * PhysicsObjectManager::GetPhysicsObject(size_t id)
{
	static_assert(std::is_base_of<PhysicsObject, ClassName>::value, "ERROR in PhysicsObjectManager::GetPhysicsObject: Template Class not derived from PhysicsObject");
	return static_cast<ClassName*>(physics_object_vec_[id].get());
}