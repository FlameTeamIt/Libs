#ifndef FLAMEIDE_TEMPLATES_INTEGERITERATOR_HPP
#define FLAMEIDE_TEMPLATES_INTEGERITERATOR_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>

#include <FlameIDE/Templates/Iterator/Operators.hpp>

// define

namespace flame_ide
{namespace templates
{

// signed

#define GENERATE_ITERATOR_DEFINE(CURRENT_ITERATOR_TYPE) \
template<> \
class Iterator< \
	CURRENT_ITERATOR_TYPE \
	, templates::IteratorCategory::RANDOM_ACCESS \
	, ContainerTraits<CURRENT_ITERATOR_TYPE> \
	, CURRENT_ITERATOR_TYPE \
>;

GENERATE_ITERATOR_DEFINE(Types::ichar_t)
GENERATE_ITERATOR_DEFINE(Types::short_t)
GENERATE_ITERATOR_DEFINE(Types::int_t)
GENERATE_ITERATOR_DEFINE(Types::long_t)

GENERATE_ITERATOR_DEFINE(Types::uichar_t)
GENERATE_ITERATOR_DEFINE(Types::ushort_t)
GENERATE_ITERATOR_DEFINE(Types::uint_t)
GENERATE_ITERATOR_DEFINE(Types::ulong_t)

#define GENERATE_ITERATOR_TYPEDEF(NAME, TYPE) \
using NAME = Iterator< \
	TYPE, templates::IteratorCategory::RANDOM_ACCESS \
	, ContainerTraits<TYPE>, TYPE \
>;

GENERATE_ITERATOR_TYPEDEF(IcharIterator, Types::ichar_t)
GENERATE_ITERATOR_TYPEDEF(ShortIterator, Types::short_t)
GENERATE_ITERATOR_TYPEDEF(IntIterator, Types::int_t)
GENERATE_ITERATOR_TYPEDEF(LongIterator, Types::long_t)

GENERATE_ITERATOR_TYPEDEF(UicharIterator, Types::uichar_t)
GENERATE_ITERATOR_TYPEDEF(UshortIterator, Types::ushort_t)
GENERATE_ITERATOR_TYPEDEF(UintIterator, Types::uint_t)
GENERATE_ITERATOR_TYPEDEF(UlongIterator, Types::ulong_t)

GENERATE_ITERATOR_TYPEDEF(SizeTypeIterator, SizeTraits::SizeType)
GENERATE_ITERATOR_TYPEDEF(SsizeTypeIterator, SizeTraits::SsizeType)

}}

// implementation

namespace flame_ide
{namespace templates
{

#define GENERATE_ITERATOR_IMPL(CURRENT_ITERATOR_TYPE) \
template<> \
class Iterator< \
	CURRENT_ITERATOR_TYPE \
	, templates::IteratorCategory::RANDOM_ACCESS \
	, ContainerTraits<CURRENT_ITERATOR_TYPE> \
	, CURRENT_ITERATOR_TYPE \
>: public iterator_utils::BaseIterator< \
		CURRENT_ITERATOR_TYPE \
		, IteratorCategory::RANDOM_ACCESS \
		, IteratorAccess::NON_CONSTANT \
		, ContainerTraits<CURRENT_ITERATOR_TYPE> \
		, CURRENT_ITERATOR_TYPE \
	> \
{ \
public: \
	using Parent = iterator_utils::BaseIterator< \
		CURRENT_ITERATOR_TYPE \
		, IteratorCategory::RANDOM_ACCESS \
		, IteratorAccess::NON_CONSTANT \
		, ContainerTraits<CURRENT_ITERATOR_TYPE> \
		, CURRENT_ITERATOR_TYPE \
	>; \
	using Me = Iterator< \
		CURRENT_ITERATOR_TYPE \
		, templates::IteratorCategory::RANDOM_ACCESS \
		, ContainerTraits<CURRENT_ITERATOR_TYPE> \
		, CURRENT_ITERATOR_TYPE \
	>; \
	using Traits = ContainerTraits<CURRENT_ITERATOR_TYPE>; \
\
	Iterator(const Me &) = default; \
	Iterator(CURRENT_ITERATOR_TYPE iterator) : Parent(iterator) \
	{} \
	~Iterator() = default; \
	Me& operator=(const Me &) = default; \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_PREFIX \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_POSTFIX \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF_CONST \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW_CONST \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_ASSIGN \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_ASSIGN \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_EQUAL \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_EQUAL \
\
	FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF \
	FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_CONST \
\
private: \
	using BaseIterator::wrappedIterator; \
};

GENERATE_ITERATOR_IMPL(Types::ichar_t)
GENERATE_ITERATOR_IMPL(Types::short_t)
GENERATE_ITERATOR_IMPL(Types::int_t)
GENERATE_ITERATOR_IMPL(Types::long_t)

GENERATE_ITERATOR_IMPL(Types::uichar_t)
GENERATE_ITERATOR_IMPL(Types::ushort_t)
GENERATE_ITERATOR_IMPL(Types::uint_t)
GENERATE_ITERATOR_IMPL(Types::ulong_t)

}}

#include <FlameIDE/Templates/Iterator/UndefOperators.hpp>

#endif // FLAMEIDE_TEMPLATES_INTEGERITERATOR_HPP
