#ifndef HANDLERINTERNALTCP_HPP
#define HANDLERINTERNALTCP_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpServer.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpClient.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpTypes.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Servers = ChooseType<
	Constants::NUMBER_OF_SERVERS != 0
	, templates::StaticArray<
		templates::UniquePointer<Server>, Constants::NUMBER_OF_SERVERS
	>
	, ::flame_ide::Empty
>::Type;

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Clients = ::flame_ide::ChooseType<
	Constants::NUMBER_OF_CLIENTS != 0
	, templates::StaticArray<
		templates::UniquePointer<Client>, Constants::NUMBER_OF_CLIENTS
	>
	, ::flame_ide::Empty
>::Type;

using SocketDescriptors = ChooseType<
	Constants::NUMBER_OF_SOCKETS != 0
	, templates::StaticArray<
		os::SocketDescriptor, Constants::NUMBER_OF_SOCKETS
	>
	, ::flame_ide::Empty
>::Type;

using AcceptedConnections = templates::StaticArray<
	templates::UniquePointer<AcceptedConnection>
	, Constants::NUMBER_OF_SERVERS_CONNECTIONS
>;

struct Tcp
{
	templates::UniquePointer<Servers> servers/* = decltype(servers)::makeEmpty()*/;
	templates::UniquePointer<AcceptedConnections> acceptedConnctions
			/* = decltype(acceptedConnctions)::makeEmpty()*/;

	templates::UniquePointer<Clients> clients/* = decltype(clients)::makeEmpty()*/;
	SocketDescriptors socketDescriptors;

	threads::Spin serversSpin;
	threads::Spin clientsSpin;
};

}}}} // namespace flame_ide::os::network::tcp

#endif // HANDLERINTERNALTCP_HPP
