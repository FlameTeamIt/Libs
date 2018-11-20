#ifndef TEMPLATES_OPTIONAL_HPP
#define TEMPLATES_OPTIONAL_HPP

#include <Templates/AlignObject.hpp>

namespace flame_ide
{namespace templates
{

template<typename T>
class Optional: public DefaultTraits<T>
{
public:
	using Me = Optional<T>;

	Optional() noexcept;
	Optional(const Me &optional);
	Optional(Me &&optional) noexcept;
	Optional(typename Me::ConstReference value);
	Optional(typename Me::MoveReference value) noexcept;
	~Optional();

	Me &operator=(const Me &optional);
	Me &operator=(Me &&optional) noexcept;
	Me &operator=(typename Me::ConstReference value);
	Me &operator=(typename Me::MoveReference value) noexcept;

	operator bool() const noexcept;

	typename Me::Pointer operator->();
	typename Me::PointerToConst operator->() const;
	typename Me::Reference operator*();
	typename Me::ConstReference operator*() const;

	void init();
	void set(typename Me::ConstReference value);
	void set(typename Me::MoveReference value) noexcept;

	typename Me::Reference get();
	typename Me::ConstReference get() const;

	typename Me::Pointer getPointer();
	typename Me::PointerToConst getPointer() const;

	void unset();

private:
	typename Me::Pointer toValue();
	typename Me::PointerToConst toValue() const;

	AlignObject<T> value;
	bool isFill;
};

}}

namespace flame_ide
{namespace templates
{

template<typename T>
Optional<T>::Optional() noexcept : value(), isFill(false)
{}

template<typename T>
Optional<T>::Optional(const Optional<T> &optional) : Optional<T>()
{
	if (optional)
	{
		placementNew(toValue(), optional.get());
		isFill = true;
	}
}

template<typename T>
Optional<T>::Optional(Optional<T> &&optional) noexcept : Optional<T>()
{
	if (optional)
	{
		placementNew(toValue(), move(optional.get()));
		isFill = true;
	}
}

template<typename T>
Optional<T>::Optional(typename Optional<T>::ConstReference value)
		: Optional<T>()
{
	placementNew(toValue(), value);
	isFill = true;
}

template<typename T>
Optional<T>::Optional(typename Optional<T>::MoveReference value) noexcept
		: Optional<T>()
{
	placementNew(toValue(), move(value));
	isFill = true;
}

template<typename T>
Optional<T>::~Optional()
{
	unset();
}

template<typename T>
Optional<T> &Optional<T>::operator=(const Optional &optional)
{
	if (*this)
	{
		if (optional)
		{
			*toValue() = optional.get();
		}
	}
	else
	{
		if (optional)
		{
			placementNew(toValue(), optional.get());
			isFill = true;
		}
	}
	return *this;
}

template<typename T>
Optional<T> &Optional<T>::operator=(Optional &&optional) noexcept
{
	if (*this)
	{
		if (optional)
		{
			*toValue() = move(optional.get());
		}
	}
	else
	{
		if (optional)
		{
			placementNew(toValue(), move(optional.get()));
			isFill = true;
		}
	}
	return *this;
}

template<typename T>
Optional<T> &Optional<T>::operator=(typename Me::ConstReference value)
{
	if (*this)
	{
		*toValue() = value;
	}
	else
	{
		placementNew(toValue(), value);
		isFill = true;
	}
	return *this;
}

template<typename T>
Optional<T> &Optional<T>::operator=(typename Me::MoveReference value) noexcept
{
	if (*this)
	{
		*toValue() = move(value);
	}
	else
	{
		placementNew(toValue(), move(value));
		isFill = true;
	}
	return *this;
}

template<typename T>
Optional<T>::operator bool() const noexcept
{
	return isFill;
}

template<typename T>
typename Optional<T>::Pointer Optional<T>::operator->()
{
	return toValue();
}

template<typename T>
typename Optional<T>::PointerToConst Optional<T>::operator->() const
{
	return toValue();
}

template<typename T>
typename Optional<T>::Reference Optional<T>::operator*()
{
	return *toValue();
}

template<typename T>
typename Optional<T>::ConstReference Optional<T>::operator*() const
{
	return *toValue();
}

template<typename T>
void Optional<T>::init()
{
	emplaceNew(toValue());
}

template<typename T>
void Optional<T>::set(typename Optional<T>::ConstReference value)
{
	operator=(value);
}

template<typename T>
void Optional<T>::set(typename Optional<T>::MoveReference value) noexcept
{
	operator=(move(value));
}

template<typename T>
typename Optional<T>::Reference Optional<T>::get()
{
	return *toValue();
}

template<typename T>
typename Optional<T>::ConstReference Optional<T>::get() const
{
	return *toValue();
}

template<typename T>
typename Optional<T>::Pointer Optional<T>::getPointer()
{
	return toValue();
}

template<typename T>
typename Optional<T>::PointerToConst Optional<T>::getPointer() const
{
	return toValue();
}

template<typename T>
void Optional<T>::unset()
{
	if (*this)
	{
		toValue()->~T();
		isFill = false;
	}
}

template<typename T>
typename Optional<T>::Pointer Optional<T>::toValue()
{
	return static_cast<typename Me::Pointer>(
			static_cast<void *>(value.array)
	);
}

template<typename T>
typename Optional<T>::PointerToConst Optional<T>::toValue() const
{
	return static_cast<typename Me::PointerToConst>(
			static_cast<const void *>(value.array)
	);
}

}}

#endif // TEMPLATES_OPTIONAL_HPP
