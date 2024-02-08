#ifndef FLAMEIDE_COMMON_UTILS_HPP
#define FLAMEIDE_COMMON_UTILS_HPP

#include <FlameIDE/Common/Traits.hpp>

namespace flame_ide
{

///
/// @brief Get info about T is a primitive type or not.
///
template<typename T>
inline constexpr bool isPrimitiveType() noexcept;

///
/// @brief Comparing types.
/// @tparam First param.
/// @tparam Second param.
///
template<typename T, typename U>
inline constexpr bool isSameTypes() noexcept;

///
/// @brief Compile time checking const mode/
/// @tparam Value type.
///
template<typename T> inline constexpr
bool isConst() noexcept;

///
/// @brief std::move alternative.
/// @tparam First param.
///
template<typename T> constexpr inline
typename RemoveReferenceTrait<T>::Type&& move(T &&reference) noexcept;

///
/// @brief std::forward alternative.
/// @tparam First param.
///
template<class T> constexpr inline
T&& forward(T &&reference) noexcept;

///
/// @brief std::forward alternative.
/// @tparam First param.
///
template<class T> constexpr inline
T&& forward(T &reference) noexcept;

///
/// @brief Adapter for palcement new operator.
/// @tparam First param.
/// @tparam First param.
///
/// Call custom constructors.
///
template<typename T, typename ...Args> inline
typename DefaultTraits<T>::Pointer
emplaceNew(T *pointer, Args &&...args) noexcept;

///
/// @brief placementNew
/// @tparam First param.
/// @param pointer
/// @param obj
///
template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer
		, typename DefaultTraits<T>::MoveReference obj) noexcept;

template<typename T> inline
typename DefaultTraits<T>::Pointer
placementNew(T *pointer
		, typename DefaultTraits<T>::ConstReference obj) noexcept;

///
/// @brief Comparing ranges.
/// @tparam First param.
/// @tparam First param.
///
template<typename Iterator1 , typename Iterator2>
bool isEqual(Iterator1 start1, Iterator1 end1,
		Iterator2 start2, Iterator2 end2);

template<typename T, typename U>
bool isEqual(const T &value1, const U &value2);

///
/// @brief begin
/// @param container
/// @return
///
template<typename Container> inline
typename Container::Iterator begin(Container &container);

///
/// @brief cbegin
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ConstIterator cbegin(const Container &container);

///
/// @brief rbegin
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ReverseIterator rbegin(Container &container);

///
/// @brief crbegin
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ConstReverseIterator crbegin(const Container &container);

///
/// @brief end
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::Iterator end(Container &container);

///
/// @brief cend
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ConstIterator cend(const Container &container);

///
/// @brief rend
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ReverseIterator rend(Container &container);

///
/// @brief crend
/// @tparam First param.
/// @param container
/// @return
///
template<typename Container> inline
typename Container::ConstReverseIterator crend(const Container &container);

template<typename T, typename Tt = T&&>
Tt __implementation_decval__(int) noexcept;

template<typename T>
T __implementation_decval__(long) noexcept;

///
/// @brief declareValue
/// @tparam First param.
///
template<typename Type>
decltype(__implementation_decval__<Type>) declareValue() noexcept;

///
/// @brief The IsStaticCastable struct
/// @tparam First param.
/// @tparam First param.
///
template <class F, class T, class = T>
struct IsStaticCastable: public FalseType
{};

template <class F, class T>
struct IsStaticCastable<F, T, decltype(static_cast<T>(declareValue<F>()))>: public TrueType
{};

template<typename Iterator> inline
auto getPointer(Iterator iterator) noexcept -> decltype(&(*iterator));

template<typename T, Types::size_t SIZE>
void copy(T (& dest)[SIZE], const T (& src)[SIZE]);

template<typename T, typename U>
void copy(T &src, const U &dest, Types::size_t size);

template<typename T>
Types::size_t length(const T *array);

template<
	typename T1, typename T2
	, typename = typename EnableType<IsIntegralValue<T1>, T1>::Type
	, typename = typename EnableType<IsIntegralValue<T2>, T2>::Type
>
constexpr decltype(T1{} + T2{}) max(T1 value1, T2 value2) noexcept;

