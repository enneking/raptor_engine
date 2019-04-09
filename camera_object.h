
#pragma once
#include "update_object.h"

#include "non_copyable.h"
#include "matrices_helpers.h"
#include "observer.h"


	class CameraObject : public UpdateObject
	{
		friend class CameraManager;
	public:
		CameraObject();

		struct TransformMatrices {
			Eigen::Matrix4f view_matrix;
			Eigen::Matrix4f projection_matrix;
			Eigen::Matrix4f view_projection_matrix;
			Eigen::Matrix4f inverse_view_matrix;
		};

		virtual void Update(float delta_time) override;

		TransformMatrices const * const GetTransformData() const;

		const Eigen::Vector3f * const GetPos() const;

	protected:
		Observer<Eigen::Vector3f> center_;
		Observer<Eigen::Vector3f> eye_;
		Eigen::Vector3f up_;


	private:
		TransformMatrices transform_matrices_;
	};
