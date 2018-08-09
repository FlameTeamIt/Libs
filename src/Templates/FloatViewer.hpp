#ifndef TEMPLATES_FLOATVIEWER_HPP
#define TEMPLATES_FLOATVIEWER_HPP

#include <Templates/Bits.hpp>

namespace flame_ide
{namespace templates
{namespace bits
{

namespace float_utils
{

template<typename FloatType>
struct FloatTraits
{
	static constexpr Types::uichar_t SIGN = -1;
	static constexpr Types::uichar_t EXPONENT = -1;
	static constexpr Types::uichar_t MANTISSA = -1;
	static_assert(isFloatType<FloatType>(), "This type is not float.");
};

template<>
struct FloatTraits<Types::float_t>: public NonCreational
{
	static constexpr Types::uichar_t SIGN = 1;
	static constexpr Types::uichar_t EXPONENT = 8;
	static constexpr Types::uichar_t MANTISSA = 23;
};

template<>
struct FloatTraits<Types::double_t>: public NonCreational
{
	static constexpr Types::uichar_t SIGN = 1;
	static constexpr Types::uichar_t EXPONENT = 11;
	static constexpr Types::uichar_t MANTISSA = 52;
};

}

template<typename FloatType>
class FloatViewer: public float_utils::FloatTraits<FloatType>
{
public:
	FloatViewer(FloatType valueInit);
	using SignValueType = typename MinimalType<SIGN>::Type;
	using ExponentValueType = typename MinimalType<EXPONENT>::Type;
	using MantissaValueType = typename MinimalType<MANTISSA>::Type;

	SignValueType getSign() const;
	ExponentValueType getExponent() const;
	MantissaValueType getMantissa() const;

private:
	FloatType value;
};

}}}

#endif // TEMPLATES_FLOATVIEWER_HPP
