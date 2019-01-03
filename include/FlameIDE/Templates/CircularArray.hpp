#ifndef FLAMEIDE_TEMPLATES_CIRCULARARRAY_HPP
#define FLAMEIDE_TEMPLATES_CIRCULARARRAY_HPP

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

template <typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits
>
class CircularArray;

}}

namespace flame_ide
{namespace templates
{

namespace circulararray_utils
{

template<
	typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits = ContainerTraits<T>
>
class Iterator:
		public iterator_utils::BaseIterator<
			typename Array<T, ARRAY_CAPACITY, true, Traits>::Iterator
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
			, CircularArray<T, ARRAY_CAPACITY, Traits>
		>
{
public:
	using Me = Iterator<T, ARRAY_CAPACITY, Traits>;
	using Parent = iterator_utils::BaseIterator<
		typename Array<T, ARRAY_CAPACITY, true, Traits>::Iterator
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::NON_CONSTANT
		, Traits
		, CircularArray<T, ARRAY_CAPACITY, Traits>
	>;

	using Container = CircularArray<T, ARRAY_CAPACITY, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SsizeType = typename Traits::SsizeType;

	Iterator();
	Iterator(const Me &) = default;
	~Iterator() = default;

	Me &operator++() noexcept;
	Me operator++(int) noexcept;

	Me &operator--() noexcept;
	Me operator--(int) noexcept;

	Reference operator*() noexcept;
	Pointer operator->() noexcept;

	ConstReference operator*() const noexcept;
	PointerToConst operator->() const noexcept;

	template<typename IntType>
	Me &operator+=(IntType value) noexcept;

	template<typename IntType>
	Me &operator-=(IntType value) noexcept;

	template<typename IntType>
	Me operator+(IntType value) const;

	template<typename IntType>
	Me operator-(IntType value) const;

	bool operator==(const Me &iterator) const noexcept;
	bool operator!=(const Me &iterator) const noexcept;
	bool operator>(const Me &iterator) const noexcept;
	bool operator<(const Me &iterator) const noexcept;
	bool operator>=(const Me &iterator) const noexcept;
	bool operator<=(const Me &iterator) const noexcept;

protected:


private:
};

template<
	typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits = ContainerTraits<T>
>
class ConstIterator:
		public iterator_utils::BaseIterator<
			typename StaticArray<T, ARRAY_CAPACITY, Traits>::Iterator
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
			, CircularArray<T, ARRAY_CAPACITY, Traits>
		>
{
public:
	using Me = ConstIterator<T, ARRAY_CAPACITY, Traits>;
	using Parent = iterator_utils::BaseIterator<
		typename Array<T, ARRAY_CAPACITY, true, Traits>::Iterator
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::CONSTANT
		, Traits
		, CircularArray<T, ARRAY_CAPACITY, Traits>
	>;

	using Container = CircularArray<T, ARRAY_CAPACITY, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SsizeType = typename Traits::SsizeType;

	ConstIterator();
	~ConstIterator() = default;

	Me &operator++() noexcept;
	Me operator++(int) noexcept;

	Me &operator--() noexcept;
	Me operator--(int) noexcept;

	ConstReference operator*() const noexcept;
	PointerToConst operator->() const noexcept;

	template<typename IntType>
	Me operator+(IntType value) const;

	template<typename IntType>
	Me operator-(IntType value) const;

	bool operator==(const Me &iterator) const noexcept;
	bool operator!=(const Me &iterator) const noexcept;
	bool operator>(const Me &iterator) const noexcept;
	bool operator<(const Me &iterator) const noexcept;
	bool operator>=(const Me &iterator) const noexcept;
	bool operator<=(const Me &iterator) const noexcept;
};

}

template <typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename Traits = ContainerTraits<T>
>
class CircularArray
{
public:
	using Me = CircularArray<T, ARRAY_CAPACITY, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	static constexpr SizeType CAPACITY = ARRAY_CAPACITY;

	CircularArray() noexcept = default;
	CircularArray(const Me &array) noexcept = default;
	CircularArray(Me &&array) noexcept = default;
	~CircularArray();
	Me &operator=(const Me &) noexcept;
	Me &operator=(Me &&) noexcept;


private:
	StaticArray<T, CAPACITY, Traits> array;
};

}}

namespace flame_ide
{namespace templates
{

#define TEMPLATE_DEFINE \
	template < \
		typename T \
		, SizeTraits::SizeType ARRAY_CAPACITY \
		, typename Traits \
	>


namespace circulararray_utils
{

#define ITERATOR_TYPE \
	Iterator<T, ARRAY_CAPACITY, Traits>

TEMPLATE_DEFINE
ITERATOR_TYPE::Iterator()
{}

}

//#define TEMPLATE_DEFINE_1 \
//	template < \
//		SizeTraits::SizeType ARRAY_CAPACITY1 \
//		, typename Traits1 \
//	>

//#define ARRAY_TYPE \
//	CircularArray<T, ARRAY_CAPACITY, Traits>

//#define ARRAY_TYPE_1 \
//	CircularArray<T, ARRAY_CAPACITY1, Traits1>


}}

#endif // CIRCULARARRAY_HPP
