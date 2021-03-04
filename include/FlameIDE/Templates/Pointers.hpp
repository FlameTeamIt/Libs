#ifndef FLAMEIDE_TEMPLATES_POINTERS_HPP
#define FLAMEIDE_TEMPLATES_POINTERS_HPP

#include <FlameIDE/Templates/Allocator.hpp>

#define SHARED_TEMPLATE_DEFINE \
	template< \
		typename T, typename Traits, typename Allocator, \
		typename Counter, typename CounterAllocator \
	>

#define UNIQUE_TEMPLATE_DEFINE \
	template<typename T, typename Traits, typename Allocator>

#define SHARED_TYPE \
	SharedPointer<T, Traits, Allocator, Counter, CounterAllocator>

#define UNIQUE_TYPE \
	UniquePointer<T, Traits, Allocator>

// defines

namespace flame_ide
{namespace templates
{

namespace pointer_utils
{

template<typename CounterType>
struct Counter;

}

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T>
	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
	, typename CounterAllocator = allocator::ObjectAllocator<Counter>
>
class SharedPointer;

template<typename T
	, typename Traits = ContainerTraits<T>
>
class WeakPointer;

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T>
	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
	, typename CounterAllocator = allocator::ObjectAllocator<Counter>
	, typename ...Args>
SHARED_TYPE makeShared(Args &&...args);

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T, Traits>
>
class UniquePointer;

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T, Traits>
	, typename ...Args>
UNIQUE_TYPE makeUnique(Args &&...args);

// FIXME: Не совсем понятно, как привидить типы при разных аллокаторах
template<
	typename T, typename U
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T>
	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
	, typename CounterAllocator = allocator::ObjectAllocator<Counter>
	, typename TraitsU = ContainerTraits<T>
	, typename AllocatorU = allocator::ObjectAllocator<T>
	, typename CounterU = pointer_utils::Counter<SizeTraits::SizeType>
	, typename CounterAllocatorU = allocator::ObjectAllocator<Counter>
> inline
SHARED_TYPE staticPointerCast(
		SharedPointer<U, TraitsU, AllocatorU, Counter, CounterU> &pointer
) noexcept;
template<
	typename T, typename U
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T>
	, typename TraitsU = allocator::ObjectAllocator<U>
	, typename AllocatorU = allocator::ObjectAllocator<U>
> inline
UNIQUE_TYPE staticPointerCast(UniquePointer<U, TraitsU, AllocatorU>  &pointer) noexcept;

//template<
//	typename T, typename U
//	, typename Traits = ContainerTraits<T>
//	, typename Allocator = allocator::ObjectAllocator<T>
//	, typename TraitsU = ContainerTraits<U>
//	, typename AllocatorU = allocator::ObjectAllocator<U>
//> inline
//SHARED_TYPE reiterpretPointerCast(SHARED_U_TYPE &pointer) noexcept;
//template<
//	typename T, typename U
//	, typename Traits = ContainerTraits<T>
//	, typename Allocator = allocator::ObjectAllocator
//> inline
//UNIQUE_TYPE reiterpretPointerCast(UNIQUE_U_TYPE &pointer) noexcept;

}}

// interface

namespace flame_ide
{namespace templates
{

namespace pointer_utils
{

template<typename CounterType>
struct Counter
{
	Counter();
	Counter(const Counter<CounterType> &) = delete;
	Counter(Counter<CounterType> &&) = delete;
	~Counter() = default;

	Counter<CounterType> &operator++()
	{
		++counter;
		return *this;
	}
	Counter<CounterType> &operator--()
	{
		--counter;
		return *this;
	}

	CounterType get() const noexcept
	{
		return counter;
	}

	operator bool()
	{
		return counter;
	}

	static constexpr CounterType NULL_VALUE = CounterType();

	CounterType counter;
};

}

template<
	typename T
	, typename Traits, typename Allocator
	, typename Counter, typename CounterAllocator
>
class SharedPointer
{
public:
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using SizeType = typename Traits::SizeType;

	using Me = SHARED_TYPE;

	SharedPointer() noexcept = default;
	SharedPointer(const Me &) noexcept;
	SharedPointer(Me &&) noexcept;
	SharedPointer(ConstReference obj) noexcept;
	SharedPointer(MoveReference obj) noexcept;
	~SharedPointer();
	Me &operator=(const Me &) noexcept;
	Me &operator=(Me &&) noexcept;

	Reference operator*() noexcept;
	ConstReference operator*() const noexcept;

	Pointer operator->() noexcept;
	PointerToConst operator->() const noexcept;

	operator bool() const noexcept;

	void clean();

	Pointer pointer() noexcept;

	PointerToConst pointer() const noexcept;

	Reference reference() noexcept;

	ConstReference reference() const noexcept;

private:
	using PointerCounter = typename ContainerTraits<Counter>::Pointer;

	mutable Allocator allocator;
	mutable CounterAllocator counterAllocator;
	mutable Pointer object;
	mutable PointerCounter objectCounter;
};

/// @brief The UniquePointer class
/// @tparam T
/// @tparam Traits
/// @tparam Allocator
template<typename T, typename Traits, typename Allocator>
class UniquePointer
{
public:
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;

	using Me = UNIQUE_TYPE;

	UniquePointer() = default;
	UniquePointer(const Me &) = delete;
	UniquePointer(Me &&) noexcept;
	UniquePointer(ConstReference object) noexcept;
	UniquePointer(MoveReference object) noexcept;
	~UniquePointer();
	Me &operator=(const Me &) = delete;
	Me &operator=(Me &&) noexcept;

	Reference operator*() noexcept;
	ConstReference operator*() const noexcept;

	Pointer operator->() noexcept;
	PointerToConst operator->() const noexcept;

	operator bool() const noexcept;

	void clean();

	Pointer pointer() noexcept;

	PointerToConst pointer() const noexcept;

	Reference reference() noexcept;

	ConstReference reference() const noexcept;

private:
	Allocator allocator;
	Pointer object;
};

}}

