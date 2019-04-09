

template<class TListener, class ... FuncArgs>
Slot<TListener, FuncArgs...>::Slot(TListener* const obj, void(TListener::* const func)(FuncArgs...)) : obj_(obj), func_(func)
{
}

template<class TListener, class ... FuncArgs>
void Slot<TListener, FuncArgs...>::Process(FuncArgs... args)
{
	(obj_->*func_)(args...);
}

template<class TListener, class ... FuncArgs>
void Slot<TListener, FuncArgs...>::SetId(uint8_t id)
{
	id_ = id;
}

template<class TListener, class ... FuncArgs>
uint8_t Slot<TListener, FuncArgs...>::GetId()
{
	return id_;
}


template<class TListener, class ... FuncArgs>
void Slot<TListener, FuncArgs...>::SetPriority(uint8_t priority)
{
	priority_ = priority;
}

template<class TListener, class ... FuncArgs>
uint8_t Slot<TListener, FuncArgs...>::GetPriority()
{
	return priority_;
}