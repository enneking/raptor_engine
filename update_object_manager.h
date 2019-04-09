#pragma once
#include "update_object.h"
#include "object_manager.h"
#include <vector>
#include <memory>



	class UpdateObjectManager final : public Factory<UpdateObject>
	{
	public:
		UpdateObjectManager(EventInterface<float> * update_event);

	private:
		void UpdateObjectManager::UpdateObjects(float delta_time);

	};

