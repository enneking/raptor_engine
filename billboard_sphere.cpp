#include "billboard_sphere.h"



BillboardSphere::BillboardSphere(Eigen::Vector3f pos)
{
	view_ = Engine::GetInstance()->GetGraphicsSystem()->GetRenderObjectManager()->Create<BillboardSphereView>();
	model_ = Engine::GetInstance()->GetEditor()->Create<BillboardSphereModel>(pos);

	view_->GetRequestDataEvent()->AddSlot(this, &BillboardSphere::ProvideDrawData);
}


void BillboardSphere::ProvideDrawData()
{
	view_->SetDrawData(model_->GetModelMatrix());
}
