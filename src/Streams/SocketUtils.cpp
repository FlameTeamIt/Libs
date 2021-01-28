#include <FlameIDE/Streams/SocketUtils.hpp>
#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace streams
{namespace socket_utils
{

Ipv4::Ipv4() noexcept :
	port{}
{
	templates::foreach(
			templates::makeRange(addressNumber)
			, [](auto &i)
			{
				i = typename RemoveAll<decltype(i)>::Type{};
			}
	);
}

Ipv4::Ipv4(const Ipv4 &address) noexcept :
	port{ address.port }
{
	templates::copy(
			templates::makeConstRange(address.addressNumber)
			, templates::makeRange(addressNumber).begin()
	);

}

Ipv4::Ipv4(const char* address) noexcept
{}

Ipv4 &Ipv4::operator=(const Ipv4 &address) noexcept
{
	templates::copy(
			templates::makeConstRange(address.addressNumber)
			, templates::makeRange(addressNumber).begin()
	);
	port = address.port;
	return *this;
}

Ipv4::AddressString Ipv4::getAddress() const noexcept
{
	AddressString addressString;
	return addressString;
}

}}}

namespace flame_ide
{namespace streams
{namespace socket_utils
{

Ipv6::Ipv6() noexcept :
	port{}
{
	templates::foreach(
			templates::makeRange(addressNumber)
			, [](auto &i)
			{
				i = typename RemoveAll<decltype(i)>::Type{};
			}
	);
}

Ipv6::Ipv6(const Ipv6 &address) noexcept :
	port{ address.port }
{
	templates::copy(
			templates::makeConstRange(address.addressNumber)
			, templates::makeRange(addressNumber).begin()
	);
}

Ipv6::Ipv6(const char* address) noexcept
{}

Ipv6 &Ipv6::operator=(const Ipv6 &address) noexcept
{
	templates::copy(
			templates::makeConstRange(address.addressNumber)
			, templates::makeRange(addressNumber).begin()
	);
	port = address.port;
	return *this;
}

Ipv6::AddressString Ipv6::getAddress() const noexcept
{
	AddressString addressString;
	return addressString;
}

}}}
