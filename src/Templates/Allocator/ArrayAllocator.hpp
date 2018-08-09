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
/// View flame_ide::templates::ContainerTraits
///
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class ArrayAllocator: protected MallocAllocator<Traits>
{
public:
	using ParentType = MallocAllocator<Traits>;
	using VoidPointer = typename MallocAllocator<Traits>::VoidPointer;
	using SizeType = typename MallocAllocator<Traits>::SizeType;
	using SsizeType = typename MallocAllocator<Traits>::SsizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;

	ArrayAllocator() = default;
	ArrayAllocator(const ArrayAllocator<T, Traits> &) = default;
	ArrayAllocator(ArrayAllocator<T, Traits> &&) = default;
	~ArrayAllocator() = default;
	ArrayAllocator<T, Traits> &operator=(const ArrayAllocator<T, Traits> &) = default;
	ArrayAllocator<T, Traits> &operator=(ArrayAllocator<T, Traits> &&) = default;

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
	using ParentType::allocate;
	using ParentType::deallocate;
};

}}}

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename T, typename Traits>
template<typename ...Args>
typename ArrayAllocator<T, Traits>::Pointer
ArrayAllocator<T, Traits>::construct(
		typename ArrayAllocator<T, Traits>::SizeType count
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

template<typename T, typename Traits>
typename ArrayAllocator<T, Traits>::Pointer
ArrayAllocator<T, Traits>::createArray(SizeType count)
{
	return reinterpret_cast<Pointer>(this->allocate(SizeType(sizeof(Type) * count)));
}

template<typename T, typename Traits>
typename ArrayAllocator<T, Traits>::Pointer
ArrayAllocator<T, Traits>::reallocateArray(typename ArrayAllocator<T, Traits>::Pointer pointer,
		SizeType count)
{
	return reinterpret_cast<Pointer>(
			this->reallocate(
					VoidPointer(pointer), SizeType(sizeof(Type) * count)
			)
	);
}

template<typename T, typename Traits>
void ArrayAllocator<T, Traits>::destroy(
		typename ArrayAllocator<T, Traits>::Pointer &pointer
		, typename ArrayAllocator<T, Traits>::SizeType count) noexcept
{
	for (Pointer iterator = pointer; SizeType(iterator - pointer) < count; ++iterator)
		(*iterator).~T();
	this->deallocate(pointer);
	pointer = nullptr;
}

template<typename T, typename Traits>
void ArrayAllocator<T, Traits>::freeArray(
		typename ArrayAllocator<T, Traits>::Pointer pointer)
{
	this->deallocate(pointer);
}

}}}

#endif // TEMPLATES_ALLOCATOR_ARRAY_ALLOCATOR_HPP
