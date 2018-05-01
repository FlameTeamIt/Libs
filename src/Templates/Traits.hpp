#ifndef TEMPLATES_TRAITS_HPP
#define TEMPLATES_TRAITS_HPP

#include <Others/PrimitiveTypes.hpp>

#include <Templates/Macroses.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief A variable of this struct cannot be create with constructor.
 */
struct NonDefault
{
	NonDefault() = delete;
};

/**
 * @brief A variable of this struct cannot be move.
 */
struct NonMove
{
	NonMove(NonMove &&) = delete;
};

/**
 * @brief A variable of this struct cannot be copy.
 */
struct NonCopy
{
	NonCopy(const NonCopy &) = delete;
};

/**
 * @brief A variable of this struct cannot be define.
 */
struct NonCreational: public NonDefault, public NonMove, public NonCopy
{
	~NonCreational() = delete;
};


/**
 * @brief Template compile time constant.
 * @tparam Raw type.
 * @tparam Raw type value.
 */
template<typename T, T v>
struct IntegralConstant
{
	using Type = T;
	static constexpr Type VALUE = v;
};

/**
 * @brief Compile time true constant.
 */
struct TrueType: public IntegralConstant<bool, true>
{};

/**
 * @brief Compile time false constant.
 */
struct FalseType: public IntegralConstant<bool, false>
{};


/**
 * @brief Removing pointer from type.
 * @tparam Raw type.
 */
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


/**
 * @brief Removing reference from type.
 * @tparam Raw type.
 */
template<typename T>
struct RemoveReference
{
	using Type = T;
};

template<typename T>
struct RemoveReference<T &>
{
	using Type = T;
};

template<typename T>
struct RemoveReference<T &&>
{
	using Type = T;
};


/**
 * @brief View RemoveConst
 */
template<typename T>
struct RemoveConst
{
	using Type = T;
};

template<typename T>
struct RemoveConst<const T>
{
	using Type = T;
};


/**
 * @brief Removing volatile from type.
 * @tparam Raw type.
 */
template<typename T>
struct RemoveVolatile
{
	using Type = T;
};

template<typename T>
struct RemoveVolatile<volatile T>
{
	using Type = T;
};


/**
 * @brief Removing all modificators for getting
 * @tparam Raw type.
 */
template<typename T>
struct RemoveAll
{
	using Type = T;
};

template<typename T>
struct RemoveAll<volatile T>
{
	using Type = typename RemoveAll<typename RemoveVolatile<T>::Type>::Type;
};


/**
 * @brief View RemoveAll.
 */
template<typename T>
struct RemoveAll<T *>
{
	using Type = typename RemoveAll<typename RemovePointer<T>::Type>::Type;
};

template<typename T>
struct RemoveAll<T const>
{
	using Type = typename RemoveAll<typename RemoveConst<T>::Type>::Type;
};


/**
 * @brief View RemoveAll.
 */
template<typename T>
struct RemoveAll<T &>
{
	using Type = typename RemoveAll<typename RemoveReference<T>::Type>::Type;
};

/**
 * @brief View RemoveAll.
 */
template<typename T>
struct RemoveAll<T &&>
{
	using Type = typename RemoveAll<typename RemoveReference<T>::Type>::Type;
};


/**
 * @brief Aliases to primitive fixed size types.
 */
struct Types: public NonCreational
{
	using char_t = flame_ide::types::primitive::char_t;
	using short_t = flame_ide::types::primitive::short_t;
	using int_t = flame_ide::types::primitive::int_t;
	using long_t = flame_ide::types::primitive::long_t;
	using llong_t = flame_ide::types::primitive::llong_t;

	using byte_t = flame_ide::types::primitive::uchar_t;

	using uchar_t = flame_ide::types::primitive::uchar_t;
	using ushort_t = flame_ide::types::primitive::ushort_t;
	using uint_t = flame_ide::types::primitive::uint_t;
	using ulong_t = flame_ide::types::primitive::ulong_t;
	using ullong_t = flame_ide::types::primitive::ullong_t;

	using float_t = flame_ide::types::primitive::float_t;
	using double_t = flame_ide::types::primitive::double_t;
	using ldouble_t = flame_ide::types::primitive::ldouble_t;

