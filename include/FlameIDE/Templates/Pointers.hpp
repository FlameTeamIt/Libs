#ifndef FLAMEIDE_TEMPLATES_POINTERS_HPP
#define FLAMEIDE_TEMPLATES_POINTERS_HPP

#include <FlameIDE/Templates/Allocator.hpp>

#include <FlameIDE/Templates/Variant.hpp>

#define SHARED_TEMPLATE_DEFINE \
	template< \
		typename T, typename Traits \
		, template<typename> class Allocator \
		, typename Counter \
	>

#define UNIQUE_TEMPLATE_DEFINE \
	template<typename T, typename Traits, typename Allocator>

#define SHARED_TYPE \
	SharedPointer<T, Traits, Allocator, Counter>

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

template<
	typename T
	, typename ObjectCounter = Counter<SizeTraits::SizeType>
>
struct Members;

} // namespace pointer_utils

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, template<typename> class Allocator = allocator::defaults::ObjectAllocator
	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
>
class SharedPointer;

template<
	typename T
	, typename Traits = ContainerTraits<T>
>
class WeakPointer;

//template<
//	typename T
//	, typename Traits = ContainerTraits<T>
//	, template<typename> class Allocator = allocator::DefaultObjectAllocator
//	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
//	, typename CounterAllocator = allocator::ObjectAllocator<Counter>
//	, typename ...Args
//>
//SHARED_TYPE makeShared(Args &&...args);

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T, Traits>
>
class UniquePointer;

//template<
//	typename T
//	, typename Traits = ContainerTraits<T>
//	, typename Allocator = allocator::ObjectAllocator<T, Traits>
//	, typename ...Args
//>
//UNIQUE_TYPE makeUnique(Args &&...args);

// FIXME: Не совсем понятно, как привидить типы при разных аллокаторах
//template<
//	typename T, typename U
//	, typename Traits = ContainerTraits<T>
//	, typename Allocator = allocator::ObjectAllocator<T>
//	, typename Counter = pointer_utils::Counter<SizeTraits::SizeType>
//	, typename CounterAllocator = allocator::ObjectAllocator<Counter>
//	, typename TraitsU = ContainerTraits<T>
//	, typename AllocatorU = allocator::ObjectAllocator<T>
//	, typename CounterU = pointer_utils::Counter<SizeTraits::SizeType>
//	, typename CounterAllocatorU = allocator::ObjectAllocator<Counter>
//> inline
//SHARED_TYPE staticPointerCast(
//		SharedPointer<U, TraitsU, AllocatorU, Counter, CounterU> &pointer
//) noexcept;
//template<
//	typename T, typename U
//	, typename Traits = ContainerTraits<T>
//	, typename Allocator = allocator::ObjectAllocator<T>
//	, typename TraitsU = allocator::ObjectAllocator<U>
//	, typename AllocatorU = allocator::ObjectAllocator<U>
//> inline
//UNIQUE_TYPE staticPointerCast(UniquePointer<U, TraitsU, AllocatorU> &pointer) noexcept;

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
struct Counter: public flame_ide::NonAssignable
{
	Counter() noexcept;
	~Counter() = default;

	Counter<CounterType> &operator++();
	Counter<CounterType> &operator--();

	CounterType get() const noexcept;

	operator bool() const noexcept;

public:
	static constexpr CounterType NULL_VALUE = CounterType{};
	CounterType counter;
};

template<typename T, typename ObjectCounter>
struct Members: public flame_ide::NonAssignable
{
public:
	Members() noexcept = default;

	template<typename ...Args>
	Members(Args &&...args) :
			counter{}
			, object(flame_ide::forward<decltype(args)>(args)...)
	{}

	~Members() noexcept = default;

public:
	ObjectCounter counter;
	T object;
};

}

template<
	typename T, typename Traits
	, template<typename> class Allocator
	, typename Counter
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
	SharedPointer(const Me &point) noexcept;
	SharedPointer(Me &&point) noexcept;
//	SharedPointer(ConstReference obj) noexcept;
//	SharedPointer(MoveReference obj) noexcept;

	template<typename ...Args>
	SharedPointer(Args &&...args) noexcept;

	~SharedPointer() noexcept;

	Me &operator=(const Me &pointer) noexcept;
	Me &operator=(Me &&pointer) noexcept;

	Reference operator*() noexcept;
	ConstReference operator*() const noexcept;

	Pointer operator->() noexcept;
	PointerToConst operator->() const noexcept;

	operator bool() const noexcept;

	void clean() noexcept;

	Pointer pointer() noexcept;

	PointerToConst pointer() const noexcept;

	Reference reference() noexcept;

	ConstReference reference() const noexcept;

