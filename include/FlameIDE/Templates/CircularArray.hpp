#ifndef FLAMEIDE_TEMPLATES_CIRCULARARRAY_HPP
#define FLAMEIDE_TEMPLATES_CIRCULARARRAY_HPP

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

template <
	typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits
>
class CircularArray;

}}

namespace flame_ide
{namespace templates
{

template <typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits = ContainerTraits<T>
>
class CircularArray
{
public:
	using Me = CircularArray<T, ARRAY_CAPACITY, Traits>;
	static_assert(ARRAY_CAPACITY >= 0, "Invalid CircularArray size.");

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	using BufferType = StaticVector<T, ARRAY_CAPACITY + 1, Traits>;
	static constexpr SizeType CAPACITY = BufferType::CAPACITY - 1;

	using Iterator = CircularIterator<
		typename BufferType::Iterator
		, IteratorCategory::RANDOM_ACCESS
		, Traits, Me
	>;
	using ConstIterator = ConstCircularIterator<
		typename BufferType::ConstIterator
		, IteratorCategory::RANDOM_ACCESS
		, Traits, Me
	>;
	using ReverseIterator = templates::ReverseIterator<
		Iterator, IteratorCategory::RANDOM_ACCESS
		, Traits, Me
	>;
	using ConstReverseIterator = templates::ConstReverseIterator<
		ConstIterator
		, IteratorCategory::RANDOM_ACCESS
		, Traits, Me
	>;

	CircularArray() noexcept;
	CircularArray(const Me &array) noexcept;
	CircularArray(Me &&array) noexcept;
	~CircularArray();
	Me &operator=(const Me &) noexcept;
	Me &operator=(Me &&) noexcept;

	///
	/// @brief data
	/// @return
	///
	Pointer data() noexcept;

	///
	/// @brief data
	/// @return
	///
	PointerToConst data() const noexcept;

	///
	/// @brief size
	/// @return
	///
	SizeType size() const noexcept;

	///
	/// @brief capacity
	/// @return
	///
	constexpr SizeType capacity() noexcept
	{
		return CAPACITY;
	}

	///
	/// @brief clean
	///
	void clean() noexcept;

	///
	/// @brief pushBack
	/// @param obj
	///
	void pushBack(ConstReference obj) noexcept;

	///
	/// @brief pushBack
	/// @param obj
	///
	void pushBack(MoveReference obj) noexcept;

	///
	/// @brief pushBack
	/// @param range
	///
	template<typename InputIterator>
	void pushBack(const Range<InputIterator> &range) noexcept;

	template<typename InputIterator>
	///
	/// @brief pushBack
	/// @param range
	///
	void pushBack(Range<InputIterator> &&range) noexcept;

	///
	/// @brief emplaceBack
	/// @param args
	///
	template<typename ...Args>
	void emplaceBack(Args &&...args) noexcept;

	///
	/// @brief popFront
	///
	void popFront() noexcept;

	///
	/// @brief begin
	/// @return
	///
	Iterator begin() noexcept;

	///
	/// @brief begin
	/// @return
	///
	ConstIterator begin() const noexcept;

	///
	/// @brief cbegin
	/// @return
	///
	ConstIterator cbegin() const noexcept;

	///
	/// @brief rbegin
	/// @return
	///
	ReverseIterator rbegin() noexcept;

	///
	/// @brief rbegin
	/// @return
	///
	ConstReverseIterator rbegin() const noexcept;

	///
	/// @brief crbegin
	/// @return
	///
	ConstReverseIterator crbegin() const noexcept;

	///
	/// @brief end
	/// @return
	///
	Iterator end() noexcept;

	///
	/// @brief end
	/// @return
	///
	ConstIterator end() const noexcept;

	///
	/// @brief cend
	/// @return
	///
	ConstIterator cend() const noexcept;

	///
	/// @brief rend
	/// @return
	///
	ReverseIterator rend() noexcept;

	///
	/// @brief rend
	/// @return
	///
	ConstReverseIterator rend() const noexcept;

	///
	/// @brief crend
	/// @return
	///
	ConstReverseIterator crend() const noexcept;

private:
	///
	/// @brief updateTerminal
	/// @param terminal
	///
	void updateTerminal(typename BufferType::Iterator &terminal) noexcept;

	BufferType buffer; ///<
	typename BufferType::Iterator head; ///<
	typename BufferType::Iterator tail; ///<
};

}}

