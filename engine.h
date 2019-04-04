#pragma once

//std libs
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

#include "display_system.h"
#include "input_system.h"
#include "graphics_system.h"
#include "game_object_manager.h"

#include "non_copyable.h"

namespace rpt {
	class Engine : public NonCopyable {
	public:
		Engine();

		static Engine * GetInstance();

		GraphicsSystem * const GetGraphicsSystem();
		InputSystem * const GetInputSystem();
		GameObjectManager * const GetGameObjectManager();
		DisplaySystem * const GetDisplaySystem();

		template<class Game>
		void Run();

		void Exit();

		const double GetDeltaTime() const;

	private:
		static Engine * instance_;
		const double delta_time_ = 1/60.0f;
		std::chrono::duration<double> lag_time_;
		bool is_running_ = true;
	
	private:
		Event<float> update_cam_event_;
		Event<float> update_game_objects_event_;
		Event<GLFWwindow*> draw_event_;

	private:
		DisplaySystem display_system_;
		InputSystem input_system_;
		GameObjectManager game_object_manager_;
		GraphicsSystem graphics_system_;
		

};
};

#include "engine.inl"