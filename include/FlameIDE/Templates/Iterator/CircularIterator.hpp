#ifndef FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>
#include <FlameIDE/Templates/Iterator/BaseIterator.hpp>

namespace flame_ide
{namespace templates
{

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY =
			iterator_utils::GetIteratorInfo<IteratorType>::CATEGORY
	, typename Traits = typename iterator_utils::IteratorTraits<IteratorType>
	, typename MetaType = void
>
class CircularIterator;

}}

namespace flame_ide
{namespace templates
{

template<
	typename IteratorType
	, typename Traits
	, typename MetaType
>
class CircularIterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::FORWARD, IteratorAccess::NON_CONSTANT
			, Traits, MetaType
		>
{
public:
private:
};

template<
	typename IteratorType
	, typename Traits
	, typename MetaType
>
class CircularIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT
			, Traits, MetaType
		>
{
public:
private:
};

template<
	typename IteratorType
	, typename Traits
	, typename MetaType
>
class CircularIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT
			, Traits, MetaType
		>
{
public:
private:
};

}}

#endif // FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP
