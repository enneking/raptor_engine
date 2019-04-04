using namespace rpt;

template<class Type, class ...EventArg>
ObjectManager<Type, EventArg...>::ObjectManager(EventInterface<EventArg...> * update_event)
{

}

template<class Type, class ...EventArg>
template<class ClassName, class ... Types>
ClassName * ObjectManager<Type, EventArg...>::Create(Types ... args)
{
	auto object = Factory<Type>::Create<ClassName, Types...>(args...);
	update_event_->AddSlot<ClassName>(object, &ClassName::Update);
	return object;
}