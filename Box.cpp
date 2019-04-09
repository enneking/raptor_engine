#include "Box.h"
#include "engine.h"


Box::Box(const Eigen::Vector3f pos)
{
	view_ = Engine::GetInstance()->GetGraphicsSystem()->GetRenderObjectManager()->Create<BoxView>();
	model_ = Engine::GetInstance()->GetEditor()->Create<BoxModel>(pos);

	view_->GetRequestDataEvent()->AddSlot(this, &Box::ProvideDrawData);
}


void Box::ProvideDrawData()
{
	view_->SetDrawData(model_->GetModelMatrix());
}
