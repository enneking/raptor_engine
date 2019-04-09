#pragma once
#include "billboard_sphere_model.h"
#include "billboard_sphere_view.h"

class BillboardSphere
{
public:
	BillboardSphere(Eigen::Vector3f pos = Eigen::Vector3f::Zero());


protected:
	BillboardSphereView * view_;
	BillboardSphereModel * model_;

private:
	void ProvideDrawData();

};

