#ifndef FLAMEIDE_COMMON_UTILS_HPP
#define FLAMEIDE_COMMON_UTILS_HPP

#include <FlameIDE/Common/Traits.hpp>

namespace flame_ide
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
T&& forward(T &&reference) noexcept;

/**
 * @brief std::forward alternative.
 */
template<class T> constexpr inline
T&& forward(T &reference) noexcept;

/**
 * @brief Adapter for palcement new operator.
 *
 * Call custom constructors.
 */
template<typename T, typename ...Args> inline
typename DefaultTraits<T>::Pointer
emplaceNew(T *pointer, Args &&...args) noexcept;

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer
		, typename DefaultTraits<T>::MoveReference obj) noexcept;

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer
		, typename DefaultTraits<T>::ConstReference obj) noexcept;

/**
 * @brief Comparing ranges.
 */
template<typename Iterator1 , typename Iterator2>
bool isEqual(Iterator1 start1, Iterator1 end1,
		Iterator2 start2, Iterator2 end2);

template<typename Container> inline
typename Container::Iterator begin(Container &container);

template<typename Container> inline
typename Container::ConstIterator cbegin(const Container &container);

template<typename Container> inline
typename Container::ReverseIterator rbegin(Container &container);

template<typename Container> inline
typename Container::ConstReverseIterator crbegin(const Container &container);

template<typename Container> inline
typename Container::Iterator end(Container &container);

template<typename Container> inline
typename Container::ConstIterator cend(const Container &container);

template<typename Container> inline
typename Container::ReverseIterator rend(Container &container);

template<typename Container> inline
typename Container::ConstReverseIterator crend(const Container &container);

template<typename T, typename Tt = T&&>
Tt __implementation_decval__(int) noexcept;

template<typename T>
T __implementation_decval__(long) noexcept;

template<typename Type>
decltype(__implementation_decval__<Type>) declareValue() noexcept;

template <class F, class T, class = T>
struct IsStaticCastable: public FalseType
{};

template <class F, class T>
struct IsStaticCastable<F, T, decltype(static_cast<T>(declareValue<F>()))>: public TrueType
{};

}

template<typename T>
inline void *operator new(flame_ide::SizeTraits::SizeType
		, T *pointer) noexcept
{
	return pointer;
}

template<typename T>
inline void *operator new[](flame_ide::SizeTraits::SizeType
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
{

template<typename T> inline constexpr
bool isPrimitiveType() noexcept
{
	using Type = typename RemoveAll<T>::Type;
	return IsPrimitiveType<Type>::VALUE;
}

template<typename T> inline constexpr
bool isFloatType() noexcept
{
	using Type = typename RemoveAll<T>::Type;
	return IsFloatType<Type>::VALUE;
}

template<typename T> inline constexpr
bool isIntegralType() noexcept
{
	using Type = typename RemoveAll<T>::Type;
	return IsIntegralType<Type>::VALUE;
}

template<typename T> inline constexpr
bool isSigned() noexcept
{
	using Type = typename RemoveAll<T>::Type;
	return IsSigned<Type>::VALUE;
}

template<typename T> inline constexpr
bool isUnsigned() noexcept
{
	using Type = typename RemoveAll<T>::Type;
	return IsUnsigned<Type>::VALUE;
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
T &&forward(T &&reference) noexcept
{
	static_assert(IsLvalue<T>::VALUE, "Cannot forward rvalue as lvalue.");
	return static_cast<T &&>(reference);
}

template<class T> constexpr inline
T &&forward(T &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename T, typename ...Args> inline
typename DefaultTraits<T>::Pointer
emplaceNew(T *pointer, Args &&...args) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(forward<decltype(args)>(args)...);
}

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer, typename DefaultTraits<T>::MoveReference obj) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(forward<T>(obj));
}

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer
		, typename DefaultTraits<T>::ConstReference obj) noexcept
{
	return new (pointer) typename DefaultTraits<T>::Type(obj);
}

template<typename Iterator1, typename Iterator2>
bool isEqual(Iterator1 start1, Iterator1 end1
		, Iterator2 start2, Iterator2 end2)
{
	static_assert(
			!isSameTypes<
				typename RemoveAll<decltype(*start1)>::Type
				, typename RemoveAll<decltype(*start2)>::Type
			>()
			, "Types is not equal."
	);

	typename RemoveAll<Iterator1>::Type it1 = start1;
	typename RemoveAll<Iterator2>::Type it2 = start2;
	for (; (it1 != end1) && (it2 != end2); ++it1, ++it2)
	{
		if ((it1 == end1) || (it2 == end2) || (*it1 != *it2))
		{
			return false;
		}
	}
	return true;
}

template<typename Container> inline
typename Container::Iterator begin(Container &container)
{
	return container.begin();
}

template<typename Container> inline
typename Container::ConstIterator cbegin(const Container &container)
{
	return container.cbegin();
}

template<typename Container> inline
typename Container::ReverseIterator rbegin(Container &container)
{
	return container.rbegin();
}

template<typename Container> inline
typename Container::ConstReverseIterator crbegin(const Container &container)
{
	return container.crbegin();
}

template<typename Container> inline
typename Container::Iterator end(Container &container)
{
	return container.end();
}

template<typename Container> inline
typename Container::ConstIterator cend(const Container &container)
{
	return container.cend();
}

template<typename Container> inline
typename Container::ReverseIterator rend(Container &container)
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

}

#endif // FLAMEIDE_COMMON_UTILS_HPP
