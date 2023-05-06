#ifndef FLAMEIDE_TEMPLATES_ALLOCATOR_STATICALLOCATOR_HPP
#define FLAMEIDE_TEMPLATES_ALLOCATOR_STATICALLOCATOR_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <FlameIDE/Templates/Allocator/Interface.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits, Types::ulong_t MEMORY_SIZE>
class StaticAllocator;

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits, Types::ulong_t MEMORY_SIZE>
class StaticAllocator: public BaseAllocator<Traits>
{
public:
	using Parent = BaseAllocator<Traits>;
	using typename Parent::SizeType;
	using typename Parent::VoidPointer;

protected:
	virtual VoidPointer vAllocate(SizeType size) noexcept override;
	virtual VoidPointer vReallocate(VoidPointer pointer, SizeType size) noexcept override;
	virtual void vDeallocate(VoidPointer pointer) noexcept override;
	virtual SizeType vMaxAllocateSize() const noexcept override;
};

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{

}}} // namespace flame_ide::templates::allocator

#endif // FLAMEIDE_TEMPLATES_ALLOCATOR_STATICALLOCATOR_HPP
