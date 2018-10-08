#ifndef TEMPLATES_INTEGERITERATOR_HPP
#define TEMPLATES_INTEGERITERATOR_HPP

#include <Common/PrimitiveTypes.hpp>
#include <Templates/Iterator.hpp>

// macroses

#define OPERATOR_INC_PREFIX \
Me &operator++() \
{ \
	++this->wrappedIterator; \
	return *this; \
}

#define OPERATOR_INC_POSTFIX \
Me operator++(int) \
{ \
	auto copy = *this;\
	++this->wrappedIterator; \
	return copy; \
}

#define OPERATOR_DEC_PREFIX \
Me &operator--() \
{ \
	--this->wrappedIterator; \
	return *this; \
}

#define OPERATOR_DEC_POSTFIX \
Me operator--(int) \
{ \
	auto copy = *this; \
	--this->wrappedIterator; \
	return copy; \
}

#define OPERATOR_DEREF \
typename Traits::Reference operator*() \
{ \
	return (this->wrappedIterator); \
}

#define OPERATOR_ARROW \
typename Traits::Pointer operator->() \
{ \
	return &(this->wrappedIterator); \
}

#define OPERATOR_DEREF_CONST \
typename Traits::ConstReference operator*() const \
{ \
	return (this->wrappedIterator); \
}

#define OPERATOR_ARROW_CONST \
typename Traits::PointerToConst operator->() const \
{ \
	return &(this->wrappedIterator); \
}

#define OPERATOR_PLUS \
template<typename IntType> Me operator+(IntType value) \
{ \
	Me copy = *this; \
	copy += value; \
	return copy; \
} \
\
template<typename IntType> \
friend Me operator+(IntType value, const Me &iterator) \
{ \
	return iterator + value; \
}

#define OPERATOR_MINUS \
template<typename IntType> Me operator-(IntType value) \
{ \
	Me copy = *this; \
	copy -= value; \
	return copy; \
} \
\
typename Traits::SsizeType operator-(const Me &iterator) \
{ \
	return static_cast<Traits::SsizeType>(this->wrappedIterator - iterator.wrappedIterator); \
}

#define OPERATOR_PLUS_ASSIGN \
template<typename IntType> Me &operator+=(IntType value) \
{ \
	this->wrappedIterator += value; \
	return *this; \
}

#define OPERATOR_MINUS_ASSIGN \
template<typename IntType> Me &operator-=(IntType value) \
{ \
	this->wrappedIterator -= value; \
	return *this; \
}

#define OPERATOR_PLUS_REVERSED \
template<typename IntType> Me operator+(IntType value) \
{ \
	Me copy = *this; \
	copy += value; \
	return copy; \
} \
\
template<typename IntType> \
friend Me operator+(IntType value, const Me &iterator) \
{ \
	return iterator + value; \
}

#define OPERATOR_MINUS_REVERSED \
template<typename IntType> Me operator-(IntType value) \
{ \
	Me copy = *this; \
	copy -= value; \
	return copy; \
} \
\
typename Traits::SsizeType operator-(const Me &iterator) \
{ \
	return this->wrappedIterator - iterator.wrappedIterator; \
}

#define OPERATOR_PLUS_ASSIGN_REVERSED \
template<typename IntType> Me &operator+=(IntType value) \
{ \
	this->wrappedIterator -= value; \
	return *this; \
}

#define OPERATOR_MINUS_ASSIGN_REVERSED \
template<typename IntType> Me &operator-=(IntType value) \
{ \
	this->wrappedIterator += value; \
	return *this; \
}

#define OPERATOR_MORE \
bool operator>(const Me &iterator) \
{ \
	return this->wrappedIterator > iterator.wrappedIterator; \
}

#define OPERATOR_LESS \
bool operator<(const Me &iterator) \
{ \
	return this->wrappedIterator < iterator.wrappedIterator; \
}

#define OPERATOR_MORE_EQUAL \
bool operator>=(const Me &iterator) \
{ \
	return this->wrappedIterator >= iterator.wrappedIterator; \
}

#define OPERATOR_LESS_EQUAL \
bool operator<=(const Me &iterator) \
{ \
	return this->wrappedIterator <= iterator.wrappedIterator; \
}

#define OPERATOR_OFFSET_DEREF \
template<typename IntType> \
typename Traits::Reference operator[](IntType value) \
{ \
	return this->wrappedIterator + value; \
}

#define OPERATOR_OFFSET_DEREF_CONST \
template<typename IntType> \
typename Traits::ConstReference operator[](IntType value) \
{ \
	return this->wrappedIterator + value; \
}

#define OPERATOR_MORE_REVERSED \
bool operator>(const Me &iterator) \
{ \
	return this->wrappedIterator <= iterator.wrappedIterator; \
}

#define OPERATOR_LESS_REVERSED \
bool operator<(const Me &iterator) \
{ \
	return this->wrappedIterator >= iterator; \
}

#define OPERATOR_MORE_EQUAL_REVERSED \
bool operator>=(const Me &iterator) \
{ \
	return this->wrappedIterator < iterator.wrappedIterator; \
}

#define OPERATOR_LESS_EQUAL_REVERSED \
bool operator<=(const Me &iterator) \
{ \
	return this->wrappedIterator > iterator.wrappedIterator; \
}

#define OPERATOR_OFFSET_DEREF_REVERSED \
template<typename IntType> \
typename Traits::Reference operator[](IntType value) \
{ \
	return *(this->wrappedIterator - value); \
}

#define OPERATOR_OFFSET_DEREF_CONST_REVERSED \
template<typename IntType> \
typename Traits::ConstReference operator[](IntType value) const \
{ \
	return *(this->wrappedIterator - value); \
}

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
> : public iterator_utils::BaseIterator< \
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
	OPERATOR_INC_PREFIX \
	OPERATOR_INC_POSTFIX \
\
	OPERATOR_DEREF \
	OPERATOR_ARROW \
\
	OPERATOR_DEREF_CONST \
	OPERATOR_ARROW_CONST \
\
	OPERATOR_PLUS \
	OPERATOR_MINUS \
\
	OPERATOR_PLUS_ASSIGN \
	OPERATOR_MINUS_ASSIGN \
\
	OPERATOR_MORE \
	OPERATOR_LESS \
\
	OPERATOR_MORE_EQUAL \
	OPERATOR_LESS_EQUAL \
\
	OPERATOR_OFFSET_DEREF \
	OPERATOR_OFFSET_DEREF_CONST \
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

#endif // TEMPLATES_INTEGERITERATOR_HPP
