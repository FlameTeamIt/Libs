#ifndef TEMPLATES_WIDEFLOAT_HPP
#define TEMPLATES_WIDEFLOAT_HPP

#include <Common/Utils.hpp>
#include <Templates/Array.hpp>

namespace flame_ide
{namespace templates
{

template<Types::ulong_t BITS>
class WideFloat
{
public:
	using Me = WideFloat<BITS>;

	WideFloat() = default;
	WideFloat(const Me&) = default;

	template<typename IntegerType>
	WideFloat(IntegerType value);

	template<typename IntegerType>
	Me &operator=(IntegerType &value);
	Me &operator=(const Me &value);

	template<typename IntegerType>
	WideFloat<BITS, SIGNED> &operator=(const IntegerType &value);

	template<typename IntegerType>
	Me &operator+(IntegerType value);
	Me &operator+(const Me &value);

	template<typename IntegerType>
	Me &operator+=(IntegerType value);
	Me &operator+=(const Me &value);

	template<typename IntegerType>
	Me &operator-(IntegerType value);
	Me &operator-(const Me &value);

	template<typename IntegerType>
	Me &operator-=(IntegerType value);
	Me &operator-=(const Me &value);

	template<typename IntegerType>
	Me &operator*(IntegerType value);
	Me &operator*(const Me &value);

	template<typename IntegerType>
	Me &operator*=(IntegerType value);
	Me &operator*=(const Me &value);

	template<typename IntegerType>
	Me &operator/(IntegerType value);
	Me &operator/(const Me &value);

	template<typename IntegerType>
	Me &operator/=(IntegerType value);
	Me &operator/=(const Me &value);

	Me &operator++();
	Me &operator++(int);
	Me &operator--();
	Me &operator--(int);

private:
};

using Float80 = WideFloat<80>;
using Float128 = WideFloat<128>;

}}

#endif // WIDEFLOAT_HPP
