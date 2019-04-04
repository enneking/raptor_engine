#include "Box.h"
#include "engine.h"


Box::Box(const Eigen::Vector3f pos) : model_(pos)
{
	view_ = rpt::Engine::GetInstance()->GetGraphicsSystem()->GetRenderObjectManager()->Create<BoxView>();
	view_->GetRequestDataEvent()->AddSlot(this, &Box::ProvideDrawData);
}

void Box::ProvideDrawData()
{
	view_->SetDrawData(model_.GetModelMatrix());
}