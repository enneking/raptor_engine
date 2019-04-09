#include "default_editor.h"
#include "engine.h"

DefaultEditor::DefaultEditor(InputSystem & input_system, DisplaySystem & display_system)
{
	input_system.GetKeyboard()->GetKey(GLFW_KEY_F2)->GetPressedEvent()->AddSlot(this, &DefaultEditor::ToggleEditor);
	input_system.GetMouse()->GetLeftButton()->GetPressedEvent()->AddSlot(this, &DefaultEditor::PlaceObject);

	input_system.GetMouse()->GetWheelEventInterface()->AddSlot(this, &DefaultEditor::ScaleObject);

	display_system.GetCameraManager()->GetCameraMovedEvent()->AddSlot(this, &DefaultEditor::OnCameraMoved);
	display_system.GetCameraManager()->GetCameraRotatedEvent()->AddSlot(this, &DefaultEditor::OnCameraMoved);
}


void DefaultEditor::ToggleEditor()
{
	if (!is_active_)
		toggle_event_id = Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_F3)->GetPressedEvent()->AddSlot(this, &DefaultEditor::CreateObject);
	else
		Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_F3)->GetPressedEvent()->RemoveSlot(toggle_event_id);

	is_active_ = !is_active_;
}

void DefaultEditor::CreateObject()
{
	created_object_vec_.emplace_back(std::make_unique<BillboardSphere>());
	selected_model_ = object_vec_.back().get();
	CalcPlacementPos(*Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetPos());
	
}

void DefaultEditor::OnCameraMoved(const Eigen::Vector3f & val, const Eigen::Vector3f & old_val)
{
	CalcPlacementPos(val);
}

void DefaultEditor::CalcPlacementPos(const Eigen::Vector3f cam_pos)
{
	auto front = Engine::GetInstance()->GetDisplaySystem()->GetCameraManager()->GetViewportCamera()->GetTransformData()->view_matrix.col(2) * 10.0f;
	SetSelectedModelPos(cam_pos + Eigen::Vector3f(front.x(), front.y(), -front.z()));
}

void DefaultEditor::PlaceObject()
{
	selected_model_ = nullptr;
}

void DefaultEditor::ScaleObject(const double & wheel_diff)
{
	auto scale_factor = static_cast<float>(wheel_diff) * 0.1f;
	ScaleSelectedModel(Eigen::Vector3f(scale_factor, scale_factor, scale_factor));
}