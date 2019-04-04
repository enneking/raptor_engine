#pragma once
#include <vector>
#include <memory>
#include "non_copyable.h"
template<class Type>
class Factory : public NonCopyable
{
public:
	Factory();

	template<class ClassName, class ... Types>
	ClassName * Create(Types ... args);

	void Remove(Type * physics_object);

protected:
	std::vector<std::unique_ptr<Type>> object_vec_;
};

#include "factory.inl"
