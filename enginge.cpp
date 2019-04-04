#include "engine.h"


rpt::Engine * rpt::Engine::instance_;

rpt::Engine::Engine()
	: display_system_(1920,1080,"GAME", update_cam_event_.GetInterface())
	, input_system_(display_system_.GetWindow())
	, game_object_manager_(update_game_objects_event_.GetInterface())
	, graphics_system_(draw_event_.GetInterface())
{
	instance_ = this;
}

rpt::Engine * rpt::Engine::GetInstance()
{
	return instance_;
}

rpt::GraphicsSystem * const rpt::Engine::GetGraphicsSystem()
{
	return &graphics_system_;
}

rpt::InputSystem * const rpt::Engine::GetInputSystem()
{
	return &input_system_;
}

rpt::GameObjectManager * const rpt::Engine::GetGameObjectManager()
{
	return &game_object_manager_;
}

rpt::DisplaySystem * const rpt::Engine::GetDisplaySystem()
{
	return &display_system_;
}

const double Engine::GetDeltaTime() const
{
	return delta_time_;
}

void rpt::Engine::Exit()
{
	is_running_ = false;
}