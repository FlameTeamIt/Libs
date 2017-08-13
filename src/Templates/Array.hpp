#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/InitializerList.hpp>
#include <Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief Array
 */
template<class T, SizeTraits::SizeType SIZE, typename Traits = ContainerTraits<T>>
class Array
{
public:
	using Me = Array<T, SIZE, Traits>;
	using SizeType = typename Traits::SizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Iterator = Pointer;
	using ConstIterator = PointerToConst;
	using ReverseIterator = flame_ide::templates::RaReverseIterator<Iterator, Traits>;
	using ConstReverseIterator = const ReverseIterator;

	/**
	 * @brief Array
	 */
	Array();

	/**
	 * @brief Array
	 * @param array
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits1>
	Array(const Array<T, SIZE1, Traits1> &objects);

	/**
	 * @brief Array
	 * @param array
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits1>
	Array(Array<T, SIZE1, Traits1> &&objects);

	/**
	 * @brief Array
	 * @param list
	 */
	Array(InitializerList<T, SIZE> list);

	~Array();

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits1>
	Me &operator=(const Array<T, SIZE1, Traits1> &objects);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits1>
	Me &operator=(Array<T, SIZE1, Traits1> &&objects);

	/**
	 * @brief size
	 * @return
	 */
	inline typename Traits::SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @return
	 */
	inline constexpr typename Traits::SizeType capacity() const noexcept;

	/**
	 * @brief first
	 * @return
	 */
	inline Reference first();

	/**
	 * @brief first
	 * @return
	 */
	inline ConstReference first() const;

	/**
	 * @brief first
	 * @return
	 */
	inline Reference last();

	/**
	 * @brief first
	 * @return
	 */
	inline ConstReference last() const;

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
	Type objects[SIZE];
	Pointer tail;
};

}}

namespace flame_ide
{namespace templates
{

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::Array()
{
	tail = objects;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<SizeTraits::SizeType SIZE1, typename Traits1>
Array<T, SIZE, Traits>::Array(const Array<T, SIZE1, Traits1> &array)
{
	if (array.size() <= capacity())
		for(auto &i : array)
			pushBack(i);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<SizeTraits::SizeType SIZE1, typename Traits1>
Array<T, SIZE, Traits>::Array(Array<T, SIZE1, Traits1> &&array)
{
	if (array.size() <= capacity())
		for(auto &&i : array)
			pushBack(move(i));
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::Array(InitializerList<T, SIZE> list)
{
	Pointer pointer = objects;
	for (auto it : list)
	{
		new(pointer++) T(move(it));
	}
	tail = pointer;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::~Array()
{
	for (auto &i : *this)
	{
		i.~T();
	}
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<SizeTraits::SizeType SIZE1, typename Traits1>
Array<T, SIZE, Traits> &
Array<T, SIZE, Traits>::operator=(const Array<T, SIZE1, Traits1> &array)
{
	if (array.size() <= capacity())
	{
		clean();
		for (auto const &i : array)
			pushBack(i);
	}
	return *this;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<SizeTraits::SizeType SIZE1, typename Traits1>
Array<T, SIZE, Traits> &
Array<T, SIZE, Traits>::operator=(Array<T, SIZE1, Traits1> &&array)
{
	if (array.size() <= capacity())
	{
		clean();
		for (auto &&i : array)
			pushBack(move(i));
	}
	return *this;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Traits::SizeType
Array<T, SIZE, Traits>::size() const noexcept
{
	return SizeType(tail - objects);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> constexpr
typename Traits::SizeType
Array<T, SIZE, Traits>::capacity() const noexcept
{
	return SIZE;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::Reference
Array<T, SIZE, Traits>::first()
{
	return *begin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstReference
Array<T, SIZE, Traits>::first() const
{
	return *begin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::Reference
Array<T, SIZE, Traits>::last()
{
	return *rbegin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstReference
Array<T, SIZE, Traits>::last() const
{
	return *rbegin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::Iterator
Array<T, SIZE, Traits>::begin() noexcept
{
	return objects;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstIterator
Array<T, SIZE, Traits>::begin() const noexcept
{
	return objects.array;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::Iterator
Array<T, SIZE, Traits>::end() noexcept
{
	return tail;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstIterator
Array<T, SIZE, Traits>::end() const noexcept
{
	return tail;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ReverseIterator
Array<T, SIZE, Traits>::rbegin() noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstReverseIterator
Array<T, SIZE, Traits>::rbegin() const noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ReverseIterator
Array<T, SIZE, Traits>::rend() noexcept
{
	auto it = begin();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
typename Array<T, SIZE, Traits>::ConstReverseIterator
Array<T, SIZE, Traits>::rend() const noexcept
{
	auto it = begin();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::pushBack(
		typename Array<T, SIZE, Traits>::ConstReference object)
{
	if (size() < capacity())
		placementNew<Type>(tail++, T(forward(object)));
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::pushBack(
		typename Array<T, SIZE, Traits>::MoveReference object)
{
	if (size() < capacity())
		placementNew<Type>(tail++, T(move(object)));
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<typename ...Args>
void Array<T, SIZE, Traits>::emplaceBack(Args &&...args)
{
	if (size() < capacity())
	{
		new (tail++) Type(forward(args)...);
	}
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::popBack()
{
	if (size())
	{
		(end() - 1)->~T();
		--tail;
	}
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::insert(typename Array<T, SIZE, Traits>::Iterator it
		, typename Array<T, SIZE, Traits>::ConstReference object)
{
	if (size() < capacity())
	{
		if (it == end())
			pushBack(object);
		else
		{
			placementNew<Type>(tail);
			for (ReverseIterator run(tail); run != it; ++run)
				run = move(*(run + 1));
			++tail;

			*it = object;
		}
	}
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::insert(typename Array<T, SIZE, Traits>::Iterator it
		, typename Array<T, SIZE, Traits>::MoveReference object)
{
	if (size() < capacity())
	{
		if (it == end())
			pushBack(move(object));
		else
		{
			placementNew<Type>(tail);
			for (ReverseIterator run(tail); run != it; ++run)
				run = move(*(run + 1));
			++tail;

			*it = object;
		}
	}
}

}}

#endif // TEMPLATES_ARRAY
