#pragma once
#include "engine.h"

class DefaultCamera : public rpt::CameraObject
{
public:
	DefaultCamera();

	virtual void Update(float delta_time) override;

protected:
	void OnWPressed(const bool &, const bool &);
	void OnAPressed(const bool &, const bool &);
	void OnSPressed(const bool &, const bool &);
	void OnDPressed(const bool &, const bool &);

	void OnMouseMoved(const Eigen::Vector2f &, const Eigen::Vector2f &);

private:
	float velocity_front_ = 0.0f;
	float velocity_back_ = 0.0f;
	float velocity_left_ = 0.0f;
	float velocity_right_ = 0.0f;

	Eigen::Vector3f view_dir_;
};

