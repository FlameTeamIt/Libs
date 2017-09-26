#ifndef TEMPLATES_ALLOCATOR_HPP
#define TEMPLATES_ALLOCATOR_HPP

#include <malloc.h>

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

/**
 * @brief Base interface for allocators
 *
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 */
template<typename Traits = flame_ide::templates::SizeTraits>
class BaseAllocator
{
public:
	using SizeType = typename Traits::SizeType;
	using VoidPointer = void *;

	BaseAllocator() = default;
	BaseAllocator(const BaseAllocator &) = default;
	BaseAllocator(BaseAllocator &&) = default;
	~BaseAllocator() = default;
	BaseAllocator &operator=(const BaseAllocator &) = default;
	BaseAllocator &operator=(BaseAllocator &&) = default;

	/**
	 * @brief Non-virtual interface for allocation
	 *
	 * @param size
	 * Count bytes
	 *
	 * @return Raw pointer to allocated memory or nullptr
	 */
	inline VoidPointer allocate(SizeType size) noexcept
	{
		return vAllocate(size);
	}

	/**
	 * @brief Non-virtual interface for freeing
	 *
	 * @param pointer
	 * Pointer to raw memory
	 */
	inline void deallocate(VoidPointer pointer) noexcept
	{
		vDeallocate(pointer);
	}

protected:
	/**
	 * @brief Virtual function for allocation
	 *
	 * @param size
	 * Count bytes
	 *
	 * @return Raw pointer to allocated memory or nullptr
	 */
	virtual VoidPointer vAllocate(SizeType size) noexcept = 0;

	/**
	 * @brief Virtual function for freeing
	 *
	 * @param pointer
	 * Pointer to raw memry
	 */
	virtual void vDeallocate(VoidPointer pointer) noexcept = 0;
};

/**
 * @brief Allocator, using malloc() as base function
 *
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 */
template<typename Traits = flame_ide::templates::SizeTraits>
class MallocAllocator: public BaseAllocator<Traits>
{
public:
	using ParentType = BaseAllocator<Traits>;
	using VoidPointer = typename BaseAllocator<Traits>::VoidPointer;
	using SizeType = typename BaseAllocator<Traits>::SizeType;

	MallocAllocator() = default;
	MallocAllocator(const MallocAllocator<Traits> &) = default;
	MallocAllocator(MallocAllocator<Traits> &&) = default;
	~MallocAllocator() = default;
	MallocAllocator &operator=(const MallocAllocator<Traits> &) = default;
	MallocAllocator &operator=(MallocAllocator<Traits> &&) = default;

protected:
	/**
	 * @brief Low-level function for allocate raw memory. Using malloc()
	 *
	 * @param size
	 * Count need bytes
	 *
	 * @return Pointer to raw memory or nullptr
	 */
	virtual VoidPointer vAllocate(typename Traits::SizeType size) noexcept;

	/**
	 * @brief Low-level function for deallocate raw memory. Using free()
	 *
	 * @param pointer
	 * Pointer to raw memory or nullptr
	 */
	virtual void vDeallocate(VoidPointer pointer) noexcept;
};

/**
 * @brief Simple allocator for construct and destruct objects
 *
 * @tparam T
 * Concrete type of objects
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 */
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class ObjectAllocator: protected MallocAllocator<Traits>
{
public:
	using ParentType = MallocAllocator<Traits>;
	using VoidPointer = typename MallocAllocator<Traits>::VoidPointer;
	using SizeType = typename MallocAllocator<Traits>::SizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;

	ObjectAllocator() = default;
	ObjectAllocator(const ObjectAllocator<T, Traits> &) = default;
	ObjectAllocator(ObjectAllocator<T, Traits> &&) = default;
	~ObjectAllocator() = default;
	ObjectAllocator<T, Traits> &operator=(const ObjectAllocator<T, Traits> &) = default;
	ObjectAllocator<T, Traits> &operator=(ObjectAllocator<T, Traits> &&) = default;

	/**
	 * @brief Function for create object, using custom constructor
	 *
	 * @tparam Args
	 * Argumet types for constructor
	 *
	 * @param args
	 * List of arguments for calling contructor
	 *
	 * @return Pointer to new object
	 */
	template<typename ...Args>
	Pointer construct(Args &&...args) noexcept;

	/**
	 * @brief Function for destruct object
	 *
	 * @param pointer
	 * Pointer to object which can be removed
	 */
	void destroy(Pointer &pointer) noexcept;
};

