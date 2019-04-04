#pragma once

#include "non_copyable.h"
namespace rpt {

	class GameObject : public NonCopyable
	{
	public:
		virtual ~GameObject() = default;

	public:
		virtual void Update(float delta_time) = 0;
	};

};

