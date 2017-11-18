#ifndef UTILS_HPP
#define UTILS_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename T>
struct AlignObject
{
	static constexpr Types::size_t ARRAY_SIZE = (sizeof(T) % sizeof(Types::size_t))
			? sizeof(T) / sizeof(Types::size_t) + 1
			: sizeof(T) / sizeof(Types::size_t);

	AlignObject()
	{
		for (Types::size_t i = 0; i < ARRAY_SIZE; ++i)
			array[i] = 0u;
	}

	size_t array[ARRAY_SIZE];
};

/**
 * @brief Get info about T is a primitive type or not.
 */
template<typename T>
inline constexpr bool isPrimitiveType() noexcept;

/**
 * @brief Comparing types.
 * @tparam First param.
 * @tparam Second param.
 */
template<typename T, typename U>
inline constexpr bool isSameTypes() noexcept;

/**
 * @brief std::move alternative.
 */
template<typename T> constexpr inline
typename RemoveReference<T>::Type&& move(T &&reference) noexcept;

/**
 * @brief std::forward alternative.
 */
template<class T> constexpr inline
T&& forward(typename RemoveReference<T>::Type &&reference) noexcept;

/**
 * @brief std::forward alternative.
 */
template<class T> constexpr inline
T&& forward(typename RemoveReference<T>::Type &reference) noexcept;

/**
 * @brief Copying range.
 */
template<typename IteratorInput, typename IteratorOutput>
void copy(IteratorInput start, IteratorInput end
		, IteratorOutput out);

/**
 * @brief Getting size of range.
 */
template<typename Iterator, typename SizeTraits = flame_ide::templates::SizeTraits>
typename SizeTraits::SizeType countIterations(Iterator start, Iterator end);

/**
 * @brief Adapter for palcement new operator.
 *
 * Call custom constructors.
 */
template<typename T, typename ...Args> inline
typename DefaultTraits<T>::Pointer
emplaceNew(typename DefaultTraits<T>::Pointer pointer, Args &&...args) noexcept;

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(typename DefaultTraits<T>::Pointer pointer
		, typename DefaultTraits<T>::MoveReference obj) noexcept;

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(typename DefaultTraits<T>::Pointer pointer
		, typename DefaultTraits<T>::ConstReference obj) noexcept;
/**
 * @brief Comparing ranges.
 */
template<typename Iterator1 , typename Iterator2>
bool isEqual(Iterator1 start1, Iterator1 end1,
		Iterator2 start2, Iterator2 end2);

template<typename Container> inline
typename Container::Iterator begin(Container &&container);

template<typename Container> inline
typename Container::ConstIterator cbegin(const Container &container);

template<typename Container> inline
typename Container::ReverseIterator rbegin(Container &&container);

template<typename Container> inline
typename Container::ConstReverseIterator crbegin(const Container &container);

template<typename Container> inline
typename Container::Iterator end(Container &&container);

template<typename Container> inline
typename Container::ConstIterator cend(const Container &container);

template<typename Container> inline
typename Container::ReverseIterator rend(Container &&container);

template<typename Container> inline
typename Container::ConstReverseIterator crend(const Container &container);

}}

template<typename T>
inline void *operator new(flame_ide::templates::SizeTraits::SizeType
		, T *pointer) noexcept
{
	return pointer;
}

template<typename T>
inline void *operator new[](flame_ide::templates::SizeTraits::SizeType
		, T * pointer) noexcept
{
	return pointer;
}

template<typename T>
inline void operator delete(void *, T *) noexcept
{}

template<typename T>
inline void operator delete[](void *, T *) noexcept
{}

