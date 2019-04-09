#include "camera_manager.h"

CameraManager::CameraManager(EventInterface<float> * update_cam_event)
{
	update_cam_event->AddSlot(this, &CameraManager::UpdateObjects);
}


void CameraManager::SetCameraToViewport(CameraObject * camera_object)
{
	viewport_camera_ = camera_object;
	viewport_camera_.Get()->eye_.GetInterface()->AddSlot<CameraManager>(this, &CameraManager::OnCameraMoved);
	viewport_camera_.Get()->center_.GetInterface()->AddSlot<CameraManager>(this, &CameraManager::OnCameraRotated);
}

void CameraManager::UpdateObjects(float dt)
{
	if(viewport_camera_.Get() != nullptr)
		viewport_camera_.Get()->Update(dt);
}

CameraObject * const CameraManager::GetViewportCamera()
{
	if (viewport_camera_ == nullptr && !object_vec_.empty())
		SetCameraToViewport( object_vec_[0].get() );


	return viewport_camera_.Get();
}

Observer<Eigen::Vector3f>::Interface * const CameraManager::GetCameraMovedEvent()
{
	return camera_moved_event_.GetInterface();
}

Observer<Eigen::Vector3f>::Interface * const CameraManager::GetCameraRotatedEvent()
{
	return camera_rotated_event_.GetInterface();
}

void CameraManager::OnCameraMoved(const Eigen::Vector3f& val, const Eigen::Vector3f& old_val)
{
	camera_moved_event_.Broadcast(val, old_val);
}

void CameraManager::OnCameraRotated(const Eigen::Vector3f& center, const Eigen::Vector3f& old_center)
{
	camera_moved_event_.Broadcast(center, old_center);
}