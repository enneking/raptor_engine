#pragma once
#include "Box.h"
#include "settings.h"

class TestGame : public NonCopyable
{
public:
	TestGame();

private:
	void OnEscKeyPressed();

private:
	Box box_;
	Settings settings_;
};

