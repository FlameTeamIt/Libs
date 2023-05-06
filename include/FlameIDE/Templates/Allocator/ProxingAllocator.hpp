#ifndef FLAMEIDE_TEMPLATES_ALLOCATOR_PROXINGLLOCATOR_HPP
#define FLAMEIDE_TEMPLATES_ALLOCATOR_PROXINGLLOCATOR_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <FlameIDE/Templates/Allocator/Interface.hpp>

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits>
class ProxingAllocator;

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits>
class ProxingAllocator: public BaseAllocator<Traits>
{
public:
	using Parent = BaseAllocator<Traits>;
	using Me = ProxingAllocator<Traits>;
	using typename Parent::SizeType;
	using typename Parent::VoidPointer;

	ProxingAllocator(Parent &proxiedAllocator);

protected:
	virtual VoidPointer vAllocate(SizeType size) noexcept override;
	virtual VoidPointer vReallocate(VoidPointer pointer, SizeType size) noexcept override;
	virtual void vDeallocate(VoidPointer pointer) noexcept override;
	virtual SizeType vMaxAllocateSize() const noexcept override;

private:
	Parent *proxiedAllocator;
};

}}} // namespace flame_ide::templates::allocator

namespace flame_ide
{namespace templates
{namespace allocator
{

template<typename Traits>
ProxingAllocator<Traits>::ProxingAllocator(Parent &proxiedAllocator) :
		proxiedAllocator{ &proxiedAllocator }
{}

template<typename Traits>
typename ProxingAllocator<Traits>::VoidPointer
ProxingAllocator<Traits>::vAllocate(SizeType size) noexcept
{
	return proxiedAllocator->allocate(size);
}

template<typename Traits>
typename ProxingAllocator<Traits>::VoidPointer
ProxingAllocator<Traits>::vReallocate(VoidPointer pointer, SizeType size) noexcept
{
	return proxiedAllocator->reallocate(pointer, size);
}

template<typename Traits>
void
ProxingAllocator<Traits>::vDeallocate(VoidPointer pointer) noexcept
{
	proxiedAllocator->deallocate(pointer);
}

template<typename Traits>
typename ProxingAllocator<Traits>::SizeType
ProxingAllocator<Traits>::vMaxAllocateSize() const noexcept
{
	return proxiedAllocator->maxAllocateSize();
}

}}} // namespace flame_ide::templates::allocator

#endif // FLAMEIDE_TEMPLATES_ALLOCATOR_PROXINGLLOCATOR_HPP
