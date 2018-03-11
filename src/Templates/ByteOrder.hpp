#ifndef TEMPLATES_BYTEORDER_HPP
#define TEMPLATES_BYTEORDER_HPP

#include <Templates/Traits.hpp>
#include <Templates/Bits.hpp>

namespace flame_ide
{namespace templates
{

template<ByteOrder CURRENT_ORDER, ByteOrder NEED_ORDER>
struct ToNeedOrder
{
	static_assert(
			CURRENT_ORDER != ByteOrder::PDP_ENDIAN_ORDER
			|| NEED_ORDER != ByteOrder::PDP_ENDIAN_ORDER,
			"PDP endian not support."
	);
};

template<>
struct ToNeedOrder<ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER>
{
	template<typename T>
	auto operator()(T value) const
	{
		return convert(value);
	}

	template<typename T>
	static auto convert(T value)
	{
		return value;
	}
};

template<>
struct ToNeedOrder<ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER>
{
public:
	template<typename T>
	auto operator()(T value) const
	{
		return convert(value);
	}

	template<typename T>
	static auto convert(T value)
	{
		return reverseBytes(value);
	}
private:
	static Types::uchar_t  reverseBytes(Types::uchar_t  value)
	{
		return value;
	}
	static Types::ushort_t reverseBytes(Types::ushort_t value)
	{
		constexpr Types::ushort_t BYTE = bits::Constants::BYTE_FF;

		Types::ushort_t RESULT = (value & BYTE) << 8;
		RESULT |= (value & (BYTE << 8)) >> 8;

		return RESULT;
	}
	static Types::uint_t   reverseBytes(Types::uint_t   value)
	{
		constexpr Types::uint_t BYTE = bits::Constants::BYTE_FF;

		const Types::uint_t BYTE1 = (value & BYTE) << 24;
		const Types::uint_t BYTE2 = (value & (BYTE << 8)) << 8;
		const Types::uint_t BYTE3 = (value & (BYTE << 16)) >> 8;
		const Types::uint_t BYTE4 = (value & (BYTE << 24)) >> 24;

		decltype(value) result = BYTE1;
		result |= BYTE2;
		result |= BYTE3;
		result |= BYTE4;
		return result;
	}
	static Types::ulong_t  reverseBytes(Types::ulong_t  value)
	{
		constexpr Types::ulong_t BYTE = bits::Constants::BYTE_FF;

		const Types::ulong_t BYTE1 = (value & BYTE) << 56;
		const Types::ulong_t BYTE2 = (value & (BYTE << 8)) << 40;
		const Types::ulong_t BYTE3 = (value & (BYTE << 16)) << 24;
		const Types::ulong_t BYTE4 = (value & (BYTE << 24)) << 8;
		const Types::ulong_t BYTE5 = (value & (BYTE << 32)) >> 8;
		const Types::ulong_t BYTE6 = (value & (BYTE << 40)) >> 24;
		const Types::ulong_t BYTE7 = (value & (BYTE << 48)) >> 40;
		const Types::ulong_t BYTE8 = (value & (BYTE << 56)) >> 56;

		decltype(value) result = BYTE1;
		result |= BYTE2;
		result |= BYTE3;
		result |= BYTE4;
		result |= BYTE5;
		result |= BYTE6;
		result |= BYTE7;
		result |= BYTE8;
		return result;
	}

	static Types::char_t  reverseBytes(Types::char_t  value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>
		(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::short_t reverseBytes(Types::short_t value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>
		(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::int_t   reverseBytes(Types::int_t   value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>
		(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::long_t  reverseBytes(Types::long_t  value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>
		(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
};

template<>
struct ToNeedOrder<ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER>
{
	template<typename T>
	auto operator()(T value) const
	{
		return convert(value);
	}

	template<typename T>
	static auto convert(T value)
	{
		return ToNeedOrder<
			ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER
		>()(value);
	}
};

template<>
struct ToNeedOrder<ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER>
{
	template<typename T>
	auto operator()(T value) const
	{
		return convert(value);
	}

	template<typename T>
	static auto convert(T value)
	{
		return value;
	}
};


}}

namespace flame_ide
{namespace templates
{

using ToBigEndian = ToNeedOrder<ByteOrder::HOST_ORDER, ByteOrder::BIG_ENDIAN_ORDER>;
using ToLittleEndian = ToNeedOrder<ByteOrder::HOST_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER>;

using FromBigEndian = ToNeedOrder<ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::HOST_ORDER>;
using FromLittleEndian = ToNeedOrder<ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::HOST_ORDER>;

}}

#endif // TEMPLATES_BYTEORDER_HPP