/**
 * @brief Allocator for create and delete arrays
 *
 * @tparam T
 * Concrete type of objects
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 */
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class ArrayAllocator: protected MallocAllocator<Traits>
{
public:
	using ParentType = MallocAllocator<Traits>;
	using VoidPointer = typename MallocAllocator<Traits>::VoidPointer;
	using SizeType = typename MallocAllocator<Traits>::SizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;

	ArrayAllocator() = default;
	ArrayAllocator(const ArrayAllocator<T, Traits> &) = default;
	ArrayAllocator(ArrayAllocator<T, Traits> &&) = default;
	~ArrayAllocator() = default;
	ArrayAllocator<T, Traits> &operator=(const ArrayAllocator<T, Traits> &) = default;
	ArrayAllocator<T, Traits> &operator=(ArrayAllocator<T, Traits> &&) = default;

	/**
	 * @brief Allocate array and initialize cells by need constructor
	 *
	 * @tparam Args
	 * Argumet types for constructor calling
	 *
	 * @param count
	 * Count need elemets in array
	 * @param ...args
	 * List of arguments for constructor
	 *
	 * @return Pointer to first member of array
	 */
	template<typename ...Args>
	Pointer construct(SizeType count, Args &&...args) noexcept;

	/**
	 * @brief createArray
	 * @param count
	 * @return
	 */
	Pointer createArray(SizeType count);

	/**
	 * @brief Call destructors and free memory in array
	 *
	 * @param pointer
	 * Pointer to first member of array
	 * @param count
	 * Count exist elemets in array
	 */
	void destroy(Pointer &pointer, SizeType count) noexcept;

	/**
	 * @brief freeArray
	 * @param pointer
	 */
	void freeArray(Pointer pointer);

private:
	using ParentType::allocate;
	using ParentType::deallocate;
};

/**
 * @brief Stack strategy allocation
 *
 * @tparam T
 * Concrete type of objects
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 *
 * @warning Finish me!
 */
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class StackAllocator: protected BaseAllocator<Traits>
{};

/**
 * @brief Object pool strategy allocation
 *
 * @tparam T
 * Concrete type of objects
 *
 * @tparam Traits
 * View flame_ide::templates::ContainerTraits
 *
 * @warning Finish me!
 */
template<typename T, typename Traits = flame_ide::templates::ContainerTraits<T>>
class PoolAllocator: protected BaseAllocator<Traits>
{};

}}}

namespace flame_ide
{namespace templates
{namespace allocator
{


// MallocAllocator

template<typename Traits>
typename MallocAllocator<Traits>::VoidPointer
MallocAllocator<Traits>::vAllocate(typename Traits::SizeType size) noexcept
{
	return malloc(size);
}

template<typename Traits>
void MallocAllocator<Traits>::vDeallocate(MallocAllocator<Traits>::VoidPointer pointer) noexcept
{
	free(pointer);
}

// ObjectAllocator

template<typename T, typename Traits>
template<typename ...Args>
typename ObjectAllocator<T, Traits>::Pointer
ObjectAllocator<T, Traits>::construct(Args &&...args) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type))));
	if (pointer)
		placementNew<Type>(pointer, forward<decltype(args)>(args)...);
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

// ArrayAllocator

template<typename T, typename Traits>
template<typename ...Args>
typename ArrayAllocator<T, Traits>::Pointer
ArrayAllocator<T, Traits>::construct(
		typename ArrayAllocator<T, Traits>::SizeType count
		, Args &&...args) noexcept
{
	Pointer pointer = reinterpret_cast<Pointer>(
			this->allocate(SizeType(sizeof(Type) * count)));
	if (pointer)
	{
		for (Pointer iterator = pointer; SizeType(iterator - pointer) < count; ++iterator)
			placementNew<Type>(iterator, forward(args)...);
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
void ArrayAllocator<T, Traits>::destroy(
		typename ArrayAllocator<T, Traits>::Pointer &pointer
		, typename ArrayAllocator<T, Traits>::SizeType count) noexcept
{
	for (Pointer iterator = pointer; iterator - pointer < SizeTraits::SsizeType(count); ++iterator)
		(*iterator).~T();
	deallocate(pointer);
	pointer = nullptr;
}

template<typename T, typename Traits>
void ArrayAllocator<T, Traits>::freeArray(
		typename ArrayAllocator<T, Traits>::Pointer pointer)
{
	this->deallocate(pointer);
}

}}}

#endif // TEMPLATES_ALLOCATOR_HPP
