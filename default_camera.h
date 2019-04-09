#pragma once
#include "engine.h"

class DefaultCamera : public CameraObject
{
public:
	DefaultCamera();

	virtual void Update(float delta_time) override;

protected:
	void OnWPressed();
	void OnAPressed();
	void OnSPressed();
	void OnDPressed();

	void OnWReleased();
	void OnAReleased();
	void OnSReleased();
	void OnDReleased();

	void OnMouseMoved(const Eigen::Vector2f &, const Eigen::Vector2f &);

private:
	float velocity_front_ = 0.0f;
	float velocity_back_ = 0.0f;
	float velocity_left_ = 0.0f;
	float velocity_right_ = 0.0f;
	Eigen::Vector2f rotation_;

	Eigen::Vector3f view_dir_;
};

