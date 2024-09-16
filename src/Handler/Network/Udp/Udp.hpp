#ifndef HANDLERINTERNALUDP_HPP
#define HANDLERINTERNALUDP_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Client.hpp>

namespace flame_ide
{namespace handler
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

class Udp
{
public:
	Server *push(os::network::UdpServer &&server) noexcept;
	os::network::UdpServer pop(Server *server) noexcept;

	Client *push(os::network::UdpClient &&client) noexcept;
	os::network::UdpClient pop(Client *client) noexcept;

public:
	templates::UniquePointer<Servers> servers = decltype(servers)::makeEmpty();
	templates::UniquePointer<Clients> clients/* = decltype(clients)::makeEmpty()*/;
	SocketDescriptors socketDescriptors;

	os::threads::Spin serversSpin;
	os::threads::Spin clientsSpin;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDP_HPP
