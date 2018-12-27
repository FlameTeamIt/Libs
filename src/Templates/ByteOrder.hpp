#ifndef TEMPLATES_BYTEORDER_HPP
#define TEMPLATES_BYTEORDER_HPP

#include <Common/Macroses.hpp>
#include <Templates/Bits.hpp>

namespace flame_ide
{namespace templates
{

enum class ByteOrder
{
	LITTLE_ENDIAN_ORDER = ORDER_LITTLE_ENDIAN
	, BIG_ENDIAN_ORDER = ORDER_BIG_ENDIAN
	, PDP_ENDIAN_ORDER = ORDER_PDP_ENDIAN
	, HOST_ORDER = CURRENT_BYTE_ORDER
};

template<typename T>
struct CompileTimeReverseBytes
{
};

template<>
struct CompileTimeReverseBytes<Types::ushort_t>
{
	template<Types::ushort_t VALUE>
	static constexpr Types::ushort_t ReverseBytes()
	{
		constexpr Types::ushort_t BYTE = bits::Constants::BYTE_FF;

		constexpr Types::ushort_t BYTE1 = (VALUE & BYTE) << 8;
		constexpr Types::ushort_t BYTE2 = (VALUE & (BYTE << 8)) >> 8;
		constexpr Types::ushort_t RESULT = BYTE1 | BYTE2;

		return RESULT;
	}
};

template<>
struct CompileTimeReverseBytes<Types::uint_t>
{
	template<Types::uint_t VALUE>
	static constexpr Types::uint_t ReverseBytes()
	{
		constexpr Types::uint_t BYTE = bits::Constants::BYTE_FF;

		constexpr Types::uint_t BYTE1 = (VALUE & BYTE) << 24;
		constexpr Types::uint_t BYTE2 = (VALUE & (BYTE << 8)) << 8;
		constexpr Types::uint_t BYTE3 = (VALUE & (BYTE << 16)) >> 8;
		constexpr Types::uint_t BYTE4 = (VALUE & (BYTE << 24)) >> 24;

		constexpr Types::uint_t result = BYTE1 | BYTE2 | BYTE3 | BYTE4;
		return result;
	}
};

template<>
struct CompileTimeReverseBytes<Types::ulong_t>
{
	template<Types::ulong_t VALUE>
	static constexpr Types::ulong_t ReverseBytes()
	{
		constexpr Types::ulong_t BYTE = bits::Constants::BYTE_FF;

		constexpr Types::ulong_t BYTE1 = (VALUE & BYTE) << 56;
		constexpr Types::ulong_t BYTE2 = (VALUE & (BYTE << 8)) << 40;
		constexpr Types::ulong_t BYTE3 = (VALUE & (BYTE << 16)) << 24;
		constexpr Types::ulong_t BYTE4 = (VALUE & (BYTE << 24)) << 8;
		constexpr Types::ulong_t BYTE5 = (VALUE & (BYTE << 32)) >> 8;
		constexpr Types::ulong_t BYTE6 = (VALUE & (BYTE << 40)) >> 24;
		constexpr Types::ulong_t BYTE7 = (VALUE & (BYTE << 48)) >> 40;
		constexpr Types::ulong_t BYTE8 = (VALUE & (BYTE << 56)) >> 56;

		constexpr Types::ulong_t result = BYTE1 | BYTE2 | BYTE3
				| BYTE4 | BYTE5 | BYTE6 | BYTE7 | BYTE8;
		return result;
	}
};

template<>
struct CompileTimeReverseBytes<Types::short_t>
{
	template<Types::short_t VALUE>
	static constexpr Types::short_t ReverseBytes()
	{
		return static_cast<Types::short_t>(
			CompileTimeReverseBytes::ReverseBytes<static_cast<Types::ushort_t>(VALUE)>()
		);
	}
};

template<>
struct CompileTimeReverseBytes<Types::int_t>
{
	template<Types::short_t VALUE>
	static constexpr Types::short_t ReverseBytes()
	{
		return static_cast<Types::int_t>(
			CompileTimeReverseBytes::ReverseBytes<static_cast<Types::uint_t>(VALUE)>()
		);
	}
};

template<>
struct CompileTimeReverseBytes<Types::long_t>
{
	template<Types::short_t VALUE>
	static constexpr Types::short_t ReverseBytes()
	{
		return static_cast<Types::long_t>(
			CompileTimeReverseBytes::ReverseBytes<static_cast<Types::ulong_t>(VALUE)>()
		);
	}
};

template<ByteOrder CURRENT_ORDER, ByteOrder NEED_ORDER>
struct ToNeedOrder
{
	static_assert(CURRENT_ORDER != ByteOrder::PDP_ENDIAN_ORDER
			|| NEED_ORDER != ByteOrder::PDP_ENDIAN_ORDER
			, "PDP endian not support.");
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
	static Types::uichar_t reverseBytes(Types::uichar_t value)
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
	static Types::uint_t reverseBytes(Types::uint_t value)
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
	static Types::ulong_t reverseBytes(Types::ulong_t value)
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

	static Types::ichar_t reverseBytes(Types::ichar_t value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::short_t reverseBytes(Types::short_t value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::int_t reverseBytes(Types::int_t value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>(
				reverseBytes(static_cast<ValueUType>(value))
		);
	}
	static Types::long_t reverseBytes(Types::long_t value)
	{
		using ValueType = decltype(value);
		using ValueUType = typename MakeUnsigned<ValueType>::Type;
		return static_cast<ValueType>(
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
