#ifndef TEMPLATES_VECTOR_HPP
#define TEMPLATES_VECTOR_HPP

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/InitializerList.hpp>
#include <Templates/View.hpp>

#define TEMPLATE_DEFINE \
	template< \
		typename T \
		, typename Traits \
		, typename Allocator \
		, typename Traits::SizeType START_SIZE \
		, typename Traits::SizeType RESIZE_FACTOR_MULT \
		, typename Traits::SizeType RESIZE_FACTOR_DIV \
	>

#define TEMPLATE_DEFINE_1 \
	template<\
		typename Traits1 \
		, typename Allocator1 \
		, typename Traits::SizeType START_SIZE1 \
		, typename Traits::SizeType RESIZE_FACTOR_MULT1 \
		, typename Traits::SizeType RESIZE_FACTOR_DIV1 \
	>

#define VECTOR_TYPE \
	Vector< \
		T, Traits, Allocator \
		, START_SIZE, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>

#define VECTOR_TYPE_1 \
	Vector< \
		T, Traits1, Allocator1 \
		, START_SIZE1, RESIZE_FACTOR_MULT1, RESIZE_FACTOR_DIV1>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T, Traits>
	, typename Traits::SizeType START_SIZE = 16
	, typename Traits::SizeType RESIZE_FACTOR_MULT = 3
	, typename Traits::SizeType RESIZE_FACTOR_DIV = 2
>
class Vector: public Traits
{
public:
	static_assert(RESIZE_FACTOR_MULT > RESIZE_FACTOR_DIV, "Error");

	using Me = VECTOR_TYPE;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using Iterator = flame_ide::templates::Iterator<
		Pointer, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ConstIterator = flame_ide::templates::ConstIterator<Iterator>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = flame_ide::templates::ConstIterator<ReverseIterator>;

	/**
	 * @brief Vector
	 */
	Vector();

	/**
	 * @brief Vector
	 * @param vector
	 */
	TEMPLATE_DEFINE_1
	Vector(const VECTOR_TYPE_1 &vector);

	/**
	 * @brief Vector
	 * @param vector
	 */
	TEMPLATE_DEFINE_1
	Vector(VECTOR_TYPE_1 &&vector) noexcept;

	/**
	 * @brief Vector
	 * @param size
	 */
	Vector(SizeType size);

	template<typename ...Args>
	Vector(Args &&...args);

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
	TEMPLATE_DEFINE_1
	Me &operator=(VECTOR_TYPE_1 &&vector) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	Reference operator[](SizeType index) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	ConstReference operator[](SizeType index) const noexcept;

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
	 * @brief first
	 * @return
	 */
	Reference first();

	/**
	 * @brief first
	 * @return
	 */
	ConstReference first() const;

	/**
	 * @brief last
	 * @return
	 */
	Reference last();

	/**
	 * @brief last
	 * @return
	 */
	ConstReference last() const;

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
	Iterator begin();

	/**
	 * @brief begin
	 * @return
	 */
	ConstIterator begin() const;

	/**
	 * @brief end
	 * @return
	 */
	Iterator end();

	/**
	 * @brief end
	 * @return
	 */
	ConstIterator end() const;

	/**
	 * @brief rbegin
	 * @return
	 */
	ReverseIterator rbegin();

	/**
	 * @brief rbegin
	 * @return
	 */
	ConstReverseIterator rbegin() const;

	/**
	 * @brief rend
	 * @return
	 */
	ReverseIterator rend();

	/**
	 * @brief rend
	 * @return
	 */
	ConstReverseIterator rend() const;

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

	// TODO
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

	Pointer head;
	Pointer tail;
	SizeType vectorCapacity;
	Allocator allocator;
};

}}

