#pragma once
#include "event_base.h"

namespace rpt {
template<class Type>
class Observer : public EventBase<const Type&, const Type&> {
public:
	using Interface = EventInterface<const Type&, const Type&>;
public:
	Observer();
	explicit Observer( Type &value );
	explicit Observer( Type value );

	Type const & Get() const;
	void operator=(Type value);
	bool operator==(Type value);
	void operator*=(Type value);
	void operator/=(Type value);
	Type operator+(Type value);
	Type operator-(Type value);
	Type operator+(Observer<Type> value);
	Type operator-(Observer<Type> value);


private:
	Type val_;
	bool is_locked_ = false;
};	
};

#include "Observer.inl"