#ifndef TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP
#define TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP

#include <Templates/Allocator/MallocAllocator.hpp>

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
/// View flame_ide::templates::ContainerTraits
///
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class ObjectAllocator: protected MallocAllocator<Traits>
{
public:
	using Parent = MallocAllocator<Traits>;
	using typename Parent::VoidPointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;
	using typename Traits::Type;
	using typename Traits::Pointer;
	using typename Traits::MoveReference;
	using typename Traits::ConstReference;

	ObjectAllocator() = default;
	ObjectAllocator(const ObjectAllocator<T, Traits> &) = default;
	ObjectAllocator(ObjectAllocator<T, Traits> &&) = default;
	~ObjectAllocator() = default;
	ObjectAllocator<T, Traits> &operator=(const ObjectAllocator<T, Traits> &) = default;
	ObjectAllocator<T, Traits> &operator=(ObjectAllocator<T, Traits> &&) = default;

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

}}}

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename T, typename Traits>
template<typename ...Args>
typename ObjectAllocator<T, Traits>::Pointer
ObjectAllocator<T, Traits>::construct(Args &&...args) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		emplaceNew<Type>(pointer, forward<decltype(args)>(args)...);
	return pointer;
}

template<typename T, typename Traits>
typename ObjectAllocator<T, Traits>::Pointer
ObjectAllocator<T, Traits>::construct(
		typename ObjectAllocator<T, Traits>::MoveReference obj) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		placementNew<Type>(pointer, obj);
	return pointer;
}

template<typename T, typename Traits>
typename ObjectAllocator<T, Traits>::Pointer
ObjectAllocator<T, Traits>::construct(typename ObjectAllocator<T, Traits>::ConstReference obj) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type)))
	);
	if (pointer)
		emplaceNew<Type>(pointer, obj);
	return pointer;
}

template<typename T, typename Traits>
void ObjectAllocator<T, Traits>::destroy(
		typename ObjectAllocator<T, Traits>::Pointer &pointer) noexcept
{
	(*pointer).~T();
	this->deallocate(pointer);
	pointer = nullptr;
}

}}}

#endif // TEMPLATES_ALLOCATOR_OBJECT_ALLOCATOR_HPP
