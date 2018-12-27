#ifndef FLAMEIDE_TEMPLATES_CIRCULARVECTOR_HPP
#define FLAMEIDE_TEMPLATES_CIRCULARVECTOR_HPP

#include <FlameIDE/Templates/Allocator.hpp>
#include <FlameIDE/Templates/Iterator.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>
>
class CircularVector;

namespace circularvector_utils
{

template<typename T, typename Traits = ContainerTraits<T>>
class Iterator: public iterator_utils::BaseIterator<
			typename Traits::Pointer
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
		>
{
public:
	using Me = Iterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		typename Traits::Pointer
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;

	using typename Parent::Type;
	using typename Parent::Reference;
	using typename Parent::Pointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;
	using IteratorType = Pointer;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(Me &&) = default;
	Iterator(Pointer initWappedIterator, Pointer initActualBegin
			, Pointer initActualEnd);
	~Iterator() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++();
	Me operator++(int);
	Me &operator--();
	Me operator--(int);

	Reference operator*();
	Pointer operator->();

	template<typename IntType>
	Me operator+(IntType integer);

	template<typename IntType>
	Me operator-(IntType integer);

	SsizeType operator-(Me integer);

	bool operator==(const Me &iterator);
	bool operator!=(const Me &iterator);
	bool operator>(const Me &iterator);
	bool operator<(const Me &iterator);
	bool operator>=(const Me &iterator);
	bool operator<=(const Me &iterator);

private:
	using Parent::wrappedIterator;
	Pointer actualArrayBegin;
	Pointer actualArrayEnd;
};

template<typename T, typename Traits = ContainerTraits<T>>
class ConstIterator: public iterator_utils::BaseIterator<
			typename Traits::PointerToConst
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::CONSTANT
			, Traits
		>
{
public:
	using Me = ConstIterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		typename Traits::PointerToConst
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::CONSTANT
		, Traits
	>;

	using typename Parent::Type;
	using typename Parent::ConstReference;
	using typename Parent::PointerToConst;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;
	using IteratorType = PointerToConst;

	ConstIterator() = default;
	ConstIterator(const Me &) = default;
	ConstIterator(Me &&) = default;
	ConstIterator(PointerToConst initWappedIterator
			, PointerToConst initActualBegin
			, PointerToConst initActualEnd);
	~ConstIterator() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++();
	Me &operator++(int);
	Me &operator--();
	Me &operator--(int);

	ConstReference operator*() const;
	PointerToConst operator->() const;

	template<typename IntType>
	Me operator+(IntType integer);
	Me operator+(Me iterator);

	template<typename IntType>
	Me operator-(IntType integer);
	SsizeType operator-(Me integer);

	bool operator>(Me iterator);
	bool operator<(Me iterator);
	bool operator>=(Me iterator);
	bool operator<=(Me iterator);

private:
	using Parent::wrappedIterator;
	PointerToConst actualArrayBegin;
	PointerToConst actualArrayEnd;
};

} // circularvector_utils

// TODO: маловато параметров
template<typename T, typename Traits, typename Allocator>
class CircularVector: public Traits
{
public:
	using Me = CircularVector<T, Traits, Allocator>;
	using Parent = Traits;

	using Iterator = circularvector_utils::Iterator<T, Parent>;
	using ConstIterator = circularvector_utils::ConstIterator<T, Parent>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = flame_ide::templates::ConstReverseIterator<ConstIterator>;

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	using typename Parent::SizeType;
	using typename Parent::SsizeType;

	CircularVector() noexcept;
	CircularVector(const Me &);
	CircularVector(Me &&) noexcept;

	/**
	 * @brief CircularVector
	 * @param beginIt
	 * @param endIt
	 */
	template<typename InputIterator>
	CircularVector(InputIterator beginIt, InputIterator endIt);

	~CircularVector();

	Me &operator=(const Me &);
	Me &operator=(Me &&) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	Reference operator[](SsizeType index);

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	ConstReference operator[](SsizeType index) const;

	/**
	 * @brief size
	 * @return
	 */
	SizeType size() const;

	/**
	 * @brief capacity
	 * @return
	 */
	SizeType capacity() const;

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
	 * @brief pushBack
	 * @param itBegin
	 * @param itEnd
	 */
	template<typename InputIterator>
	void pushBack(InputIterator itBegin, InputIterator itEnd);

	/**
	 * @brief pushFront
	 * @param object
	 */
	void pushFront(ConstReference object);

	/**
	 * @brief pushFront
	 * @param object
	 */
	void pushFront(MoveReference object);

	/**
	 * @brief pushFront
	 * @param itBegin
	 * @param itEnd
	 */
	template<typename InputIterator>
	void pushFront(InputIterator itBegin, InputIterator itEnd);
	/**
	 * @brief emplaceBack
	 * @param args
	 */
	template<typename ...Args>
	void emplaceBack(Args &&...args);

	/**
	 * @brief emplaceFront
	 * @param args
	 */
	template<typename ...Args>
	void emplaceFront(Args &&...args);

	/**
	 * @brief popBack
	 */
	void popBack();

