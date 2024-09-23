#ifndef FLAMEIDE_TEMPLATES_OPTIONAL_HPP
#define FLAMEIDE_TEMPLATES_OPTIONAL_HPP

#include <FlameIDE/Templates/AlignObject.hpp>

namespace flame_ide
{namespace templates
{

template<typename T, typename Traits = DefaultTraits<T>>
class Optional
{
public:
	using Me = Optional<T, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;

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
	typename Me::MoveReference pull() noexcept;

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

template<typename T, typename Traits>
Optional<T, Traits>::Optional() noexcept : value(), isFill(false)
{}

template<typename T, typename Traits>
Optional<T, Traits>::Optional(const Me &optional) : Optional()
{
	if (optional)
	{
		placementNew(toValue(), optional.get());
		isFill = true;
	}
}

template<typename T, typename Traits>
Optional<T, Traits>::Optional(Me &&optional) noexcept : Optional()
{
	if (optional)
	{
		placementNew(toValue(), move(optional.get()));
		isFill = true;
	}
}

template<typename T, typename Traits>
Optional<T, Traits>::Optional(ConstReference value)
		: Optional<T>()
{
	placementNew(toValue(), value);
	isFill = true;
}

template<typename T, typename Traits>
Optional<T, Traits>::Optional(MoveReference value) noexcept
		: Optional()
{
	placementNew(toValue(), move(value));
	isFill = true;
}

template<typename T, typename Traits>
Optional<T, Traits>::~Optional()
{
	unset();
}

template<typename T, typename Traits>
Optional<T, Traits> &Optional<T, Traits>::operator=(const Me &optional)
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

template<typename T, typename Traits>
Optional<T, Traits> &Optional<T, Traits>::operator=(Me &&optional) noexcept
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

template<typename T, typename Traits>
Optional<T, Traits> &Optional<T, Traits>::operator=(ConstReference value)
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

template<typename T, typename Traits>
Optional<T, Traits> &Optional<T, Traits>::operator=(MoveReference value) noexcept
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

template<typename T, typename Traits>
Optional<T, Traits>::operator bool() const noexcept
{
	return isFill;
}

template<typename T, typename Traits>
typename Optional<T, Traits>::Pointer Optional<T, Traits>::operator->()
{
	return toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::PointerToConst Optional<T, Traits>::operator->() const
{
	return toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::Reference Optional<T, Traits>::operator*()
{
	return *toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::ConstReference Optional<T, Traits>::operator*() const
{
	return *toValue();
}

template<typename T, typename Traits>
void Optional<T, Traits>::init()
{
	emplaceNew(toValue());
}

template<typename T, typename Traits>
void Optional<T, Traits>::set(typename Optional<T, Traits>::ConstReference value)
{
	operator=(value);
}

template<typename T, typename Traits>
void Optional<T, Traits>::set(typename Optional<T, Traits>::MoveReference value) noexcept
{
	operator=(move(value));
}

template<typename T, typename Traits>
typename Optional<T, Traits>::Reference Optional<T, Traits>::get()
{
	return *toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::ConstReference Optional<T, Traits>::get() const
{
	return *toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::MoveReference Optional<T, Traits>::pull() noexcept
{
	isFill = false;
	return flame_ide::move(get());
}

template<typename T, typename Traits>
typename Optional<T, Traits>::Pointer Optional<T, Traits>::getPointer()
{
	return toValue();
}

template<typename T, typename Traits>
typename Optional<T, Traits>::PointerToConst Optional<T, Traits>::getPointer() const
{
	return toValue();
}

template<typename T, typename Traits>
void Optional<T, Traits>::unset()
{
	if (*this)
	{
		toValue()->~T();
		isFill = false;
	}
}

template<typename T, typename Traits>
typename Optional<T, Traits>::Pointer Optional<T, Traits>::toValue()
{
	return static_cast<typename Me::Pointer>(
			static_cast<void *>(value.array)
	);
}

template<typename T, typename Traits>
typename Optional<T, Traits>::PointerToConst Optional<T, Traits>::toValue() const
{
	return static_cast<typename Me::PointerToConst>(
			static_cast<const void *>(value.array)
	);
}

}}

#endif // FLAMEIDE_TEMPLATES_OPTIONAL_HPP
