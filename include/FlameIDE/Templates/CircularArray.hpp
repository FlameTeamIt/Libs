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

	using BaseType = StaticVector<T, CAPACITY, Traits>;

	using Iterator = CircularIterator<
		typename BaseType::Iterator, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;
	using ConstIterator = ConstCircularIterator<
		typename BaseType::ConstIterator, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;
	using ReverseIterator = ReverseIterator<
		Iterator, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;
	using ConstReverseIterator = ConstReverseIterator<
		ConstIterator, IteratorCategory::RANDOM_ACCESS, Traits, Me
	>;

	CircularArray() noexcept = default;
	CircularArray(const Me &array) noexcept = default;
	CircularArray(Me &&array) noexcept = default;
	~CircularArray();
	Me &operator=(const Me &) noexcept;
	Me &operator=(Me &&) noexcept;

	Pointer data() noexcept;
	PointerToConst data() const noexcept;

	SizeType size() const noexcept;
	SizeType capacity() const noexcept;
	SizeType clean() const noexcept;

	void pushBack(ConstReference obj);
	void pushBack(MoveReference obj);
	void emplaceBack(MoveReference obj);
	void popFront();

	Iterator begin();
	ConstIterator begin() const;
	ConstIterator cbegin() const;

	ReverseIterator rbegin();
	ConstReverseIterator rbegin() const;
	ConstReverseIterator crbegin() const;

	Iterator end();
	ConstIterator end() const;
	ConstIterator cend() const;

	ReverseIterator rend();
	ConstReverseIterator rend() const;
	ConstReverseIterator crend() const;

private:
	StaticVector<T, CAPACITY, Traits> buffer;
};

}}

namespace flame_ide
{namespace templates
{

}}

#endif // CIRCULARARRAY_HPP
