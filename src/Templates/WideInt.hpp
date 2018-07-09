#ifndef TEMPLATES_WIDEINT_HPP
#define TEMPLATES_WIDEINT_HPP

#include <Templates/Utils.hpp>
#include <Templates/Array.hpp>
#include <Templates/Serialization.hpp>

#define TEMPLATE_WIDE_INT \
	template<Types::ullong_t BITS, bool SIGNED>
#define WIDE_INT \
	WideInt<BITS, SIGNED>

#define TEMPLATE_WIDE_INT_SIGNED \
	template<Types::ullong_t BITS>
#define WIDE_INT_SIGNED \
	WideInt<BITS, true>


namespace flame_ide
{namespace templates
{

namespace wideint_utils
{

}

// class defines

template<Types::ullong_t BITS, bool SIGNED = false>
class WideInt
{
public:
	using Me = WideInt<BITS, SIGNED>;
	using MeSigned = WideInt<BITS, !SIGNED>;

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
	template<typename IntegralType>
	void set(IntegralType value);

	static constexpr Types::size_t COUNT_BYTES = (BITS % 8)
		? BITS / 8 + 1
		: BITS / 8;

	Array<Types::uichar_t, COUNT_BYTES> byteArray;
};

template<Types::ullong_t BITS>
class WideInt<BITS, true>
{
public:
	using Me = WideInt<BITS, true>;
	using MeUnsigned = WideInt<BITS, false>;

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

	static constexpr Types::size_t COUNT_BYTES = ((BITS - 1) % 8)
		? BITS / 8 + 1
		: BITS / 8;

	ichar_t signedByte;
	Array<Types::uichar_t, COUNT_BYTES> byteArray;
};

template<Types::size_t COUNT_BITS>
using SignedInt = WideInt<COUNT_BITS, true>;

template<Types::size_t COUNT_BITS>
using UnsignedInt = WideInt<COUNT_BITS, false>;


// traits

template<Types::ullong_t BITS>
struct MakeSigned<WideInt<BITS, true>>
{
	using Type = WideInt<BITS, true>;
};

template<Types::ullong_t BITS>
struct MakeSigned<WideInt<BITS, false>>
{
	using Type = WideInt<BITS, true>;
};

template<Types::ullong_t BITS>
struct MakeUnsigned<WideInt<BITS, true>>
{
	using Type = WideInt<BITS, false>;
};

template<Types::ullong_t BITS>
struct MakeUnsigned<WideInt<BITS, false>>
{
	using Type = WideInt<BITS, false>;
};

// typedefs

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

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT::WideInt(PrimitiveType value)
{
	static_assert(IsPrimitiveType<PrimitiveType>::VALUE, "It is not primitive type");

	using RealType = typename RemoveAll<PrimitiveType>::Type;
	if (isFloatType<RealType>())
	{
		using CastFromFloatType = Types::llong_t;
		set(static_cast<CastFromFloatType>(value));
	}
	else
	{
		set(value);
	}
}


// private

TEMPLATE_WIDE_INT
template<typename IntegralType>
void WIDE_INT::set(IntegralType value)
{
	static_assert(IsIntegralType<IntegralType>::VALUE, "It is not integral type");
	SpecializedValue<ByteOrder::HOST_ORDER, IntegralType> specValue(
		value
		, (COUNT_BYTES >= sizeof(IntegralType) ? sizeof(IntegralType) : COUNT_BYTES)
		, (
				(COUNT_BYTES >= sizeof(IntegralType))
						? COUNT_BYTES -  sizeof(IntegralType)
						: sizeof(IntegralType) - COUNT_BYTES
		)
	);

	SerializerBe serializer(byteArray.data());
	serializer(specValue);
}

}}

#endif // TEMPLATES_WIDEINT_HPP
