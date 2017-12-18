#ifndef TEMPLATES_STRING_HPP
#define TEMPLATES_STRING_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>
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

template<typename T, bool SIGNED = isSigned<T>()>
struct BufferSize;

}

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>>
class BasicString;

using String = BasicString<char>;
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

template<typename T, bool SIGNED>
struct BufferSize
{
	static inline SizeTraits::SizeType get(T integer);
};

template<typename T>
struct BufferSize<T, false>
{
	static inline SizeTraits::SizeType get(T integer);
};

template<typename IntValue>
String toString(IntValue value);

template<typename NumberType, bool IS_FLOAT = isFloatType<NumberType>()>
struct NumberConverter
{
	static String convert(NumberType value);
};

template<typename NumberType>
struct NumberConverter<NumberType, true>
{
	static String convert(NumberType value);
};

template<typename IntType, typename CharType>
class IntegerToCharStream
{
	static constexpr CharType NULL_SYMBOL = CharType();

	IntegerToCharStream(IntType value);

	CharType get();
	bool next() const;

private:
	IntType value;
};

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
	ConstReference operator[](IntType integer) const noexcept;

	// TODO: Not implement
	Me &operator+=(const T &object);
	Me &operator+=(T &&object);
	template<typename IntType>
	Me &operator+=(IntType integer);
	Me &operator+=(const Me &string);
	template<typename InputIterator>
	Me &operator+=(Range<InputIterator> range);

	// TODO: Not implement
	Me &operator-=(Iterator it);
	Me &operator-=(ReverseIterator it);
	Me &operator-=(Range<Iterator> range);
	Me &operator-=(Range<ReverseIterator> range);

	SizeType length() const noexcept;
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
	void insert(Iterator it, PointerToConst array);

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

namespace string_utils
{

template<Types::ullong_t MIN, Types::ullong_t MAX, SizeTraits::SizeType BUFFER_SIZE>
template<typename IntType>
inline SizeTraits::SizeType
NumberChecker<MIN, MAX, BUFFER_SIZE>::get(IntType value)
{
	if (MIN <= value && value <= MAX)
		return BUFFER_SIZE;
	else
		return NumberChecker<
			MAX, MAX * Types::ullong_t(10) + Types::ullong_t(9)
			, BUFFER_SIZE + SizeTraits::SizeType(1)
		>::get(value);
}

template<SizeTraits::SizeType BUFFER_SIZE>
template<typename IntType>
inline SizeTraits::SizeType NumberChecker<
	Types::ullong_t(999999999999999999ULL), Types::ullong_t(9999999999999999999ULL)
	, BUFFER_SIZE>::get(IntType value)
{
	constexpr Types::ullong_t MIN = Types::ullong_t(999999999999999999ULL);
	constexpr Types::ullong_t MAX = Types::ullong_t(9999999999999999999ULL);

	if (MIN <= value && value <= MAX)
		return BUFFER_SIZE;
	else
		return BUFFER_SIZE + 1;
}

template<typename IntType, bool SIGNED>
SizeTraits::SizeType BufferSize<IntType, SIGNED>::get(IntType integer)
{
	SizeTraits::SizeType signedValue = 0;
	if (integer < 0)
	{
		++signedValue;
		integer *= -1;
	}
	typename MakeUnsigned<IntType>::Type value = integer;

	return signedValue + NumberChecker<0ULL, 9ULL, 1>::get(value);
}

template<typename IntType>
SizeTraits::SizeType BufferSize<IntType, false>::get(IntType integer)
{
	return NumberChecker<0ULL, 9ULL, 1>::get(integer);
}

template<typename IntType>
SizeTraits::SizeType bufferSize(IntType integer)
{
	return BufferSize<IntType>::get(integer);
}

}

TEMPLATE_TYPE
STRING_TYPE::BasicString() : allocator()
		, stringCapacity()
		, head(nullptr), tail(nullptr)
{}

TEMPLATE_TYPE
STRING_TYPE::BasicString(const STRING_TYPE &string)
		: allocator(string.allocator)
		, stringCapacity(string.length() + SizeType(1))
		, head(allocator.createArray(stringCapacity))
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
	if (capacity() >= string.length())
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
		reserve(string.length() - length());
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
	string.stringCapacity = decltype(string.stringCapacity)();

	return *this;
}

TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator=(typename STRING_TYPE::PointerToConst array)
{
	clean();
	const auto arraySize = rawStringLength(array) + SizeType(1);

	if (capacity() >= arraySize)
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
		reserve(arraySize - length());
		return operator=(array);
	}

	return *this;
}

