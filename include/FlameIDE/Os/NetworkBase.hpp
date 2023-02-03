#ifndef FLAMEIDE_OS_NETWORKBASE_HPP
#define FLAMEIDE_OS_NETWORKBASE_HPP

#include <FlameIDE/Os/Ipv4.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{

class NetworkBase
{
public:
	using Range = templates::Range<byte_t *>;
	using ConstRange = templates::Range<const byte_t *>;

public:
	~NetworkBase() noexcept;

protected:
	NetworkBase(Socket socket) noexcept;
	NetworkBase(NetworkBase &&udp) noexcept;

protected:
	Socket socket;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_NETWORKBASE_HPP
