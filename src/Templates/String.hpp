#ifndef TEMPLATES_STRING_HPP
#define TEMPLATES_STRING_HPP

#include <Templates/Traits.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/View.hpp>

#ifndef STRING_RESIZE_FACTOR_MULT
#define STRING_RESIZE_FACTOR_MULT 3
#endif // STRING_RESIZE_FACTOR_MULT

#ifndef STRING_RESIZE_FACTOR_DIV
#define STRING_RESIZE_FACTOR_DIV 2
#endif // STRING_RESIZE_FACTOR_DIV

#define TEMPLATE_TYPE \
	template< \
		typename T, typename Traits, typename Allocator \
	>

#define STRING_TYPE \
	BasicString<T, Traits, Allocator>

#define TO_STRING(VALUE) # VALUE

// Define classes

namespace flame_ide
{namespace templates
{

namespace string_utils
{

template<
	Types::ullong_t MIN, Types::ullong_t MAX
	, SizeTraits::SizeType BUFFER_SIZE
>
struct NumberChecker;

template<typename T>
SizeTraits::SizeType bufferSize(T integer);

}

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>>
class BasicString;

using String = BasicString<Types::char_t>;
using U8String = BasicString<Types::uchar_t>;
using U16String = BasicString<Types::ushort_t>;
using U32String = BasicString<Types::uint_t>;

}}

// Define types

namespace flame_ide
{namespace templates
{

namespace string_utils
{

template<
	Types::ullong_t MIN, Types::ullong_t MAX
	, SizeTraits::SizeType BUFFER_SIZE
>
struct NumberChecker
{
	template<typename IntType>
	static inline SizeTraits::SizeType get(IntType value);
};

template<SizeTraits::SizeType BUFFER_SIZE>
struct NumberChecker<
	Types::ullong_t(999999999999999999ULL), Types::ullong_t(9999999999999999999ULL)
	, BUFFER_SIZE
>
{
	template<typename IntType>
	static inline SizeTraits::SizeType get(IntType value);
};

template<typename T>
SizeTraits::SizeType bufferSize(T integer);

}


TEMPLATE_TYPE
class BasicString: public Traits
{
public:
	using Me = STRING_TYPE;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using Iterator = flame_ide::templates::Iterator<
			Pointer, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ConstIterator = flame_ide::templates::ConstIterator<
			PointerToConst, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = flame_ide::templates::ConstIterator<ReverseIterator>;

	BasicString();
	BasicString(const Me &string);
	BasicString(Me &&string);
	BasicString(PointerToConst rawString);
	~BasicString();
	Me &operator=(const Me &string);
	Me &operator=(Me &&string);
	Me &operator=(PointerToConst array);

	template<typename IntType>
	Reference operator[](IntType integer) noexcept;

	template<typename IntType>
	Type operator[](IntType integer) const noexcept;

	Me &operator+=(const T &object);
	Me &operator+=(T &&object);
	template<typename IntType>
	Me &operator+=(IntType integer);
	Me &operator+=(const Me &string);
	template<typename InputIterator>
	Me &operator+=(Range<InputIterator> range);

	Me &operator-=(Iterator it);
	Me &operator-=(ReverseIterator it);
	Me &operator-=(Range<Iterator> range);
	Me &operator-=(Range<ReverseIterator> range);

	SizeType size() const noexcept;
	SizeType capacity() const noexcept;
	PointerToConst data() const noexcept;

	void clean();

	Me clone() const;

	Iterator begin() noexcept;
	ConstIterator begin() const noexcept;
	ConstIterator cbegin() const noexcept;
	ReverseIterator rbegin() noexcept;
	ConstReverseIterator rbegin() const noexcept;
	ConstReverseIterator crbegin() const noexcept;

	Iterator end() noexcept;
	ConstIterator end() const noexcept;
	ConstIterator cend() const noexcept;
	ReverseIterator rend() noexcept;
	ConstReverseIterator rend() const noexcept;
	ConstReverseIterator crend() const noexcept;

	void resize(SizeType newSize);
	void reserve(SizeType addSize);

	void pushBack(ConstReference object);
	void pushBack(MoveReference object);
	void pushBack(PointerToConst array);

	void popBack();

	void insert(Iterator it, ConstReference object);
	void insert(Iterator it, MoveReference object);
	template<typename InputIterator>
	void insert(Iterator it, InputIterator itBegin, InputIterator itEnd);

	void erase(Iterator it);
	void erase(Iterator itBegin, Iterator itEnd);

	static SizeType rawStringLength(PointerToConst rawString);

	static constexpr Type NULL_SYMBOL = Type();

private:
	inline SizeType nextCapacity() const noexcept;

	Allocator allocator;
	SizeType stringCapacity;
	Pointer head;
	Pointer tail;
};

template<typename T, typename Traits, typename Allocator, typename IntType>
STRING_TYPE operator+(const STRING_TYPE &string, IntType integer);

template<typename T, typename Traits, typename Allocator, typename IntType>
STRING_TYPE operator+(IntType integer, const STRING_TYPE &string);

TEMPLATE_TYPE
STRING_TYPE operator+(const STRING_TYPE &string1, const STRING_TYPE &string2);

TEMPLATE_TYPE
STRING_TYPE operator+(const STRING_TYPE &string, typename STRING_TYPE::PointerToConst array);

TEMPLATE_TYPE
STRING_TYPE operator+(typename STRING_TYPE::PointerToConst array, const STRING_TYPE &string);


}}

