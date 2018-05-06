#ifndef TEMPLATES_CIRCULARVECTOR_HPP
#define TEMPLATES_CIRCULARVECTOR_HPP

#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

namespace circularvector_utils
{

template<typename T, typename Traits = ContainerTraits<T>>
class Iterator: public iterator_utils::BaseIterator<
		T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT, Traits>
{
public:
	using Me = Iterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT, Traits
	>;

	using typename Parent::Type;
	using typename Parent::Reference;
	using typename Parent::Pointer;
	using typename Parent::SizeType;
	using typename Parent::SsizeType;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(Me &&) = default;
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
	Me operator+(Me iterator);

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
};

template<typename T, typename Traits = ContainerTraits<T>>
class ConstIterator: public iterator_utils::BaseIterator<
		const T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::CONSTANT, Traits>
{
public:
	using Me = Iterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::CONSTANT, Traits
	>;

	using typename Parent::Type;

	using typename Parent::ConstReference;
	using typename Parent::PointerToConst;

	using typename Parent::SizeType;
	using typename Parent::SsizeType;

	ConstIterator() = default;
	ConstIterator(const Me &) = default;
	ConstIterator(Me &&) = default;
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
};

} // circularvector_utils

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>
>
class CircularVector: public Traits
{
public:
	using Me = CircularVector<T, Traits, Allocator>;
	using Parent = Traits;

	using Iterator = circularvector_utils::Iterator<T, Traits>;
	using ConstIterator = circularvector_utils::ConstIterator<T, Traits>;
	using ReverseIterator = ReverseIterator<Iterator>;
	using ConstReverseIterator = ConstReverseIterator<ConstIterator>;

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
	Me &operator=(Me &&);

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	Reference operator[](Types::ssize_t index);

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	ConstReference operator[](Types::ssize_t index) const;

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

	T *array; /**< */
	T *head; /**< */
	T *tail; /**< */
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
Iterator<T, Traits> &Iterator<T, Traits>::operator++()
{}

template<typename T, typename Traits>
Iterator<T, Traits> Iterator<T, Traits>::operator++(int)
{}

template<typename T, typename Traits>
Iterator<T, Traits> &Iterator<T, Traits>::operator--()
{}

template<typename T, typename Traits>
Iterator<T, Traits> Iterator<T, Traits>::operator--(int)
{}

template<typename T, typename Traits>
typename Iterator<T, Traits>::Reference Iterator<T, Traits>::operator*()
{}

template<typename T, typename Traits>
typename Iterator<T, Traits>::Pointer Iterator<T, Traits>::operator->()
{}


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



// private

template<typename T, typename Traits, typename Allocator>
typename CircularVector<T, Traits, Allocator>::SizeType
CircularVector<T, Traits, Allocator>::realCapacity() const noexcept
{
	return vectorCapacity;
}

}}

#endif // TEMPLATES_CIRCULARVECTOR_HPP
