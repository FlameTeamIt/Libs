#ifndef FLAMEIDE_TEMPLATES_STATICALLOCATOR_HPP
#define FLAMEIDE_TEMPLATES_STATICALLOCATOR_HPP

#include <FlameIDE/Templates/Allocator/Interface.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Range.hpp>

/*
 * Концепция статического аллокатора
 */

namespace flame_ide
{namespace templates
{namespace allocator
{

template<Types::size_t ALLOCATOR_CAPACITY, typename Traits = SizeTraits>
class StaticAllocator: public BaseAllocator<Traits>
{
public:
	using Me = StaticAllocator<ALLOCATOR_CAPACITY, Traits>;
	using Parent = BaseAllocator<Traits>;

	using SizeType = typename Parent::SizeType;
	using SsizeType = typename Parent::SsizeType;
	using VoidPointer = typename Parent::VoidPointer;

	StaticAllocator() noexcept = default;
	StaticAllocator(const Me &me) noexcept;
	StaticAllocator(Me &&me) noexcept;
	~StaticAllocator() noexcept;

private:
	using Iterator = templates::CircularIterator<
		Types::size_t *
		, IteratorCategory::RANDOM_ACCESS
	>;
	using Range = templates::Range<
		Iterator
	>;

	static constexpr SizeType FLAGS_SIZE = ALLOCATOR_CAPACITY % sizeof(Types::size_t)
			? ALLOCATOR_CAPACITY / sizeof(Types::size_t)
			: ALLOCATOR_CAPACITY / sizeof(Types::size_t) + 1;

	virtual VoidPointer vAllocate(SizeType size) noexcept
	{
		(void)size;
		return nullptr;
	}

	virtual VoidPointer vReallocate(VoidPointer pointer, SizeType size) noexcept
	{
		(void)pointer;
		(void)size;
		return nullptr;
	}

	virtual void vDeallocate(VoidPointer) noexcept
	{}

	virtual void vDeallocate(VoidPointer pointer, SizeType size) noexcept
	{
		(void)pointer;
		(void)size;
	}

	Range createBufferRange() noexcept
	{
		templates::Range<size_t *> range = makeRange(buffer, buffer + FLAGS_SIZE);
		Iterator itBegin(range.begin(), range);
		Iterator itEnd(range.end(), range);
		return Range(itBegin, itEnd);
	}

	Types::size_t buffer[FLAGS_SIZE];
	Types::uichar_t flags[FLAGS_SIZE]; ///< Флаги для определения занятости.
};

}}}

#endif // FLAMEIDE_TEMPLATES_STATICALLOCATOR_HPP