namespace flame_ide
{namespace templates
{

TEMPLATE_TYPE
STRING_TYPE::BasicString() : allocator()
		, stringCapacity()
		, head(nullptr), tail(nullptr)
{}

TEMPLATE_TYPE
STRING_TYPE::BasicString(const STRING_TYPE &string)
		: allocator(string.allocator)
		, stringCapacity(string.size() + SizeType(1))
		, head(allocator.createArray(string.size()))
		, tail(head + stringCapacity - SizeType(1))
{
	Pointer pointer = head;
	for (auto c : string)
	{
		*pointer = c;
		++pointer;
	}
	*tail = NULL_SYMBOL;
}

TEMPLATE_TYPE
STRING_TYPE::BasicString(STRING_TYPE &&string)
		: allocator(string.allocator)
		, stringCapacity(string.stringCapacity)
		, head(string.head)
		, tail(string.tail)
{
	string.head = nullptr;
	string.tail = nullptr;
	string.stringCapacity = SizeType();
}

TEMPLATE_TYPE
STRING_TYPE::BasicString(typename STRING_TYPE::PointerToConst rawString)
		: allocator()
		, stringCapacity(rawStringLength(rawString) + SizeType(1))
		, head(allocator.createArray(stringCapacity))
		, tail(head + stringCapacity - SizeType(1))
{
	Iterator it = begin();
	auto range = makeRange(rawString, rawString + stringCapacity - SizeType(1));
	for (auto i : range)
	{
		*(it++) = i;
	}
	*it = NULL_SYMBOL;
}

TEMPLATE_TYPE
STRING_TYPE::~BasicString()
{
	clean();
	allocator.freeArray(head);
}

TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator=(const STRING_TYPE &string)
{
	if (size() >= string.size())
	{
		clean();
		Iterator it = begin();
		for (auto i : string)
		{
			*it = i;
			++it;
		}
		*it = NULL_SYMBOL;
	}
	else
	{
		reserve(string.size() - size());
		operator=(string);
	}
	return *this;
}

TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator=(STRING_TYPE &&string)
{
	clean();
	if (head)
	{
		allocator.freeArray(head);
	}

	allocator = string.allocator;
	stringCapacity = string.stringCapacity;
	head = string.head;
	tail = string.tail;

	string.head = string.tail = nullptr;

	return *this;
}

TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator=(typename STRING_TYPE::PointerToConst array)
{
	clean();
	const auto arraySize = rawStringLength(array);

	if (size() >= arraySize)
	{
		Range<decltype(array)> range(array, array + arraySize);
		auto it = begin();
		for (auto &i : range)
		{
			*it = i;
			++it;
		}
		*it = NULL_SYMBOL;
	}
	else
	{
		reserve(arraySize - size());
		operator=(array);
	}

	return *this;
}

TEMPLATE_TYPE
template<typename IntType>
typename STRING_TYPE::Reference
STRING_TYPE::operator[](IntType integer) noexcept
{
	return head[integer];
}

TEMPLATE_TYPE
template<typename IntType>
typename STRING_TYPE::Type
STRING_TYPE::operator[](IntType integer) const noexcept
{
	return head[integer];
}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(const T &object)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(T &&object)
{}

// TODO: implement
TEMPLATE_TYPE
template<typename IntType>
STRING_TYPE &STRING_TYPE::operator+=(IntType integer)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(const Me &string)
{}

// TODO: implement
TEMPLATE_TYPE
template<typename InputIterator>
STRING_TYPE &STRING_TYPE::operator+=(Range<InputIterator> range)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator-=(Iterator it)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator-=(ReverseIterator it)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator-=(Range<Iterator> range)
{}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator-=(Range<ReverseIterator> range)
{}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::size() const noexcept
{
	return tail - head;
}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::capacity() const noexcept
{}

TEMPLATE_TYPE
typename STRING_TYPE::PointerToConst STRING_TYPE::data() const noexcept
{
	return head;
}

TEMPLATE_TYPE
void STRING_TYPE::clean()
{
	for(auto &i : *this)
		i.~T();
}

TEMPLATE_TYPE
STRING_TYPE STRING_TYPE::clone() const
{
	Me copy = *this;
	return copy;
}

TEMPLATE_TYPE
typename STRING_TYPE::Iterator
STRING_TYPE::begin() noexcept
{
	return Iterator(head);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstIterator
STRING_TYPE::begin() const noexcept
{
	return ConstIterator(head);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstIterator
STRING_TYPE::cbegin() const noexcept
{
	return begin();
}

TEMPLATE_TYPE
typename STRING_TYPE::ReverseIterator
STRING_TYPE::rbegin() noexcept
{
	return ReverseIterator(tail - 1);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstReverseIterator
STRING_TYPE::rbegin() const noexcept
{
	return ConstReverseIterator(tail - 1);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstReverseIterator
STRING_TYPE::crbegin() const noexcept
{
	return rbegin();
}

TEMPLATE_TYPE
typename STRING_TYPE::Iterator
STRING_TYPE::end() noexcept
{
	return Iterator(tail);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstIterator
STRING_TYPE::end() const noexcept
{
	return ConstIterator(tail);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstIterator
STRING_TYPE::cend() const noexcept
{
	return end();
}

TEMPLATE_TYPE
typename STRING_TYPE::ReverseIterator
STRING_TYPE::rend() noexcept
{
	return ReverseIterator(head - 1);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstReverseIterator
STRING_TYPE::rend() const noexcept
{
	return ConstReverseIterator(head - 1);
}

TEMPLATE_TYPE
typename STRING_TYPE::ConstReverseIterator
STRING_TYPE::crend() const noexcept
{
	return rend();
}

TEMPLATE_TYPE
void STRING_TYPE::resize(typename STRING_TYPE::SizeType newSize)
{}

TEMPLATE_TYPE
void STRING_TYPE::reserve(typename STRING_TYPE::SizeType addSize)
{}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::ConstReference object)
{}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::MoveReference object)
{}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::PointerToConst array)
{}

TEMPLATE_TYPE
void STRING_TYPE::popBack()
{}

TEMPLATE_TYPE
void STRING_TYPE::insert(Iterator it, typename STRING_TYPE::ConstReference object)
{}

TEMPLATE_TYPE
void STRING_TYPE::insert(Iterator it, typename STRING_TYPE::MoveReference object)
{}

TEMPLATE_TYPE
template<typename InputIterator>
void STRING_TYPE::insert(typename STRING_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{}

TEMPLATE_TYPE
void STRING_TYPE::erase(typename STRING_TYPE::Iterator it)
{}

TEMPLATE_TYPE
void STRING_TYPE::erase(typename STRING_TYPE::Iterator itBegin
		, typename STRING_TYPE::Iterator itEnd)
{}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::nextCapacity() const noexcept
{
	return (capacity() * STRING_RESIZE_FACTOR_MULT) / STRING_RESIZE_FACTOR_DIV;
}

}}

#endif // TEMPLATES_STRING_HPP
