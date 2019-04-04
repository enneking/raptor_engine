
#pragma once
#include "game_object.h"

#include "non_copyable.h"
#include "matrices_helpers.h"

namespace rpt {
	class CameraObject : public GameObject
	{
	public:
		CameraObject();

		struct TransformMatrices {
			Eigen::Matrix4f view_matrix;
			Eigen::Matrix4f projection_matrix;
			Eigen::Matrix4f view_projection_matrix;
		};

		virtual void Update(float delta_time) override;

		TransformMatrices const * const GetTransformData() const;
	protected:
		Eigen::Vector3f center_;
		Eigen::Vector3f eye_;
		Eigen::Vector3f up_;

	private:
		TransformMatrices transform_matrices_;
	};
};

