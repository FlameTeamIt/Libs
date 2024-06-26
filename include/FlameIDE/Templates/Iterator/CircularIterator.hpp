#ifndef FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP

#include <FlameIDE/Templates/Range.hpp>

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>

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
class CircularIterator;

namespace defaults
{

template<typename IteratorType>
using CircularForwardIterator = CircularIterator<
	IteratorType, IteratorCategory::FORWARD
>;

template<typename IteratorType>
using CircularBidirectionalIterator = CircularIterator<
	IteratorType, IteratorCategory::BIDIRECTIONAL
>;

template<typename IteratorType>
using CircularRandomAccessIterator = CircularIterator<
	IteratorType, IteratorCategory::RANDOM_ACCESS
>;

} // namespace defaults

}} // namespace flame_ide::templates

namespace flame_ide
{namespace templates
{

template<typename IteratorType, typename Traits, typename MetaType>
class CircularIterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>:
		public Iterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>
{
public:
	using Parent = Iterator<
		IteratorType, IteratorCategory::FORWARD, Traits, MetaType
	>;
	using Me = CircularIterator<
		IteratorType, IteratorCategory::FORWARD, Traits, MetaType
	>;
	using Range = templates::Range<IteratorType>;

	CircularIterator() noexcept = default;
	CircularIterator(const Me &) noexcept = default;
	CircularIterator(IteratorType iterator, Range containerActualRange) noexcept
			: Parent(iterator)
			, range(containerActualRange)
	{}
	~CircularIterator() noexcept = default;
	Me& operator=(const Me &) noexcept = default;
	Me& operator=(Me &&) noexcept = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_CIRCULARITERATOR_OPERATOR_INC_PREFIX

protected:
	using Parent::internalData;
private:
	mutable Range range;
};

template<typename IteratorType, typename Traits, typename MetaType>
class CircularIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>:
		public Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>
{
public:
	using Parent = Iterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType
	>;
	using Me = CircularIterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType
	>;
	using Range = templates::Range<IteratorType>;

	CircularIterator() noexcept = default;
	CircularIterator(const Me &) noexcept = default;
	CircularIterator(IteratorType iterator, Range containerActualRange)
			: Parent(iterator)
			, range(containerActualRange)
	{}
	~CircularIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX

	FLAMEIDE_CIRCULARITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_DEC_PREFIX

protected:
	using Parent::internalData;
private:
	mutable Range range;
};

template<typename IteratorType, typename Traits, typename MetaType>
class CircularIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>:
		public Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>
{
public:
	using Parent = Iterator<
		IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType
	>;
	using Me = CircularIterator<
		IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType
	>;
	using Range = templates::Range<IteratorType>;

	CircularIterator() noexcept = default;
	CircularIterator(const Me &) noexcept = default;
	CircularIterator(IteratorType iterator, Range containerActualRange)
			: Parent(iterator)
			, range(containerActualRange)
	{}
	~CircularIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_CIRCULARITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_DEC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_PLUS
	FLAMEIDE_ITERATOR_OPERATOR_MINUS
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_PLUS_ASSIGN
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_MINUS_ASSIGN
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_OFFSET_DEREF
	FLAMEIDE_CIRCULARITERATOR_OPERATOR_OFFSET_DEREF_CONST

protected:
	using Parent::internalData;
private:
	mutable Range range;
};

}} // namespace flame_ide::templates

#include <FlameIDE/Templates/Iterator/UndefOperators.hpp>

#endif // FLAMEIDE_TEMPLATES_ITERATOR_CIRCULARITERATOR_HPP
