#pragma once
#include "Box.h"
#include "settings.h"

class TestGame : public NonCopyable
{
public:
	TestGame();

private:
	void OnEscKeyPressed(const bool &, const bool &);

private:
	Box box_;
	Settings settings_;
};

