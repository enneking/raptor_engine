

template<class ... FuncArgs>
EventInterface<FuncArgs...>::EventInterface(void(EventInterface::** const func)(FuncArgs...))
{
	*func = &EventInterface::Broadcast;
}

template<class ... FuncArgs>
template<class TListener>
uint8_t EventInterface<FuncArgs...>::AddSlot(TListener* const obj, void(TListener::* const func)(FuncArgs...), uint8_t priority)
{
	if(method_container_.size() == 0)
		method_container_.emplace_back(std::make_unique<Slot<TListener, FuncArgs...>>(obj, func));
	else
	{
		for (auto it = method_container_.begin();; it++)
		{
			if (it == method_container_.end() || it->get()->GetPriority() < priority )
			{
				method_container_.insert(it, std::make_unique<Slot<TListener, FuncArgs...>>(obj, func));
				break;
			}
		}
	}
	
	method_container_.back()->SetId(static_cast<uint8_t>(method_container_.size() - 1));
	method_container_.back()->SetPriority(priority);
	return 	method_container_.back()->GetId();
}

template<class ... FuncArgs>
void EventInterface<FuncArgs...>::RemoveSlot(uint8_t id)
{
	for (auto it = method_container_.begin(); it != method_container_.end(); it++)
	{
		if (it->get()->GetId() == id)
		{
			method_container_.erase(it);
			return;
		}
	}
}

template<class ... FuncArgs>
void EventInterface<FuncArgs...>::Broadcast(FuncArgs... args)
{
	if (is_locked_)
	{
		return;
	}
	is_locked_ = true;
	for (size_t i = 0; i < method_container_.size(); i++)
	{
		method_container_[i]->Process(args...);
	}
	is_locked_ = false;
}