#pragma once
#include "factory.h"
#include "event.h"
#include "non_copyable.h"


template<class Type, class ...EventArg>
class ObjectManager : public NonCopyable
{
public:
	ObjectManager(EventInterface<EventArg...> * update_event);

	template<class ClassName, class ... Types>
	ClassName * Create(Types ... args);

private:
	EventInterface<EventArg...> * update_event_;
};


#include "object_manager.inl"