private:
	mutable Allocator<pointer_utils::Members<T, Counter>> allocator;
	mutable pointer_utils::Members<T, Counter> *members;
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

	template<typename ...Args>
	UniquePointer(Args &&...args);

	UniquePointer(const Me &) = delete;
	UniquePointer(Me &&) noexcept;
	UniquePointer(ConstReference object) noexcept;
	UniquePointer(MoveReference object) noexcept;

	~UniquePointer() noexcept;

	Me &operator=(const Me &) = delete;
	Me &operator=(Me &&) noexcept;

	Reference operator*() noexcept;
	ConstReference operator*() const noexcept;

	Pointer operator->() noexcept;
	PointerToConst operator->() const noexcept;

	operator bool() const noexcept;

	void clean() noexcept;

	Pointer pointer() noexcept;

	PointerToConst pointer() const noexcept;

	Reference reference() noexcept;

	ConstReference reference() const noexcept;

	static Me makeEmpty() noexcept;

private:
	UniquePointer(Empty) noexcept;

private:
	Allocator allocator;
	Pointer object = nullptr;
};

}}

// implementation

namespace flame_ide
{namespace templates
{

namespace pointer_utils
{

template<typename CounterType>
Counter<CounterType>::Counter() noexcept : counter(Counter<CounterType>::NULL_VALUE)
{}

template<typename CounterType>
Counter<CounterType> &Counter<CounterType>::operator++()
{
	++counter;
	return *this;
}

template<typename CounterType>
Counter<CounterType> &Counter<CounterType>::operator--()
{
	--counter;
	return *this;
}

template<typename CounterType>
CounterType Counter<CounterType>::get() const noexcept
{
	return counter;
}

template<typename CounterType>
Counter<CounterType>::operator bool() const noexcept
{
	return NULL_VALUE != counter;
}

} // namespace pointer_utils

// SharedPointer

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(const SHARED_TYPE &pointer) noexcept
		: allocator(pointer.allocator)
		, members(pointer.members)
{
	++(members->counter);
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::SharedPointer(SHARED_TYPE &&pointer) noexcept
		: allocator(pointer.allocator)
		, members(pointer.members)
{
	pointer.members = nullptr;
}

//SHARED_TEMPLATE_DEFINE
//SHARED_TYPE::SharedPointer(typename SHARED_TYPE::ConstReference obj) noexcept
//		: allocator()
//		, members{allocator.construct(obj)}
//{}

//SHARED_TEMPLATE_DEFINE
//SHARED_TYPE::SharedPointer(typename SHARED_TYPE::MoveReference obj) noexcept
//		: allocator()
//		, members{allocator.construct(flame_ide::move(obj))}
//{}

SHARED_TEMPLATE_DEFINE
template<typename ...Args>
SHARED_TYPE::SharedPointer(Args &&...args) noexcept
		: allocator()
		, members{allocator.construct(flame_ide::forward<Args>(args)...)}
{}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::~SharedPointer() noexcept
{
	clean();
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE &SHARED_TYPE::operator=(const SHARED_TYPE &pointer) noexcept
{
	clean();

	allocator = pointer.allocator;
	members = pointer.members;

	++(members->counter);

	return *this;
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE &SHARED_TYPE::operator=(SHARED_TYPE &&pointer) noexcept
{
	clean();

	allocator = flame_ide::move(pointer.allocator);
	members = pointer.members;

	pointer.members = nullptr;

	return *this;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Reference SHARED_TYPE::operator*() noexcept
{
	return members->object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::ConstReference SHARED_TYPE::operator*() const noexcept
{
	return members->object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::Pointer SHARED_TYPE::operator->() noexcept
{
	return &members->object;
}

SHARED_TEMPLATE_DEFINE
typename SHARED_TYPE::PointerToConst SHARED_TYPE::operator->() const noexcept
{
	return &members->object;
}

SHARED_TEMPLATE_DEFINE
SHARED_TYPE::operator bool() const noexcept
{
	return operator->();
}

SHARED_TEMPLATE_DEFINE
void SHARED_TYPE::clean() noexcept
{
	if (members && !--(members->counter) )
	{
		allocator.destroy(members);
		members = nullptr;
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
template<typename ...Args>
UNIQUE_TYPE::UniquePointer(Args &&...args)
		: allocator{}
		, object{ allocator.construct(forward<Args>(args)...) }
{}

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
UNIQUE_TYPE::~UniquePointer() noexcept
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
void UNIQUE_TYPE::clean() noexcept
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

UNIQUE_TEMPLATE_DEFINE
typename UNIQUE_TYPE::Me UNIQUE_TYPE::makeEmpty() noexcept
{
	return Me{ Empty{} };
}

// private

UNIQUE_TEMPLATE_DEFINE
UNIQUE_TYPE::UniquePointer(Empty) noexcept
{}

}} // namespace flame_ide::templates

#undef SHARED_TEMPLATE_DEFINE
#undef UNIQUE_TEMPLATE_DEFINE

#undef SHARED_TYPE
#undef UNIQUE_TYPE

#endif // FLAMEIDE_TEMPLATES_POINTERS_HPP
