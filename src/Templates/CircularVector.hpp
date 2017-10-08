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
	using Parent = BaseIterator<
		T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::NON_CONSTANT, Traits
	>;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

private:
	using Parent::wrappedIterator;
};

template<typename T, typename Traits = ContainerTraits<T>>
class ConstIterator: public iterator_utils::BaseIterator<
		const T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::CONSTANT, Traits>
{
public:
	using Me = Iterator<T, Traits>;
	using Parent = BaseIterator<
		T *, IteratorCategory::RANDOM_ACCESS, IteratorAccess::CONSTANT, Traits
	>;

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	using typename Parent::Pointer;
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
}

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>
>
class CircularVector: public Traits
{
public:
	using Me = CircularVector<T, Traits, Allocator>;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	CircularVector();
	CircularVector(const Me &);
	CircularVector(Me &&);
	~CircularVector();
	Me &operator=(const Me &);
	Me &operator=(Me &&);

	SizeType size() const;
	SizeType capacity() const;

private:
	T *array;
	T *head;
	T *tail;
	SizeType vectorCapacity;
};

}}

#endif // TEMPLATES_CIRCULARVECTOR_HPP
