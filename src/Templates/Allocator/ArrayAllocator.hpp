#ifndef TEMPLATES_ALLOCATOR_ARRAY_ALLOCATOR_HPP
#define TEMPLATES_ALLOCATOR_ARRAY_ALLOCATOR_HPP

#include <Templates/Allocator/MallocAllocator.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

///
/// @brief Allocator for create and delete arrays
///
/// @tparam T
/// Concrete type of objects
/// @tparam Traits
/// View flame_ide::ContainerTraits
///
template<typename T, typename Traits = flame_ide::ContainerTraits<T>, typename BaseAllocatorImpl = MallocAllocator<Traits>>
class ArrayAllocator: protected BaseAllocatorImpl
{
public:
	using Parent = BaseAllocatorImpl;
	using typename Parent::VoidPointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;
	using typename Parent::Type;
	using typename Parent::Pointer;
	using Me = ArrayAllocator<T, Traits, BaseAllocatorImpl>;

	ArrayAllocator() = default;
	ArrayAllocator(const Me &) = default;
	ArrayAllocator(Me &&) = default;
	~ArrayAllocator() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	///
	/// @brief Allocate array and initialize cells by need constructor
	///
	/// @tparam Args
	/// Argumet types for constructor calling
	///
	/// @param count
	/// Count need elemets in array
	/// @param ...args
	/// List of arguments for constructor
	///
	/// @return Pointer to first member of array
	///
	template<typename ...Args>
	Pointer construct(SizeType count, Args &&...args) noexcept;

	///
	/// @brief createArray
	/// @param count
	/// @return
	///
	Pointer createArray(SizeType count);

	///
	/// @brief reallocateArray
	/// @param count
	/// @return
	///
	Pointer reallocateArray(Pointer pointer, SizeType count);

	///
	/// @brief Call destructors and free memory in array
	///
	/// @param pointer
	/// Pointer to first member of array
	/// @param count
	/// Count exist elemets in array
	///
	void destroy(Pointer &pointer, SizeType count) noexcept;

	///
	/// @brief freeArray
	/// @param pointer
	///
	void freeArray(Pointer pointer);

private:
	using Parent::allocate;
	using Parent::deallocate;
};

}}}

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename T, typename Traits, typename BaseAllocatorImpl>
template<typename ...Args>
typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ArrayAllocator<T, Traits, BaseAllocatorImpl>::construct(
		typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::SizeType count
		, Args &&...args) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type) * count))
	);
	if (pointer)
	{
		for (Pointer iterator = pointer; SizeType(iterator - pointer) < count;
				++iterator)
			emplaceNew<Type>(iterator, forward<decltype(args)>(args)...);
	}
	return pointer;
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ArrayAllocator<T, Traits, BaseAllocatorImpl>::createArray(SizeType count)
{
	return reinterpret_cast<Pointer>(this->allocate(SizeType(sizeof(Type) * count)));
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer
ArrayAllocator<T, Traits, BaseAllocatorImpl>::reallocateArray(
		typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer pointer
		, SizeType count)
{
	return reinterpret_cast<Pointer>(
			this->reallocate(
					VoidPointer(pointer), SizeType(sizeof(Type) * count)
			)
	);
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
void ArrayAllocator<T, Traits, BaseAllocatorImpl>::destroy(
		typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer &pointer
		, typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::SizeType count) noexcept
{
	for (Pointer iterator = pointer; SizeType(iterator - pointer) < count; ++iterator)
		(*iterator).~T();
	this->deallocate(pointer);
	pointer = nullptr;
}

template<typename T, typename Traits, typename BaseAllocatorImpl>
void ArrayAllocator<T, Traits, BaseAllocatorImpl>::freeArray(
		typename ArrayAllocator<T, Traits, BaseAllocatorImpl>::Pointer pointer)
{
	this->deallocate(pointer);
}

}}}

#endif // TEMPLATES_ALLOCATOR_ARRAY_ALLOCATOR_HPP
