#ifndef FLAMEIDE_TEMPLATES_VECTOR_HPP
#define FLAMEIDE_TEMPLATES_VECTOR_HPP

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>
#include <FlameIDE/Templates/Iterator.hpp>
#include <FlameIDE/Templates/Allocator.hpp>
#include <FlameIDE/Templates/InitializerList.hpp>
#include <FlameIDE/Templates/View.hpp>

#ifndef VECTOR_RESIZE_FACTOR_MULT
#define VECTOR_RESIZE_FACTOR_MULT 3
#endif // VECTOR_RESIZE_FACTOR_MULT

#ifndef VECTOR_RESIZE_FACTOR_DIV
#define VECTOR_RESIZE_FACTOR_DIV 2
#endif // VECTOR_RESIZE_FACTOR_DIV

#define TEMPLATE_DEFINE \
	template < \
		typename T \
		, typename Traits \
		, typename Allocator \
	>

#define TEMPLATE_DEFINE_1 \
	template < \
		typename Traits1 \
		, typename Allocator1 \
	>

#define VECTOR_TYPE \
	Vector< \
		T, Traits, Allocator \
	>

#define VECTOR_TYPE_1 \
	Vector< \
		T, Traits1, Allocator1 \
	>

namespace flame_ide
{namespace templates
{

template <typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T, Traits>
>
class Vector: public Traits
{
public:
	static_assert(VECTOR_RESIZE_FACTOR_MULT > VECTOR_RESIZE_FACTOR_DIV,
			"VECTOR_RESIZE_FACTOR_MULT can be more than VECTOR_RESIZE_FACTOR_DIV.");

	using Me = VECTOR_TYPE;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

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
	 * @brief Vector
	 */
	Vector() noexcept;

	/**
	 * @brief Vector
	 * @param vector
	 */
	TEMPLATE_DEFINE_1
	Vector(const VECTOR_TYPE_1 &vector);
	Vector(const VECTOR_TYPE &vector);

	/**
	 * @brief Vector
	 * @param vector
	 */
	TEMPLATE_DEFINE_1
	Vector(VECTOR_TYPE_1 &&vector) noexcept;
	Vector(VECTOR_TYPE &&vector) noexcept;

	/**
	 * @brief Vector
	 * @param size
	 */
	Vector(SizeType size);

	/**
	 * @brief Vector
	 * @param vector
	 */
	template<SizeTraits::SizeType INIT_LIST_SIZE = 64>
	Vector(InitializerList<T, INIT_LIST_SIZE> list);

	~Vector();

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(const VECTOR_TYPE_1 &vector);

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	Me &operator=(const Me &vector);

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	TEMPLATE_DEFINE_1
	Me &operator=(VECTOR_TYPE_1 &&vector) noexcept;

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	Me &operator=(Me &&vector);

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	template<typename IntType>
	Reference operator[](IntType index) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	template<typename IntType>
	ConstReference operator[](IntType index) const noexcept;

	Me &operator+=(const Type &object);
	Me &operator+=(Type &&object);
	template<typename InputIterator>
	Me &operator+=(Range<InputIterator> range);

	Me &operator-=(Iterator it);
	Me &operator-=(ReverseIterator it);
	Me &operator-=(ConstIterator it);
	Me &operator-=(ConstReverseIterator it);

	Me &operator-=(Range<Iterator> range);
	Me &operator-=(Range<ConstIterator> range);
	Me &operator-=(Range<ReverseIterator> range);
	Me &operator-=(Range<ConstReverseIterator> range);

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
	SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @param index
	 * @return
	 */
	SizeType capacity() const noexcept;

	/**
	 * @brief resize
	 * @param size
	 */
	void resize(SizeType size);

	/**
	 * @brief reserve
	 * @param capacity
	 */
	void reserve(SizeType vectorCapacity);

	/**
	 * @brief clean
	 */
	void clean();

	/**
	 * @brief clone
	 * @return
	 */
	Me clone();

	/**
	 * @brief begin
	 * @return
	 */
	Iterator begin() noexcept;

	/**
	 * @brief begin
	 * @return
	 */
	ConstIterator begin() const noexcept;

	/**
	 * @brief cbegin
	 * @return
	 */
	ConstIterator cbegin() const noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	ReverseIterator rbegin() noexcept;

	/**
	 * @brief rbegin
	 * @return
	 */
	ConstReverseIterator rbegin() const noexcept;

	/**
	 * @brief crbegin
	 * @return
	 */
	ConstReverseIterator crbegin() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	Iterator end() noexcept;

	/**
	 * @brief end
	 * @return
	 */
	ConstIterator end() const noexcept;

	/**
	 * @brief cend
	 * @return
	 */
	ConstIterator cend() const noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	ReverseIterator rend() noexcept;

	/**
	 * @brief rend
	 * @return
	 */
	ConstReverseIterator rend() const noexcept;

	/**
	 * @brief crend
	 * @return
	 */
	ConstReverseIterator crend() const noexcept;

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
	void insert(Iterator it, InputIterator itBegin, InputIterator intEnd);

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

private:
	inline SizeType nextCapacity() const;

	Allocator allocator;
	SizeType vectorCapacity;
	Pointer head;
	Pointer tail;
};

}}

