#ifndef FLAMEIDE_TEMPLATES_ITERATOR_ITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_ITERATOR_HPP

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
class Iterator;

namespace defaults
{

template<typename IteratorType>
using OutputIterator = Iterator<IteratorType, IteratorCategory::OUTPUT>;

template<typename IteratorType>
using InputIterator = Iterator<IteratorType, IteratorCategory::INPUT>;

template<typename IteratorType>
using ForwardIterator = Iterator<IteratorType, IteratorCategory::FORWARD>;

template<typename IteratorType>
using BidirectionalIterator = Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL>;

template<typename IteratorType>
using RandomAccessIterator = Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS>;

} // namespace defaults

}} // namespace flame_ide::templates

namespace flame_ide
{namespace templates
{

template<typename IteratorType, typename Traits, typename MetaType>
class Iterator<IteratorType, IteratorCategory::OUTPUT, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::OUTPUT, IteratorAccess::NON_CONSTANT, Traits, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::OUTPUT, IteratorAccess::NON_CONSTANT, Traits, MetaType
	>;
	using Me = Iterator<IteratorType, IteratorCategory::OUTPUT, Traits, MetaType>;

	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW

protected:
	using Parent::internalData;
private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class Iterator<IteratorType, IteratorCategory::INPUT, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::INPUT, IteratorAccess::NON_CONSTANT, Traits, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::INPUT, IteratorAccess::NON_CONSTANT, Traits, MetaType
	>;
	using Me = Iterator<IteratorType, IteratorCategory::INPUT, Traits, MetaType>;

	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

protected:
	using Parent::internalData;
private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class Iterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::FORWARD, IteratorAccess::NON_CONSTANT, Traits, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::FORWARD, IteratorAccess::NON_CONSTANT, Traits, MetaType
	>;
	using Me = Iterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW
	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

protected:
	using Parent::internalData;
private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT, Traits
			, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT
		, Traits, MetaType
	>;
	using Me = Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW
	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

protected:
	using Parent::internalData;
private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>:
		public iterator_utils::BaseIterator<
			IteratorType, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT, Traits
			, MetaType
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT
		, Traits, MetaType
	>;
	using Me = Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_ARROW
	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST
	FLAMEIDE_ITERATOR_OPERATOR_PLUS
	FLAMEIDE_ITERATOR_OPERATOR_MINUS
	FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN
	FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN
	FLAMEIDE_ITERATOR_OPERATOR_MORE
	FLAMEIDE_ITERATOR_OPERATOR_LESS
	FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL
	FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL
	FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF
	FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST

protected:
	using Parent::internalData;
private:
	using Parent::wrappedIterator;
};

}} // namespace flame_ide::templates

#include <FlameIDE/Templates/Iterator/UndefOperators.hpp>

#endif // FLAMEIDE_TEMPLATES_ITERATOR_ITERATOR_HPP
