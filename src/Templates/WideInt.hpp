#ifndef TEMPLATES_WIDEINT_HPP
#define TEMPLATES_WIDEINT_HPP

#include <Common/Utils.hpp>
#include <Templates/Array.hpp>
#include <Templates/Serialization.hpp>

#define TEMPLATE_WIDE_INT \
	template<Types::ulong_t BITS, bool SIGNED>
#define WIDE_INT \
	WideInt<BITS, SIGNED>

#define TEMPLATE_WIDE_INT_SIGNED \
	template<Types::ulong_t BITS>
#define WIDE_INT_SIGNED \
	WideInt<BITS, true>


namespace flame_ide
{namespace templates
{

// class define

template<Types::ulong_t BITS, bool SIGNED = false>
class WideInt
{
public:
	static constexpr bool IS_SIGNED = SIGNED;

	static constexpr Types::size_t COUNT_BYTES = (BITS % 8)
		? BITS / 8 + 1
		: BITS / 8;

	using Me = WideInt<BITS, SIGNED>;
	using MeSigned = WideInt<BITS, (IS_SIGNED) ? SIGNED : !SIGNED>;
	using MeUnsigned = WideInt<BITS, (IS_SIGNED) ? !SIGNED : SIGNED>;
	using Data = StaticArray<Types::uichar_t, COUNT_BYTES>;

	WideInt() = default;
	WideInt(const Me &integer) = default;

	template<typename PrimitiveType>
	WideInt(PrimitiveType value);

	// TODO: check this
	template<Types::ulong_t BITS1, bool SIGNED1>
	WideInt(const WideInt<BITS1, SIGNED1> &value);

	template<typename PrimitiveType>
	Me &operator=(PrimitiveType value);
	Me &operator=(const Me &value) = default;

	template<typename IntegerType>
	Me &operator<<=(IntegerType value);
	Me &operator<<=(const Me &value);

	template<typename IntegerType>
	Me &operator>>=(IntegerType value);
	Me &operator>>=(const Me &value);

	template<typename IntegerType>
	Me &operator&=(IntegerType value);
	Me &operator&=(const Me &value);

	template<typename IntegerType>
	Me &operator|=(IntegerType value);
	Me &operator|=(const Me &value);

	template<typename IntegerType>
	Me &operator+=(IntegerType value);
	Me &operator+=(const Me &value);

	template<typename IntegerType>
	Me &operator-=(IntegerType value);
	Me &operator-=(const Me &value);

	template<typename IntegerType>
	Me &operator*=(IntegerType value);
	Me &operator*=(const Me &value);

	template<typename IntegerType>
	Me &operator/=(IntegerType value);
	Me &operator/=(const Me &value);

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
	Me &operator-(IntegerType value);
	Me &operator-(const Me &value);

	template<typename IntegerType>
	Me &operator*(IntegerType value);
	Me &operator*(const Me &value);

	template<typename IntegerType>
	Me &operator/(IntegerType value);
	Me &operator/(const Me &value);

	template<typename IntegerType>
	Me &operator&(IntegerType value);
	Me &operator&(const Me &value);

	template<typename IntegerType>
	Me &operator|(IntegerType value);
	Me &operator|(const Me &value);

	Me &operator++();
	Me operator++(int) const;
	Me &operator--();
	Me operator--(int) const;

	Me &operator~();

	operator Types::uichar_t() const;
	operator Types::ushort_t() const;
	operator Types::uint_t() const;
	operator Types::ulong_t() const;

	operator Types::ichar_t() const;
	operator Types::short_t() const;
	operator Types::int_t() const;
	operator Types::long_t() const;

	void reset() noexcept;

	Data &getData() noexcept;

	const Data &getData() const noexcept;

private:
	Data byteArray;
};

template<Types::size_t COUNT_BITS>
using SignedInt = WideInt<COUNT_BITS, true>;

template<Types::size_t COUNT_BITS>
using UnsignedInt = WideInt<COUNT_BITS, false>;

} // templates

// traits

template<Types::ulong_t BITS>
struct MakeSigned<templates::WideInt<BITS, true>>
{
	using Type = templates::WideInt<BITS, true>;
};

template<Types::ulong_t BITS>
struct MakeSigned<templates::WideInt<BITS, false>>
{
	using Type = templates::WideInt<BITS, true>;
};

template<Types::ulong_t BITS>
struct MakeUnsigned<templates::WideInt<BITS, true>>
{
	using Type = templates::WideInt<BITS, false>;
};

template<Types::ulong_t BITS>
struct MakeUnsigned<templates::WideInt<BITS, false>>
{
	using Type = templates::WideInt<BITS, false>;
};

namespace templates
{

// external operators
// TODO: add external operators

// typedefs

using int40_t = SignedInt<40>;
using int80_t = SignedInt<80>;
using int128_t = SignedInt<128>;
using int256_t = SignedInt<256>;
using int512_t = SignedInt<512>;
using int1024_t = SignedInt<1024>;

using uint40_t = UnsignedInt<40>;
using uint80_t = UnsignedInt<80>;
using uint128_t = UnsignedInt<128>;
using uint256_t = UnsignedInt<256>;
using uint512_t = UnsignedInt<512>;
using uint1024_t = UnsignedInt<1024>;

}}

