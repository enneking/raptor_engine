#pragma once

#include "non_copyable.h"


class UpdateObject : public NonCopyable
{
	friend class UpdateObjectManager;
public:
	virtual ~UpdateObject() = default;

protected:
	virtual void Update(float delta_time) = 0;
};

