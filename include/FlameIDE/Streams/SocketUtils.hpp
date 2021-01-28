#ifndef FLAMEIDE_STREAMS_SOCKETUTILS_HPP
#define FLAMEIDE_STREAMS_SOCKETUTILS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

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
	using Me = IpAddressString<IP_ADDRESS_STRING_SIZE>;

	IpAddressString() noexcept;
	IpAddressString(const Me &address) noexcept;
	Me &operator=(const Me &address) noexcept;

	char value[IP_ADDRESS_STRING_SIZE];
};

/// @brief IPv4
class Ipv4
{
	static constexpr flame_ide::size_t COUNT_SPLITTERS = 3;
	static constexpr flame_ide::size_t COUNT_NUMBERS = 4;
	static constexpr flame_ide::size_t NUMBER_STRING_SIZE = 3;
	static constexpr flame_ide::size_t MAX_STRING_SIZE =
			COUNT_NUMBERS * NUMBER_STRING_SIZE + COUNT_SPLITTERS;

public:
	using AddressString = IpAddressString<MAX_STRING_SIZE + 1>;

	Ipv4() noexcept;
	Ipv4(const Ipv4 &address) noexcept;
	Ipv4(const char* address) noexcept;
	Ipv4 &operator=(const Ipv4 &address) noexcept;

	AddressString getAddress() const noexcept;

public:
	flame_ide::uichar_t addressNumber[COUNT_NUMBERS];
	flame_ide::ushort_t port;
};

/// @brief IPv6
class Ipv6
{
	static constexpr flame_ide::size_t COUNT_SPLITTERS = 7;
	static constexpr flame_ide::size_t COUNT_NUMBERS = 8;
	static constexpr flame_ide::size_t NUMBER_STRING_SIZE = 4;
	static constexpr flame_ide::size_t MAX_STRING_SIZE =
			COUNT_NUMBERS * NUMBER_STRING_SIZE + COUNT_SPLITTERS;

public:
	using AddressString = IpAddressString<MAX_STRING_SIZE + 1>;

	Ipv6() noexcept;
	Ipv6(const Ipv6 &address) noexcept;
	Ipv6(const char* address) noexcept;
	Ipv6 &operator=(const Ipv6 &address) noexcept;

	AddressString getAddress() const noexcept;

public:
	flame_ide::ushort_t addressNumber[COUNT_NUMBERS];
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
				i = decltype(i){};
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