namespace flame_ide
{namespace templates
{

namespace wideint_utils
{

template<Types::size_t COUNT_BYTES, bool IS_INTEGRAL>
struct PrimitiveTypeOperationsImpl: public NonCreational
{
	using Array = flame_ide::templates::StaticArray<Types::uichar_t, COUNT_BYTES>;

	template<typename PrimitiveType>
	static void operatorInit(Array &array, PrimitiveType value) // ctor()
	{
		static_assert(IsIntegralType<PrimitiveType>::VALUE, "It is not a integral type");

		constexpr Types::size_t SPECIALIZED_VALUE_INIT_SIZE =
				(COUNT_BYTES >= sizeof(PrimitiveType))
						? sizeof(PrimitiveType)
						: COUNT_BYTES;

		constexpr Types::size_t SPECIALIZED_VALUE_OFFSET = (COUNT_BYTES >= sizeof(PrimitiveType))
				? 0
				: sizeof(PrimitiveType) - COUNT_BYTES;

		constexpr Types::size_t SERIALIZER_OFFSET = (SPECIALIZED_VALUE_OFFSET == 0)
				? COUNT_BYTES - sizeof(PrimitiveType)
				: 0;

		SpecializedValue<ByteOrder::HOST_ORDER, PrimitiveType> specValue(
				value
				, SPECIALIZED_VALUE_INIT_SIZE
				, SPECIALIZED_VALUE_OFFSET
		);
		SerializerBe(array.data(), SERIALIZER_OFFSET)(specValue);
	}

	template<typename PrimitiveType>
	static void operatorAssign(Array &array, PrimitiveType value); // operator=

	// binary operations

	template<typename PrimitiveType>
	static void operatorShiftLeft(Array &array, PrimitiveType value); // operator<<
	template<typename PrimitiveType>
	static void operatorShiftLeft(PrimitiveType value, Array &array); // operator<<

	template<typename PrimitiveType>
	static void operatorShiftRight(Array &array, PrimitiveType value); // operator>>
	template<typename PrimitiveType>
	static void operatorShiftRight(PrimitiveType &value, Array &array); // operator>>

	template<typename PrimitiveType>
	static void operatorBinOr(Array &array, PrimitiveType value); // operator|
	template<typename PrimitiveType>
	static void operatorBinOr(PrimitiveType &value, Array &array); // operator|

	template<typename PrimitiveType>
	static void operatorBinAnd(Array &array, PrimitiveType value); // operator&
	template<typename PrimitiveType>
	static void operatorBinAnd(PrimitiveType &value, Array &array); // operator&

	static void operatorBitwiseNegation(Array &array) // operator~
	{
		using Type = typename RemoveAll<decltype(*(array.begin()))>::Type;
		for (auto &i : array)
		{
			i = Type(~i);
		}
	}

	// convert operator

	template<typename PrimitiveType>
	static void operatorConvert(const Array &array, PrimitiveType &value) // operator smth_type()
	{
		static_assert (!isConst<decltype(value)>(), "Value cannot be contant");
		static_assert(IsIntegralType<PrimitiveType>::VALUE, "It is not a integral type");

		constexpr Types::size_t SPECIALIZED_VALUE_INIT_SIZE =
				(COUNT_BYTES >= sizeof(PrimitiveType))
						? sizeof(PrimitiveType)
						: COUNT_BYTES;

		constexpr Types::size_t SPECIALIZED_VALUE_OFFSET = (COUNT_BYTES >= sizeof(PrimitiveType))
				? 0
				: sizeof(PrimitiveType) - COUNT_BYTES;

		constexpr Types::size_t SERIALIZER_OFFSET = (SPECIALIZED_VALUE_OFFSET == 0)
				? COUNT_BYTES - sizeof(PrimitiveType)
				: 0;

		SpecializedValue<ByteOrder::HOST_ORDER, PrimitiveType> specValue(
				PrimitiveType()
				, SPECIALIZED_VALUE_INIT_SIZE
				, SPECIALIZED_VALUE_OFFSET
		);
		DeserializerBe(array.data(), SERIALIZER_OFFSET)(specValue);
		value = specValue.getValue();
	}
};

template<Types::size_t COUNT_BYTES>
struct PrimitiveTypeOperationsImpl<COUNT_BYTES, false>: public NonCreational
{
	using Array = flame_ide::templates::Array<Types::uichar_t, COUNT_BYTES>;

	template<typename PrimitiveType>
	static void opeatorInit(Array &array, PrimitiveType value) // ctor()
	{
		using PrimitiveTypeOperationsImpl = PrimitiveTypeOperationsImpl<COUNT_BYTES, true>;
		PrimitiveTypeOperationsImpl::operatorInit(array, static_cast<Types::long_t>(value));
	}

	template<typename PrimitiveType>
	static void opeatorAssign(Array &array, PrimitiveType value); // operator=

	// binary operations

	template<typename PrimitiveType>
	static void opeatorShiftLeft(Array &array, PrimitiveType value); // operator<<
	template<typename PrimitiveType>
	static void opeatorShiftLeft(PrimitiveType value, Array &array); // operator<<

	template<typename PrimitiveType>
	static void opeatorShiftRight(Array &array, PrimitiveType value); // operator>>
	template<typename PrimitiveType>
	static void opeatorShiftRight(PrimitiveType &value, Array &array); // operator>>

	template<typename PrimitiveType>
	static void opeatorBinOr(Array &array, PrimitiveType value); // operator|
	template<typename PrimitiveType>
	static void opeatorBinOr(PrimitiveType &value, Array &array); // operator|

	template<typename PrimitiveType>
	static void opeatorBinAnd(Array &array, PrimitiveType value); // operator&
	template<typename PrimitiveType>
	static void opeatorBinAnd(PrimitiveType &value, Array &array); // operator&
};

template<typename Array, typename PrimitiveType>
inline PrimitiveType operatorConvert(const Array &array)
{
	PrimitiveType value;
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		Array::CAPACITY, isIntegralType<typename RemoveAll<decltype(value)>::Type>()
	>;
	Operations::operatorConvert(array, value);
	return value;
}

} // namespace wideint_utils






TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT::WideInt(PrimitiveType value)
{
	static_assert(IsPrimitiveType<PrimitiveType>::VALUE, "It is not a primitive type");

	using RealType = typename RemoveAll<PrimitiveType>::Type;
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		COUNT_BYTES, isIntegralType<RealType>()
	>;

	Operations::operatorInit(byteArray, value);
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator=(PrimitiveType value)
{
	static_assert(IsPrimitiveType<PrimitiveType>::VALUE, "It is not a primitive type");
	using RealType = typename RemoveAll<decltype(value)>::Type;
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		COUNT_BYTES, isIntegralType<RealType>()
	>;

	reset();
	Operations::operatorInit(byteArray, value);

	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator<<=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		COUNT_BYTES, isIntegralType<RealType>()
	>;

	Operations::operatorShiftLeft(byteArray, value);

	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator<<=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator>>=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		COUNT_BYTES, isIntegralType<RealType>()
	>;

	Operations::operatorShiftLeft(byteArray, value);

	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator>>=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator&=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator&=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator|=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator|=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator+=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator+=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator-=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator-=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator*=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator*=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator/=(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator/=(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}





TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator<<(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator<<(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator>>(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	static_assert(!isFloatType<RealType>(), "It is a float type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator>>(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}





TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator&(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator&(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator|(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator|(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}







TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator+(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator+(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator-(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator-(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}





TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator*(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator*(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
template<typename PrimitiveType>
WIDE_INT &WIDE_INT::operator/(PrimitiveType value)
{
	using RealType = typename RemoveAll<decltype(value)>::Type;
	static_assert(isPrimitiveType<RealType>(), "It is not a primitive type.");
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator/(const WIDE_INT &value)
{
	auto valueRange = makeRange(byteArray.rbegin(), byteArray.rend());
	auto myRange = makeRange(value.byteArray.rbegin(), value.byteArray.rend());
	return *this;
}








TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator++()
{
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT WIDE_INT::operator++(int) const
{
	auto myRange = makeRange(byteArray.rbegin(), byteArray.rend());
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator--()
{
	return *this;
}

TEMPLATE_WIDE_INT
WIDE_INT WIDE_INT::operator--(int) const
{
	auto myRange = makeRange(byteArray.rbegin(), byteArray.rend());
	return *this;
}




TEMPLATE_WIDE_INT
WIDE_INT &WIDE_INT::operator~()
{
	using Operations = wideint_utils::PrimitiveTypeOperationsImpl<
		COUNT_BYTES, true
	>;
	Operations::operatorBitwiseNegation(byteArray);
	return *this;
}




TEMPLATE_WIDE_INT
WIDE_INT::operator Types::uichar_t() const
{
	return wideint_utils::operatorConvert<Data, Types::uichar_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::ushort_t() const
{
	return wideint_utils::operatorConvert<Data, Types::ushort_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::uint_t() const
{
	return wideint_utils::operatorConvert<Data, Types::uint_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::ulong_t() const
{
	return wideint_utils::operatorConvert<Data, Types::ulong_t>(byteArray);
}




TEMPLATE_WIDE_INT
WIDE_INT::operator Types::ichar_t() const
{
	return wideint_utils::operatorConvert<Data, Types::ichar_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::short_t() const
{
	return wideint_utils::operatorConvert<Data, Types::short_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::int_t() const
{
	return wideint_utils::operatorConvert<Data, Types::int_t>(byteArray);
}

TEMPLATE_WIDE_INT
WIDE_INT::operator Types::long_t() const
{
	return wideint_utils::operatorConvert<Data, Types::long_t>(byteArray);
}





TEMPLATE_WIDE_INT
void WIDE_INT::reset() noexcept
{
	byteArray.reset();
}

TEMPLATE_WIDE_INT
typename WIDE_INT::Data &WIDE_INT::getData() noexcept
{
	return byteArray;
}

TEMPLATE_WIDE_INT
const typename WIDE_INT::Data &WIDE_INT::getData() const noexcept
{
	return byteArray;
}

// private


}}

#endif // TEMPLATES_WIDEINT_HPP
