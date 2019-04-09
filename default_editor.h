#pragma once
#include "editor.h"
#include "input_system.h"
#include "event.h"
#include "billboard_sphere.h"

class DefaultEditor : public Editor
{
public:
	DefaultEditor(InputSystem & input_system, DisplaySystem & display_system);

protected:
	virtual void ToggleEditor();
	
	virtual void CreateObject();
	virtual void PlaceObject();
	virtual void ScaleObject(const double &);

	virtual void OnCameraMoved(const Eigen::Vector3f &, const Eigen::Vector3f &);

private:
	void CalcPlacementPos(const Eigen::Vector3f cam_pos);

private:
	bool is_active_;
	std::vector<std::unique_ptr<BillboardSphere>> created_object_vec_;
	uint8_t toggle_event_id;
};

