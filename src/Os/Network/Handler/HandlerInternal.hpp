#ifndef HANDLERINTERNAL_HPP
#define HANDLERINTERNAL_HPP

#include <FlameIDE/Os/Network/Handler.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdp.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcp.hpp>

#include <FlameIDE/../../src/Os/Posix/Network/Handler/HandlerTypes.hpp>
#include <FlameIDE/../../src/Os/Windows/Network/Handler/HandlerTypes.hpp>

#include <FlameIDE/Templates/Pointers.hpp>

// Common

#if !defined(NETWORK_HANDLER_NUMBER_OF_WORKERS)
#	define NETWORK_HANDLER_NUMBER_OF_WORKERS ::flame_ide::Types::size_t{ 2 }
#endif // !defined

namespace flame_ide
{namespace os
{namespace network
{

namespace types = FLAMEIDE_HANDLERTYPES_NAMESPACE;

using Workers = templates::StaticArray<
	types::Worker, NETWORK_HANDLER_NUMBER_OF_WORKERS
>;

class Handler::Internal
{
public:
	Internal() noexcept;
	~Internal() noexcept;

	Handler::ServerHandle push(UdpServer &&server) noexcept;
	Handler::CommunicationHandle push(UdpClient &&client) noexcept;

	Handler::ServerHandle push(TcpServer &&server) noexcept;
	Handler::CommunicationHandle push(TcpClient &&client) noexcept;

private:
	Handler::ServerHandle::CallbackGetCommunicationHandle
	getServerHandleCallback() const noexcept;

private:
	udp::Udp udp;// = decltype(udp)::makeEmpty();
	tcp::Tcp tcp;// = decltype(tcp)::makeEmpty();

	types::Registration registration;
	Workers workers;
};

}}} // namespace flame_ide::os::network

#endif // HANDLERINTERNAL_HPP
