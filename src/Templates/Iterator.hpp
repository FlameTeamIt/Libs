#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include <Templates/Traits.hpp>

// defined classes and types

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

#define OPERATOR_INC_PREFIX_REVERSED \
Me &operator++() \
{ \
	--this->wrappedIterator; \
	return *this; \
}

#define OPERATOR_INC_POSTFIX_REVERSED \
Me operator++(int) \
{ \
	auto copy = *this;\
	--this->wrappedIterator; \
	return copy; \
}

#define OPERATOR_DEC_PREFIX_REVERSED \
Me &operator--() \
{ \
	++this->wrappedIterator; \
	return *this; \
}

#define OPERATOR_DEC_POSTFIX_REVERSED \
Me operator--(int) \
{ \
	auto copy = *this; \
	++this->wrappedIterator; \
	return copy; \
}

#define OPERATOR_DEREF \
typename Traits::Reference operator*() \
{ \
	return *(this->wrappedIterator); \
}

#define OPERATOR_ARROW \
typename Traits::Pointer operator->() \
{ \
	return &(*(this->wrappedIterator)); \
}

#define OPERATOR_DEREF_CONST \
typename Traits::ConstReference operator*() const \
{ \
	return *(this->wrappedIterator); \
}

#define OPERATOR_ARROW_CONST \
typename Traits::PointerToConst operator->() const \
{ \
	return &(*(this->wrappedIterator)); \
}

#define OPERATOR_PLUS \
template<typename IntType> Me operator+(IntType value) \
{ \
	Me copy = *this; \
	copy += value; \
	return copy; \
} \
\
template<typename IntType> friend Me operator+(IntType value, const Me &iterator) \
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
	return this->wrappedIterator - iterator.wrappedIterator; \
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
template<typename IntType> friend Me operator+(IntType value, const Me &iterator) \
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
	return this->wrappedIterator < iterator; \
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
template<typename IntType> typename Traits::Reference operator[](IntType value) \
{ \
	return this->wrappedIterator[value]; \
}

