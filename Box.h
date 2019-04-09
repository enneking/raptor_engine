#pragma once
#include "box_model.h"
#include "box_view.h"


class Box  : public NonCopyable
{
public:
	Box(const Eigen::Vector3f pos = Eigen::Vector3f::Zero());


protected:
	BoxView * view_;
	BoxModel * model_;

private:
	void ProvideDrawData();


};

