#pragma once
#include "game_object.h"
#include "object_manager.h"
#include <vector>
#include <memory>

namespace rpt {

	class GameObjectManager : public Factory<GameObject>
	{
	public:
		GameObjectManager(EventInterface<float> * update_event);

	private:
		void GameObjectManager::UpdateObjects(float delta_time);

	};

};