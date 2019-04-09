template<class Type>
Factory<Type>::Factory()
{
}

template<class Type>
void Factory<Type>::Remove(Type *object)
{
	for (auto it = object_vec_.begin(); it != object_vec_.end(); it++)
	{
		if (it->get() == object)
		{
			object_vec_.erase(it);
			return;
		}
	}
}

template<class Type>
template<class ClassName, class ... Types>
ClassName * Factory<Type>::Create(Types ... args)
{
	static_assert(std::is_base_of<Type, ClassName>::value, "ERROR in UpdateObjectManager::CreateUpdateObject: Template Class not derived from Factory Type");
	object_vec_.emplace_back(std::make_unique<ClassName>(args...));
	return static_cast<ClassName *>(object_vec_.back().get());
}