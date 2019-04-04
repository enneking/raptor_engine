#pragma once
#include "box_model.h"
#include "box_view.h"

#include "non_copyable.h" 

class Box : public NonCopyable
{
public:
	Box(const Eigen::Vector3f  pos_ = Eigen::Vector3f(0.0f, 0.0f, 0.0f));

private:
	void ProvideDrawData();

private:
	BoxModel model_;
	BoxView * view_;
};

