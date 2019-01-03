#ifndef FLAMEIDE_TEMPLATES_ITERATOR_CONSTITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_CONSTITERATOR_HPP

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>
#include <FlameIDE/Templates/Iterator/BaseIterator.hpp>

#include <FlameIDE/Templates/Iterator/Operators.hpp>

namespace flame_ide
{namespace templates
{

template<typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY =
			iterator_utils::GetIteratorInfo<IteratorType>::CATEGORY
	, typename Traits = typename iterator_utils::IteratorTraits<IteratorType>
	, typename MetaType = void>
class ConstIterator;

}}

namespace flame_ide
{namespace templates
{

template<typename IteratorType, typename Traits, typename MetaType>
class ConstIterator<IteratorType, IteratorCategory::OUTPUT, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::OUTPUT, IteratorAccess::CONSTANT, Traits, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType
		, IteratorCategory::OUTPUT
		, IteratorAccess::CONSTANT
		, Traits
		, MetaType
	>;
	using Me = ConstIterator<IteratorType, IteratorCategory::OUTPUT, Traits, MetaType>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class ConstIterator<IteratorType, IteratorCategory::INPUT, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::INPUT, IteratorAccess::CONSTANT, Traits, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType
		, IteratorCategory::INPUT
		, IteratorAccess::CONSTANT
		, Traits
		, MetaType
	>;
	using Me = ConstIterator<IteratorType, IteratorCategory::INPUT, Traits, MetaType>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class ConstIterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::FORWARD, IteratorAccess::CONSTANT, Traits, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType
		, IteratorCategory::FORWARD
		, IteratorAccess::CONSTANT
		, Traits
		, MetaType
	>;
	using Me = ConstIterator<IteratorType, IteratorCategory::FORWARD, Traits, MetaType>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class ConstIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::BIDIRECTIONAL, IteratorAccess::CONSTANT, Traits
			, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, IteratorAccess::CONSTANT
		, Traits, MetaType
	>;
	using Me = ConstIterator<
		IteratorType, IteratorCategory::BIDIRECTIONAL, Traits, MetaType
	>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST
	FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits, typename MetaType>
class ConstIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType>:
		public iterator_utils::BaseIterator<IteratorType
			, IteratorCategory::RANDOM_ACCESS, IteratorAccess::CONSTANT, Traits
			, MetaType>
{
public:
	using Parent = iterator_utils::BaseIterator<
		IteratorType
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::CONSTANT
		, Traits, MetaType
	>;
	using Me = ConstIterator<
		IteratorType, IteratorCategory::RANDOM_ACCESS, Traits, MetaType
	>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX

	FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX
	FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX

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

	FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

}}

#include <FlameIDE/Templates/Iterator/UndefOperators.hpp>

#endif // FLAMEIDE_TEMPLATES_ITERATOR_CONSTITERATOR_HPP
