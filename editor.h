#pragma once
#include "non_copyable.h"
#include "editor_component.h"
#include "factory.h"
#include "display_system.h"

class Editor : public Factory<Model>
{

protected:
	virtual void ToggleEditor() = 0;
	virtual void CreateObject() = 0;
	virtual void SetSelectedModelPos(const Eigen::Vector3f val);
	virtual void ScaleSelectedModel(Eigen::Vector3f scale);

	Model * selected_model_;

};

