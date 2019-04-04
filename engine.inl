template<class Game>
void rpt::Engine::Run()
{
	std::cout << "=========== Initialie Game ... start =========== \n \n";
	Game game;
	std::cout << "\n \n=========== Initialie Game ... finished =========== \n \n";

	std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point new_time;
	double accumulator = delta_time_;

	while (is_running_)
	{
		new_time = std::chrono::system_clock::now();
		lag_time_ = std::chrono::duration_cast<std::chrono::duration<float>>(new_time - current_time);
		if (lag_time_.count() > 0.25)
			accumulator += 0.25;
		current_time = new_time;
		accumulator += lag_time_.count();

		while (accumulator >= delta_time_)
		{
			accumulator -= delta_time_;
			update_game_objects_event_.Broadcast(static_cast<float>(delta_time_));
		}
		update_cam_event_.Broadcast(static_cast<float>(delta_time_));
		draw_event_.Broadcast(display_system_.GetWindow());
		
		if (glfwWindowShouldClose(display_system_.GetWindow()))
		{
			glfwDestroyWindow(display_system_.GetWindow());
			glfwTerminate();
			break;
		}
	}
}

