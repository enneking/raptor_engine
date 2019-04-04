#include "camera_manager.h"

CameraManager::CameraManager(EventInterface<float> * update_cam_event)
{
	update_cam_event->AddSlot(this, &CameraManager::UpdateObjects);
}


void CameraManager::SetCameraToViewport(CameraObject * camera_object)
{
	viewport_camera_ = camera_object;	
}

void CameraManager::UpdateObjects(float dt)
{
	if(viewport_camera_.Get() != nullptr)
		viewport_camera_.Get()->Update(dt);
}

CameraObject * const CameraManager::GetViewportCamera()
{
	if (viewport_camera_ == nullptr && !object_vec_.empty())
		viewport_camera_ = object_vec_[0].get();


	return viewport_camera_.Get();
}