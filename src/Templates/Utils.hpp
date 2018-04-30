#ifndef TEMPLATES_UTILS_HPP
#define TEMPLATES_UTILS_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

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
 * @brief Compile time checking const mode/
 * @tparam Value type.
 */
template<typename T> inline constexpr
bool isConst() noexcept;

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
Types::size_t copy(IteratorInput start, IteratorInput end
		, IteratorOutput out);
template<typename ContainerInput, typename IteratorOutput>
Types::size_t copy(const ContainerInput &input, IteratorOutput out);

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
	using Type = typename RemoveAll<T>::Type;

	using IsChar = ComparingTypes<Type, Types::char_t>;
	using IsUchar = ComparingTypes<Type, Types::uchar_t>;

	using IsShort = ComparingTypes<Type, Types::short_t>;
	using IsUshort = ComparingTypes<Type, Types::ushort_t>;

	using IsInt =ComparingTypes<Type, Types::int_t>;
	using IsUint = ComparingTypes<Type, Types::uint_t>;

	using IsLong = ComparingTypes<Type, Types::long_t>;
	using IsUlong = ComparingTypes<Type, Types::ulong_t>;

	using IsLlong = ComparingTypes<Type, Types::llong_t>;
	using IsUllong = ComparingTypes<Type, Types::ullong_t>;

	using IsFloat = ComparingTypes<Type, Types::float_t>;

	using IsDouble = ComparingTypes<Type, Types::double_t>;
	using IsLdouble = ComparingTypes<Type, Types::ldouble_t>;

	return (IsChar::VALUE || IsUchar::VALUE
			|| IsShort::VALUE  || IsUshort::VALUE
			|| IsInt::VALUE    || IsUint::VALUE
			|| IsLong::VALUE   || IsUlong::VALUE
			|| IsLlong::VALUE  || IsUllong::VALUE
			|| IsFloat::VALUE  || IsDouble::VALUE
			|| IsLdouble::VALUE);
}

template<typename T> inline constexpr
bool isFloatType() noexcept
{
	using Type = typename RemoveAll<T>::Type;

	using IsFloat = ComparingTypes<Type, Types::float_t>;

	using IsDouble = ComparingTypes<Type, Types::double_t>;
	using IsLdouble = ComparingTypes<Type, Types::ldouble_t>;

	return (IsFloat::VALUE || IsDouble::VALUE || IsLdouble::VALUE);
}

template<typename T> inline constexpr
bool isSigned() noexcept
{
	static_assert(isPrimitiveType<typename RemoveAll<T>::Type>()
			, "It is not a primitive type.");

	using Type = typename RemoveAll<T>::Type;

	using IsChar = ComparingTypes<Type, Types::char_t>;
	using IsShort = ComparingTypes<Type, Types::short_t>;
	using IsInt = ComparingTypes<Type, Types::int_t>;
	using IsLong = ComparingTypes<Type, Types::long_t>;
	using IsLlong = ComparingTypes<Type, Types::llong_t>;

	return IsChar::VALUE || IsShort::VALUE || IsInt::VALUE
			|| IsLong::VALUE || IsLlong::VALUE;
}

template<typename IntType>
struct MakeSigned
{
	static_assert(isPrimitiveType<typename RemoveAll<IntType>::Type>()
			, "It is not a primitive type.");

	static_assert(!isFloatType<typename RemoveAll<IntType>::Type>()
			, "It is only for integer types.");

	using Type = IntType;
};

template<>
struct MakeSigned<Types::uchar_t>
{
	using Type = Types::char_t;
};

template<>
struct MakeSigned<Types::ushort_t>
{
	using Type = Types::short_t;
};

template<>
struct MakeSigned<Types::uint_t>
{
	using Type = Types::int_t;
};

template<>
struct MakeSigned<Types::ulong_t>
{
	using Type = Types::long_t;
};

template<typename IntType>
struct MakeUnsigned
{
	static_assert(isPrimitiveType<typename RemoveAll<IntType>::Type>()
			, "It is not a primitive type.");

	static_assert(!isFloatType<typename RemoveAll<IntType>::Type>()
			, "It is only for integer types.");

	using Type = IntType;
};

template<>
struct MakeUnsigned<Types::char_t>
{
	using Type = Types::uchar_t;
};

template<>
struct MakeUnsigned<Types::short_t>
{
	using Type = Types::ushort_t;
};

template<>
struct MakeUnsigned<Types::int_t>
{
	using Type = Types::uint_t;
};

template<>
struct MakeUnsigned<Types::long_t>
{
	using Type = Types::ulong_t;
};

template<typename T> inline constexpr
bool isUnsigned() noexcept
{
	return !isSigned<T>();
}

template<typename T, typename U> inline constexpr
bool isSameTypes() noexcept
{
	return ComparingTypes<T, U>::VALUE;
}

template<typename T> inline constexpr
bool isConst() noexcept
{
	return IsConst<T>::VALUE;
}

template<typename T> constexpr inline
typename RemoveReference<T>::Type &&move(T &&reference) noexcept
{
	return static_cast<typename RemoveReference<T>::Type &&>(reference);
}

template<class T> constexpr inline
T &&forward(typename RemoveReference<T>::Type &&reference) noexcept
{
	static_assert(IsLvalue<T>::VALUE, "Cannot forward rvalue as lvalue.");
	return static_cast<T &&>(reference);
}

template<class T> constexpr inline
T &&forward(typename RemoveReference<T>::Type &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename IteratorInput, typename IteratorOutput>
Types::size_t copy(IteratorInput start, IteratorInput end
		, IteratorOutput out)
{
	static_assert(
			isSameTypes<
				typename RemoveAll<decltype(*start)>::Type
				, typename RemoveAll<decltype(*out)>::Type
			>()
			, "Types is not equal."
	);

	static_assert(!isConst<decltype(*out)>(), "Out iterator cannot be const.");

	Types::size_t counter = 0;
	for (auto iterator = start; iterator != end; ++iterator, ++out, ++counter)
		*out = *iterator;

	return counter;
}

template<typename ContainerInput, typename IteratorOutput>
Types::size_t copy(const ContainerInput &input, IteratorOutput out)
{
	return copy(input.begin(), input.end(), out);
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
	static_assert(!isSameTypes<decltype(*start1), decltype(*start2)>(), "Types is not equal.");

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

template<typename Container> inline
typename Container::SizeType capacity(const Container &container)
{
	return container.capacity();
}

template<typename Container> inline
typename Container::SizeType size(const Container &container)
{
	return container.size();
}

}}

#endif // TEMPLATES_UTILS_HPP
