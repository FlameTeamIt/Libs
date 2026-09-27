#ifndef FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP
#define FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP

#include <FlameIDE/Common/FunctorBase.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

namespace tag
{

struct UdpServer {};
struct UdpClient {};
struct TcpServer {};
struct TcpAcceptedConnection {};
struct TcpClient {};

} // namespace tag

template<typename Tag>
class NotificatorBase: public flame_ide::DefaultFunctorBase {};

using UdpServerNotificatorBase = NotificatorBase<tag::UdpServer>;
using UdpClientNotificatorBase = NotificatorBase<tag::UdpClient>;
using TcpServerNotificatorBase = NotificatorBase<tag::TcpServer>;
using TcpAcceptedConnectionNotificatorBase = NotificatorBase<tag::TcpAcceptedConnection>;
using TcpClientNotificatorBase = NotificatorBase<tag::TcpClient>;

}}}} // namespace flame_ide::os::async::network

#endif // FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP
