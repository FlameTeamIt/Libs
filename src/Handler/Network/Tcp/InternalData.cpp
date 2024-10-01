#include <FlameIDE/../../src/Handler/Network/Tcp/InternalData.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{namespace callbacks
{

// client

// TODO
Types::ssize_t clientBytesToRead(void * /* data */) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t clientReceive(void * /* data */, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t clientSend(void * /* data */, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// server

// TODO
Types::ssize_t serverBytesToRead(void * /* data */) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t serverReceive(void * /* data */, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t serverSend(void * /* data */, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

}}}}} // namespace flame_ide::os::network::udp::callbacks
