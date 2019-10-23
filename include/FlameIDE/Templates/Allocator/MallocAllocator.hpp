#ifndef FLAMEIDE_TEMPLATES_ALLOCATOR_MALLOC_ALLOCATOR_HPP
#define FLAMEIDE_TEMPLATES_ALLOCATOR_MALLOC_ALLOCATOR_HPP

#include <malloc.h>

#include <FlameIDE/Templates/Allocator/Interface.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

///
/// @brief Allocator, using malloc() as base function
///
/// @tparam Traits
/// View flame_ide::ContainerTraits
///
template<typename Traits = flame_ide::SizeTraits>
class MallocAllocator: public BaseAllocator<Traits>
{
public:
	using Parent = BaseAllocator<Traits>;
	using typename Parent::VoidPointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;

	MallocAllocator() = default;
	MallocAllocator(const MallocAllocator<Traits> &) = default;
	MallocAllocator(MallocAllocator<Traits> &&) noexcept = default;
	virtual ~MallocAllocator() = default;
	MallocAllocator &operator=(const MallocAllocator<Traits> &) = default;
	MallocAllocator &operator=(MallocAllocator<Traits> &&) noexcept = default;

protected:
	///
	/// @brief Low-level function for allocate raw memory. Using malloc()
	///
	/// @param size
	/// Count need bytes
	///
	/// @return Pointer to raw memory or nullptr
	///
	virtual VoidPointer vAllocate(typename Traits::SizeType size) noexcept;

	///
	/// @brief Low-level function for reallocate raw memory. Using realloc()
	///
	/// @param pointer Pointer to raw memry
	/// @param size Count bytes
	///
	/// @return Pointer to reallocated memory or nullptr
	///
	virtual VoidPointer vReallocate(VoidPointer pointer, typename Traits::SizeType size) noexcept;

	///
	/// @brief Low-level function for deallocate raw memory. Using free()
	///
	/// @param pointer
	/// Pointer to raw memory or nullptr
	///
	virtual void vDeallocate(VoidPointer pointer) noexcept;

	///
	/// @brief vMaxAllocateSize
	/// @return
	///
	virtual SizeType vMaxAllocateSize() const noexcept;
};

}}}

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits>
typename MallocAllocator<Traits>::VoidPointer
MallocAllocator<Traits>::vAllocate(typename Traits::SizeType size) noexcept
{
	return malloc(size);
}

template<typename Traits>
typename MallocAllocator<Traits>::VoidPointer
MallocAllocator<Traits>::vReallocate(typename MallocAllocator<Traits>::VoidPointer pointer
		, typename Traits::SizeType size) noexcept
{
	return realloc(pointer, size);
}

template<typename Traits>
void MallocAllocator<Traits>::vDeallocate(
		typename MallocAllocator<Traits>::VoidPointer pointer) noexcept
{
	free(pointer);
}

template<typename Traits>
typename MallocAllocator<Traits>::SizeType MallocAllocator<Traits>::vMaxAllocateSize() const noexcept
{
	return NumberLimit<SizeType>::MAX_VALUE;
}

}}}

#endif // FLAMEIDE_TEMPLATES_ALLOCATOR_MALLOC_ALLOCATOR_HPP