namespace flame_ide
{namespace templates
{

template<typename T> inline constexpr
bool isPrimitiveType() noexcept
{
	using ClearType = typename RemoveAll<T>::Type;
	using IsChar = ComparingTypes<ClearType, Types::char_t>;
	using IsUchar = ComparingTypes<ClearType, Types::uchar_t>;

	using IsShort = ComparingTypes<ClearType, Types::short_t>;
	using IsUshort = ComparingTypes<ClearType, Types::ushort_t>;

	using IsInt =ComparingTypes<ClearType, Types::int_t>;
	using IsUint = ComparingTypes<ClearType, Types::uint_t>;

	using IsLong = ComparingTypes<ClearType, Types::long_t>;
	using IsUlong = ComparingTypes<ClearType, Types::ulong_t>;

	using IsLlong = ComparingTypes<ClearType, Types::llong_t>;
	using IsUllong = ComparingTypes<ClearType, Types::ullong_t>;

	using IsFloat = ComparingTypes<ClearType, Types::float_t>;

	using IsDouble = ComparingTypes<ClearType, Types::double_t>;
	using IsLdouble = ComparingTypes<ClearType, Types::ldouble_t>;

	return (IsChar::VALUE || IsUchar::VALUE
			|| IsShort::VALUE  || IsUshort::VALUE
			|| IsInt::VALUE    || IsUint::VALUE
			|| IsLong::VALUE   || IsUlong::VALUE
			|| IsLlong::VALUE  || IsUllong::VALUE
			|| IsFloat::VALUE  || IsDouble::VALUE
			|| IsLdouble::VALUE);
}

template<typename T, typename U> inline constexpr
bool isSameTypes() noexcept
{
	return ComparingTypes<T, U>::VALUE;
}

template<typename T> constexpr inline
typename RemoveReference<T>::Type &&move(T &&reference) noexcept
{
	return static_cast<typename RemoveReference<T>::Type &&>(reference);
}

template<class T> constexpr inline
T&& forward(typename RemoveReference<T>::Type &&reference) noexcept
{
	static_assert(IsLvalue<T>::VALUE, "Cannot forward rvalue as lvalue.");
	return static_cast<T &&>(reference);
}

template<class T> constexpr inline
T&& forward(typename RemoveReference<T>::Type &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename IteratorInput, typename IteratorOutput>
void copy(IteratorInput start, IteratorInput end
		, IteratorOutput out)
{
	static_assert(!isSameTypes<decltype(*start), decltype(*out)>(), "Types is not equal");

	for(auto iterator = start; iterator != end; ++iterator, ++out)
		*out = *iterator;
}

template<typename Iterator, typename Traits>
typename Traits::SizeType countIterations(Iterator start, Iterator end)
{
	typename Traits::SizeType count = 0;
	for(auto iterator = start; iterator != end; ++iterator, ++count)
	{}
	return count;
}

template<typename T, typename ...Args> inline
typename DefaultTraits<T>::Pointer
emplaceNew(typename DefaultTraits<T>::Pointer pointer, Args &&...args) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(forward<decltype(args)>(args)...);
}

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(typename DefaultTraits<T>::Pointer pointer
		, typename DefaultTraits<T>::MoveReference obj) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(forward<T>(obj));
}

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(typename DefaultTraits<T>::Pointer pointer
		, typename DefaultTraits<T>::ConstReference obj) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(obj);
}

template<typename Iterator1, typename Iterator2>
bool isEqual(Iterator1 start1, Iterator1 end1
		, Iterator2 start2, Iterator2 end2)
{
	static_assert(!isSameTypes<decltype(*start1), decltype(*start2)>(), "Types is not equal");

	bool equal = true;
	auto iterator1 = start1;
	auto iterator2 = start2;

	for(; iterator1 != end1 && iterator2 != end2 && equal; ++iterator1, ++iterator2)
		equal = (equal && *iterator1 == *iterator2);

	if(iterator1 == end1)
		if(iterator2 == end2)
			return equal;
		else
			return false;
	else
		return false;

	return equal;
}

template<typename Container> inline
typename Container::Iterator begin(Container &&container)
{
	return container.begin();
}

template<typename Container> inline
typename Container::ConstIterator cbegin(const Container &container)
{
	return container.cbegin();
}

template<typename Container> inline
typename Container::ReverseIterator rbegin(Container &&container)
{
	return container.rbegin();
}

template<typename Container> inline
typename Container::ConstReverseIterator crbegin(const Container &container)
{
	return container.crbegin();
}


template<typename Container> inline
typename Container::Iterator end(Container &&container)
{
	return container.end();
}

template<typename Container> inline
typename Container::ConstIterator cend(const Container &container)
{
	return container.cend();
}

template<typename Container> inline
typename Container::ReverseIterator rend(Container &&container)
{
	return container.rend();
}

template<typename Container> inline
typename Container::ConstReverseIterator crend(const Container &container)
{
	return container.crend();
}

}}

#endif // UTILS_HPP