	using size_t = flame_ide::types::primitive::size_t;
	using ssize_t = flame_ide::types::primitive::ssize_t;
	using diff_t = flame_ide::types::primitive::diff_t;
};


/**
 * @brief The IsPrimitiveType struct
 */
template<typename T>
struct IsPrimitiveType: public FalseType
{};

template<>
struct IsPrimitiveType<Types::char_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::short_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::int_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::long_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::uchar_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::ushort_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::uint_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::ulong_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::float_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::double_t>: public TrueType
{};

template<>
struct IsPrimitiveType<Types::ldouble_t>: public TrueType
{};

/**
 * @brief The IsFloatType struct
 */
template<typename T>
struct IsFloatType: public FalseType
{};

template<>
struct IsFloatType<Types::float_t>: public TrueType
{};

template<>
struct IsFloatType<Types::double_t>: public TrueType
{};

template<>
struct IsFloatType<Types::ldouble_t>: public TrueType
{};


/**
 * @brief The IsSigned struct
 */
template<typename T>
struct IsSigned: public FalseType
{
	static_assert(IsPrimitiveType<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatType<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsSigned<Types::uchar_t>: public FalseType
{};

template<>
struct IsSigned<Types::ushort_t>: public FalseType
{};

template<>
struct IsSigned<Types::uint_t>: public FalseType
{};

template<>
struct IsSigned<Types::ulong_t>: public FalseType
{};

template<>
struct IsSigned<Types::char_t>: public TrueType
{};

template<>
struct IsSigned<Types::short_t>: public TrueType
{};

template<>
struct IsSigned<Types::int_t>: public TrueType
{};

template<>
struct IsSigned<Types::long_t>: public TrueType
{};


/**
 * @brief The IsUnsigned struct
 */
template<typename T>
struct IsUnsigned: public FalseType
{
	static_assert(IsPrimitiveType<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatType<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsUnsigned<Types::uchar_t>: public TrueType
{};

template<>
struct IsUnsigned<Types::ushort_t>: public TrueType
{};

template<>
struct IsUnsigned<Types::uint_t>: public TrueType
{};

template<>
struct IsUnsigned<Types::ulong_t>: public TrueType
{};

template<>
struct IsUnsigned<Types::char_t>: public FalseType
{};

template<>
struct IsUnsigned<Types::short_t>: public FalseType
{};

template<>
struct IsUnsigned<Types::int_t>: public FalseType
{};

template<>
struct IsUnsigned<Types::long_t>: public FalseType
{};


/**
 * @brief Default type traits
 * @tparam Raw type.
 */
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


/**
 * @brief Default size, diff and traits.
 */
struct SizeTraits
{
	using SizeType = Types::size_t;
	using SsizeType = Types::ssize_t;
	using DiffType = Types::diff_t;
};


/**
 * @brief Default traits for containers such as Array, Vector, etc.
 * @tparam Raw type.
 */
template<typename T>
struct ContainerTraits: public DefaultTraits<T>, public SizeTraits
{};


/**
 * @brief Default traits for containers such as Array, Vector, etc.
 * @tparam Is volatile type.
 */
template<bool IS_VOLATILE>
struct SerializationTraits
{
	using InputStream = void *;
	using ConstInputStream =  const void *;

	using InternalStream = Types::uchar_t *;
	using ConstInternalStream =  const Types::uchar_t *;
};

template<>
struct SerializationTraits<true>
{
	using InputStream = volatile void *;
	using ConstInputStream =  const volatile void *;

	using InternalStream = volatile Types::uchar_t *;
	using ConstInternalStream =  const volatile Types::uchar_t *;
};


/**
 * @brief
 * @tparam INDEX.
 * @tparam Arg.
 * @tparam Args.
 */
template<Types::size_t INDEX, typename Arg, typename ...Args>
struct TypeGetter
{
	using Type = typename TypeGetter<INDEX - 1, Args...>::Type;
};

template<typename Arg, typename ...Args>
struct TypeGetter<0, Arg, Args...>
{
	using Type = Arg;
};

template<Types::size_t INDEX, typename Arg>
struct TypeGetter<INDEX, Arg>
{
	static_assert(!(INDEX > 1), "No types.");
	using Type = Arg;
};


/**
 * @brief Comparing different types.
 * @tparam First type.
 * @tparam Second type.
 */
template<typename T, typename U>
struct ComparingTypes: public FalseType
{};


/**
 * @brief Comparing equal types.
 * @tparam Type.
 */
template<typename T>
struct ComparingTypes<T, T>: public TrueType
{};


/**
 * @brief Comparing different types.
 * @tparam First type.
 * @tparam Second type.
 */
template<typename T, typename Arg, typename ...Args>
struct ComparingTypeWithPack
{
	static constexpr bool VALUE = ComparingTypes<T, Arg>::VALUE
		|| ComparingTypeWithPack<T, Args...>::VALUE;
};

template<typename T, typename Arg>
struct ComparingTypeWithPack<T, Arg>
{
	static constexpr bool VALUE = ComparingTypes<T, Arg>::VALUE;
};


/**
 * @brief Get info is type pointer.
 * @tparam Type.
 */
template<typename T>
struct IsPointer: public FalseType
{};

template<typename T>
struct IsPointer<T *>: public TrueType
{};


/**
 * @brief Get info is type reference.
 * @tparam Type.
 */
template<typename T>
struct IsReference: public FalseType
{};

template<typename T>
struct IsReference<T &>: public TrueType
{};

template<typename T>
struct IsReference<T &&>: public TrueType
{};


/**
 * @brief Get info is const type.
 * @tparam Type.
 */
template<typename T>
struct IsConst: public FalseType
{};

template<typename T>
struct IsConst<const T>: public TrueType
{};

/**
 * @brief Get info is volatile type.
 * @tparam Type.
 */
template<typename T>
struct IsVolatile: public FalseType
{};

template<typename T>
struct IsVolatile<volatile T>: public TrueType
{};

/**
 * @brief Get info about lvalue/rvalue.
 * @tparam Type.
 */
template<typename T>
struct IsLvalue: public FalseType
{};

template<typename T>
struct IsLvalue<T &>: public TrueType
{};

/**
 * @brief Get info about lvalue/rvalue.
 * @tparam Type.
 */
template<typename T>
struct IsRvalue: public FalseType
{};

template<typename T>
struct IsRvalue<T &&>: public TrueType
{};


template<typename IntType>
struct MakeSigned
{
	static_assert(IsPrimitiveType<typename RemoveAll<IntType>::Type>::VALUE
			, "It is not a primitive type.");

	static_assert(!IsFloatType<typename RemoveAll<IntType>::Type>::VALUE
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
	static_assert(IsPrimitiveType<typename RemoveAll<IntType>::Type>::VALUE
			, "It is not a primitive type.");

	static_assert(!IsFloatType<typename RemoveAll<IntType>::Type>::VALUE
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

/**
 * @brief The ChooseType struct
 */
template<bool CONDITION_RESULT, typename T1, typename T2>
struct ChooseType: public NonCreational
{};

/**
 * @brief The ChooseType<_Tp1, T1, T2> struct
 */
template<typename T1, typename T2>
struct ChooseType<true, T1, T2>: public NonCreational
{
	using Type = T1;
};

/**
 * @brief The ChooseType<_Tp1, T1, T2> struct
 */
template<typename T1, typename T2>
struct ChooseType<false, T1, T2>: public NonCreational
{
	using Type = T2;
};

/**
 * @brief The IsUniqueParameterPack struct
 */
template<typename ...Args>
struct IsUniqueParameterPack: public TrueType
{};

/**
 * @brief The IsUniqueParameterPack<Arg, Args> struct
 */
template<typename Arg, typename ...Args>
struct IsUniqueParameterPack<Arg, Args...>
{
	static constexpr bool VALUE = ComparingTypeWithPack<Arg, Args...>::VALUE
		|| IsUniqueParameterPack<Args...>::VALUE;
};

/**
 * @brief The IsUniqueParameterPack<Arg, Args> struct
 */
template<typename Arg, typename Arg1>
struct IsUniqueParameterPack<Arg, Arg1>
{
	static constexpr bool VALUE = !ComparingTypeWithPack<Arg, Arg1>::VALUE;
};

}}

#endif // TEMPLATES_TRAITS_HPP
