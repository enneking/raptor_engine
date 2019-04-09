#pragma once
#include "event_interface.h"



	template<class ... FuncArgs>
	class EventBase : public NonCopyable
	{
	public:
		EventBase();

		EventInterface<FuncArgs...> * const GetInterface();

	protected:
		void(EventInterface<FuncArgs...>::* func_)(FuncArgs...);
		EventInterface<FuncArgs...> interface_;
	};

#include "event_base.inl"
