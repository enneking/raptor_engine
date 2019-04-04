#pragma once
#include "non_copyable.h"

class Settings : public NonCopyable
{
public:
	Settings();

protected: 
	void ToggleFullScreeen(const bool &val, const bool &old_val);

private:
	bool is_fullscreen_ = false;
};

