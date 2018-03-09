#ifndef TEMPLATES_WIDEINT_HPP
#define TEMPLATES_WIDEINT_HPP

#include <Templates/Utils.hpp>
#include <Templates/Array.hpp>

#include <Others/Bits.hpp>

#define TEMPLATE_WIDE_INT \
	template<Types::ullong_t BITS, bool SIGNED>
#define WIDE_INT \
	WideInt<BITS, SIGNED>


namespace flame_ide
{namespace templates
{

namespace wide_int_utils
{

}

template<Types::ullong_t BITS, bool SIGNED>
class WideInt
{
public:
	using Me = WideInt<BITS, SIGNED>;

	WideInt() = default;
	WideInt(const Me &integer) = default;

	template<typename IntegerType>
	WideInt(IntegerType value);

	template<typename IntegerType>
	Me &operator=(IntegerType value);
	Me &operator=(const Me &value);

	template<typename IntegerType>
	Me &operator<<(IntegerType value);
	Me &operator<<(const Me &value);

	template<typename IntegerType>
	Me &operator>>(IntegerType value);
	Me &operator>>(const Me &value);

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

	template<typename IntegerType>
	Me &operator&(IntegerType value);
	Me &operator&(const Me &value);

	template<typename IntegerType>
	Me &operator&=(IntegerType value);
	Me &operator&=(const Me &value);

	template<typename IntegerType>
	Me &operator|(IntegerType value);
	Me &operator|(const Me &value);

	template<typename IntegerType>
	Me &operator|=(IntegerType value);
	Me &operator|=(const Me &value);

	Me &operator++();
	Me operator++(int);
	Me &operator--();
	Me operator--(int);

private:
	template<typename FloatType>
	void initFloat();

	template<typename IntegralType>
	void initInteger();

	constexpr Types::size_t COUNT_BYTES = (BITS % 8)
		? BITS / 8 + 1
		: BITS / 8;

	Array<Types::uchar_t, COUNT_BYTES> byteArray;
};

template<Types::size_t COUNT_BITS>
using SignedInt = WideInt<COUNT_BITS, true>;

template<Types::size_t COUNT_BITS>
using UnsignedInt = WideInt<COUNT_BITS, false>;

using Int40 = SignedInt<40>;
using Int80 = SignedInt<80>;
using Int128 = SignedInt<128>;
using Int256 = SignedInt<256>;
using Int512 = SignedInt<512>;
using Int1024 = SignedInt<1024>;

using UInt40 = UnsignedInt<40>;
using UInt80 = UnsignedInt<80>;
using UInt128 = UnsignedInt<128>;
using UInt256 = UnsignedInt<256>;
using UInt512 = UnsignedInt<512>;
using UInt1024 = UnsignedInt<1024>;

}}

namespace flame_ide
{namespace templates
{

template<typename IntegerType>
TEMPLATE_WIDE_INT
WIDE_INT::WideInt(IntegerType integer)
{
}


}}

#endif // TEMPLATES_WIDEINT_HPP
