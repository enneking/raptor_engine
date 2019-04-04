#define _USE_MATH_DEFINES
#include <cmath>
#include "default_camera.h"


DefaultCamera::DefaultCamera() 
{
	view_dir_ = Eigen::Vector3f(0.0f, 0.0f, -1.0f);
	eye_ = Eigen::Vector3f(0.0f, 0.0f, 5.0f);
	center_ = eye_ + view_dir_;
	up_ = Eigen::Vector3f(0.0f, 1.0f, 0.0f);


	velocity_front_ = velocity_back_ = velocity_left_ = velocity_right_ = 0.0f;

	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_W)->AddSlot(this, &DefaultCamera::OnWPressed);
	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_A)->AddSlot(this, &DefaultCamera::OnAPressed);
	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_S)->AddSlot(this, &DefaultCamera::OnSPressed);
	rpt::Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKeyEventInterface(GLFW_KEY_D)->AddSlot(this, &DefaultCamera::OnDPressed);
	
	rpt::Engine::GetInstance()->GetInputSystem()->GetMouse()->GetCursorPosEventInterface()->AddSlot(this, &DefaultCamera::OnMouseMoved);

	rpt::CameraObject::Update(0.0f);
}

void DefaultCamera::OnWPressed(const bool & val, const bool & old_val)
{
	if (val == true)
		velocity_front_ = 1.0f;
	else
		velocity_front_ = 0.0f;
}

void DefaultCamera::OnAPressed(const bool & val, const bool & old_val)
{
	if (val == true)
		velocity_left_ = -1.0f;
	else
		velocity_left_ = 0.0f;
}

void DefaultCamera::OnSPressed(const bool & val, const bool & old_val)
{
	if (val == true)
		velocity_back_ = -1.0f;
	else
		velocity_back_ = 0.0f;
}

void DefaultCamera::OnDPressed(const bool &val, const bool & old_val)
{
	if (val == true)
		velocity_right_ = 1.0f;
	else
		velocity_right_ = 0.0f;
}

void DefaultCamera::OnMouseMoved(const Eigen::Vector2f & val, const Eigen::Vector2f & old_val)
{
	const auto four_pi = 4.0f * static_cast<float>(M_PI);
	const auto rot_x = Eigen::Quaternion<float>(val.x() * 0.1f, 0.0f, 1.0f, 0.0f);
	const auto rot_y = Eigen::Quaternion<float>(val.y() * 0.1f, 1.0f, 0.0f, 0.0f);
	const auto rotation = rot_x * rot_y;
	view_dir_ = (rot_x * rot_y * Eigen::Vector3f(0.0f, 0.0f, -1.0f)).normalized();
}

void DefaultCamera::Update(float delta_time)
{	
	if (velocity_front_ - velocity_back_ != 0.0f || velocity_left_ - velocity_right_ != 0.0f)
		eye_ += ((velocity_front_ + velocity_back_) * view_dir_ + (velocity_right_ + velocity_left_) * view_dir_.cross(up_)) * delta_time ;

	center_ = eye_ + view_dir_;

	rpt::CameraObject::Update(delta_time);
}