namespace flame_ide
{namespace templates
{

#define TEMPLATE_DEFINE \
	template <typename T, SizeTraits::SizeType ARRAY_CAPACITY, typename Traits>

#define CIRCULAR_ARRAY_TYPE \
	CircularArray<T, ARRAY_CAPACITY, Traits>

// public

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE::CircularArray() noexcept
		: buffer(), head(buffer.begin()), tail(head)
{}

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE::CircularArray(const Me &array) noexcept
		: buffer(), head(buffer.begin()), tail(buffer.begin() + array.size())
{
	for (auto &i : array)
	{
		buffer.pushBack(*i);
	}
}

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE::CircularArray(Me &&array) noexcept
		: buffer(), head(buffer.begin()), tail(buffer.begin() + array.size())
{
	for (auto &&i : array)
	{
		buffer.emplaceBack(move(i));
	}
}

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE::~CircularArray()
{
	for (auto i : *this)
	{
		i.~T();
	}
}

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE &CIRCULAR_ARRAY_TYPE::operator=(const Me &array) noexcept
{
	clean();
	for (auto &i : array)
	{
		placementNew(getPointer(tail), i);
		++tail;
	}
}

TEMPLATE_DEFINE
CIRCULAR_ARRAY_TYPE &CIRCULAR_ARRAY_TYPE::operator=(Me &&array) noexcept
{
	clean();
	for (auto &&i : array)
	{
		emplaceNew(getPointer(tail), move(i));
		++tail;
	}
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::Pointer
CIRCULAR_ARRAY_TYPE::data() noexcept
{
	return buffer.data();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::PointerToConst
CIRCULAR_ARRAY_TYPE::data() const noexcept
{
	return buffer.data();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::SizeType
CIRCULAR_ARRAY_TYPE::size() const noexcept
{
	if (head > tail)
	{
		return capacity() - (head - tail);
	}
	else
	{
		return static_cast<SizeType>(tail - head);
	}
}

TEMPLATE_DEFINE
void CIRCULAR_ARRAY_TYPE::clean() noexcept
{
	for (auto i : *this)
	{
		i.~T();
	}
	tail = head = buffer.begin();
}

TEMPLATE_DEFINE
void CIRCULAR_ARRAY_TYPE::pushBack(ConstReference obj) noexcept
{
	if (size() != capacity())
	{
		placementNew(getPointer(++tail), obj);
		updateTerminal(tail);
	}
}

TEMPLATE_DEFINE
void CIRCULAR_ARRAY_TYPE::pushBack(MoveReference obj) noexcept
{
	if (size() != capacity())
	{
		placementNew(getPointer(++tail), move(obj));
		updateTerminal(tail);
	}
}

TEMPLATE_DEFINE template<typename InputIterator>
void CIRCULAR_ARRAY_TYPE::pushBack(const Range<InputIterator> &range) noexcept
{
	static_assert(
			isSameTypes<typename RemoveAll<decltype(*range.begin())>::Type, Type>()
			, "Invalid 'InputIterator' type"
	);
	auto rangeSize = countIterations(range);
	if (rangeSize <= capacity() - size())
	{
		for (auto &i : range)
		{
			placementNew(getPointer(tail++), i);
			updateTerminal(tail);
		}
	}
}

TEMPLATE_DEFINE template<typename InputIterator>
void CIRCULAR_ARRAY_TYPE::pushBack(Range<InputIterator> &&range) noexcept
{
	static_assert(
			isSameTypes<typename RemoveAll<decltype(*range.begin())>::Type, Type>()
			, "Invalid 'InputIterator' type"
	);
	auto rangeSize = countIterations(range);
	if (rangeSize <= capacity() - size())
	{
		for (auto &&i : range)
		{
			placementNew(getPointer(tail++), move(i));
			updateTerminal(tail);
		}
	}
}

TEMPLATE_DEFINE template<typename ...Args>
void CIRCULAR_ARRAY_TYPE::emplaceBack(Args &&...args) noexcept
{
	pushBack(Type(forward(args)...));
}

TEMPLATE_DEFINE
void CIRCULAR_ARRAY_TYPE::popFront() noexcept
{
	if (size())
	{
		head->~T();
		++head;
		updateTerminal(head);
	}
	else
	{
		tail = head = buffer.begin();
	}
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::Iterator
CIRCULAR_ARRAY_TYPE::begin() noexcept
{
	return Iterator(head);
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstIterator
CIRCULAR_ARRAY_TYPE::begin() const noexcept
{
	return cbegin();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstIterator
CIRCULAR_ARRAY_TYPE::cbegin() const noexcept
{
	return ConstIterator(buffer.cbegin());
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ReverseIterator
CIRCULAR_ARRAY_TYPE::rbegin() noexcept
{
	return ReverseIterator(--end());
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstReverseIterator
CIRCULAR_ARRAY_TYPE::rbegin() const noexcept
{
	return crbegin();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstReverseIterator
CIRCULAR_ARRAY_TYPE::crbegin() const noexcept
{
	return ConstReverseIterator(--end());
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::Iterator
CIRCULAR_ARRAY_TYPE::end() noexcept
{
	return begin() + size();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstIterator
CIRCULAR_ARRAY_TYPE::end() const noexcept
{
	return cend();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstIterator
CIRCULAR_ARRAY_TYPE::cend() const noexcept
{
	return cbegin() + size();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ReverseIterator
CIRCULAR_ARRAY_TYPE::rend() noexcept
{
	return rbegin() + size();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstReverseIterator
CIRCULAR_ARRAY_TYPE::rend() const noexcept
{
	return crend();
}

TEMPLATE_DEFINE
typename CIRCULAR_ARRAY_TYPE::ConstReverseIterator
CIRCULAR_ARRAY_TYPE::crend() const noexcept
{
	return crbegin() + size();
}

// private

TEMPLATE_DEFINE
void CIRCULAR_ARRAY_TYPE::updateTerminal(
		typename BufferType::Iterator &terminal) noexcept
{
	if (terminal == buffer.begin() + BufferType::CAPACITY)
	{
		terminal = buffer.begin();
	}
}

#undef TEMPLATE_DEFINE
#undef CIRCULAR_ARRAY_TYPE

}}

#endif // CIRCULARARRAY_HPP