namespace flame_ide
{namespace templates
{

TEMPLATE_DEFINE
VECTOR_TYPE::Vector() noexcept
		: allocator()
		, vectorCapacity()
		, head(nullptr), tail(nullptr)
{}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE::Vector(const VECTOR_TYPE_1 &vector)
		: allocator()
		, vectorCapacity(vector.size())
		, head(allocator.createArray(vector.size())), tail(head + vector.size())
{
	Pointer it = head;
	for (const Type &i : vector)
		placementNew<Type>(it++, i);
}

TEMPLATE_DEFINE
VECTOR_TYPE::Vector(const VECTOR_TYPE &vector)
		: allocator(vector.allocator)
		, vectorCapacity(vector.size())
		, head(allocator.createArray(vector.size())), tail(head + vector.size())
{
	Pointer it = head;
	for (const Type &i : vector)
		placementNew<Type>(it++, i);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE::Vector(VECTOR_TYPE_1 &&vector) noexcept
		: allocator()
		, vectorCapacity(vector.vectorCapacity)
		, head(allocator.createArray(vector.size())), tail(head + vector.size())
{
	Pointer it = head;
	for (Type &&i : vector)
		placementNew<Type>(it++, move(i));
}

TEMPLATE_DEFINE
VECTOR_TYPE::Vector(VECTOR_TYPE &&vector) noexcept
		: allocator(move(vector.allocator))
		, vectorCapacity(vector.vectorCapacity)
		, head(vector.head), tail(vector.tail)
{
	vector.head = nullptr;
	vector.tail = nullptr;
}

TEMPLATE_DEFINE
VECTOR_TYPE::Vector(typename VECTOR_TYPE::SizeType size)
		: allocator()
		, vectorCapacity((size * VECTOR_RESIZE_FACTOR_MULT) / VECTOR_RESIZE_FACTOR_DIV)
		, head(allocator.construct(vectorCapacity)), tail(head + vectorCapacity)
{}

TEMPLATE_DEFINE
template<SizeTraits::SizeType INIT_LIST_SIZE>
VECTOR_TYPE::Vector(InitializerList<T, INIT_LIST_SIZE> list)
		: allocator()
		, vectorCapacity(list.size())
		, head(allocator.createArray(vectorCapacity)), tail(head + vectorCapacity)
{
	auto itList = list.begin();
	for (auto &i : *this)
	{
		placementNew<Type>(&i, move(*itList));
		++itList;
	}
}

TEMPLATE_DEFINE
VECTOR_TYPE::~Vector()
{
	clean();
	allocator.freeArray(head);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE &VECTOR_TYPE::operator=(const VECTOR_TYPE_1 &vector)
{
	if (capacity() < vector.size())
	{
		reserve(vector.size() - capacity());
		operator=(vector);
	}
	else
	{
		clean();
		auto it = begin();
		for(ConstReference i : vector)
		{
			*it = i;
			++it;
		}
	}
	return *this;
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE &VECTOR_TYPE::operator=(VECTOR_TYPE_1 &&vector) noexcept
{
	Pointer tmp;
	SizeType tmpCapacity;

	tmp = head;
	head = vector.head;
	vector.head = tmp;

	tmp = tail;
	tail = vector.tail;
	vector.tail = tmp;

	tmpCapacity = vectorCapacity;
	vectorCapacity = vector.vectorCapacity;
	vector.vectorCapacity = tmp;

	return *this;
}

TEMPLATE_DEFINE
template<typename IntType>
typename VECTOR_TYPE::Reference VECTOR_TYPE::operator[](
		IntType index) noexcept
{
	return *(head + index);
}

TEMPLATE_DEFINE
template<typename IntType>
typename VECTOR_TYPE::ConstReference VECTOR_TYPE::operator[](
		IntType index) const noexcept
{
	return *(head + index);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Pointer VECTOR_TYPE::data() noexcept
{
	return head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::PointerToConst VECTOR_TYPE::data() const noexcept
{
	return head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::SizeType VECTOR_TYPE::size() const noexcept
{
	return SizeType(tail - head);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::SizeType VECTOR_TYPE::capacity() const noexcept
{
	return vectorCapacity;
}

TEMPLATE_DEFINE
void VECTOR_TYPE::resize(typename VECTOR_TYPE::SizeType newSize)
{
	if (size() < newSize)
	{
		if (capacity() > newSize)
		{
			while (size() != newSize)
				emplaceNew<Type>(tail++);
		}
		else if (capacity() < newSize)
		{
			reserve(nextCapacity());
			resize(newSize);
		}
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::reserve(typename VECTOR_TYPE::SizeType newCapacity)
{
	if (capacity() < newCapacity)
	{
		Pointer tempHead = allocator.reallocateArray(head, newCapacity);
		if (!tempHead)
		{
			tempHead = allocator.createArray(newCapacity);
			if (tempHead)
			{
				Range<Pointer> rangeNew(tempHead, tempHead + newCapacity);
				Range<Iterator> rangeOld(begin(), end());

				auto itNew = rangeNew.begin();
				auto itOld = rangeOld.begin();
				for (; itNew != rangeNew.end() && itOld != rangeOld.end();
						++itNew, ++itOld)
				{
					placementNew<Type>(itNew, move(*itOld));
					itOld->~T();
				}
				allocator.freeArray(head);
				tail = tempHead + size();
				head = tempHead;
				vectorCapacity = newCapacity;
			}
		}
		else
		{
			auto diff = tail - head;
			head = tempHead;
			tail = head + diff;
			vectorCapacity = newCapacity;
		}
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::clean()
{
	for (auto &i : *this)
		i.~T();
	tail = head;
}

TEMPLATE_DEFINE
VECTOR_TYPE VECTOR_TYPE::clone()
{
	Me clone;
	clone.reserve(size());
	for (const Type &i : *this)
		clone.pushBack(i);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Iterator VECTOR_TYPE::begin() noexcept
{
	return Iterator(head);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::begin() const noexcept
{
	return ConstIterator(head);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::cbegin() const noexcept
{
	return begin();
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ReverseIterator VECTOR_TYPE::rbegin() noexcept
{
	return ReverseIterator(--end());
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::rbegin() const noexcept
{
	return ConstReverseIterator(--end());
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::crbegin() const noexcept
{
	return rbegin();
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Iterator VECTOR_TYPE::end() noexcept
{
	return tail;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::end() const noexcept
{
	return tail;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::cend() const noexcept
{
	return end();
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ReverseIterator VECTOR_TYPE::rend() noexcept
{
	return ReverseIterator(--begin());
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::rend() const noexcept
{
	return ConstReverseIterator(--begin());
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::crend() const noexcept
{
	return rend();
}

TEMPLATE_DEFINE
void VECTOR_TYPE::pushBack(typename VECTOR_TYPE::ConstReference object)
{
	if (tail != head + capacity())
	{
		placementNew<Type>(tail, object);
		++tail;
	}
	else
	{
		reserve(nextCapacity());
		pushBack(object);
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::pushBack(typename VECTOR_TYPE::MoveReference object)
{
	if (tail != head + capacity())
		placementNew<Type>(tail++, move(object));
	else
	{
		reserve(nextCapacity());
		pushBack(move(object));
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void VECTOR_TYPE::emplaceBack(Args &&...args)
{
	if (tail != head + capacity())
		emplaceNew<Type>(tail++, forward<decltype(args)>(args)...);
	else
	{
		reserve(nextCapacity());
		emplaceBack(forward<decltype(args)>(args)...);
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::popBack()
{
	if (tail != head)
		(--tail)->~T();
}

TEMPLATE_DEFINE
void VECTOR_TYPE::insert(typename VECTOR_TYPE::Iterator it
		, typename VECTOR_TYPE::ConstReference object)
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
	else
	{
		auto newIt = it - begin();
		reserve(nextCapacity());
		insert(begin() + newIt, object);
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::insert(typename VECTOR_TYPE::Iterator it
		, typename VECTOR_TYPE::MoveReference object)
{
	if (size() < capacity())
	{
		if (it == end())
			pushBack(move(object));
		else
		{
			placementNew<Type>(tail);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(--rangeOld.begin(), --rangeOld.end());
			for (ReverseIterator itOld = rangeOld.begin()
					, itNew = rangeNew.begin(); itOld != rangeOld.end();
					++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = move(object);
			++tail;
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(nextCapacity());
		insert(begin() + newIt, object);
	}
}

TEMPLATE_DEFINE
template<typename InputIterator>
void VECTOR_TYPE::insert(VECTOR_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	auto rangeSize = countIterations(itBegin, itEnd);
	if (!rangeSize)
		return;
	else if (rangeSize + size() <= capacity())
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
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(capacity() + rangeSize);
		insert(begin() + newIt, itBegin, itEnd);
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void VECTOR_TYPE::emplace(typename VECTOR_TYPE::Iterator it, Args &&...args)
{
	if (size() < capacity())
	{
		if (it == end())
			emplaceBack(forward<decltype(args)>(args)...);
		else
		{
			emplaceNew<Type>(tail);

			Range<ReverseIterator> rangeOld(rbegin(), ReverseIterator(it - 1))
					, rangeNew(--rangeOld.begin(), --rangeOld.end());
			for (ReverseIterator itOld = rangeOld.begin()
					, itNew = rangeNew.begin(); itOld != rangeOld.end();
					++itOld, ++itNew)
				*itNew = move(*itOld);

			placementNew<Type>(&(*it), forward<decltype(args)>(args)...);
			++tail;
		}
	}
	else
	{
		auto newIt = it - begin();
		reserve(nextCapacity());
		emplace(begin() + newIt, forward<decltype(args)>(args)...);
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::erase(VECTOR_TYPE::Iterator it)
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
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::erase(typename VECTOR_TYPE::Iterator itBegin
		, typename VECTOR_TYPE::Iterator itEnd)
{
	if (SizeType(itEnd - itBegin) == size())
		clean();
	else if (itEnd - itBegin < SizeTraits::SsizeType(size())
			&& itEnd - itBegin > SizeTraits::SsizeType(0))
	{
		Range<Iterator> rangeErasing(itBegin, itEnd);
		for (auto &i : rangeErasing)
			i.~T();

		auto rangeOld = makeRange(itEnd, end());
		auto rangeNew = makeRange(itBegin, itBegin + (end() - itEnd));
		for (Iterator itOld = rangeOld.begin(), itNew = rangeNew.begin();
				itOld != rangeOld.end(); ++itNew, ++itOld)
			*itNew = move(*itOld);

		tail -= SizeType(rangeErasing.end() - rangeErasing.begin());
	}
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::SizeType VECTOR_TYPE::nextCapacity() const
{
	return ((capacity() * VECTOR_RESIZE_FACTOR_MULT) / VECTOR_RESIZE_FACTOR_DIV);
}

}}

#undef TEMPLATE_DEFINE
#undef TEMPLATE_DEFINE_1
#undef VECTOR_TYPE
#undef VECTOR_TYPE_1

#endif // FLAMEIDE_TEMPLATES_VECTOR_HPP
