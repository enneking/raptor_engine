template<class ...FuncArgs>
void Event<FuncArgs...>::Broadcast(FuncArgs... args)
{
	(interface_.*(func_))(args...);
}