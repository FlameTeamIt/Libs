#include <FlameIDE/Streams/SocketUtils.hpp>
#include <FlameIDE/Templates/String.hpp>
#include <FlameIDE/Templates/StringConvertions.hpp>

namespace flame_ide
{namespace streams
{namespace socket_utils
{

namespace
{

Ipv4::ExpectedAddress stringToIpv4(const char *address)
{
	Ipv4::ExpectedAddress result(int{-1});
	const auto addressSize = templates::String::rawStringLength(address);
	if (addressSize >= Ipv4::AddressString::MAX_LENGTH)
	{
		return result;
	}

	auto range = templates::makeRange<const char*>(address, address + addressSize);
	flame_ide::size_t counter{};
	templates::foreach(
			range
			, [&counter](char value)
			{
				if (value == ':')
				{
					++counter;
				}
			}
	);
	if (counter < Ipv4::Traits::COUNT_SPLITTERS)
	{
		return result;
	}

	result = Ipv4{};
	return result;
}

//Ipv4::AddressString ipv4ToString(const Ipv4 &address)
//{
//	(void)address;
//	return Ipv4::AddressString{};
//}

} // namespace anonymous

Ipv4::Ipv4() noexcept :
	port{}
{
	templates::foreach(
			templates::makeRange(addressNumber)
			, [](auto &i)
			{
				i = typename RemoveAllTrait<decltype(i)>::Type{};
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

Ipv4::Ipv4(const char* address) noexcept : Ipv4(stringToIpv4(address))
{}

Ipv4::Ipv4(const Ipv4::ExpectedAddress &expectAddress) noexcept
{
	expectAddress.ifError(
			[this](int)
			{
				*this = Ipv4{};
			}
	)
	.ifResult(
			[this](const Ipv4 &address)
			{
				*this = address;
			}
	)
	.done();
}

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

Ipv6::Ipv6() noexcept
	: port{}
{
	templates::foreach(
			templates::makeRange(addressNumber)
			, [](auto &i)
			{
				i = typename RemoveAllTrait<decltype(i)>::Type{};
			}
	);
}

Ipv6::Ipv6(const Ipv6 &address) noexcept
	: port{ address.port }
{
	templates::copy(
			templates::makeConstRange(address.addressNumber)
			, templates::makeRange(addressNumber).begin()
	);
}

Ipv6::Ipv6(const char* /*address*/) noexcept
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