namespace flame_ide
{namespace templates
{

TEMPLATE_DEFINE
VECTOR_TYPE::Vector() :
		head(nullptr), tail(nullptr)
		, vectorCapacity(0)
		, allocator()
{}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE::Vector(const VECTOR_TYPE_1 &vector) :
		head(vector.allocator.createArray(vector.size()))
		, tail(head + vector.size())
		, vectorCapacity(vector.size())
{
	Iterator it = head;
	for (const Type &i : vector)
		placementNew<Type>(it, i);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE::Vector(VECTOR_TYPE_1 &&vector) noexcept
		: head(vector.head)
		, tail(vector.tail)
		, vectorCapacity(vector.vectorCapacity)
{
	vector.head = nullptr;
	vector.tail = nullptr;
}

TEMPLATE_DEFINE
VECTOR_TYPE::Vector(typename VECTOR_TYPE::SizeType size) : Vector()
{
	vectorCapacity = size;

	head = allocator.createArray(nextCapacity());
	tail = head + size;

	vectorCapacity = nextCapacity();
}

TEMPLATE_DEFINE
template<typename ...Args>
VECTOR_TYPE::Vector(Args &&...args)
{
	head = allocator.createArray(sizeof...(Args) * sizeof(Type));
	tail = head + sizeof...(Args);
	vectorCapacity = sizeof...(Args);

	InitializerList<Type, sizeof...(Args)> list(forward<decltype(args)>(args)...);
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
	for (auto &i : *this)
		i.~T();
	allocator.freeArray(head);
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE &VECTOR_TYPE::operator=(const VECTOR_TYPE_1 &vector)
{
	auto tempHead = allocator.createArray(vector.size());
	auto it = tempHead;
	for (const Type &i : vector)
		placementNew<Type>(it++, i);

	for (auto &i : *this)
		i.~T();
	allocator.freeArray(head);

	vectorCapacity = vector.size();
	head = tempHead;
	tail = head + vectorCapacity;
}

TEMPLATE_DEFINE TEMPLATE_DEFINE_1
VECTOR_TYPE &VECTOR_TYPE::operator=(VECTOR_TYPE_1 &&vector) noexcept
{
	head = vector.head;
	tail = vector.tail;
	vectorCapacity = vector.vectorCapacity;

	vector.head = nullptr;
	vector.tail = nullptr;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Reference VECTOR_TYPE::operator[](
		typename VECTOR_TYPE::SizeType index) noexcept
{
	return *(head + index);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReference VECTOR_TYPE::operator[](
		typename VECTOR_TYPE::SizeType index) const noexcept
{
	return *(head + index);
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
				placementNew<Type>(tail++);
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
		Pointer tempHead = allocator.createArray(newCapacity);
		if (tempHead)
		{
			Range<Pointer> rangeNew(tempHead, tempHead + newCapacity);
			View<Me> viewOld(begin(), end());

			auto itNew = rangeNew.begin();
			auto itOld = viewOld.begin();
			for (; itNew != rangeNew.end() && itOld != viewOld.end();
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
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Reference VECTOR_TYPE::first()
{
	return *head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReference VECTOR_TYPE::first() const
{
	return *head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Reference VECTOR_TYPE::last()
{
	return *(tail - 1);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReference VECTOR_TYPE::last() const
{
	return *(tail - 1);
}

TEMPLATE_DEFINE
void VECTOR_TYPE::clean()
{
	for (auto &i : *this)
		i.~T();
	tail = head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Iterator VECTOR_TYPE::begin()
{
	return head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::begin() const
{
	return head;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::Iterator VECTOR_TYPE::end()
{
	return tail;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstIterator VECTOR_TYPE::end() const
{
	return tail;
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ReverseIterator VECTOR_TYPE::rbegin()
{
	return ReverseIterator(end() - 1);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::rbegin() const
{
	return ConstReverseIterator(end() - 1);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ReverseIterator VECTOR_TYPE::rend()
{
	return ReverseIterator(begin() - 1);
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::ConstReverseIterator VECTOR_TYPE::rend() const
{
	return ConstReverseIterator(begin() - 1);
}

TEMPLATE_DEFINE
void VECTOR_TYPE::pushBack(typename VECTOR_TYPE::ConstReference object)
{
	if (tail != head + capacity())
		placementNew<Type>(tail++, object);
	else
	{
		reserve((capacity() * RESIZE_FACTOR_MULT) / RESIZE_FACTOR_DIV);
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
		reserve((capacity() * RESIZE_FACTOR_MULT) / RESIZE_FACTOR_DIV);
		pushBack(move(object));
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void VECTOR_TYPE::emplaceBack(Args &&...args)
{
	if (tail != head + capacity())
		placementNew<Type>(tail++, forward(args)...);
	else
	{
		reserve((capacity() * RESIZE_FACTOR_MULT) / RESIZE_FACTOR_DIV);
		emplaceBack(forward(args...));
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
			placementNew<Type>(tail);
			View<Me, ReverseIterator> viewOld(rbegin(), ReverseIterator(it));
			View<Me, ReverseIterator> viewNew(--viewOld.begin(), --viewOld.end());

			for (ReverseIterator itOld = viewOld.begin(), itNew = viewNew.begin();
					itNew != viewNew.end() - 1; ++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = object;
			++tail;
		}
	}
	else
	{
		reserve(nextCapacity());
		insert(it, object);
	}
}

TEMPLATE_DEFINE
void VECTOR_TYPE::insert(
		typename VECTOR_TYPE::Iterator it
		, typename VECTOR_TYPE::MoveReference object)
{
	if (size() < capacity())
	{
		if (it == end())
			pushBack(move(object));
		else
		{
			placementNew<Type>(tail);
			View<Me> viewOld(rbegin(), ReverseIterator(it + 1));
			View<Me> viewNew(--viewOld.begin(), --viewOld.end());

			for (ReverseIterator itOld = viewOld.begin()
					, itNew = viewNew.begin(); itOld != viewOld.end();
					++itOld, ++itNew)
				*itNew = move(*itOld);

			*it = move(object);
			++tail;
		}
	}
	else
	{
		reserve(nextCapacity());
		insert(it, object);
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
			for (Reference itInsert : range)
				pushBack(itInsert);
		else
		{
			View<Me> initView(end(), end() + rangeSize);
			for (Reference it : initView)
				placementNew<Type>(&it);

			View<Me, ReverseIterator> viewOld(rbegin(), ReverseIterator(it - 1));
			View<Me, ReverseIterator> viewNew(viewOld.begin() + rangeSize
					, viewOld.end() + rangeSize);
			for (ReverseIterator itOld = viewOld.begin(), itNew = viewNew.begin();
					itOld != viewOld.end(); ++itOld, ++itNew)
				*itNew = move(*itOld);

			for (auto &itInsert : range)
				*it = itInsert
				, ++it;
			tail += rangeSize;
		}
	}
}

// TODO: add implementation
TEMPLATE_DEFINE
template<typename ...Args>
void VECTOR_TYPE::emplace(typename VECTOR_TYPE::Iterator it, Args &&...args)
{
}

TEMPLATE_DEFINE
void VECTOR_TYPE::erase(VECTOR_TYPE::Iterator it)
{
	if (it == end())
		return;
	else if (it == end() - 1)
		popBack();
	else
	{
		View<Me> viewOld(it + 1, end());
		View<Me> viewNew(viewOld.begin() - 1, viewOld.end() - 1);
		for (Iterator itOld = viewOld.begin(), itNew = viewNew.begin();
				itOld != viewOld.end(); ++itOld, ++itNew)
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
		View<Me> viewErasing(itBegin, itEnd);
		for (auto &i : viewErasing)
			i.~T();

		View<Me> viewOld(itEnd, end());
		View<Me> viewNew(itBegin, itBegin + (end() - itEnd));
		for (Iterator itOld = viewOld.begin(), itNew = viewNew.begin();
				itOld != viewOld.end(); ++itNew, ++itOld)
			*itNew = move(*itOld);

		tail -= SizeType(viewErasing.end() - viewErasing.begin());
	}
}

TEMPLATE_DEFINE
typename VECTOR_TYPE::SizeType VECTOR_TYPE::nextCapacity() const
{
	return ((capacity() * RESIZE_FACTOR_MULT) / RESIZE_FACTOR_DIV);
}

}}

#undef TEMPLATE_DEFINE
#undef TEMPLATE_DEFINE_1
#undef VECTOR_TYPE
#undef VECTOR_TYPE_1

#endif // TEMPLATES_VECTOR_HPP
