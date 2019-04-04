#pragma once
#include "event_base.h"

namespace rpt {
	template<class ... FuncArgs>
	class Event : public EventBase<FuncArgs...>
	{
	public:
		void Broadcast(FuncArgs... args);
	};
};

#include "event.inl"