TEMPLATE_TYPE
template<typename IntType>
typename STRING_TYPE::Reference
STRING_TYPE::operator[](IntType integer) noexcept
{
	static_assert( !isFloatType<IntType>(), "Invalid index type." );
	return head[integer];
}

TEMPLATE_TYPE
template<typename IntType>
typename STRING_TYPE::ConstReference
STRING_TYPE::operator[](IntType integer) const noexcept
{
	static_assert( !isFloatType<IntType>(), "Invalid index type." );
	return head[integer];
}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(const T &object)
{
	pushBack(object);
	return *this;
}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(T &&object)
{
	pushBack(object);
	return *this;
}

// TODO: implement
TEMPLATE_TYPE
template<typename IntType>
STRING_TYPE &STRING_TYPE::operator+=(IntType integer)
{

	return *this;
}

// TODO: implement
TEMPLATE_TYPE
STRING_TYPE &STRING_TYPE::operator+=(const Me &string)
{
	return *this;
}

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
typename STRING_TYPE::SizeType STRING_TYPE::length() const noexcept
{
	return tail - head;
}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::capacity() const noexcept
{
	return stringCapacity;
}

TEMPLATE_TYPE
typename STRING_TYPE::PointerToConst STRING_TYPE::data() const noexcept
{
	return head;
}

TEMPLATE_TYPE
void STRING_TYPE::clean()
{
	if (stringCapacity)
	{
		for(auto &i : *this)
			i.~T();
		tail = head;
		*head = NULL_SYMBOL;
	}
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
{
	if (head)
	{
		if (newSize > stringCapacity)
		{
			auto tmp = allocator.reallocateArray(head, newSize);
			if (tmp != head)
			{
				tail = (tail - head) + tmp;
				head = tmp;
			}
			stringCapacity = newSize;
		}
	}
	else
	{
		head = allocator.createArray(newSize);
		*(tail = head) = NULL_SYMBOL;
		stringCapacity = newSize;
	}
}

TEMPLATE_TYPE
void STRING_TYPE::reserve(typename STRING_TYPE::SizeType addSize)
{
	resize(capacity() + addSize);
}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::ConstReference object)
{
	if (length() < capacity())
	{
		*tail = object;
		++tail;
		*tail = NULL_SYMBOL;
	}
	else
	{
		resize(nextCapacity());
		pushBack(object);
	}
}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::MoveReference object)
{
	if (length() + SizeType(1) < capacity())
	{
		*tail = object;
		++tail;
		*tail = NULL_SYMBOL;
	}
	else
	{
		resize(nextCapacity());
		pushBack(object);
	}
}

TEMPLATE_TYPE
void STRING_TYPE::pushBack(typename STRING_TYPE::PointerToConst array)
{
	auto arraySize = rawStringLength(array);
	if (length() + arraySize + SizeType(2) < capacity())
	{
		auto range = makeRange(tail, tail + arraySize);
		auto pointer = array;
		for (auto &i : range)
		{
			i = *(pointer++);
		}
		tail = tail + arraySize;
		*range.end() = NULL_SYMBOL;
	}
	else
	{
		SizeType stringNewCapacity = nextCapacity();
		if (length() + arraySize + SizeType(2) < stringNewCapacity)
			resize(stringNewCapacity);
		else
			resize(length() + arraySize + SizeType(2));

		pushBack(array);
	}
}

TEMPLATE_TYPE
void STRING_TYPE::popBack()
{
	if (length())
	{
		--tail;
		*tail = NULL_SYMBOL;
	}
}

