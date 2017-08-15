#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/InitializerList.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/View.hpp>

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
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	inline Reference operator[](SizeType index) noexcept;

	/**
	 * @brief operator[]
	 * @param index
	 * @return
	 */
	inline ConstReference operator[](SizeType index) const noexcept;

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
	inline Pointer head();
	inline PointerToConst head() const;

	Types::byte_t bytes[sizeof(Type) * SIZE];
	Pointer tail;
};

}}

namespace flame_ide
{namespace templates
{

template<typename T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::Array()
{
	tail = head();
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
	Pointer pointer = head();
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

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Reference
Array<T, SIZE, Traits>::operator[](typename Array<T, SIZE, Traits>::SizeType index) noexcept
{
	return head()[index];
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstReference
Array<T, SIZE, Traits>::operator[](typename Array<T, SIZE, Traits>::SizeType index) const noexcept
{
	return head()[index];
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Traits::SizeType
Array<T, SIZE, Traits>::size() const noexcept
{
	return SizeType(tail - head());
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> constexpr inline
typename Traits::SizeType
Array<T, SIZE, Traits>::capacity() const noexcept
{
	return SIZE;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Reference
Array<T, SIZE, Traits>::first()
{
	return *begin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstReference
Array<T, SIZE, Traits>::first() const
{
	return *begin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Reference
Array<T, SIZE, Traits>::last()
{
	return *rbegin();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstReference
Array<T, SIZE, Traits>::last() const
{
	return *rbegin();
}

// TODO
template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
void Array<T, SIZE, Traits>::clean()
{
	for (auto &it : *this)
		it.~T();
	tail = head();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Iterator
Array<T, SIZE, Traits>::begin() noexcept
{
	return head();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstIterator
Array<T, SIZE, Traits>::begin() const noexcept
{
	return head();
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Iterator
Array<T, SIZE, Traits>::end() noexcept
{
	return tail;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstIterator
Array<T, SIZE, Traits>::end() const noexcept
{
	return tail;
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ReverseIterator
Array<T, SIZE, Traits>::rbegin() noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ConstReverseIterator
Array<T, SIZE, Traits>::rbegin() const noexcept
{
	auto it = end();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::ReverseIterator
Array<T, SIZE, Traits>::rend() noexcept
{
	auto it = begin();
	return ReverseIterator(--it);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
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
			View<Me, ReverseIterator> viewOld(rbegin(), ReverseIterator(it));
			View<Me, ReverseIterator> viewNew(--viewOld.begin(), --viewOld.end());

			for (ReverseIterator itOld = viewOld.begin(), itNew = viewNew.begin();
					itNew != viewNew.end() - 1; ++itOld, ++itNew)
			{
				*itNew = move(*itOld);
			}

			*it = object;
			++tail;
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
			View<Me> viewOld(rbegin(), ReverseIterator(it + 1));
			View<Me> viewNew(--viewOld.begin(), --viewOld.end());

			for (ReverseIterator itOld = viewOld.begin()
					, itNew = viewNew.begin(); itOld != viewOld.end();
					++itOld, ++itNew)
			{
				*itNew = move(*itOld);
			}

			*it = move(object);
			++tail;
		}
	}
}

// TODO
template<typename T, SizeTraits::SizeType SIZE, typename Traits>
template<typename InputIterator>
void Array<T, SIZE, Traits>::insert(typename Array<T, SIZE, Traits>::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	if (itBegin == itEnd)
		return;

	auto rangeSize = countIterations(itBegin, itEnd);
	if (rangeSize + size() <= capacity())
	{
		Pointer headPointer = head();
		Range<InputIterator> range(itBegin, itEnd);
		if (it == end())
			for (Reference itInsert : range)
				pushBack(itInsert);
		else
		{
			View<Me> initView(end(), end() + rangeSize);
			for (Reference it : initView)
				placementNew<Type>(&it);

			// [000i00____] < [000111i00_]
			View<Me, ReverseIterator> viewOld(rbegin(), ReverseIterator(it - 1));
			View<Me, ReverseIterator> viewNew(viewOld.begin() + rangeSize
					, viewOld.end() + rangeSize);
			for (ReverseIterator itOld = viewOld.begin(), itNew = viewNew.begin();
					itOld != viewOld.end(); ++itOld, ++itNew)
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

// TODO
template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::erase(Array<T, SIZE, Traits>::Iterator it)
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
				itOld != viewNew.end(); ++itOld, ++itNew)
		{
			*itNew = *itOld;
		}
		--tail;
	}
}

// TODO
template<typename T, SizeTraits::SizeType SIZE, typename Traits>
void Array<T, SIZE, Traits>::erase(Array<T, SIZE, Traits>::Iterator itBegin
		, Array<T, SIZE, Traits>::Iterator itEnd)
{
	if (itBegin >= itEnd)
		return;

	if (SizeType(itEnd - itBegin) == size())
		clean();
	else
	{
		Pointer headPointer = head();

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

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::Pointer
Array<T, SIZE, Traits>::head()
{
	return reinterpret_cast<Pointer>(bytes);
}

template<typename T, SizeTraits::SizeType SIZE, typename Traits> inline
typename Array<T, SIZE, Traits>::PointerToConst
Array<T, SIZE, Traits>::head() const
{
	return reinterpret_cast<PointerToConst>(bytes);
}

}}

#endif // TEMPLATES_ARRAY
