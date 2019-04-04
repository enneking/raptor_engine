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

protected:
	void UpdateObjects(float dt);

private:
	Observer<CameraObject *> viewport_camera_;
};