#ifndef FLAMEIDE_TEMPLATES_ITERATOR_REVERSEITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_REVERSEITERATOR_HPP

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>
#include <FlameIDE/Templates/Iterator/BaseIterator.hpp>

#include <FlameIDE/Templates/Iterator/Operators.hpp>

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
class ReverseIterator;

}}

namespace flame_ide
{namespace templates
{

template<typename IteratorType, typename Traits, typename MetaType>
class ReverseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT, Traits, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT
		, Traits, MetaType
	>;
	using Me = ReverseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>;

	ReverseIterator(const Me &) = default;
	ReverseIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ReverseIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class ReverseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
			, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType
		, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT
		, Traits, MetaType
	>;
	using Me = ReverseIterator<
		IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType
	>;

	ReverseIterator(const Me &) = default;
	ReverseIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ReverseIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

	FLAMEIDE_ITERATOR_OPERATOR_PLUS_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_MINUS_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_MORE_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_LESS_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL_REVERSED

	FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_REVERSED
	FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST_REVERSED

private:
	using Parent::wrappedIterator;
};

}}

#include <FlameIDE/Templates/Iterator/UndefOperators.hpp>

#endif // FLAMEIDE_TEMPLATES_ITERATOR_REVERSEITERATOR_HPP
