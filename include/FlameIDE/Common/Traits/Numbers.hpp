#ifndef FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP
#define FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{

/**
 * @brief Aliases to primitive fixed size types.
 */
struct Types: public NonCreational
{
	using char_t = flame_ide::char_t;

	using ichar_t = flame_ide::ichar_t;
	using short_t = flame_ide::short_t;
	using int_t = flame_ide::int_t;
	using long_t = flame_ide::long_t;

	using byte_t = flame_ide::uichar_t;

	using uichar_t = flame_ide::uichar_t;
	using ushort_t = flame_ide::ushort_t;
	using uint_t = flame_ide::uint_t;
	using ulong_t = flame_ide::ulong_t;

	using float_t = flame_ide::float_t;
	using double_t = flame_ide::double_t;
	using ldouble_t = flame_ide::ldouble_t;

	using size_t = flame_ide::size_t;
	using ssize_t = flame_ide::ssize_t;
	using diff_t = flame_ide::diff_t;
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
struct IsPrimitiveType<Types::ichar_t>: public TrueType
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
struct IsPrimitiveType<Types::uichar_t>: public TrueType
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


///
/// @brief The IsFloatType struct
///
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


///
/// @brief The IsSigned struct
///
template<typename T>
struct IsSigned: public FalseType
{
	static_assert(IsPrimitiveType<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatType<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsSigned<Types::uichar_t>: public FalseType
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
struct IsSigned<Types::ichar_t>: public TrueType
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


///
/// @brief The IsUnsigned struct
///
template<typename T>
struct IsUnsigned: public FalseType
{
	static_assert(IsPrimitiveType<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatType<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsUnsigned<Types::uichar_t>: public TrueType
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
struct IsUnsigned<Types::ichar_t>: public FalseType
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


///
/// @brief The IsIntegralType struct
///
template<typename Type>
struct IsIntegralType: public IntegralConstant<
			bool, IsPrimitiveType<Type>::VALUE && !IsFloatType<Type>::VALUE
		>
{};


///
/// @brief The MakeSigned struct
///
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
struct MakeSigned<Types::uichar_t>
{
	using Type = Types::ichar_t;
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
struct MakeUnsigned<Types::ichar_t>
{
	using Type = Types::uichar_t;
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

///
/// @brief The NumerLimit struct
///
template<typename IntType>
struct NumberLimit
{};

template<>
struct NumberLimit<Types::ichar_t>
{
	static constexpr Types::ichar_t MIN_VALUE = INT8_MIN;
	static constexpr Types::ichar_t MAX_VALUE = INT8_MAX;
};

template<>
struct NumberLimit<Types::short_t>
{
	static constexpr Types::short_t MIN_VALUE = INT16_MIN;
	static constexpr Types::short_t MAX_VALUE = INT16_MAX;
};

template<>
struct NumberLimit<Types::int_t>
{
	static constexpr Types::int_t MIN_VALUE = INT32_MIN;
	static constexpr Types::int_t MAX_VALUE = INT32_MAX;
};

template<>
struct NumberLimit<Types::long_t>
{
	static constexpr Types::long_t MIN_VALUE = INT64_MIN;
	static constexpr Types::long_t MAX_VALUE = INT64_MAX;
};

template<>
struct NumberLimit<Types::uichar_t>
{
	static constexpr Types::uichar_t MIN_VALUE = 0;
	static constexpr Types::uichar_t MAX_VALUE = UINT8_MAX;
};

template<>
struct NumberLimit<Types::ushort_t>
{
	static constexpr Types::ushort_t MIN_VALUE = 0;
	static constexpr Types::ushort_t MAX_VALUE = UINT16_MAX;
};

template<>
struct NumberLimit<Types::uint_t>
{
	static constexpr Types::uint_t MIN_VALUE = 0;
	static constexpr Types::uint_t MAX_VALUE = UINT32_MAX;
};

template<>
struct NumberLimit<Types::ulong_t>
{
	static constexpr Types::ulong_t MIN_VALUE = 0;
	static constexpr Types::ulong_t MAX_VALUE = UINT64_MAX;
};

}

#endif // FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP
