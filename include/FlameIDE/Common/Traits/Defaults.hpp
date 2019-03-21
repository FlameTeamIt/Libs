#ifndef FLAMEIDE_COMMON_TRAITS_DEFAULTS_HPP
#define FLAMEIDE_COMMON_TRAITS_DEFAULTS_HPP

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>

namespace flame_ide
{

///
/// @brief Template compile time constant.
/// @tparam Raw type.
/// @tparam Raw type value.
///
template<typename T, T v>
struct IntegralConstant: public NonCreational
{
	using Type = T;
	static constexpr Type VALUE = v;
};

///
/// @brief Compile time true constant.
///
struct TrueType: public IntegralConstant<bool, true>
{};

///
/// @brief Compile time false constant.
///
struct FalseType: public IntegralConstant<bool, false>
{};


///
/// @brief Default type traits
/// @tparam Raw type.
///
template<typename T>
struct DefaultTraits
{
	using Type = T;
	using ConstType = Type const;

	using Reference = Type &;
	using MoveReference =  Type &&;
	using ConstReference = Type const&;

	using Pointer = Type *;
	using PointerToConst = Type const*;
	using ConstPointer = Type *const;

	using VoidPointer = void *;
};

template<>
struct DefaultTraits<void>
{
	using Pointer = void *;
	using VoidToConst = void const *;
	using ConstPointer = void *const;
	using ConstPointerToConst = void const *const;
};

///
/// @brief Removing pointer from type.
/// @tparam Raw type.
///
template<typename T>
struct RemovePointer
{
	using Type = T;
};

template<typename T>
struct RemovePointer<T *>
{
	using Type = T;
};


///
/// @brief Removing reference from type.
/// @tparam Raw type.
///
template<typename T>
struct RemoveReference: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveReference<T &>: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveReference<T &&>: public NonCreational
{
	using Type = T;
};


///
/// @brief View RemoveConst
///
template<typename T>
struct RemoveConst: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveConst<const T>: public NonCreational
{
	using Type = T;
};


///
/// @brief Removing volatile from type.
/// @tparam Raw type.
///
template<typename T>
struct RemoveVolatile: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveVolatile<volatile T>: public NonCreational
{
	using Type = T;
};


///
/// @brief Removing all modificators for getting
/// @tparam Raw type.
///
template<typename T>
struct RemoveAll: public NonCreational
{
	using Type = T;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAll<volatile T>: public NonCreational
{
	using Type = typename RemoveAll<typename RemoveVolatile<T>::Type>::Type;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAll<T *>: public NonCreational
{
	using Type = typename RemoveAll<typename RemovePointer<T>::Type>::Type;
};

template<typename T>
struct RemoveAll<T const>: public NonCreational
{
	using Type = typename RemoveAll<typename RemoveConst<T>::Type>::Type;
};


///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAll<T &>: public NonCreational
{
	using Type = typename RemoveAll<typename RemoveReference<T>::Type>::Type;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAll<T &&>: public NonCreational
{
	using Type = typename RemoveAll<typename RemoveReference<T>::Type>::Type;
};

}

#endif // FLAMEIDE_COMMON_TRAITS_DEFAULTS_HPP
