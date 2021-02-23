#ifndef FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP
#define FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{

///
/// @brief Aliases to primitive fixed size types.
///
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

///
/// @brief The IsPrimitiveTrait struct
///
template<typename T>
struct IsPrimitiveTrait: public FalseType
{};

template<>
struct IsPrimitiveTrait<Types::char_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::ichar_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::short_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::int_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::long_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::uichar_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::ushort_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::uint_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::ulong_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::float_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::double_t>: public TrueType
{};

template<>
struct IsPrimitiveTrait<Types::ldouble_t>: public TrueType
{};

template<typename T>
constexpr auto IsPrimitiveValue = IsPrimitiveTrait<T>::VALUE;


///
/// @brief The IsFloatTrait struct
///
template<typename T>
struct IsFloatTrait: public FalseType
{};

template<>
struct IsFloatTrait<Types::float_t>: public TrueType
{};

template<>
struct IsFloatTrait<Types::double_t>: public TrueType
{};

template<>
struct IsFloatTrait<Types::ldouble_t>: public TrueType
{};

template<typename T>
constexpr auto IsFloatValue = IsFloatTrait<T>::VALUE;

///
/// @brief The IsSignedTrait struct
///
template<typename T>
struct IsSignedTrait: public FalseType
{
	static_assert(IsPrimitiveTrait<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatTrait<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsSignedTrait<Types::uichar_t>: public FalseType
{};

template<>
struct IsSignedTrait<Types::ushort_t>: public FalseType
{};

template<>
struct IsSignedTrait<Types::uint_t>: public FalseType
{};

template<>
struct IsSignedTrait<Types::ulong_t>: public FalseType
{};

template<>
struct IsSignedTrait<Types::ichar_t>: public TrueType
{};

template<>
struct IsSignedTrait<Types::short_t>: public TrueType
{};

template<>
struct IsSignedTrait<Types::int_t>: public TrueType
{};

template<>
struct IsSignedTrait<Types::long_t>: public TrueType
{};

template<typename T>
constexpr auto IsSignedValue = IsSignedTrait<T>::VALUE;

///
/// @brief The IsUnsignedTrait struct
///
template<typename T>
struct IsUnsignedTrait: public FalseType
{
	static_assert(IsPrimitiveTrait<typename RemoveAll<T>::Type>::VALUE
			, "It is not a primitive type.");
	static_assert(!IsFloatTrait<typename RemoveAll<T>::Type>::VALUE
			, "It's a float type.");
};

template<>
struct IsUnsignedTrait<Types::uichar_t>: public TrueType
{};

template<>
struct IsUnsignedTrait<Types::ushort_t>: public TrueType
{};

template<>
struct IsUnsignedTrait<Types::uint_t>: public TrueType
{};

template<>
struct IsUnsignedTrait<Types::ulong_t>: public TrueType
{};

template<>
struct IsUnsignedTrait<Types::ichar_t>: public FalseType
{};

template<>
struct IsUnsignedTrait<Types::short_t>: public FalseType
{};

template<>
struct IsUnsignedTrait<Types::int_t>: public FalseType
{};

template<>
struct IsUnsignedTrait<Types::long_t>: public FalseType
{};

template<typename T>
constexpr auto IsUnsignedValue = IsUnsignedTrait<T>::VALUE;

///
/// @brief The IsIntegralType struct
///
template<typename Type>
struct IsIntegralTrait: public IntegralConstant<
			bool, IsPrimitiveTrait<Type>::VALUE && !IsFloatTrait<Type>::VALUE
		>
{};

template<typename T>
constexpr auto IsIntegralValue = IsIntegralTrait<T>::VALUE;

///
/// @brief The MakeSignedTrait struct
///
template<typename IntType>
struct MakeSignedTrait
{
	static_assert(IsPrimitiveTrait<typename RemoveAll<IntType>::Type>::VALUE
			, "It is not a primitive type.");

	static_assert(!IsFloatTrait<typename RemoveAll<IntType>::Type>::VALUE
			, "It is only for integer types.");

	using Type = IntType;
};

template<>
struct MakeSignedTrait<Types::uichar_t>
{
	using Type = Types::ichar_t;
};

template<>
struct MakeSignedTrait<Types::ushort_t>
{
	using Type = Types::short_t;
};

template<>
struct MakeSignedTrait<Types::uint_t>
{
	using Type = Types::int_t;
};

template<>
struct MakeSignedTrait<Types::ulong_t>
{
	using Type = Types::long_t;
};

template<typename T>
using MakeSignedType = typename MakeSignedTrait<T>::Type;

///
/// @brief The MakeUnsignedTrait struct
///
template<typename IntType>
struct MakeUnsignedTrait
{
	static_assert(IsPrimitiveTrait<typename RemoveAll<IntType>::Type>::VALUE
			, "It is not a primitive type.");

	static_assert(!IsFloatTrait<typename RemoveAll<IntType>::Type>::VALUE
			, "It is only for integer types.");

	using Type = IntType;
};

template<>
struct MakeUnsignedTrait<Types::ichar_t>
{
	using Type = Types::uichar_t;
};

template<>
struct MakeUnsignedTrait<Types::short_t>
{
	using Type = Types::ushort_t;
};

template<>
struct MakeUnsignedTrait<Types::int_t>
{
	using Type = Types::uint_t;
};

template<>
struct MakeUnsignedTrait<Types::long_t>
{
	using Type = Types::ulong_t;
};

template<typename T>
using MakeUnsignedType = typename MakeUnsignedTrait<T>::Type;

///
/// @brief The NumerLimitTrait struct
///
template<typename IntType>
struct NumberLimitTrait
{};

template<>
struct NumberLimitTrait<Types::ichar_t>
{
	static constexpr Types::ichar_t MIN_VALUE = INT8_MIN;
	static constexpr Types::ichar_t MAX_VALUE = INT8_MAX;
};

template<>
struct NumberLimitTrait<Types::short_t>
{
	static constexpr Types::short_t MIN_VALUE = INT16_MIN;
	static constexpr Types::short_t MAX_VALUE = INT16_MAX;
};

template<>
struct NumberLimitTrait<Types::int_t>
{
	static constexpr Types::int_t MIN_VALUE = INT32_MIN;
	static constexpr Types::int_t MAX_VALUE = INT32_MAX;
};

template<>
struct NumberLimitTrait<Types::long_t>
{
	static constexpr Types::long_t MIN_VALUE = INT64_MIN;
	static constexpr Types::long_t MAX_VALUE = INT64_MAX;
};

template<>
struct NumberLimitTrait<Types::uichar_t>
{
	static constexpr Types::uichar_t MIN_VALUE = 0;
	static constexpr Types::uichar_t MAX_VALUE = UINT8_MAX;
};

template<>
struct NumberLimitTrait<Types::ushort_t>
{
	static constexpr Types::ushort_t MIN_VALUE = 0;
	static constexpr Types::ushort_t MAX_VALUE = UINT16_MAX;
};

template<>
struct NumberLimitTrait<Types::uint_t>
{
	static constexpr Types::uint_t MIN_VALUE = 0;
	static constexpr Types::uint_t MAX_VALUE = UINT32_MAX;
};

template<>
struct NumberLimitTrait<Types::ulong_t>
{
	static constexpr Types::ulong_t MIN_VALUE = 0;
	static constexpr Types::ulong_t MAX_VALUE = UINT64_MAX;
};

template<typename T>
constexpr auto NumberLimitValueMin = NumberLimitTrait<T>::MIN_VALUE;

template<typename T>
constexpr auto NumberLimitValueMax = NumberLimitTrait<T>::MAX_VALUE;

}

#endif // FLAMEIDE_COMMON_TRAITS_NUMBERS_HPP
