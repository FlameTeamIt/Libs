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
/// @brief The ResultType struct
///
template<typename T>
struct ResultType: public NonCreational
{
	using Type = T;
};

///
/// @brief Default type traits
/// @tparam Raw type.
///
template<typename T>
struct DefaultTraits: public ResultType<T>
{
	using typename ResultType<T>::Type;
	using ConstType = Type const;

	using Reference = Type &;
	using MoveReference =  Type &&;
	using ConstReference = Type const &;

	using Pointer = Type *;
	using PointerToConst = Type const*;
	using ConstPointer = Type *const;

	using VoidPointer = void *;
};

template<typename T>
struct DefaultTraits<const T>: public NonCreational
{
	using Type = const T;
	using Reference = const Type &;
	using ConstReference = const Type &;
	using MoveReference = const Type &&;

	using Pointer = const Type *;
	using PointerToConst = const Type *;
	using ConstPointer = const Type *const;

	using VoidPointer = const void *;
};
template<typename T>
using ConstTraits = DefaultTraits<const T>;

template<>
struct DefaultTraits<void>: NonCreational
{
	using Pointer = void *;
	using PointerToConst = void const *;
	using ConstPointer = void *const;
	using ConstPointerToConst = void const *const;
};
using VoidTraits = DefaultTraits<void>;

///
/// @brief Removing pointer from type.
/// @tparam Raw type.
///
template<typename T>
struct RemovePointerTrait: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemovePointerTrait<T *>: public NonCreational
{
	using Type = T;
};

template<typename T>
using RemovePointerType = typename RemovePointerTrait<T>::Type;

///
/// @brief Removing reference from type.
/// @tparam Raw type.
///
template<typename T>
struct RemoveReferenceTrait: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveReferenceTrait<T &>: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveReferenceTrait<T &&>: public NonCreational
{
	using Type = T;
};

template<typename T>
using RemoveReferenceType = typename RemoveReferenceTrait<T>::Type;

///
/// @brief View RemoveConst
///
template<typename T>
struct RemoveConstTrait: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveConstTrait<const T>: public NonCreational
{
	using Type = T;
};

template<typename T>
using RemoveConstType = typename RemoveConstTrait<T>::Type;

///
/// @brief Removing volatile from type.
/// @tparam Raw type.
///
template<typename T>
struct RemoveVolatileTrait: public NonCreational
{
	using Type = T;
};

template<typename T>
struct RemoveVolatileTrait<volatile T>: public NonCreational
{
	using Type = T;
};

template<typename T>
using RemoveVolatileType = typename RemoveVolatileTrait<T>::Type;

///
/// @brief Removing all modificators for getting
/// @tparam Raw type.
///
template<typename T>
struct RemoveAllTrait: public NonCreational
{
	using Type = T;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAllTrait<volatile T>: public NonCreational
{
	using Type = typename RemoveAllTrait<typename RemoveVolatileTrait<T>::Type>::Type;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAllTrait<T *>: public NonCreational
{
	using Type = typename RemoveAllTrait<typename RemovePointerTrait<T>::Type>::Type;
};

template<typename T>
struct RemoveAllTrait<T const>: public NonCreational
{
	using Type = typename RemoveAllTrait<typename RemoveConstTrait<T>::Type>::Type;
};


///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAllTrait<T &>: public NonCreational
{
	using Type = typename RemoveAllTrait<typename RemoveReferenceTrait<T>::Type>::Type;
};

///
/// @brief View RemoveAll.
///
template<typename T>
struct RemoveAllTrait<T &&>: public NonCreational
{
	using Type = typename RemoveAllTrait<typename RemoveReferenceTrait<T>::Type>::Type;
};

template<typename T>
using RemoveAllType = typename RemoveAllTrait<T>::Type;

template<typename T>
struct WithParent: public T
{
	using Parent = T;
};

///
/// @brief The AddReferenceTrait class
///
template<typename T>
struct AddReferenceTrait: public NonCreational
{
	using Type = typename DefaultTraits<T>::Reference;
};
template<typename T>
using AddReferenceType = typename AddReferenceTrait<T>::Type;

///
/// @brief The AddMoveReferenceTrait class
///
template<typename T>
struct AddMoveReferenceTrait: public NonCreational
{
	using Type = typename DefaultTraits<T>::MoveReference;
};
template<typename T>
using AddMoveReferenceType = typename AddMoveReferenceTrait<T>::Type;

///
/// @brief The AddConstTrait class
///
template<typename T>
struct AddConstTrait: public NonCreational
{
	using Type = const typename DefaultTraits<T>::Type;
};
template<typename T>
using AddConstType = typename AddConstTrait<T>::Type;

///
/// @brief The AddPointerTrait class
///
template<typename T>
struct AddPointerTrait: public NonCreational
{
	using Type = typename DefaultTraits<T>::Pointer;
};
template<typename T>
using AddPointerType = typename AddPointerTrait<T>::Type;

///
/// @brief The AddVolatileTrait class
///
template<typename T>
struct AddVolatileTrait: public NonCreational
{
	using Type = volatile typename DefaultTraits<T>::Pointer;
};
template<typename T>
using AddVolatileType = typename AddVolatileTrait<T>::Type;

}

#endif // FLAMEIDE_COMMON_TRAITS_DEFAULTS_HPP
