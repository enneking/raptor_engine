#pragma once

#include<vector>
#include<iostream>
#include <memory>
#include "non_copyable.h" 
#include"Slot.h"




	template<class ... FuncArgs>
class EventInterface : public NonCopyable {
public:
	explicit EventInterface(void(EventInterface<FuncArgs...>::** const func)(FuncArgs...));

	//returns id of slot
	template<class TListener> 
	uint8_t AddSlot(TListener* const obj, void(TListener::* const func)(FuncArgs...), uint8_t priority = 128);

	void RemoveSlot(uint8_t id);

protected:
	void Broadcast(FuncArgs...);

private:
	std::vector<std::unique_ptr<SlotBase<FuncArgs...>>> method_container_;
	bool is_locked_ = false;
};



#include"event_interface.inl"