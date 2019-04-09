#pragma once
#include <Eigen\Core>
#include "non_copyable.h"


class Model : public NonCopyable
{
	friend class Editor;

private:
	void UpdatePosByEditor(Eigen::Vector3f new_pos);
	void ScaleByEditor(Eigen::Vector3f new_scale);

protected:
	Eigen::Matrix4f model_matrix_;

};
