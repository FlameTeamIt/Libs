#ifndef TEMPLATES_ALLOCATOR_INTERFACE_HPP
#define TEMPLATES_ALLOCATOR_INTERFACE_HPP

#include <Common/Traits.hpp>
#include <Common/Utils.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

///
/// @brief Base interface for allocators
///
/// @tparam Traits
/// View flame_ide::templates::ContainerTraits
///
template<typename Traits = flame_ide::SizeTraits>
class BaseAllocator: public Traits
{
public:
	using typename Traits::SizeType;
	using typename Traits::SsizeType;
	using VoidPointer = void *;

	BaseAllocator() = default;
	BaseAllocator(const BaseAllocator &) = default;
	BaseAllocator(BaseAllocator &&) = default;
	~BaseAllocator() = default;
	BaseAllocator &operator=(const BaseAllocator &) = default;
	BaseAllocator &operator=(BaseAllocator &&) = default;

	///
	/// @brief Non-virtual interface for allocation
	///
	/// @param size
	/// Count bytes
	///
	/// @return Raw pointer to allocated memory or nullptr
	///
	inline VoidPointer allocate(SizeType size) noexcept
	{
		return vAllocate(size);
	}

	///
	/// @brief Non-virtual interface for reallocating
	///
	/// @param pointer
	/// Pointer to raw memory
	///
	inline VoidPointer reallocate(VoidPointer pointer, SizeType size) noexcept
	{
		return vReallocate(pointer, size);
	}

	///
	/// @brief Non-virtual interface for freeing
	///
	/// @param pointer
	/// Pointer to raw memory
	///
	inline void deallocate(VoidPointer pointer) noexcept
	{
		vDeallocate(pointer);
	}

protected:
	///
	/// @brief Virtual function for allocation
	///
	/// @param size
	/// Count bytes
	///
	/// @return Raw pointer to allocated memory or nullptr
	///
	virtual VoidPointer vAllocate(SizeType size) noexcept = 0;

	///
	/// @brief Virtual function for reallocating memory
	///
	/// @param pointer Pointer to raw memry
	/// @param size Count bytes
	///
	/// @return Pointer to reallocated memory or nullptr
	///
	virtual VoidPointer vReallocate(VoidPointer pointer, SizeType size) noexcept = 0;

	///
	/// @brief Virtual function for freeing
	///
	/// @param pointer
	/// Pointer to raw memry
	///
	virtual void vDeallocate(VoidPointer pointer) noexcept = 0;
};

}}}

#endif // TEMPLATES_ALLOCATOR_INTERFACE_HPP
