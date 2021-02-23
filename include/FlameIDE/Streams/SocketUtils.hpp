#ifndef FLAMEIDE_STREAMS_SOCKETUTILS_HPP
#define FLAMEIDE_STREAMS_SOCKETUTILS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>
#include <FlameIDE/Templates/Expected.hpp>

namespace flame_ide
{namespace streams
{namespace socket_utils
{

/// @brief Supported protocol types
enum class Protocol
{
	Tcp, Udp
};

/// @brief TCP note types
enum class TcpType
{
	Server, Client
};

/// @brief Static size array containing ip address
template<flame_ide::size_t IP_ADDRESS_STRING_SIZE>
struct IpAddressString
{
	static_assert (IP_ADDRESS_STRING_SIZE > 2, "Invalid string size");

	using Me = IpAddressString<IP_ADDRESS_STRING_SIZE>;

	static constexpr flame_ide::size_t MAX_LENGTH = IP_ADDRESS_STRING_SIZE - 1;

	IpAddressString() noexcept;
	IpAddressString(const Me &address) noexcept;
	Me &operator=(const Me &address) noexcept;

	char value[IP_ADDRESS_STRING_SIZE];
};

/// @brief IPv4
class Ipv4
{
public:
	struct Traits
	{
		static constexpr flame_ide::size_t COUNT_SPLITTERS = 3;
		static constexpr flame_ide::size_t COUNT_NUMBERS = 4;
		static constexpr flame_ide::size_t NUMBER_STRING_SIZE = 3;
		static constexpr flame_ide::size_t MAX_STRING_SIZE =
				COUNT_NUMBERS * NUMBER_STRING_SIZE + COUNT_SPLITTERS;
		using ValueType = flame_ide::uichar_t;
		using PortType = flame_ide::ushort_t;
	};
	using AddressString = IpAddressString<Traits::MAX_STRING_SIZE + 1>;
	using ExpectedAddress = templates::Expected<Ipv4, int>;

public:
	Ipv4() noexcept;
	Ipv4(const Ipv4 &address) noexcept;
	Ipv4(const char* address) noexcept;
	Ipv4 &operator=(const Ipv4 &address) noexcept;

private:
	Ipv4(const ExpectedAddress &expectedAddress) noexcept;

public:
	AddressString getAddress() const noexcept;

	static ExpectedAddress make(const char* address);

public:
	Traits::ValueType addressNumber[Traits::COUNT_NUMBERS];
	Traits::PortType port;

};

/// @brief IPv6
class Ipv6
{
public:
	struct Traits
	{
		static constexpr flame_ide::size_t COUNT_SPLITTERS = 7;
		static constexpr flame_ide::size_t COUNT_NUMBERS = 8;
		static constexpr flame_ide::size_t NUMBER_STRING_SIZE = 4;
		static constexpr flame_ide::size_t MAX_STRING_SIZE =
				COUNT_NUMBERS * NUMBER_STRING_SIZE + COUNT_SPLITTERS;
	};

public:
	using AddressString = IpAddressString<Traits::MAX_STRING_SIZE + 1>;

	Ipv6() noexcept;
	Ipv6(const Ipv6 &address) noexcept;
	Ipv6(const char *address) noexcept;
	Ipv6 &operator=(const Ipv6 &address) noexcept;

	AddressString getAddress() const noexcept;

public:
	flame_ide::ushort_t addressNumber[Traits::COUNT_NUMBERS];
	flame_ide::ushort_t port;
};

}}}

namespace flame_ide
{namespace streams
{namespace socket_utils
{

template<flame_ide::size_t IP_ADDRESS_STRING_SIZE>
IpAddressString<IP_ADDRESS_STRING_SIZE>::IpAddressString() noexcept
{
	templates::foreach(
			templates::makeRange(value)
			, [](auto &i)
			{
				i = typename RemoveAllTrait<decltype(i)>::Type{};
			}
	);
}

template<flame_ide::size_t IP_ADDRESS_STRING_SIZE>
IpAddressString<IP_ADDRESS_STRING_SIZE>::IpAddressString(
		const IpAddressString<IP_ADDRESS_STRING_SIZE>::Me &address) noexcept
{
	templates::copy(
			templates::makeConstRange(address.value)
			, templates::makeRange(value).begin()
	);
}

template<flame_ide::size_t IP_ADDRESS_STRING_SIZE>
typename IpAddressString<IP_ADDRESS_STRING_SIZE>::Me &
IpAddressString<IP_ADDRESS_STRING_SIZE>::operator=(
		const IpAddressString<IP_ADDRESS_STRING_SIZE>::Me &address) noexcept
{
	templates::copy(
			templates::makeConstRange(address.value)
			, templates::makeRange(value).begin()
	);
	return *this;
}

}}}

#endif // FLAMEIDE_STREAMS_SOCKETUTILS_HPP
