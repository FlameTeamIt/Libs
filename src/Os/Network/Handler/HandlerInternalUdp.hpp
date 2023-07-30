#ifndef HANDLERINTERNALUDP_HPP
#define HANDLERINTERNALUDP_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpServer.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpClient.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Servers = ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Server>, Constants::NUMBER_OF_SERVERS
>;

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Clients = ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Client>, Constants::NUMBER_OF_CLIENTS
>;

using SocketDescriptors = ::flame_ide::templates::StaticArray<
	::flame_ide::os::SocketDescriptor
	, Constants::NUMBER_OF_SERVERS + Constants::NUMBER_OF_CLIENTS
>;

struct Udp
{
	templates::UniquePointer<Servers> servers/* = decltype(servers)::makeEmpty()*/;
	templates::UniquePointer<Clients> clients/* = decltype(clients)::makeEmpty()*/;
	SocketDescriptors socketDescriptors;

	threads::Spin serversSpin;
	threads::Spin clientsSpin;
};

}}}} // namespace flame_ide::os::network::udp

#endif // HANDLERINTERNALUDP_HPP
