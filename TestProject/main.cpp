#include "engine.h"
#include "test_game.h"

void main()
{
	Engine engine;

	engine.Run<TestGame>();
}