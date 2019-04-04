template<class ... FuncArgs>
EventBase<FuncArgs...>::EventBase() : interface_(&func_)
{
	
}

template<class ... FuncArgs>
EventInterface<FuncArgs...> * const EventBase<FuncArgs...>::GetInterface()
{
	return &interface_;
}
