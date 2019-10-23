#ifndef FLAMEIDE_TEMPLATES_ALLOCATOR_INTERFACE_HPP
#define FLAMEIDE_TEMPLATES_ALLOCATOR_INTERFACE_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

/// @brief Base interface for allocators
/// @tparam Traits See flame_ide::templates::ContainerTraits
template<typename SizeTraits = flame_ide::SizeTraits>
class BaseAllocator
{
public:
	using SizeType = typename SizeTraits::SizeType;
	using SsizeType = typename SizeTraits::SsizeType;
	using VoidPointer = void *;

	BaseAllocator() noexcept = default;
	BaseAllocator(const BaseAllocator &) noexcept = default;
	BaseAllocator(BaseAllocator &&) noexcept = default;
	virtual ~BaseAllocator() noexcept = default;
	BaseAllocator &operator=(const BaseAllocator &) noexcept = default;
	BaseAllocator &operator=(BaseAllocator &&) noexcept = default;

	/// @brief Non-virtual interface for allocation.
	/// @param size Count bytes.
	/// @return Raw pointer to allocated memory or nullptr.
	inline VoidPointer allocate(SizeType size) noexcept
	{
		return vAllocate(size);
	}

	/// @brief Non-virtual interface for reallocating
	/// @param pointer Pointer to raw memory
	inline VoidPointer reallocate(VoidPointer pointer, SizeType size) noexcept
	{
		return vReallocate(pointer, size);
	}

	/// @brief Non-virtual interface for freeing
	/// @param pointer Pointer to raw memory
	inline void deallocate(VoidPointer pointer) noexcept
	{
		vDeallocate(pointer);
	}

	/// @brief Non-virtual interface for getting max allocate size
	/// @return
	inline SizeType maxAllocateSize() const noexcept
	{
		return vMaxAllocateSize();
	}

protected:
	/// @brief Virtual function for allocation
	/// @param size Count bytes
	/// @return Raw pointer to allocated memory or nullptr
	virtual VoidPointer vAllocate(SizeType size) noexcept = 0;

	/// @brief Virtual function for reallocating memory
	/// @param pointer Pointer to raw memry
	/// @param size Count bytes
	/// @return Pointer to reallocated memory or nullptr
	virtual VoidPointer vReallocate(VoidPointer pointer, SizeType size) noexcept = 0;

	/// @brief Virtual function for freeing
	/// @param pointer Pointer to raw memry
	virtual void vDeallocate(VoidPointer pointer) noexcept = 0;

	/// @brief vMaxAllocateSize
	/// @return
	virtual SizeType vMaxAllocateSize() const noexcept = 0;
};

}}}

#endif // FLAMEIDE_TEMPLATES_ALLOCATOR_INTERFACE_HPP
