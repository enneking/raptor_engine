#pragma once
#include "non_copyable.h"

class Settings : public NonCopyable
{
public:
	Settings();

protected: 
	void ToggleFullScreeen();

private:
	bool is_fullscreen_ = false;
};

