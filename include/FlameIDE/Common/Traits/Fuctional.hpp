#ifndef FLAMEIDE_COMMON_TRAITS_FUCTIONAL_HPP
#define FLAMEIDE_COMMON_TRAITS_FUCTIONAL_HPP

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{

///
/// @brief
/// @tparam INDEX.
/// @tparam Arg.
/// @tparam Args.
///
template<Types::size_t INDEX, typename ...Args>
struct GetTypeByIndex: public NonCreational
{};

template<Types::size_t INDEX, typename Arg, typename ...Args>
struct GetTypeByIndex<INDEX, Arg, Args...>: public NonCreational
{
	using Type = typename GetTypeByIndex<INDEX - 1, Args...>::Type;
};

template<typename Arg, typename ...Args>
struct GetTypeByIndex<0, Arg, Args...>: public NonCreational
{
	using Type = Arg;
};

template<Types::size_t INDEX>
struct GetTypeByIndex<INDEX>: public NonCreational
{
	static_assert(!(INDEX > 1), "No types.");
};

template<>
struct GetTypeByIndex<0>: public NonCreational
{
	using Type = void;
};


///
/// @brief Comparing different types.
/// @tparam First type.
/// @tparam Second type.
///
template<typename T, typename U>
struct ComparingTypes: public FalseType
{};


///
/// @brief Comparing equal types.
/// @tparam Type.
///
template<typename T>
struct ComparingTypes<T, T>: public TrueType
{};


///
/// @brief Comparing different types.
/// @tparam First type.
/// @tparam Second type.
///
template<typename T, typename Arg, typename ...Args>
struct ComparingTypeWithPack: public NonCreational
{
	static constexpr bool VALUE = ComparingTypes<T, Arg>::VALUE
		|| ComparingTypeWithPack<T, Args...>::VALUE;
};

template<typename T, typename Arg>
struct ComparingTypeWithPack<T, Arg>: public NonCreational
{
	static constexpr bool VALUE = ComparingTypes<T, Arg>::VALUE;
};


///
/// @brief Get info is type pointer.
/// @tparam Type.
///
template<typename T>
struct IsPointer: public FalseType
{};

///
/// @brief The IsPointer<T *> struct
///
template<typename T>
struct IsPointer<T *>: public TrueType
{};


///
/// @brief Get info is type reference.
/// @tparam Type.
///
template<typename T>
struct IsReference: public FalseType
{};

template<typename T>
struct IsReference<T &>: public TrueType
{};

template<typename T>
struct IsReference<T &&>: public TrueType
{};


///
/// @brief Get info is const type.
/// @tparam Type.
///
template<typename T>
struct IsConst: public FalseType
{};

///
/// @brief The IsConst<const T> struct
///
template<typename T>
struct IsConst<const T>: public TrueType
{};

///
/// @brief Get info is volatile type.
/// @tparam Type.
///
template<typename T>
struct IsVolatile: public FalseType
{};

template<typename T>
struct IsVolatile<volatile T>: public TrueType
{};

///
/// @brief Get info about lvalue/rvalue.
/// @tparam Type.
///
template<typename T>
struct IsLvalue: public FalseType
{};

template<typename T>
struct IsLvalue<T &>: public TrueType
{};

///
/// @brief Get info about lvalue/rvalue.
/// @tparam Type.
///
template<typename T>
struct IsRvalue: public FalseType
{};

///
/// @brief The IsRvalue<T &&> struct
///
template<typename T>
struct IsRvalue<T &&>: public TrueType
{};


///
/// @brief The ChooseType struct
///
template<bool CONDITION_RESULT, typename T1, typename T2>
struct ChooseType: public NonCreational
{};

///
/// @brief The ChooseType<_Tp1, T1, T2> struct
///
template<typename T1, typename T2>
struct ChooseType<true, T1, T2>: public NonCreational
{
	using Type = T1;
};

///
/// @brief The ChooseType<_Tp1, T1, T2> struct
///
template<typename T1, typename T2>
struct ChooseType<false, T1, T2>: public NonCreational
{
    using Type = T2;
};

///
/// @brief The EnableType<_Tp1, T1> struct
///
template<bool CONDITION_RESULT, typename T1>
struct EnableType: public NonCreational
{
	static constexpr bool VALUE = CONDITION_RESULT;
};

///
/// @brief The EnableType<_Tp1, T1> struct
///
template<typename T1>
struct EnableType<true, T1>: public NonCreational
{
	static constexpr bool VALUE = true;
	using Type = T1;
};

///
/// @brief The IsUniqueParameterPack struct
///
template<typename ...Args>
struct IsUniqueParameterPack: public TrueType
{};

///
/// @brief The IsUniqueParameterPack<Arg, Args...> struct
///
template<typename Arg, typename ...Args>
struct IsUniqueParameterPack<Arg, Args...>
{
	static constexpr bool VALUE = ComparingTypeWithPack<Arg, Args...>::VALUE
		|| IsUniqueParameterPack<Args...>::VALUE;
};

template<typename Arg, typename Arg1>
struct IsUniqueParameterPack<Arg, Arg1>
{
	static constexpr bool VALUE = !ComparingTypeWithPack<Arg, Arg1>::VALUE;
};

template<typename T, typename ...Args>
struct GetIndexOfType
{
	static constexpr Types::ssize_t INDEX = -1;
};

///
/// @brief The GetIndexOfType<T, Arg, Args...> struct
///
template<typename T, typename Arg, typename ...Args>
struct GetIndexOfType<T, Arg, Args...>
{
	static constexpr Types::ssize_t INDEX = (ComparingTypes<T, Arg>::VALUE)
			? Types::ssize_t(0)
			: (GetIndexOfType<T, Args...>::INDEX < 0)
					? GetIndexOfType<T, Args...>::INDEX
					: Types::ssize_t(1) + GetIndexOfType<T, Args...>::INDEX;
};

template<typename T>
struct GetIndexOfType<T>
{
	static constexpr Types::ssize_t INDEX = -1;
};

///
/// @brief The FunctionReturnValueType struct
///
template <typename T>
struct FunctionReturnValueType;

///
/// @brief The FunctionReturnValueType<ReturnType(*)(Args...)> struct
///
template <typename ReturnType, typename... Args>
struct FunctionReturnValueType<ReturnType(*)(Args...)>
{
	using Type = ReturnType;
};

///
/// @brief The FunctionReturnValueType<ReturnType(ObjectType::*)(Args...)> struct
///
template <typename ReturnType, typename ObjectType, typename... Args>
struct FunctionReturnValueType<ReturnType(ObjectType::*)(Args...)>
{
	using Type = ReturnType;
};

///
/// @brief The FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) const> struct
///
template <typename ReturnType, typename ObjectType, typename... Args>
struct FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) const>
{
	using Type = ReturnType;
};

