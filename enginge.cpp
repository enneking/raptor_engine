#include "engine.h"
#include "default_editor.h"


Engine * Engine::instance_;

Engine::Engine()
	: display_system_(1920,1080,"GAME", update_cam_event_.GetInterface())
	, input_system_(display_system_.GetWindow())
	, update_object_manager_(update_update_objects_event_.GetInterface())
	, graphics_system_(draw_event_.GetInterface())
	, editor_(std::make_unique<DefaultEditor>(input_system_, display_system_))
{
	instance_ = this;
}

Engine * Engine::GetInstance()
{
	return instance_;
}

GraphicsSystem * const Engine::GetGraphicsSystem()
{
	return &graphics_system_;
}

InputSystem * const Engine::GetInputSystem()
{
	return &input_system_;
}

UpdateObjectManager * const Engine::GetUpdateObjectManager()
{
	return &update_object_manager_;
}

DisplaySystem * const Engine::GetDisplaySystem()
{
	return &display_system_;
}

Editor * const Engine::GetEditor()
{
	return editor_.get();
}

const double Engine::GetDeltaTime() const
{
	return delta_time_;
}

void Engine::Exit()
{
	is_running_ = false;
}