#define OPERATOR_OFFSET_DEREF_CONST \
template<typename IntType> typename Traits::ConstReference operator[](IntType value) \
{ \
	return this->wrappedIterator[value]; \
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
template<typename IntType> typename Traits::Reference operator[](IntType value) \
{ \
	return *(this->wrappedIterator - value); \
}

#define OPERATOR_OFFSET_DEREF_CONST_REVERSED \
template<typename IntType> typename Traits::ConstReference operator[](IntType value) const \
{ \
	return *(this->wrappedIterator - value); \
}

namespace flame_ide
{namespace templates
{

enum class IteratorCategory
{
	OUTPUT
	, INPUT
	, FORWARD
	, BIDIRECTIONAL
	, RANDOM_ACCESS
};

enum class IteratorSuccess
{
	NON_CONSTANT
	, CONSTANT
};

namespace iterator_utils
{

template<typename IteratorType>
struct GetType
{
	using Type = typename IteratorType::Type;
};

template<typename IteratorType>
struct GetType<IteratorType *>
{
	using Type = IteratorType;
};

template<typename IteratorType>
struct IteratorTraits: public ContainerTraits<typename GetType<IteratorType>::Type>
{};

}

template<typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, typename Traits>
class BaseIterator;

template<typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, typename Traits = typename iterator_utils::IteratorTraits<IteratorType>::Type>
class Iterator;

template<typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, typename Traits = typename iterator_utils::IteratorTraits<IteratorType>::Type>
class ReverseIterator;

template<typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, typename Traits = typename iterator_utils::IteratorTraits<IteratorType>::Type>
class ConstIterator;

}}

// define interfaces

namespace flame_ide
{namespace templates
{

// BaseIterator

template<typename IteratorType, IteratorCategory ITERATOR_CATEGORY, typename Traits>
class BaseIterator
{
public:
	using Me = BaseIterator<IteratorType, ITERATOR_CATEGORY, Traits>;

	BaseIterator(const Me &) = default;
	Me &operator=(const Me &) = default;
	~BaseIterator() = default;

	bool operator==(const Me &iterator)
	{
		return wrappedIterator == iterator.wrappedIterator;
	}

	bool operator!=(const Me &iterator)
	{
		return wrappedIterator != iterator.wrappedIterator;
	}

	static constexpr IteratorCategory CATEGORY = ITERATOR_CATEGORY;

protected:
	BaseIterator(IteratorType iterator) : wrappedIterator(iterator)
	{}

	mutable IteratorType wrappedIterator;
};

// Iterator

template<typename IteratorType
	, typename Traits>
class Iterator<IteratorType, IteratorCategory::OUTPUT, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::OUTPUT, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::OUTPUT, Traits>;
	using Me = Iterator<IteratorType, IteratorCategory::OUTPUT, Traits>;

	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF
	OPERATOR_ARROW

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class Iterator<IteratorType, IteratorCategory::INPUT, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::INPUT, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::INPUT, Traits>;
	using Me = Iterator<IteratorType, IteratorCategory::INPUT, Traits>;

	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class Iterator<IteratorType, IteratorCategory::FORWARD, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::FORWARD, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::FORWARD, Traits>;
	using Me = Iterator<IteratorType, IteratorCategory::FORWARD, Traits>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF
	OPERATOR_ARROW

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;
	using Me = Iterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEC_PREFIX
	OPERATOR_DEC_POSTFIX

	OPERATOR_DEREF
	OPERATOR_ARROW

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;
	using Me = Iterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(IteratorType iterator) : Parent(iterator)
	{}
	~Iterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEC_PREFIX
	OPERATOR_DEC_POSTFIX

	OPERATOR_DEREF
	OPERATOR_ARROW

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

	OPERATOR_PLUS
	OPERATOR_MINUS

	OPERATOR_PLUS_ASSIGN
	OPERATOR_MINUS_ASSIGN

	OPERATOR_MORE
	OPERATOR_LESS

	OPERATOR_MORE_EQUAL
	OPERATOR_LESS_EQUAL

	OPERATOR_OFFSET_DEREF
	OPERATOR_OFFSET_DEREF_CONST

private:
	using Parent::wrappedIterator;
};

// ReverseIterator

template<typename IteratorType, typename Traits>
class ReverseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;
	using Me = ReverseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;

	ReverseIterator(const Me &) = default;
	ReverseIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ReverseIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX_REVERSED
	OPERATOR_INC_POSTFIX_REVERSED

	OPERATOR_DEC_PREFIX_REVERSED
	OPERATOR_DEC_POSTFIX_REVERSED

	OPERATOR_DEREF
	OPERATOR_ARROW

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class ReverseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;
	using Me = ReverseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;

	ReverseIterator(const Me &) = default;
	ReverseIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ReverseIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX_REVERSED
	OPERATOR_INC_POSTFIX_REVERSED

	OPERATOR_DEC_PREFIX_REVERSED
	OPERATOR_DEC_POSTFIX_REVERSED

	OPERATOR_DEREF
	OPERATOR_ARROW

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

	OPERATOR_PLUS_REVERSED
	OPERATOR_MINUS_REVERSED

	OPERATOR_PLUS_ASSIGN_REVERSED
	OPERATOR_MINUS_ASSIGN_REVERSED

	OPERATOR_MORE_REVERSED
	OPERATOR_LESS_REVERSED

	OPERATOR_MORE_EQUAL_REVERSED
	OPERATOR_LESS_EQUAL_REVERSED

	OPERATOR_OFFSET_DEREF_REVERSED
	OPERATOR_OFFSET_DEREF_CONST_REVERSED

private:
	using Parent::wrappedIterator;
};

// ConstIterator

template<typename IteratorType, typename Traits>
class ConstIterator<IteratorType, IteratorCategory::OUTPUT, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::OUTPUT, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::OUTPUT, Traits>;
	using Me = ConstIterator<IteratorType, IteratorCategory::OUTPUT, Traits>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class ConstIterator<IteratorType, IteratorCategory::INPUT, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::INPUT, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::INPUT, Traits>;
	using Me = ConstIterator<IteratorType, IteratorCategory::INPUT, Traits>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class ConstIterator<IteratorType, IteratorCategory::FORWARD, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::FORWARD, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::FORWARD, Traits>;
	using Me = ConstIterator<IteratorType, IteratorCategory::FORWARD, Traits>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class ConstIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;
	using Me = ConstIterator<IteratorType, IteratorCategory::BIDIRECTIONAL, Traits>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEC_PREFIX
	OPERATOR_DEC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

private:
	using Parent::wrappedIterator;
};

