#ifndef FLAMEIDE_TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP
#define FLAMEIDE_TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP

#include <FlameIDE/Templates/Allocator/MallocAllocator.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

///
/// @brief Simple allocator for construct and destruct objects
///
/// @tparam T
/// Concrete type of objects
/// @tparam Traits
/// View flame_ide::ContainerTraits
///
template<
	typename T
	, typename Traits = flame_ide::ContainerTraits<T>
	, typename BaseAllocatorImpl = MallocAllocator<Traits>
>
class ObjectAllocator: protected BaseAllocatorImpl
{
public:
	using Parent = BaseAllocatorImpl;
	using typename Parent::VoidPointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;

	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using MoveReference = typename Traits::MoveReference;
	using ConstReference = typename Traits::ConstReference;

	using Me = ObjectAllocator<T, Traits, BaseAllocatorImpl>;

	ObjectAllocator() = default;
	ObjectAllocator(const Me &) = default;
	ObjectAllocator(Me &&) noexcept = default;
	~ObjectAllocator() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

	///
	/// @brief Function for create object, using custom constructor
	///
	/// @tparam Args
	/// Argumet types for constructor
	///
	/// @param args
	/// List of arguments for calling contructor
	///
	/// @return Pointer to new object
	///
	template<typename ...Args>
	Pointer construct(Args &&...args) noexcept;
	Pointer construct(MoveReference obj) noexcept;
	Pointer construct(ConstReference obj) noexcept;

	///
	/// @brief Function for destruct object
	///
	/// @param pointer
	/// Pointer to object which can be removed
	///
	void destroy(Pointer &pointer) noexcept;
};

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename T, typename Traits, typename BaseAllocatorImpl>
template<typename ...Args>
typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ObjectAllocator<T, Traits, BaseAllocatorImpl>::construct(Args &&...args) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		flame_ide::emplaceNew<Type>(pointer, forward<decltype(args)>(args)...);
	return pointer;
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ObjectAllocator<T, Traits, BaseAllocatorImpl>::construct(
		typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::MoveReference obj) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		placementNew<Type>(pointer, obj);
	return pointer;
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ObjectAllocator<T, Traits, BaseAllocatorImpl>::construct(
		typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::ConstReference obj) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		emplaceNew<Type>(pointer, obj);
	return pointer;
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
void ObjectAllocator<T, Traits, BaseAllocatorImpl>::destroy(
		typename ObjectAllocator<T, Traits, BaseAllocatorImpl>::Pointer &pointer) noexcept
{
	(*pointer).~T();
	this->deallocate(pointer);
	pointer = nullptr;
}

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{namespace defaults
{

template<typename T>
using ObjectAllocator = flame_ide::templates::allocator::ObjectAllocator<
	T, flame_ide::ContainerTraits<T>, MallocAllocator<flame_ide::ContainerTraits<T>>
>;

}}}} // namespace flame_ide::templates::allocator::defaults

#endif // FLAMEIDE_TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP
