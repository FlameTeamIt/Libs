#ifndef FLAMEIDE_TEMPLATES_ARRAY_HPP
#define FLAMEIDE_TEMPLATES_ARRAY_HPP

#include <FlameIDE/Templates/Bits.hpp>
#include <FlameIDE/Templates/AlignObject.hpp>
#include <FlameIDE/Templates/InitializerList.hpp>
#include <FlameIDE/Templates/Iterator.hpp>
#include <FlameIDE/Templates/View.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

#define TEMPLATE_DEFINE \
	template < \
		typename T \
		, SizeTraits::SizeType ARRAY_CAPACITY \
		, bool AS_PURE_C_ARRAY \
		, typename Traits \
	>

#define TEMPLATE_DEFINE_1 \
	template < \
		SizeTraits::SizeType ARRAY_CAPACITY1 \
		, typename Traits1 \
		, bool AS_PURE_C_ARRAY1 \
	>

#define ARRAY_TYPE \
	Array<T, ARRAY_CAPACITY, AS_PURE_C_ARRAY, Traits>

#define ARRAY_TYPE_1 \
	Array<T, ARRAY_CAPACITY1, AS_PURE_C_ARRAY1, Traits1>

namespace flame_ide
{namespace templates
{

/**
 * @brief Array
 */
template <typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, bool AS_PURE_C_ARRAY = false
	, typename Traits = ContainerTraits<T>
>
class Array
{
public:
	static_assert (ARRAY_CAPACITY != 0, "Zero-sized array is impossible");

	using Me = ARRAY_TYPE;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;
	using VoidPointer = typename Traits::VoidPointer;

	static constexpr SizeType CAPACITY = ARRAY_CAPACITY;

	using Iterator = flame_ide::templates::Iterator<
		Pointer, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;
	using ConstIterator = flame_ide::templates::ConstIterator<
		PointerToConst, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<
		Iterator
	>;
	using ConstReverseIterator = flame_ide::templates::ConstReverseIterator<
		ConstIterator
	>;

	/**
	 * @brief Array
	 */
	Array();

	/**
	 * @brief Array
	 * @param array
	 */
	TEMPLATE_DEFINE_1
	Array(const ARRAY_TYPE_1 &objects);

	/**
	 * @brief Array
	 * @param objects
	 */
	Array(const Me &objects);

	/**
	 * @brief Array
	 * @param array
	 */
	TEMPLATE_DEFINE_1
	Array(ARRAY_TYPE_1 &&objects);

	/**
	 * @brief Array
	 * @param objects
	 */
	Array(Me &&objects);

	/**
	 * @brief Array
	 * @param args
	 */
	Array(InitializerList<T, ARRAY_CAPACITY> list);

	~Array();

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(const ARRAY_TYPE_1 &objects);

	/**
	 * @brief operator =
	 * @param objects
	 * @return
	 */
	Me &operator=(const Me &objects);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(ARRAY_TYPE_1 &&objects);

	/**
	 * @brief operator =
	 * @param objects
	 * @return
	 */
	Me &operator=(Me &&objects);

	/**
	 * @brief operator ==
	 * @param array
	 * @return
	 */
	bool operator==(const Me &array) const;

	/**
	 * @brief operator !=
	 * @param array
	 * @return
	 */
	bool operator!=(const Me &array) const;

	/**
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	template<typename IntType> inline
	Reference operator[](IntType index) noexcept;

	/**
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	template<typename IntType> inline
	ConstReference operator[](IntType index) const noexcept;

	/**
	 * @brief operator +=
	 * @param object
	 * @return
	 */
	Me &operator+=(ConstReference object);

	/**
	 * @brief operator +=
	 * @param object
	 * @return
	 */
	Me &operator+=(MoveReference object);

	/**
	 * @brief operator +=
	 * @param range
	 * @return
	 */
	template<typename InputIterator>
	Me &operator+=(Range<InputIterator> range);

	/**
	 * @brief operator -=
	 * @param it
	 * @return
	 */
	Me &operator-=(Iterator it);

	/**
	 * @brief operator -=
	 * @param it
	 * @return
	 */
	Me &operator-=(ReverseIterator it);

	/**
	 * @brief operator -=
	 * @param range
	 * @return
	 */
	Me &operator-=(Range<Iterator> range);

	/**
	 * @brief operator -=
	 * @param range
	 * @return
	 */
	Me &operator-=(Range<ReverseIterator> range);

	/**
	 * @brief data
	 * @return
	 */
	Pointer data() noexcept;

	/**
	 * @brief data
	 * @return
	 */
	PointerToConst data() const noexcept;

	/**
	 * @brief size
	 * @return
	 */
	inline SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @return
	 */
	inline constexpr SizeType capacity() const noexcept;

	/**
	 * @brief clean
	 */
	inline void clean();

	/**
	 * @brief clone
	 * @return
	 */
	Me clone() const;

	/**
	 * @brief begin
	 * @return
	 */
	inline Iterator begin() noexcept;

	/**
	 * @brief begin
	 * @return
	 */
	inline ConstIterator begin() const noexcept;

	/**
	 * @brief cbegin
	 * @return
	 */
	inline ConstIterator cbegin() const noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	inline ReverseIterator rbegin() noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	inline ConstReverseIterator rbegin() const noexcept;

	/**
	 * @brief crbegin
	 * @return
	 */
	inline ConstReverseIterator crbegin() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline Iterator end() noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline ConstIterator end() const noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	inline ReverseIterator rend() noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	inline ConstReverseIterator rend() const noexcept;

	/**
	 * @brief cend
	 * @return
	 */
	inline ConstIterator cend() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline ConstReverseIterator crend() const noexcept;

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(ConstReference object);

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(MoveReference object);

	/**
	 * @brief emplaceBack
	 * @param args
	 */
	template<typename ...Args>
	void emplaceBack(Args &&...args);

	/**
	 * @brief popBack
	 */
	void popBack();

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, ConstReference type);

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, MoveReference type);

