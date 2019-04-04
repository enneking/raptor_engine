#pragma once
#include "render_object.h"
#include "matrices_helpers.h"
#include "engine.h"

class BoxView : public rpt::RenderObject
{
public:
	BoxView();
	
	void SetDrawData(const Eigen::Matrix4f * const model_matrix);
	EventInterface<> * const GetRequestDataEvent();

protected:
	virtual void Draw() override;

private:
	GLuint vertex_array_, shader_;
	Event<> request_data_event_;

};

