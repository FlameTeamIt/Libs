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

	static constexpr IteratorCategory CATEGORY = ITERATOR_CATEGORY;
	static constexpr IteratorAccess ACCESS = ITERATOR_ACCESS;

	BaseIterator() = default;
	BaseIterator(const Me &it) noexcept;
	BaseIterator(Me &&it) noexcept = default;

	~BaseIterator() noexcept = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

	bool operator==(const Me &iterator);
	bool operator!=(const Me &iterator);

	IteratorType &internalData();
	const IteratorType &internalData() const;

protected:
	using WrappedIterator = IteratorType;

	BaseIterator(const IteratorType &iteratorInit) : wrappedIterator(iteratorInit)
	{}

	BaseIterator(IteratorType &&iteratorInit) : wrappedIterator(move(iteratorInit))
	{}

	mutable WrappedIterator wrappedIterator;
};

}}} // namespace flame_ide::templates::iterator_utils

namespace flame_ide
{namespace templates
{namespace iterator_utils
{

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType
>
BaseIterator<IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType>::BaseIterator(
		const Me &it
) noexcept : wrappedIterator(it.wrappedIterator)
{}

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType
>
bool
BaseIterator<IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType>
::operator==(const Me &iterator)
{
	return wrappedIterator == iterator.wrappedIterator;
}

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType
>
bool
BaseIterator<IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType>::operator!=(
		const Me &iterator
)
{
	return wrappedIterator != iterator.wrappedIterator;
}

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType
>
IteratorType &
BaseIterator<IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType>::internalData()
{
	return wrappedIterator;
}

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType
>
const IteratorType &
BaseIterator<IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType>
::internalData() const
{
	return wrappedIterator;
}

}}} // namespace flame_ide::templates::iterator_utils

#endif // FLAMEIDE_TEMPLATES_ITERATOR_BASEITERATOR_HPP

