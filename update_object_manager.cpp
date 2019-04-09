#include "update_object_manager.h"




UpdateObjectManager::UpdateObjectManager(EventInterface<float> * update_event)
{
	update_event->AddSlot(this, &UpdateObjectManager::UpdateObjects);
}

void UpdateObjectManager::UpdateObjects(float delta_time)
{
	auto game_obj_vec_size = object_vec_.size();
	for (size_t i = 0; i < game_obj_vec_size; ++i)
		object_vec_[i]->Update(delta_time);
}

