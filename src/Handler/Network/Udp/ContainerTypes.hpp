#ifndef HANDLER_INTERNAL_UDP_CONTAINER_TYPES_HPP
#define HANDLER_INTERNAL_UDP_CONTAINER_TYPES_HPP

#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Client.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

// WARNING: using UniquePointer because malloc doen't work with big sizes
class Servers: public ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Server>, Constants::NUMBER_OF_SERVERS
>
{};

// WARNING: using UniquePointer because malloc doen't work with big sizes
class Clients: public ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Client>, Constants::NUMBER_OF_CLIENTS
>
{};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_CONTAINER_TYPES_HPP