	/**
	 * @brief insert
	 * @param it
	 * @param begin
	 * @param end
	 */
	template<typename InputIterator>
	void insert(Iterator it, InputIterator begin, InputIterator end);

	/**
	 * @brief emplace
	 * @param it
	 * @param args
	 */
	template<typename ...Args>
	void emplace(Iterator it, Args &&...args);

	/**
	 * @brief erase
	 * @param it
	 */
	void erase(Iterator it);

	/**
	 * @brief erase
	 * @param itBegin
	 * @param itEnd
	 */
	void erase(Iterator itBegin, Iterator itEnd);

	/**
	 * @brief reset
	 */
	void reset();

private:
	inline Pointer head();
	inline PointerToConst head() const;

	AlignObject<Type> objects[ARRAY_CAPACITY];
	Pointer tail;
};

}}

namespace flame_ide
{namespace templates
{

TEMPLATE_DEFINE
ARRAY_TYPE::Array()
{
	tail = head();
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE::Array(const ARRAY_TYPE_1 &array)
{
	tail = head();
	if (array.size() <= capacity())
		for (ConstReference &i : array)
			pushBack(i);
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(const ARRAY_TYPE &array)
{
	tail = head();
	for (ConstReference &i : array)
		pushBack(i);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE::Array(ARRAY_TYPE_1 &&array)
{
	tail = head();
	if (array.size() <= capacity())
		for (auto &&i : array)
			pushBack(forward<Type>(i));
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(ARRAY_TYPE &&array)
{
	tail = head();
	for (auto &&i : array)
		pushBack(forward<Type>(i));
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(InitializerList<T, ARRAY_CAPACITY> list)
{
	tail = head();
	for (auto it : list)
		pushBack(move(it));
}

TEMPLATE_DEFINE
ARRAY_TYPE::~Array()
{
	for (Type &i : *this)
		i.~T();
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE &ARRAY_TYPE::operator=(const ARRAY_TYPE_1 &array)
{
	if (array.size() > capacity())
		return *this;

	clean();
	for (auto const &i : array)
		pushBack(i);
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator=(const ARRAY_TYPE &array)
{
	if (&array != this)
	{
		clean();
		for (auto const &i : array)
			pushBack(i);
	}
	return *this;
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE &ARRAY_TYPE::operator=(ARRAY_TYPE_1 &&array)
{
	if (array.size() > capacity())
		return *this;

	clean();
	for (auto &&i : array)
		pushBack(move(i));
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator=(ARRAY_TYPE &&array)
{
	if (&array != this)
	{
		clean();
		for (auto &&i : array)
			pushBack(move(i));
	}
	return *this;
}

TEMPLATE_DEFINE
bool ARRAY_TYPE::operator==(const ARRAY_TYPE &array) const
{
	if (&array != this)
	{
		if (this->size() != array.size())
		{
			return false;
		}

		auto it = array.begin();
		for (auto i : *this)
		{
			if (i != *it)
			{
				return false;
			}
		}
	}
	return true;
}

TEMPLATE_DEFINE
bool ARRAY_TYPE::operator!=(const ARRAY_TYPE &array) const
{
	return !(*this == array);
}

TEMPLATE_DEFINE
template<typename IntType> inline
typename ARRAY_TYPE::Reference
ARRAY_TYPE::operator[](IntType index) noexcept
{
	return head()[index];
}

TEMPLATE_DEFINE
template<typename IntType> inline
typename ARRAY_TYPE::ConstReference
ARRAY_TYPE::operator[](IntType index) const noexcept
{
	return head()[index];
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator+=(ARRAY_TYPE::ConstReference object)
{
	pushBack(object);
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator+=(ARRAY_TYPE::MoveReference object)
{
	pushBack(move(object));
	return *this;
}

TEMPLATE_DEFINE
template<typename InputIterator>
ARRAY_TYPE &ARRAY_TYPE::operator+=(Range<InputIterator> range)
{
	for (auto &i : range)
		pushBack(i);
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator-=(ARRAY_TYPE::Iterator it)
{
	erase(it);
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator-=(ARRAY_TYPE::ReverseIterator it)
{
	return operator-=(Iterator(&(*it)));
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator-=(Range<ARRAY_TYPE::Iterator> range)
{
	erase(range.begin(), range.end());
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator-=(Range<ARRAY_TYPE::ReverseIterator> range)
{
	Range<ARRAY_TYPE::Iterator> forwardRange = {
			&(*(--range.end())), &(*(--range.begin()))
	};
	return operator-=(forwardRange);
}

TEMPLATE_DEFINE
typename ARRAY_TYPE::Pointer ARRAY_TYPE::data() noexcept
{
	return head();
}

TEMPLATE_DEFINE
typename ARRAY_TYPE::PointerToConst ARRAY_TYPE::data() const noexcept
{
	return head();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::SizeType ARRAY_TYPE::size() const noexcept
{
	return SizeType(tail - head());
}

TEMPLATE_DEFINE constexpr inline
typename ARRAY_TYPE::SizeType ARRAY_TYPE::capacity() const noexcept
{
	return ARRAY_CAPACITY;
}

TEMPLATE_DEFINE inline
void ARRAY_TYPE::clean()
{
	for (auto &it : *this)
		it.~T();
	tail = head();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Me ARRAY_TYPE::clone() const
{
	Me copy;
	for (ConstReference i : *this)
		copy.pushBack(i);
	return copy;
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Iterator ARRAY_TYPE::begin() noexcept
{
	return head();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::begin() const noexcept
{
	return ConstIterator(head());
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Iterator ARRAY_TYPE::end() noexcept
{
	return tail;
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::end() const noexcept
{
	return ConstIterator(tail);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ReverseIterator ARRAY_TYPE::rbegin() noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::rbegin() const noexcept
{
	auto it = end();
	return ConstReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ReverseIterator ARRAY_TYPE::rend() noexcept
{
	auto it = begin();
	return ReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::rend() const noexcept
{
	auto it = begin();
	return ConstReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::cbegin() const noexcept
{
	return begin();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::cend() const noexcept
{
	return end();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::crbegin() const noexcept
{
	return rbegin();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::crend() const noexcept
{
	return rend();
}

TEMPLATE_DEFINE
void ARRAY_TYPE::pushBack(typename ARRAY_TYPE::ConstReference object)
{
	if (size() < capacity())
	{
		placementNew<Type>(tail, object);
		++tail;
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::pushBack(typename ARRAY_TYPE::MoveReference object)
{
	if (size() < capacity())
	{
		placementNew<Type>(tail, move(object));
		++tail;
	}

}

TEMPLATE_DEFINE
template<typename ...Args>
void ARRAY_TYPE::emplaceBack(Args &&...args)
{
	if (size() < capacity())
		emplaceNew<Type>(tail++, forward<decltype(args)>(args)...);
}

TEMPLATE_DEFINE
void ARRAY_TYPE::popBack()
{
	if (size())
	{
		(end() - 1)->~T();
		--tail;
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::insert(typename ARRAY_TYPE::Iterator it
		, typename ARRAY_TYPE::ConstReference object)
{
	if (size() < capacity())
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
		}
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::insert(typename ARRAY_TYPE::Iterator it
		, typename ARRAY_TYPE::MoveReference object)
{
	if (size() < capacity())
	{
		if (it == end())
			pushBack(move(object));
		else
		{
			placementNew<Type>(tail);

			Range<ReverseIterator> viewOld(rbegin(), ReverseIterator(it - 1))
					, viewNew(--viewOld.begin(), --viewOld.end());
			for (ReverseIterator itOld = viewOld.begin() , itNew = viewNew.begin();
					itOld != viewOld.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = move(object);
			++tail;
		}
	}
}

TEMPLATE_DEFINE
template<typename InputIterator>
void ARRAY_TYPE::insert(typename ARRAY_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	auto rangeSize = countIterations(itBegin, itEnd);
	if (!rangeSize)
		return;
	else if (rangeSize + size() <= capacity())
	{
		Range<InputIterator> range(itBegin, itEnd);
		if (it == end())
			for (Reference itInsert : range)
				pushBack(itInsert);
		else
		{
			Range<Iterator> initRange(end(), end() + rangeSize);
			for (Reference it : initRange)
				emplaceNew<Type>(&it);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(rangeOld.begin() - rangeSize, rangeOld.end() - rangeSize);
			for (ReverseIterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
					itOld != rangeOld.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			for (auto &itInsert : range)
			{
				*it = itInsert;
				++it;
			}
			tail += rangeSize;
		}
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void ARRAY_TYPE::emplace(typename ARRAY_TYPE::Iterator it, Args &&...args)
{
	if (size() < capacity())
	{
		if (it == end())
			emplaceBack(forward<decltype(args)>(args)...);
		else
		{
			emplaceNew<Type>(tail);

			Range<ReverseIterator> viewOld(rbegin(), ReverseIterator(it - 1))
					, viewNew(--viewOld.begin(), --viewOld.end());
			for (ReverseIterator itOld = viewOld.begin(), itNew = viewNew.begin();
					itOld != viewOld.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			it->~T();
			emplaceNew<Type>(&(*it), forward<decltype(args)>(args)...);
			++tail;
		}
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::erase(ARRAY_TYPE::Iterator it)
{
	if (it == end())
		return;
	else if (it == end() - 1)
		popBack();
	else
	{
		Range<Iterator> rangeOld(it + 1, end())
				, rangeNew(rangeOld.begin() - 1, rangeOld.end() - 1);
		for (Iterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
				itOld != rangeOld.end(); ++itOld, ++itNew)
			*itNew = move(*itOld);
		--tail;
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::erase(ARRAY_TYPE::Iterator itBegin, ARRAY_TYPE::Iterator itEnd)
{
	if (itEnd == itBegin + size())
		clean();
	else if (itEnd - itBegin < SizeTraits::SsizeType(size())
			&& itEnd - itBegin > SizeTraits::SsizeType(0))
	{
		Range<Iterator> rangeErasing(itBegin, itEnd);
		for (auto &i : rangeErasing)
			i.~T();

		Range<Iterator> rangeOld(itEnd, end())
				, rangeNew(itBegin, itBegin + (end() - itEnd));
		for (Iterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
				itOld != rangeOld.end(); ++itNew, ++itOld)
			*itNew = move(*itOld);

		tail -= SizeType(rangeErasing.end() - rangeErasing.begin());
	}
}

TEMPLATE_DEFINE
void ARRAY_TYPE::reset()
{
	clean();
	auto range = makeRange(objects, objects + ARRAY_CAPACITY);
	for (auto &i : range)
	{
		i = AlignObject<Type>();
	}
}


TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Pointer ARRAY_TYPE::head()
{
	return reinterpret_cast<Pointer>(objects);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::PointerToConst ARRAY_TYPE::head() const
{
	return reinterpret_cast<PointerToConst>(objects);
}

}}

#undef ARRAY_TYPE
#undef TEMPLATE_DEFINE

#define TEMPLATE_DEFINE \
	template <typename T, SizeTraits::SizeType ARRAY_CAPACITY, typename Traits>

#define ARRAY_TYPE \
	Array<T, ARRAY_CAPACITY, true, Traits>

namespace flame_ide
{namespace templates
{

/**
 * @brief Array
 */
template <typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits
>
class Array<T, ARRAY_CAPACITY, true, Traits>: public Traits
{
public:
	static_assert (ARRAY_CAPACITY != 0, "Zero-sized array is impossible");

	using Me = ARRAY_TYPE;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using typename Traits::VoidPointer;

	static constexpr SizeType CAPACITY = ARRAY_CAPACITY;

	using Iterator = flame_ide::templates::Iterator<
		Pointer, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ConstIterator = flame_ide::templates::ConstIterator<
		PointerToConst, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<
		Iterator
	>;
	using ConstReverseIterator = flame_ide::templates::ConstReverseIterator<
		ConstIterator
	>;

	/**
	 * @brief Array
	 */
	Array();

	/**
	 * @brief Array
	 * @param array
	 */
	TEMPLATE_DEFINE_1
	Array(const ARRAY_TYPE_1 &objects);

	/**
	 * @brief Array
	 * @param objects
	 */
	Array(const Me &objects);

	/**
	 * @brief Array
	 * @param array
	 */
	TEMPLATE_DEFINE_1
	Array(ARRAY_TYPE_1 &&objects) noexcept;

	/**
	 * @brief Array
	 * @param objects
	 */
	Array(Me &&objects) noexcept;

	/**
	 * @brief Array
	 * @param args
	 */
	Array(InitializerList<T, ARRAY_CAPACITY> list);

	~Array() = default;

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(const ARRAY_TYPE_1 &objects);

	/**
	 * @brief operator =
	 * @param objects
	 * @return
	 */
	Me &operator=(const Me &objects);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(ARRAY_TYPE_1 &&objects) noexcept;

	/**
	 * @brief operator =
	 * @param objects
	 * @return
	 */
	Me &operator=(Me &&objects) noexcept;

	/**
	 * @brief operator ==
	 * @param array
	 * @return
	 */
	bool operator==(const Me &array) const;

	/**
	 * @brief operator !=
	 * @param array
	 * @return
	 */
	bool operator!=(const Me &array) const;

	/**
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	template<typename IntType> inline
	Reference operator[](IntType index) noexcept;

	/**
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	template<typename IntType> inline
	ConstReference operator[](IntType index) const noexcept;

	/**
	 * @brief data
	 * @return
	 */
	Pointer data() noexcept;

	/**
	 * @brief data
	 * @return
	 */
	PointerToConst data() const noexcept;

	/**
	 * @brief size
	 * @return
	 */
	inline SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @return
	 */
	inline constexpr SizeType capacity() const noexcept;

	/**
	 * @brief reset
	 */
	void reset();

	/**
	 * @brief clone
	 * @return
	 */
	Me clone() const;

	/**
	 * @brief begin
	 * @return
	 */
	inline Iterator begin() noexcept;

	/**
	 * @brief begin
	 * @return
	 */
	inline ConstIterator begin() const noexcept;

	/**
	 * @brief cbegin
	 * @return
	 */
	inline ConstIterator cbegin() const noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	inline ReverseIterator rbegin() noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	inline ConstReverseIterator rbegin() const noexcept;

	/**
	 * @brief crbegin
	 * @return
	 */
	inline ConstReverseIterator crbegin() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline Iterator end() noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline ConstIterator end() const noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	inline ReverseIterator rend() noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	inline ConstReverseIterator rend() const noexcept;

	/**
	 * @brief cend
	 * @return
	 */
	inline ConstIterator cend() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	inline ConstReverseIterator crend() const noexcept;

private:
	inline Pointer head();
	inline PointerToConst head() const;

	Type objects[CAPACITY];
};

template <typename T, SizeTraits::SizeType ARRAY_CAPACITY, typename Traits = ContainerTraits<T>>
using StaticArray = ARRAY_TYPE;

}}

namespace flame_ide
{namespace templates
{

TEMPLATE_DEFINE
ARRAY_TYPE::Array()
{}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE::Array(const ARRAY_TYPE_1 &array)
{
	if (array.size() <= capacity())
	{
		auto it = this->begin();
		for (ConstReference &i : array)
		{
			*it = i;
			++it;
		}
	}
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(const ARRAY_TYPE &array)
{
	auto it = this->begin();
	for (ConstReference &i : array)
	{
		*it = i;
		++it;
	}
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE::Array(ARRAY_TYPE_1 &&array) noexcept
{
	if (array.size() <= capacity())
	{
		auto it = this->begin();
		for (MoveReference i : array)
		{
			*it = move(i);
			++it;
		}
	}
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(ARRAY_TYPE &&array) noexcept
{
	auto it = this->begin();
	for (MoveReference i : array)
	{
		*it = move(i);
		++it;
	}
}

TEMPLATE_DEFINE
ARRAY_TYPE::Array(InitializerList<T, ARRAY_CAPACITY> list)
{
	auto arrIt = this->begin();
	for (auto &&it : list)
	{
		*arrIt = move(it);
		++arrIt;
	}
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE &ARRAY_TYPE::operator=(const ARRAY_TYPE_1 &array)
{
	if (array.size() <= capacity())
	{
		auto it = this->begin();
		for (auto const &i : array)
		{
			*it = i;
		}
	}
	return *this;
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator=(const ARRAY_TYPE &array)
{
	if (&array != this)
	{
		auto it = this->begin();
		for (auto const &i : array)
		{
			*it = i;
		}
	}
	return *this;
}

TEMPLATE_DEFINE
bool ARRAY_TYPE::operator==(const ARRAY_TYPE &array) const
{
	if (this->size() != array.size())
	{
		return false;
	}

	auto it = array.begin();
	for (auto i : *this)
	{
		if (i != *it)
		{
			return false;
		}
		++it;
	}

	return true;
}

TEMPLATE_DEFINE
bool ARRAY_TYPE::operator!=(const ARRAY_TYPE &array) const
{
	return !(*this == array);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
ARRAY_TYPE &ARRAY_TYPE::operator=(ARRAY_TYPE_1 &&array) noexcept
{
	if (array.size() <= capacity())
	{
		auto it = this->begin();
		for (MoveReference i : array)
		{
			*it = move(i);
			++it;
		}
	}
}

TEMPLATE_DEFINE
ARRAY_TYPE &ARRAY_TYPE::operator=(ARRAY_TYPE &&array) noexcept
{
	auto it = this->begin();
	for (MoveReference i : array)
	{
		*it = move(i);
		++it;
	}
}

TEMPLATE_DEFINE
template<typename IntType> inline
typename ARRAY_TYPE::Reference
ARRAY_TYPE::operator[](IntType index) noexcept
{
	return head()[index];
}

TEMPLATE_DEFINE
template<typename IntType> inline
typename ARRAY_TYPE::ConstReference
ARRAY_TYPE::operator[](IntType index) const noexcept
{
	return head()[index];
}

TEMPLATE_DEFINE
typename ARRAY_TYPE::Pointer ARRAY_TYPE::data() noexcept
{
	return head();
}

TEMPLATE_DEFINE
typename ARRAY_TYPE::PointerToConst ARRAY_TYPE::data() const noexcept
{
	return head();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::SizeType ARRAY_TYPE::size() const noexcept
{
	return capacity();
}

TEMPLATE_DEFINE constexpr inline
typename ARRAY_TYPE::SizeType ARRAY_TYPE::capacity() const noexcept
{
	return CAPACITY;
}

TEMPLATE_DEFINE
void ARRAY_TYPE::reset()
{
	auto range = makeRange(objects, objects + ARRAY_CAPACITY);
	for (auto &i : range)
	{
		i = Type();
	}
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Me ARRAY_TYPE::clone() const
{
	Me copy;
	auto copyIt = copy.begin();
	for (ConstReference i : *this)
	{
		*copyIt = i;
	}
	return copy;
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Iterator ARRAY_TYPE::begin() noexcept
{
	return head();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::begin() const noexcept
{
	return ConstIterator(head());
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Iterator ARRAY_TYPE::end() noexcept
{
	return head() + capacity();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::end() const noexcept
{
	return ConstIterator(head() + capacity());
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ReverseIterator ARRAY_TYPE::rbegin() noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::rbegin() const noexcept
{
	auto it = end();
	return ConstReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ReverseIterator ARRAY_TYPE::rend() noexcept
{
	auto it = begin();
	return ReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::rend() const noexcept
{
	auto it = begin();
	return ConstReverseIterator(--it);
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::cbegin() const noexcept
{
	return begin();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstIterator ARRAY_TYPE::cend() const noexcept
{
	return end();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::crbegin() const noexcept
{
	return rbegin();
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::ConstReverseIterator ARRAY_TYPE::crend() const noexcept
{
	return rend();
}

// private

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::Pointer ARRAY_TYPE::head()
{
	return objects;
}

TEMPLATE_DEFINE inline
typename ARRAY_TYPE::PointerToConst ARRAY_TYPE::head() const
{
	return objects;
}

}}

#undef ARRAY_TYPE_1
#undef ARRAY_TYPE
#undef TEMPLATE_DEFINE_1
#undef TEMPLATE_DEFINE

#endif // FLAMEIDE_TEMPLATES_ARRAY_HPP
