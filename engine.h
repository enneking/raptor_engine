#pragma once

//std libs
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

#include "display_system.h"
#include "input_system.h"
#include "graphics_system.h"
#include "update_object_manager.h"
#include "editor.h"


	class Engine : public NonCopyable {
	public:
		Engine();

		static Engine * GetInstance();

		GraphicsSystem * const GetGraphicsSystem();
		InputSystem * const GetInputSystem();
		UpdateObjectManager * const GetUpdateObjectManager();
		Editor * const GetEditor();
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
		Event<float> update_update_objects_event_;
		Event<GLFWwindow*> draw_event_;

	private:
		DisplaySystem display_system_;
		InputSystem input_system_;
		UpdateObjectManager update_object_manager_;
		GraphicsSystem graphics_system_;
		std::unique_ptr<Editor> editor_;
		

};


#include "engine.inl"