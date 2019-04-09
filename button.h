#pragma once
#include "event.h"

class ButtonInterface {

public:
	EventInterface<> * GetPressedEvent() { return pressed_event.GetInterface(); }
	EventInterface<> * GetReleasedEvent() { return released_event.GetInterface(); }
	EventInterface<> * GetRepeatEvent() { return repeat_event.GetInterface(); }

protected:
	Event<> pressed_event;
	Event<> released_event;
	Event<> repeat_event;

};


class Button : public ButtonInterface{
	
public:
	void BroadCastPressed() { pressed_event.Broadcast(); }
	void BroadCastReleased() { released_event.Broadcast(); }
	void BroadCastRepeat() { repeat_event.Broadcast(); }

};