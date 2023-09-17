#ifndef TCPSOCKETFUNCTIONS_HPP
#define TCPSOCKETFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{

using ByteRange = templates::Range<byte_t *>;
using ConstByteRange = templates::Range<const byte_t *>;

}}}}} // namespace flame_ide::os::network::socket::tcp

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{namespace server
{

///
/// \brief listen
/// \param socket
/// \param backlog
/// \return
///
Status listen(const Socket &socket, Types::size_t backlog) noexcept;

///
/// \brief accept
/// \param socket
/// \return
///
Socket accept(const Socket &socket, Status *result = nullptr) noexcept;

}}}}}} // namespace flame_ide::os::network::socket::tcp::server

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{namespace client
{

///
/// \brief connect
/// \param socket
/// \return
///
Status connect(const Socket &socket) noexcept;

}}}}}} // namespace flame_ide::os::network::socket::tcp::client

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{

///
/// \brief send
/// \param socket
/// \param range
/// \return
///
Types::ssize_t send(const Socket &socket, ConstByteRange range) noexcept;

///
/// \brief receive
/// \param socket
/// \param range
/// \return
///
Types::ssize_t receive(const Socket &socket, ByteRange range) noexcept;

///
/// \brief waitBytes
/// \param socket
/// \param number
/// \return
///
Types::ssize_t waitBytes(const Socket &socket, Types::size_t number) noexcept;

///
/// \brief alive
/// \param socket
/// \return
///
bool alive(const Socket &socket) noexcept;

}}}}} // namespace flame_ide::os::network::socket::tcp

#endif // TCPSOCKETFUNCTIONS_HPP
