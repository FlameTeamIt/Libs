#include <FlameIDE/Os/Network/Ipv4.hpp>

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <FlameIDE/Templates/Iterator/ConstIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstReverseIterator.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{
namespace // anonymous
{

constexpr Types::size_t IP_MIN_STRING_LENGTH = sizeof("0.0.0.0") - 1;
constexpr Types::size_t IP_MAX_STRING_LENGTH = Ipv4::MAX_STRING_SIZE - 1;

constexpr Types::char_t POINT = '.';
constexpr Types::char_t ZERO = '0';
constexpr Types::char_t CHAR_NULL = '\0';

bool convertIp(Ipv4::Number (& ipDest)[Ipv4::COUNT_NUMBERS], const char *ipSrc)
{
	const Types::size_t ipSrcLength = length(ipSrc);
	auto isNumberLambda = [](char value) -> bool
	{
		if (value >= '0' && value <= '9')
		{
			return true;
		}
		return false;
	};
	auto stringToNumberLambda = [](const char *begin, const char *end) -> Ipv4::Number
	{
		using ConstReverseIterator =
				templates::defaults::ConstReverseBidirectionalIterator<
					const char *
				>;

		auto range = templates::makeRange(
				ConstReverseIterator{end - 1}, ConstReverseIterator{begin - 1}
		);
		Ipv4::Number number = 0;
		Ipv4::Number devider = 1;
		for (auto i : range)
		{
			number += (i - '0') * devider;
			devider *= 10;
		}
		return number;
	};

	if (IP_MIN_STRING_LENGTH > ipSrcLength || ipSrcLength > IP_MAX_STRING_LENGTH)
	{
		return false;
	}

	const char *numberStart = ipSrc;
	Types::size_t index = 0;
	auto range = templates::makeRange(ipSrc, ipSrc + (ipSrcLength + 1));
	for (const char *it = range.begin(); it != range.end(); ++it)
	{
		if (isNumberLambda(*it))
		{
			if (!numberStart)
			{
				numberStart = it;
			}
			continue;
		}

		if (index == Ipv4::COUNT_NUMBERS)
		{
			return false;
		}
		if (!(*it == POINT || *it == CHAR_NULL))
		{
			return false;
		}

		ipDest[index++] = stringToNumberLambda(numberStart, it);
		numberStart = nullptr;

	}

	return true;
}

bool convertIp(char *ipDest, const Ipv4::Number (& ipSrc)[Ipv4::COUNT_NUMBERS])
{
	constexpr Types::size_t COUNT_POINTS = Ipv4::COUNT_NUMBERS - 1;
	constexpr Ipv4::Number HUNDERD_DEVIDER = 100;
	constexpr Ipv4::Number TEN_DEVIDER = 10;

	Types::size_t points = 0;
	char *ipIt = ipDest;
	for (Types::size_t i = 0; i < Ipv4::COUNT_NUMBERS; ++i)
	{
		Ipv4::Number value = ipSrc[i] / HUNDERD_DEVIDER;
		if (value)
			*(ipIt++) = static_cast<char>(value + ZERO);

		value = (ipSrc[i] % HUNDERD_DEVIDER) / TEN_DEVIDER;
		if (value)
			*(ipIt++) = static_cast<char>(value + ZERO);

		value = (ipSrc[i] % HUNDERD_DEVIDER) % TEN_DEVIDER;
		*(ipIt++) = static_cast<char>(value + ZERO);

		if (points != COUNT_POINTS)
		{
			*(ipIt++) = POINT;
			++points;
		}
	}
	*ipIt = CHAR_NULL;

	return true;
}

} // namespace anonymous
}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

Ipv4::Ipv4(const char *ip, Port port) noexcept : port(port)
{
	if (!convertIp(this->ip, ip))
	{
		reset();
	}
}

Ipv4::Ipv4(const Address &address) noexcept : Ipv4(address.ip, address.port)
{}

Ipv4::Ipv4(const Number (& ip)[COUNT_NUMBERS], Port port) noexcept : port(port)
{
	copy(this->ip, ip);
}

Ipv4::operator Ipv4::Address() const noexcept
{
	Address address;
	if (convertIp(address.ip, this->ip))
	{
		address.port = port;
		return address;
	}
	return {};
}

Ipv4::operator bool() const noexcept
{
	for (const auto &i : ip)
	{
		if (NumberLimitTrait<Types::uichar_t>::MIN_VALUE <= i
				&& i <= NumberLimitTrait<Types::uichar_t>::MAX_VALUE)
		{
			continue;
		}
		return false;
	}
	return true;
}

bool Ipv4::set(const char *ipString, Port portInit) noexcept
{
	if (!convertIp(this->ip, ipString))
	{
		reset();
		return false;
	}
	this->port = portInit;
	return true;
}

bool Ipv4::set(const Address &address) noexcept
{
	return set(address.ip, address.port);
}

bool Ipv4::set(const Number (& ipArray)[COUNT_NUMBERS], Port portInit) noexcept
{
	copy(this->ip, ipArray);
	this->port = portInit;
	return true;
}

Ipv4 Ipv4::localhost(Ipv4::Port port) noexcept
{
	const Number ipNumbers[] = {Number{127}, Number{0}, Number{0}, Number{1}};

	Ipv4 ip(ipNumbers, port);
	return ip;
}

void Ipv4::reset() noexcept
{
	const Number reset[] = {
			NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
	};
	copy(this->ip, reset);
	port = NumberLimitTrait<Port>::MIN_VALUE;
}

}}} // namespace flame_ide::os::network