///
/// @brief The FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) volatile> struct
///
template <typename ReturnType, typename ObjectType, typename... Args>
struct FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) volatile>
{
	using Type = ReturnType;
};

///
/// @brief The FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) const volatile>
/// struct
///
template <typename ReturnType, typename ObjectType, typename... Args>
struct FunctionReturnValueType<ReturnType(ObjectType::*)(Args...) const volatile>
{
	using Type = ReturnType;
};

///
/// @brief The ReturnValue alias
///
template <typename T>
using FunctionReturnType = typename FunctionReturnValueType<T>::Type;

///
/// @brief The DoSomeByIndex struct
///
template<typename T, Types::size_t INDEX, Types::size_t SIZE>
struct DoSomeByIndex
{
	static void copy(T (&dest)[SIZE], const T (&src)[SIZE])
	{
		dest[INDEX] = src[INDEX];
		DoSomeByIndex<T, INDEX + 1, SIZE>::copy(dest, src);
	}
};

///
/// @brief The DoSomeByIndex<T, SIZE, SIZE> struct
///
template<typename T, Types::size_t SIZE>
struct DoSomeByIndex<T, SIZE, SIZE>
{
	static void copy(T (&)[SIZE], const T (&)[SIZE])
	{}
};

}

#endif // FLAMEIDE_COMMON_TRAITS_FUCTIONAL_HPP
