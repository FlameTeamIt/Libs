#ifndef FLAMEIDE_OS_NETWORKBASE_HPP
#define FLAMEIDE_OS_NETWORKBASE_HPP

#include <FlameIDE/Os/Ipv4.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{

class NetworkBase: public NonCopy
{
public:
	using Range = templates::Range<byte_t *>;
	using ConstRange = templates::Range<const byte_t *>;

public:
	~NetworkBase() noexcept;

	operator bool() const noexcept;

	Status getStatus() const noexcept;

	const Socket &native() const;

protected:
	NetworkBase(Socket socket) noexcept;
	NetworkBase(NetworkBase &&base) noexcept;

	NetworkBase &operator=(NetworkBase &&base) noexcept;

	void setStatus(Status status) noexcept;

protected:
	static Types::int_t checkStatus(Status status) noexcept;

protected:
	Socket socket;

private:
	Status status = 0;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_NETWORKBASE_HPP
