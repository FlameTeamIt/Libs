#ifndef FLAMEIDE_OS_IPV4_HPP
#define FLAMEIDE_OS_IPV4_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{namespace os
{

class Ipv4
{
public:
	static constexpr Types::size_t MAX_STRING_SIZE = sizeof("128.128.128.128");
	static constexpr Types::size_t COUNT_NUMBERS = 4;

public:
	using Number = Types::short_t;
	using Port = Types::int_t;

	struct Address
	{
		Types::char_t ip[MAX_STRING_SIZE] = "0.0.0.0";
		Port port = 0;
	};

	Ipv4() noexcept = default;
	Ipv4(const Ipv4 &) noexcept = default;
	Ipv4(Ipv4 &) noexcept = default;

	Ipv4(const char *ip, Port port) noexcept;
	Ipv4(const Address &ip) noexcept;
	Ipv4(const Number (& ip)[COUNT_NUMBERS], Port port) noexcept;

	~Ipv4() noexcept = default;

	Ipv4 &operator=(const Ipv4 &) = default;
	Ipv4 &operator=(Ipv4 &&) = default;

	operator Ipv4::Address() const noexcept;
	operator bool() const noexcept;

	bool set(const char *ip, Port port) noexcept;
	bool set(const Address &ip) noexcept;
	bool set(const Number (& ip)[COUNT_NUMBERS], Port port) noexcept;

	static Ipv4 localhost(Port port) noexcept;

private:
	void reset() noexcept;

private:
	Number ip[COUNT_NUMBERS] = {
			NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
			, NumberLimitTrait<Number>::MIN_VALUE
	};
	Port port = NumberLimitTrait<Port>::MIN_VALUE;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_IPV4_HPP
