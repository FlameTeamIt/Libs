#ifndef FLAMEIDE_TEMPLATES_STRINGCONVERTIONS_HPP
#define FLAMEIDE_TEMPLATES_STRINGCONVERTIONS_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Templates/String.hpp>

// Define classes

namespace flame_ide
{namespace templates
{namespace string_utils
{

enum class NumberView
{
	Dec
	, Bin
	, Hex
};

template<
	Types::ulong_t MIN, Types::ulong_t MAX
	, SizeTraits::SizeType BUFFER_SIZE
>
struct NumberChecker;

template<typename T, bool SIGNED = isSigned<T>()>
struct BufferSize;

}}} // flame_ide::templates::string_utils

// Declare classes

namespace flame_ide
{namespace templates
{namespace string_utils
{

template<
	Types::ulong_t MIN, Types::ulong_t MAX
	, SizeTraits::SizeType BUFFER_SIZE
>
struct NumberChecker
{
	template<typename IntType>
	static constexpr SizeTraits::SizeType get(IntType value);
};

template<SizeTraits::SizeType BUFFER_SIZE>
struct NumberChecker<
	Types::ulong_t(999999999999999999ULL), Types::ulong_t(9999999999999999999ULL)
	, BUFFER_SIZE
>
{
	template<typename IntType>
	static constexpr SizeTraits::SizeType get(IntType value);
};

template<typename T, bool SIGNED>
struct BufferSize
{
	static inline SizeTraits::SizeType get(T integer);
};

template<typename T>
struct BufferSize<T, false>
{
	static inline SizeTraits::SizeType get(T integer);
};

template<typename IntValue>
String toString(IntValue value);

template<typename NumberType, bool IS_FLOAT = isFloatType<NumberType>()>
struct NumberConverter
{
	static String convert(NumberType value);
};

template<typename NumberType>
struct NumberConverter<NumberType, true>
{
	static String convert(NumberType value);
};

}}} // flame_ide::templates::string_utils

namespace flame_ide
{namespace templates
{

namespace string_utils
{

template<Types::ulong_t MIN, Types::ulong_t MAX, SizeTraits::SizeType BUFFER_SIZE>
template<typename IntType>
constexpr SizeTraits::SizeType
NumberChecker<MIN, MAX, BUFFER_SIZE>::get(IntType value)
{
	if (MIN <= value && value <= MAX)
		return BUFFER_SIZE;
	else
		return NumberChecker<
			MAX, MAX * Types::ulong_t(10) + Types::ulong_t(9)
			, BUFFER_SIZE + SizeTraits::SizeType(1)
		>::get(value);
}

template<SizeTraits::SizeType BUFFER_SIZE> template<typename IntType>
constexpr SizeTraits::SizeType NumberChecker<
	Types::ulong_t(999999999999999999ULL), Types::ulong_t(9999999999999999999ULL)
	, BUFFER_SIZE
>::get(IntType value)
{
	constexpr Types::ulong_t MIN = Types::ulong_t(999999999999999999ULL);
	constexpr Types::ulong_t MAX = Types::ulong_t(9999999999999999999ULL);

	if (MIN <= value && value <= MAX)
	{
		return BUFFER_SIZE;
	}
	else
	{
		return BUFFER_SIZE + 1;
	}
}

template<typename IntType, bool SIGNED>
SizeTraits::SizeType BufferSize<IntType, SIGNED>::get(IntType integer)
{
	SizeTraits::SizeType signedValue = 0;
	if (integer < 0)
	{
		++signedValue;
		integer *= -1;
	}
	typename MakeUnsigned<IntType>::Type value = integer;

	return signedValue + NumberChecker<0ULL, 9ULL, 1>::get(value);
}

template<typename IntType>
SizeTraits::SizeType BufferSize<IntType, false>::get(IntType integer)
{
	return NumberChecker<0ULL, 9ULL, 1>::get(integer);
}

template<typename IntType>
SizeTraits::SizeType bufferSize(IntType integer)
{
	return BufferSize<IntType>::get(integer);
}

}}} // flame_ide::templates::string_utils


namespace flame_ide
{namespace templates
{

namespace string_utils
{

template<typename NumberType, bool IS_FLOAT>
String NumberConverter<NumberType, IS_FLOAT>::convert(NumberType value)
{
	String string;
	SizeTraits::SizeType buffer = string_utils::BufferSize<NumberType>::get(value);
	string.reserve(buffer);

	if (isSigned<NumberType>())
	{
		if (value < 0)
		{
			string.pushBack('-');
			value *= -1;
			--buffer;
		}
	}

	SizeTraits::SizeType dec = 1;
	for (decltype(buffer) i = 1; i < buffer; ++i)
	{
		dec *= static_cast<SizeTraits::SizeType>(10);
	}

	for (decltype(buffer) i = 0; i < buffer; ++i)
	{
		auto result = value / dec;
		string.pushBack(String::Type('0' + result));
		value %= dec;
		dec /= static_cast<SizeTraits::SizeType>(10);
	}

	return string;
}

// TODO: Implement
template<typename NumberType>
String NumberConverter<NumberType, true>::convert(NumberType)
{
	static_assert(!isFloatType<NumberType>(), "Not implemented.");

	String string;
	return string;
}

}

template<typename IntValue>
String toString(IntValue value)
{
	return string_utils::NumberConverter<
		IntValue
		, isFloatType<IntValue>()
	>::convert(value);
}

}}

#endif // FLAMEIDE_TEMPLATES_STRINGCONVERTIONS_HPP
