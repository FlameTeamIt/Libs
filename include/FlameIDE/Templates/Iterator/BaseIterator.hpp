#ifndef FLAMEIDE_TEMPLATES_ITERATOR_BASEITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_BASEITERATOR_HPP

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>

namespace flame_ide
{namespace templates
{namespace iterator_utils
{

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType = void
>
class BaseIterator
{
public:
	using Me = BaseIterator<
		IteratorType
		, ITERATOR_CATEGORY
		, ITERATOR_ACCESS
		, Traits
		, MetaType
	>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SsizeType = typename Traits::SsizeType;

	BaseIterator() = default;
	BaseIterator(const Me &) = default;
	~BaseIterator() = default;
	Me &operator=(const Me &) = default;

	bool operator==(const Me &iterator)
	{
		return wrappedIterator == iterator.wrappedIterator;
	}

	bool operator!=(const Me &iterator)
	{
		return wrappedIterator != iterator.wrappedIterator;
	}

	IteratorType &internalData()
	{
		return wrappedIterator;
	}

	const IteratorType &internalData() const
	{
		return wrappedIterator;
	}

	static constexpr IteratorCategory CATEGORY = ITERATOR_CATEGORY;
	static constexpr IteratorAccess ACCESS = ITERATOR_ACCESS;

protected:
	using WrappedIterator = IteratorType;

	BaseIterator(const IteratorType &iteratorInit) : wrappedIterator(iteratorInit)
	{}

	BaseIterator(IteratorType &&iteratorInit) : wrappedIterator(move(iteratorInit))
	{}

	mutable WrappedIterator wrappedIterator;
};

}}}

#endif // FLAMEIDE_TEMPLATES_ITERATOR_BASEITERATOR_HPP

