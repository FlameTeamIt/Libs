#ifndef HANDLERINTERNALTCP_HPP
#define HANDLERINTERNALTCP_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/TcpConfig.hpp>
#include <FlameIDE/../../src/Handler/Network/TcpServer.hpp>
#include <FlameIDE/../../src/Handler/Network/TcpClient.hpp>

namespace flame_ide
{namespace handler
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

// WARNING: using UniquePointer because malloc doen't work with big sizes
using AcceptedConnections = templates::StaticArray<
	templates::UniquePointer<AcceptedConnection>
	, Constants::NUMBER_OF_SERVERS_CONNECTIONS
>;

struct Tcp
{
public:
	Server *push(os::network::TcpServer &&server) noexcept;
	os::network::TcpServer pop(Server *server) noexcept;

	Client *push(os::network::TcpClient &&client) noexcept;
	os::network::TcpClient pop(Client *client) noexcept;

public:
	templates::UniquePointer<Servers> servers = decltype(servers)::makeEmpty();
	templates::UniquePointer<AcceptedConnections> acceptedConnctions
			/* = decltype(acceptedConnctions)::makeEmpty()*/;

	templates::UniquePointer<Clients> clients/* = decltype(clients)::makeEmpty()*/;
	SocketDescriptors socketDescriptors;

	os::threads::Spin serversSpin;
	os::threads::Spin acceptedConnctionsSpin;
	os::threads::Spin clientsSpin;
};

}}}} // namespace flame_ide::handler::network::tcp

#endif // HANDLERINTERNALTCP_HPP
