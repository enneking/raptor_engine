#include "test_game.h"
#include "engine.h"
#include "default_camera.h"

TestGame::TestGame()
{
	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_ESCAPE)->AddSlot(this, &TestGame::OnEscKeyPressed);
	rpt::Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->Create<DefaultCamera>();
}


void TestGame::OnEscKeyPressed(const bool &, const bool &)
{
	rpt::Engine::GetInstance()->Exit();
}