template<typename IteratorType, typename Traits>
class ConstIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>:
		public BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>
{
public:
	using Parent = BaseIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;
	using Me = ConstIterator<IteratorType, IteratorCategory::RANDOM_ACCESS, Traits>;

	ConstIterator(const Me &) = default;
	ConstIterator(IteratorType iterator) : Parent(iterator)
	{}
	~ConstIterator() = default;
	Me& operator=(const Me &) = default;

	OPERATOR_INC_PREFIX
	OPERATOR_INC_POSTFIX

	OPERATOR_DEC_PREFIX
	OPERATOR_DEC_POSTFIX

	OPERATOR_DEREF_CONST
	OPERATOR_ARROW_CONST

	OPERATOR_PLUS
	OPERATOR_MINUS

	OPERATOR_PLUS_ASSIGN
	OPERATOR_MINUS_ASSIGN

	OPERATOR_MORE
	OPERATOR_LESS

	OPERATOR_MORE_EQUAL
	OPERATOR_LESS_EQUAL

	OPERATOR_OFFSET_DEREF_CONST

private:
	using Parent::wrappedIterator;
};

}}

// implementation

namespace flame_ide
{namespace templates
{

}}

#undef OPERATOR_OFFSET_DEREF_CONST_REVERSED
#undef OPERATOR_OFFSET_DEREF_REVERSED

#undef OPERATOR_LESS_EQUAL_REVERSED
#undef OPERATOR_MORE_EQUAL_REVERSED

#undef OPERATOR_LESS_REVERSED
#undef OPERATOR_MORE_REVERSED

#undef OPERATOR_OFFSET_DEREF_CONST
#undef OPERATOR_OFFSET_DEREF

#undef OPERATOR_LESS_EQUAL
#undef OPERATOR_MORE_EQUAL

#undef OPERATOR_LESS
#undef OPERATOR_MORE

#undef OPERATOR_MINUS_ASSIGN_REVERSED
#undef OPERATOR_PLUS_ASSIGN_REVERSED

#undef OPERATOR_MINUS_REVERSED
#undef OPERATOR_PLUS_REVERSED

#undef OPERATOR_MINUS_ASSIGN
#undef OPERATOR_PLUS_ASSIGN

#undef OPERATOR_MINUS
#undef OPERATOR_PLUS

#undef OPERATOR_ARROW_CONST
#undef OPERATOR_DEREF_CONST

#undef OPERATOR_ARROW
#undef OPERATOR_DEREF

#undef OPERATOR_DEC_POSTFIX_REVERSED
#undef OPERATOR_DEC_PREFIX_REVERSED

#undef OPERATOR_INC_POSTFIX_REVERSED
#undef OPERATOR_INC_PREFIX_REVERSED

#undef OPERATOR_DEC_POSTFIX
#undef OPERATOR_DEC_PREFIX

#undef OPERATOR_INC_POSTFIX
#undef OPERATOR_INC_PREFIX

#endif // ITERATOR_HPP
