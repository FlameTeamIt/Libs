#ifndef HANDLERINTERNALTCPDATA_HPP
#define HANDLERINTERNALTCPDATA_HPP

#include <FlameIDE/../../src/Handler/Network/Tcp/Client.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp/Server.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{namespace callbacks
{

// client

// TODO
Types::ssize_t clientBytesToRead(void *data) noexcept;

// TODO
Types::ssize_t clientReceive(void *data, templates::Range<byte_t *>) noexcept;

// TODO
Types::ssize_t clientSend(void *data, templates::Range<const byte_t *>) noexcept;

// server

// TODO
Types::ssize_t serverBytesToRead(void *data) noexcept;

// TODO
Types::ssize_t serverReceive(void *data, templates::Range<byte_t *>) noexcept;

// TODO
Types::ssize_t serverSend(void *data, templates::Range<const byte_t *>) noexcept;

}}}}} // namespace flame_ide::os::network::udp::callbacks

#endif // HANDLERINTERNALTCPDATA_HPP