	/**
	 * @brief popFront
	 */
	void popFront();

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
	 * @brief cbegin
	 * @return
	 */
	ConstIterator cbegin() const;

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
	 * @brief crbegin
	 * @return
	 */
	ConstReverseIterator crbegin() const;

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
	 * @brief cend
	 * @return
	 */
	ConstIterator cend() const;

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
	 * @brief crend
	 * @return
	 */
	ConstReverseIterator crend() const;

private:
	SizeType realCapacity() const noexcept;

	Pointer array; /**< */
	Pointer head; /**< */
	Pointer tail; /**< */
	SizeType vectorCapacity; /**< */
	Allocator allocator;

}; // class CircularVector

}}

namespace flame_ide
{namespace templates
{

namespace circularvector_utils
{

// Iterator
template<typename T, typename Traits>
Iterator<T, Traits>::Iterator(Pointer initWappedIterator, Pointer initActualBegin
		, Pointer initActualEnd)
		: Parent(initWappedIterator)
		, actualArrayBegin(initActualBegin)
		, actualArrayEnd(initActualEnd)
{}

template<typename T, typename Traits>
Iterator<T, Traits> &Iterator<T, Traits>::operator++()
{
	if (wrappedIterator + 1 == actualArrayEnd)
	{
		wrappedIterator = actualArrayBegin;
	}
	else
	{
		++wrappedIterator;
	}
	return *this;
}

template<typename T, typename Traits>
Iterator<T, Traits> Iterator<T, Traits>::operator++(int)
{
	Me tempIterator(this->wrappedIterator,
			this->actualArrayBegin, this->actualArrayEnd);
	++(*this);
	return tempIterator;
}

template<typename T, typename Traits>
Iterator<T, Traits> &Iterator<T, Traits>::operator--()
{
	if (wrappedIterator == actualArrayBegin)
	{
		wrappedIterator = actualArrayEnd - 1;
	}
	else
	{
		--wrappedIterator;
	}
	return *this;
}

template<typename T, typename Traits>
Iterator<T, Traits> Iterator<T, Traits>::operator--(int)
{
	Iterator<T, Traits> tempIterator(this->wrappedIterator,
			this->actualArrayBegin, this->actualArrayEnd);
	--(*this);
	return tempIterator;
}

template<typename T, typename Traits>
typename Iterator<T, Traits>::Reference Iterator<T, Traits>::operator*()
{
	return *wrappedIterator;
}

template<typename T, typename Traits>
typename Iterator<T, Traits>::Pointer Iterator<T, Traits>::operator->()
{
	return wrappedIterator;
}

// ConstIterator

} // circularvector_utils

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator>::CircularVector() noexcept
		: array(nullptr), head(nullptr), tail(nullptr) , vectorCapacity(0), allocator()
{}

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator>::CircularVector(const Me &me)
		: CircularVector<T, Traits, Allocator>()
{
	array = allocator.createArray(me.size() + 1);
	head = tail = array;
	vectorCapacity = me.size() + 1;
}

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator>::CircularVector(Me &&me) noexcept
		: array(move(me.array)), head(move(me.head)), tail(move(me.tail))
		, vectorCapacity(move(me.vectorCapacity)), allocator(move(me.allocator))
{
	me.array = me.head = me.tail = nullptr;
	me.vectorCapacity = 0;
}

template<typename T, typename Traits, typename Allocator>
template<typename InputIterator>
CircularVector<T, Traits, Allocator>::CircularVector(InputIterator beginIt, InputIterator endIt)
		: CircularVector<T, Traits, Allocator>()
{
	auto size = countIterations(beginIt, endIt);
	array = allocator.createArray(size + 1);
	head = tail = array;
	vectorCapacity = size + 1;
}

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator>::~CircularVector()
{
	/*
	for (auto i : *this)
	{
		i.~T();
	}
	*/
	allocator.freeArray(array);
}

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator> &
CircularVector<T, Traits, Allocator>::operator=(const Me &me)
{
	if (&me != this)
	{
	}
	*this;
}

template<typename T, typename Traits, typename Allocator>
CircularVector<T, Traits, Allocator> &
CircularVector<T, Traits, Allocator>::operator=(Me &&me) noexcept
{
	if (&me != this)
	{
	}
	*this;
}

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::Reference
CircularVector<T, Traits, Allocator>::operator[](
		CircularVector<T, Traits, Allocator>::SsizeType index)
{
	// TODO: закостылено
	return head[index];
}

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::ConstReference
CircularVector<T, Traits, Allocator>::operator[](
		CircularVector<T, Traits, Allocator>::SsizeType index) const
{
	// TODO: закостылено
	return head[index];
}

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::SizeType
CircularVector<T, Traits, Allocator>::size() const
{
	// TODO: закостылено
	return tail - head;
}

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::SizeType
CircularVector<T, Traits, Allocator>::capacity() const
{
	return realCapacity() - 1;
}


// private

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::SizeType
CircularVector<T, Traits, Allocator>::realCapacity() const noexcept
{
	return vectorCapacity;
}

}}

#endif // FLAMEIDE_TEMPLATES_CIRCULARVECTOR_HPP
