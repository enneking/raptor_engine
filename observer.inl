

template<class Type>
Observer<Type>::Observer() : val_(Type())
{
}

template<class Type>
Observer<Type>::Observer( Type &value ) : val_(value)
{
}

template<class Type>
Observer<Type>::Observer(Type value) : val_(value)
{
	
}

template<class Type>
Type const & Observer<Type>::Get() const
{
	return val_;
}

template<class Type>
void Observer<Type>::operator=(Type value)
{
	if (val_ == value)
		return;
	
	auto old_val = val_;
	val_ = value;
	(interface_.*(func_))(val_, old_val);
}

template<class Type>
bool Observer<Type>::operator==(Type value)
{
	return val_ == value;
}

template<class Type>
void Observer<Type>::operator+=(Type value)
{
	*this = *this + value;
}

template<class Type>
void Observer<Type>::operator-=(Type value)
{
	*this = *this - value;
}

template<class Type>
void Observer<Type>::operator*=(Type value)
{
	*this = *this * value;
}

template<class Type>
void Observer<Type>::operator/=(Type value)
{
	*this = *this / value;
}

template<class Type>
Type Observer<Type>::operator+(Type value)
{
	return val_ + value;
}

template<class Type>
Type Observer<Type>::operator-(Type value)
{
	return val_ - value;
}

template<class Type>
Type Observer<Type>::operator+(Observer<Type> value)
{
	return val_ + value();
}

template<class Type>
Type Observer<Type>::operator-(Observer<Type> value)
{
	return val_ - value();
}