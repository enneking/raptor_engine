#include "test_game.h"
#include "engine.h"
#include "default_camera.h"

TestGame::TestGame()
{
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_ESCAPE)->GetPressedEvent()->AddSlot(this, &TestGame::OnEscKeyPressed);
	Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->Create<DefaultCamera>();
}


void TestGame::OnEscKeyPressed()
{
	Engine::GetInstance()->Exit();
}