template<
	typename T1, typename T2
	, typename = typename EnableType<IsIntegralValue<T1>, T1>::Type
	, typename = typename EnableType<IsIntegralValue<T2>, T2>::Type
>
constexpr decltype(T1{} + T2{}) min(T1 value1, T2 value2) noexcept;

template<typename T>
void unused(const T &);

template<typename T>
void unused(T &&);

} // namespace flame_ide

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
	using Type = typename RemoveAllTrait<T>::Type;
	return IsPrimitiveTrait<Type>::VALUE;
}

template<typename T> inline constexpr
bool isFloatType() noexcept
{
	using Type = typename RemoveAllTrait<T>::Type;
	return IsFloatTrait<Type>::VALUE;
}

template<typename T> inline constexpr
bool isIntegralType() noexcept
{
	using Type = typename RemoveAllTrait<T>::Type;
	return IsIntegralTrait<Type>::VALUE;
}

template<typename T> inline constexpr
bool isSigned() noexcept
{
	using Type = typename RemoveAllTrait<T>::Type;
	return IsSignedTrait<Type>::VALUE;
}

template<typename T> inline constexpr
bool isUnsigned() noexcept
{
	using Type = typename RemoveAllTrait<T>::Type;
	return IsUnsignedTrait<Type>::VALUE;
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
typename RemoveReferenceTrait<T>::Type &&move(T &&reference) noexcept
{
	return static_cast<typename RemoveReferenceTrait<T>::Type &&>(reference);
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
				typename RemoveAllTrait<decltype(*start1)>::Type
				, typename RemoveAllTrait<decltype(*start2)>::Type
			>()
			, "Types is not equal."
	);

	typename RemoveAllTrait<Iterator1>::Type it1 = start1;
	typename RemoveAllTrait<Iterator2>::Type it2 = start2;
	for (; (it1 != end1) && (it2 != end2); ++it1, ++it2)
	{
		if ((it1 == end1) || (it2 == end2) || (*it1 != *it2))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool isEqual(const T &value1, const T &value2)
{
	volatile const flame_ide::byte_t *v1 =
			reinterpret_cast<volatile const flame_ide::byte_t *>(
					&value1
			);
	volatile const flame_ide::byte_t *v2 =
			reinterpret_cast<volatile const flame_ide::byte_t *>(
					&value2
			);

	bool result = true;
	for (Types::size_t i = 0; i < sizeof(T) && result; ++i, ++v1, ++v2)
	{
		result = (*v1 == *v2);
	}
	return result;
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

template<typename Type>
decltype(__implementation_decval__<Type>) declareValue() noexcept
{
	static_assert(FalseType::VALUE, "It can't ba called");
	return __implementation_decval__<Type>(0);
}

template<typename Iterator> inline
auto getPointer(Iterator iterator) noexcept -> decltype(&(*iterator))
{
	return &(*iterator);
}

template<typename T, Types::size_t SIZE>
void copy(T (& dest)[SIZE], const T (& src)[SIZE])
{
	DoSomeByIndex<T, Types::size_t{ 0 }, SIZE>::copy(dest, src);
}

template<typename T, typename U>
void copy(T &dst, const U &src, Types::size_t size)
{
	volatile auto *out = reinterpret_cast<volatile Types::uichar_t *>(&dst);
	volatile const auto *in = reinterpret_cast<volatile const Types::uichar_t *>(&src);

	for (Types::size_t i = 0; i < size; ++i)
	{
		out[i] = in[i];
	}
}

template<typename T>
Types::size_t length(const T *array)
{
	const auto nullValue = T{};

	Types::size_t length = 0;
	for (auto it = array; *it != nullValue; ++it, ++length)
	{}
	return length;
}

template<typename T1, typename T2, typename, typename>
constexpr decltype(T1{} + T2{}) max(T1 value1, T2 value2) noexcept
{
	if (value1 > value2)
		return value1;
	return value2;
}

template<typename T1, typename T2, typename, typename>
constexpr decltype(T1{} + T2{}) min(T1 value1, T2 value2) noexcept
{
	if (value2 > value1)
		return value1;
	return value2;
}

template<typename T>
void unused(const T &)
{}

template<typename T>
void unused(T &&)
{}

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_UTILS_HPP
