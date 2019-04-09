#pragma once
#include "camera_object.h"
#include "object_manager.h"
#include "observer.h"

#include "non_copyable.h"

class CameraManager : public Factory<CameraObject>
{
public:
	CameraManager(EventInterface<float> * update_event_interface);
	void SetCameraToViewport(CameraObject * camera_object);
	CameraObject * const GetViewportCamera();

	Observer<Eigen::Vector3f>::Interface * const GetCameraMovedEvent();
	Observer<Eigen::Vector3f>::Interface * const GetCameraRotatedEvent();

protected:
	void UpdateObjects(float dt);

private:
	void OnCameraMoved(const Eigen::Vector3f&, const Eigen::Vector3f&);
	void OnCameraRotated(const Eigen::Vector3f& center, const Eigen::Vector3f& old_center);

private:
	Observer<CameraObject *> viewport_camera_;
	Event < const Eigen::Vector3f &, const Eigen::Vector3f & > camera_moved_event_;
	Event < const Eigen::Vector3f &, const Eigen::Vector3f & > camera_rotated_event_;
};