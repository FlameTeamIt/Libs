#ifndef HANDLERINTERNALUDPDATA_HPP
#define HANDLERINTERNALUDPDATA_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Client.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace callbacks
{

// server

Types::ssize_t serverBytesToRead(const udp::ServerCommunicationData *message) noexcept;

Types::ssize_t serverReceive(
		udp::ServerCommunicationData *message, templates::Range<byte_t *> range
) noexcept;

Types::ssize_t serverSend(
		udp::ServerCommunicationData *data, templates::Range<const byte_t *>
) noexcept;

// client

// TODO
Types::ssize_t clientBytesToRead(void *data) noexcept;

// TODO
Types::ssize_t clientReceive(void *data, templates::Range<byte_t *>) noexcept;

// TODO
Types::ssize_t clientSend(void *data, templates::Range<const byte_t *>) noexcept;

}}}}} // namespace flame_ide::os::network::udp::callbacks

#endif // HANDLERINTERNALUDPDATA_HPP
