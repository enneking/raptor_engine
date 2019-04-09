#include "model.h"
#include "engine.h"


void Model::UpdatePosByEditor(Eigen::Vector3f new_pos)
{
	model_matrix_(0,3) = new_pos.x();
	model_matrix_(1,3) = new_pos.y();
	model_matrix_(2,3) = new_pos.z();
}

void Model::ScaleByEditor(Eigen::Vector3f new_scale)
{
	model_matrix_(0, 0) += new_scale(0);
	model_matrix_(1, 1) += new_scale(1);
	model_matrix_(2, 2) += new_scale(2);
}