TEMPLATE_TYPE
void STRING_TYPE::insert(Iterator it, typename STRING_TYPE::ConstReference object)
{
	if (length() + SizeType(1) < capacity())
	{
		if (it == end())
			pushBack(object);
		else
		{
			emplaceNew<Type>(tail);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(--rangeOld.begin(), --rangeOld.end());
			for (ReverseIterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
					itNew != rangeNew.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = object;
			++tail;
			*tail = NULL_SYMBOL;
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(nextCapacity());
		insert(begin() + newIt, object);
	}
}

TEMPLATE_TYPE
void STRING_TYPE::insert(Iterator it, typename STRING_TYPE::MoveReference object)
{
	if (length() + SizeType(1) < capacity())
	{
		if (it == end())
			pushBack(move(object));
		else
		{
			emplaceNew<Type>(tail);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(--rangeOld.begin(), --rangeOld.end());
			for (ReverseIterator itOld = rangeOld.begin()
					, itNew = rangeNew.begin(); itOld != rangeOld.end();
					++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = move(object);
			++tail;
			*tail = NULL_SYMBOL;
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(nextCapacity());
		insert(begin() + newIt, object);
	}
}

TEMPLATE_TYPE
template<typename InputIterator>
void STRING_TYPE::insert(typename STRING_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	auto rangeSize = countIterations(itBegin, itEnd);
	if (!rangeSize)
		return;
	else if (capacity() > rangeSize + length())
	{
		Range<InputIterator> range(itBegin, itEnd);
		if (it == end())
			for (auto &itInsert : range)
				pushBack(itInsert);
		else
		{
			Range<Iterator> initRange(end(), end() + rangeSize);
			for (Reference it : initRange)
				emplaceNew<Type>(&it);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(rangeOld.begin() - rangeSize
							, rangeOld.end() - rangeSize);
			for (ReverseIterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
					itOld != rangeOld.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			for (auto &itInsert : range)
			{
				*it = itInsert;
				++it;
			}
			tail += rangeSize;
			*tail = NULL_SYMBOL;
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(rangeSize - capacity());
		insert(begin() + newIt, itBegin, itEnd);
	}
}

TEMPLATE_TYPE
void STRING_TYPE::insert(typename STRING_TYPE::Iterator it
		, typename STRING_TYPE::PointerToConst array)
{
	SizeType rawSize = rawStringLength(array);
	insert(it, array, array + rawSize);
}

TEMPLATE_TYPE
void STRING_TYPE::erase(typename STRING_TYPE::Iterator it)
{
	if (it == end())
		return;
	else if (it == --end())
		popBack();
	else
	{
		auto rangeOld = makeRange(it + 1, end());
		auto rangeNew = makeRange(rangeOld.begin() - 1, rangeOld.end() - 1);
		for (Iterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
				itOld != rangeOld.end(); ++itOld, ++itNew)
			*itNew = move(*itOld);
		--tail;
		*tail = NULL_SYMBOL;
	}
}

TEMPLATE_TYPE
void STRING_TYPE::erase(typename STRING_TYPE::Iterator itBegin
		, typename STRING_TYPE::Iterator itEnd)
{
	if (SizeType(itEnd - itBegin) == length())
		clean();
	else if (itEnd - itBegin < SizeTraits::SsizeType(length())
			&& itEnd - itBegin > SizeTraits::SsizeType(0))
	{
		auto rangeErasing = makeRange(itBegin, itEnd);
		for (auto &i : rangeErasing)
			i.~T();

		auto rangeOld = makeRange(itEnd, end());
		auto rangeNew = makeRange(itBegin, itBegin + (end() - itEnd));
		for (Iterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
				itOld != rangeOld.end(); ++itNew, ++itOld)
			*itNew = move(*itOld);

		tail -= SizeType(rangeErasing.end() - rangeErasing.begin());
		*tail = NULL_SYMBOL;
	}
}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::nextCapacity() const noexcept
{
	return (capacity() * STRING_RESIZE_FACTOR_MULT) / STRING_RESIZE_FACTOR_DIV;
}

TEMPLATE_TYPE
typename STRING_TYPE::SizeType STRING_TYPE::rawStringLength(
		typename STRING_TYPE::PointerToConst rawString)
{
	SizeType length;
	for (length = 0; rawString[length] != NULL_SYMBOL; ++length);
	return length;
}

namespace string_utils
{

template<typename NumberType, bool IS_FLOAT>
String NumberConverter<NumberType, IS_FLOAT>::convert(NumberType value)
{
	String string;
	SizeTraits::SizeType buffer = string_utils::BufferSize<NumberType>::get(value);
	string.reserve(buffer);

	if (isSigned<NumberType>())
	{
		if (value < 0)
		{
			string.pushBack('-');
			value *= -1;
			--buffer;
		}
	}

	SizeTraits::SizeType dec = 1;
	for (decltype(buffer) i = 1; i < buffer; ++i)
	{
		dec *= static_cast<SizeTraits::SizeType>(10);
	}

	for (decltype(buffer) i = 0; i < buffer; ++i)
	{
		auto result = value / dec;
		string.pushBack(String::Type('0' + result));
		value %= dec;
		dec /= static_cast<SizeTraits::SizeType>(10);
	}

	return string;
}

template<typename NumberType>
String NumberConverter<NumberType, true>::convert(NumberType)
{
	String string;
	return string;
}

}

template<typename IntValue>
String toString(IntValue value)
{
	return string_utils::NumberConverter<IntValue, isFloatType<IntValue>()>::convert(value);
}

}}

#endif // TEMPLATES_STRING_HPP
