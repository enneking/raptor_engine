#include "editor.h"


void Editor::SetSelectedModelPos(const Eigen::Vector3f val)
{
	if(selected_model_ != nullptr)
		selected_model_->UpdatePosByEditor(val);
}

void Editor::ScaleSelectedModel(Eigen::Vector3f new_scale)
{
	if (selected_model_ != nullptr)
		selected_model_->ScaleByEditor(new_scale);
}