#define _USE_MATH_DEFINES
#include <cmath>
#include "default_camera.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

DefaultCamera::DefaultCamera() 
{
	view_dir_ = Eigen::Vector3f(0.0f, 0.0f, -1.0f);
	eye_ = Eigen::Vector3f(0.0f, 0.0f, 5.0f);
	center_ = eye_ + view_dir_;
	up_ = Eigen::Vector3f(0.0f, 1.0f, 0.0f);
	rotation_.setZero();


	velocity_front_ = velocity_back_ = velocity_left_ = velocity_right_ = 0.0f;

	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_W)->GetPressedEvent()->AddSlot(this, &DefaultCamera::OnWPressed);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_A)->GetPressedEvent()->AddSlot(this, &DefaultCamera::OnAPressed);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_S)->GetPressedEvent()->AddSlot(this, &DefaultCamera::OnSPressed);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_D)->GetPressedEvent()->AddSlot(this, &DefaultCamera::OnDPressed);

	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_W)->GetReleasedEvent()->AddSlot(this, &DefaultCamera::OnWReleased);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_A)->GetReleasedEvent()->AddSlot(this, &DefaultCamera::OnAReleased);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_S)->GetReleasedEvent()->AddSlot(this, &DefaultCamera::OnSReleased);
	Engine::GetInstance()->GetInputSystem()->GetKeyboard()->GetKey(GLFW_KEY_D)->GetReleasedEvent()->AddSlot(this, &DefaultCamera::OnDReleased);
	
	Engine::GetInstance()->GetInputSystem()->GetMouse()->GetCursorPosEventInterface()->AddSlot(this, &DefaultCamera::OnMouseMoved);

	CameraObject::Update(0.0f);
}

void DefaultCamera::OnWPressed()
{
	velocity_front_ = 1.0f;
}

void DefaultCamera::OnAPressed()
{
		velocity_left_ = -1.0f;
}

void DefaultCamera::OnSPressed()
{
		velocity_back_ = -1.0f;
}

void DefaultCamera::OnDPressed()
{
	velocity_right_ = 1.0f;
}

void DefaultCamera::OnWReleased()
{
	velocity_front_ = 0.0f;
}

void DefaultCamera::OnAReleased()
{
	velocity_left_ = 0.0f;
}

void DefaultCamera::OnSReleased()
{
	velocity_back_ = 0.0f;
}

void DefaultCamera::OnDReleased()
{
	velocity_right_ = 0.0f;
}

void DefaultCamera::OnMouseMoved(const Eigen::Vector2f & val, const Eigen::Vector2f & old_val)
{
	const auto pi = static_cast<float>(M_PI);
	rotation_ += (val - old_val) * 0.1f;
	if (rotation_.x() >= pi)
		rotation_.x() -= 2 * pi;
	if (rotation_.y() >= pi)
		rotation_.y() -= 2 * pi;
	if (rotation_.x() <= -pi)
		rotation_.x() += 2 * pi;
	if (rotation_.y() <= -pi)
		rotation_.y() += 2 * pi;

	const auto rot_x = Eigen::AngleAxis<float>(-rotation_.x(), Eigen::Vector3f(0.0f, 1.0f, 0.0f));
	const auto rot_y = Eigen::AngleAxis<float>(rotation_.y(), Eigen::Vector3f(1.0f, 0.0f, 0.0f));
	view_dir_ = (rot_x * rot_y * Eigen::Vector3f(0.0f, 0.0f, -1.0f)).normalized();
}

void DefaultCamera::Update(float delta_time)
{	
	if (velocity_front_ - velocity_back_ != 0.0f || velocity_left_ - velocity_right_ != 0.0f)
		eye_ += ((velocity_front_ + velocity_back_) * view_dir_ + (velocity_right_ + velocity_left_) * view_dir_.cross(up_)) * delta_time ;

	center_ = eye_ + view_dir_;
	up_ = Eigen::Vector3f(0.0f, 1.0f, 0.0f);
	CameraObject::Update(delta_time);
}