// implementation

namespace flame_ide
{namespace templates
{

namespace pointer_utils
{

template<typename CounterType>
Counter<CounterType>::Counter() : counter(Counter<CounterType>::NULL_VALUE)
{}

}

// SharedPointer

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(const SHARED_TYPE &pointer) noexcept
		: allocator(pointer.allocator)
		, counterAllocator(pointer.counterAllocator)
		, object(pointer.object)
		, objectCounter(pointer.objectCounter)
{
	++(*objectCounter);
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(SHARED_TYPE &&pointer) noexcept
		: allocator(pointer.allocator)
		, counterAllocator(pointer.counterAllocator)
		, object(pointer.object)
		, objectCounter(pointer.objectCounter)
{
	pointer.object = nullptr;
	pointer.objectCounter = nullptr;
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(typename SHARED_TYPE::ConstReference obj) noexcept
		: allocator()
		, counterAllocator()
		, object(allocator.construct(obj))
		, objectCounter(counterAllocator.construct())
{
	++(*objectCounter);
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(typename SHARED_TYPE::MoveReference obj) noexcept
		: allocator()
		, counterAllocator()
		, object(allocator.construct(obj))
		, objectCounter(counterAllocator.construct())
{
	++(*objectCounter);
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::~SharedPointer()
{
	clean();
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE &SHARED_TYPE::operator=(const SHARED_TYPE &pointer) noexcept
{
	clean();

	allocator = pointer.allocator;
	counterAllocator = pointer.counterAllocator;
	object = pointer.object;
	objectCounter = pointer.objectCounter;

	++(*objectCounter);

	return *this;
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE &SHARED_TYPE::operator=(SHARED_TYPE &&pointer) noexcept
{
	clean();

	allocator = pointer.allocator;
	counterAllocator = pointer.counterAllocator;
	object = pointer.object;
	objectCounter = pointer.objectCounter;

	pointer.object = nullptr;
	pointer.objectCounter = nullptr;

	return *this;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Reference SHARED_TYPE::operator*() noexcept
{
	return *object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::ConstReference SHARED_TYPE::operator*() const noexcept
{
	return *object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Pointer SHARED_TYPE::operator->() noexcept
{
	return object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::PointerToConst SHARED_TYPE::operator->() const noexcept
{
	return object;
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::operator bool() const noexcept
{
	return operator->();
}

SHARED_TEMPLATE_DEFINE
void SHARED_TYPE::clean()
{
	if (object && objectCounter && !--(*objectCounter) )
	{
		allocator.destroy(object);
		counterAllocator.destroy(objectCounter);

		object = nullptr;
		objectCounter = nullptr;
	}
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Pointer SHARED_TYPE::pointer() noexcept
{
	return operator*();
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::PointerToConst SHARED_TYPE::pointer() const noexcept
{
	return operator*();
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Reference SHARED_TYPE::reference() noexcept
{
	return operator->();
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::ConstReference SHARED_TYPE::reference() const noexcept
{
	return operator->();
}

// UniquePointer

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::UniquePointer(UNIQUE_TYPE &&pointer) noexcept
		: allocator(pointer.allocator)
		, object(pointer.object)
{
	pointer.object = nullptr;
}

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::UniquePointer(typename UNIQUE_TYPE::ConstReference obj) noexcept
		: allocator()
		, object(allocator.construct(obj))
{}

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::UniquePointer(typename UNIQUE_TYPE::MoveReference obj) noexcept
		: allocator()
		, object(allocator.construct(obj))
{}

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE &UNIQUE_TYPE::operator=(UNIQUE_TYPE &&pointer) noexcept
{
	clean();

	object = pointer.object;
	allocator = pointer.allocator;

	pointer.object = nullptr;

	return *this;
}

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::~UniquePointer()
{
	clean();
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::Reference UNIQUE_TYPE::operator*() noexcept
{
	return *object;
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::ConstReference UNIQUE_TYPE::operator*() const noexcept
{
	return *object;
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::Pointer UNIQUE_TYPE::operator->() noexcept
{
	return object;
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::PointerToConst UNIQUE_TYPE::operator->() const noexcept
{
	return object;
}

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::operator bool() const noexcept
{
	return operator->();
}

UNIQUE_TEMPLATE_DEFINE
void UNIQUE_TYPE::clean()
{
	if (object)
	{
		allocator.destroy(object);
		object = nullptr;
	}
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::Pointer UNIQUE_TYPE::pointer() noexcept
{
	return operator->();
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::PointerToConst UNIQUE_TYPE::pointer() const noexcept
{
	return operator->();
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::Reference UNIQUE_TYPE::reference() noexcept
{
	return operator*();
}

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::ConstReference UNIQUE_TYPE::reference() const noexcept
{
	return operator*();
}

}}

#undef SHARED_TEMPLATE_DEFINE
#undef UNIQUE_TEMPLATE_DEFINE

#undef SHARED_TYPE
#undef UNIQUE_TYPE

#endif // FLAMEIDE_TEMPLATES_POINTERS_HPP
