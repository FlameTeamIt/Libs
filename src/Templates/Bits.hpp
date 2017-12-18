#ifndef TEMPLATES_BITS_HPP
#define TEMPLATES_BITS_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{namespace bits
{

template<typename T>
struct AlignObject
{
	static constexpr Types::size_t ARRAY_SIZE = (sizeof(T) % sizeof(Types::size_t))
			? sizeof(T) / sizeof(Types::size_t) + 1
			: sizeof(T) / sizeof(Types::size_t);

	AlignObject()
	{
		for (Types::size_t i = 0; i < ARRAY_SIZE; ++i)
			array[i] = 0u;
	}

	size_t array[ARRAY_SIZE];
};

template<Types::size_t COUNT_BITS>
struct MinimalType
{
	using Type = typename ChooseType<
		COUNT_BITS <= sizeof(uint8_t) * 8
		, uint8_t
		, typename ChooseType<
			COUNT_BITS <= sizeof(uint16_t) * 8
			, uint16_t
			, typename ChooseType<
				COUNT_BITS <= sizeof(uint32_t) * 8
				, uint32_t
				, typename ChooseType<
					COUNT_BITS <= sizeof(uint64_t) * 8
					, uint64_t
					, void
				>::Type
			>::Type
		>::Type
	>::Type;
};

template<typename FloatType>
struct FloatBits
{
	static constexpr Types::uchar_t SIGN = -1;
	static constexpr Types::uchar_t EXPONENT = -1;
	static constexpr Types::uchar_t MANTISSA = -1;
	static_assert(isFloatType<FloatType>(), "This type is not float.");
};

template<Types::float_t>
struct FloatBits
{
	static constexpr Types::uchar_t SIGN = 1;
	static constexpr Types::uchar_t EXPONENT = 8;
	static constexpr Types::uchar_t MANTISSA = 23;
};

template<Types::double_t>
struct FloatBits
{
	static constexpr Types::uchar_t SIGN = 1;
	static constexpr Types::uchar_t EXPONENT = 11;
	static constexpr Types::uchar_t MANTISSA = 52;
};

template<typename FloatType>
struct FloatViewer
{
	union
	{
		struct
		{
			MinimalType<FloatBits<FloatType>::SIGN>::Type SIGN :
					FloatBits<FloatType>::SIGN;
			MinimalType<FloatBits<FloatType>::EXPONENT>::Type EXPONENT :
					FloatBits<FloatType>::EXPONENT;
			MinimalType<FloatBits<FloatType>::MANTISSA>::Type MANTISSA :
					FloatBits<FloatType>::MANTISSA;
		};
		FloatType value;
	};
};


}}}

#endif // TEMPLATES_BITS_HPP
