#ifndef HANDLERINTERNALUDPENDPOINT_HPP
#define HANDLERINTERNALUDPENDPOINT_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Client.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

// Container data

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

template<typename Container>
struct HandlerEndpointUdpData
{
	templates::UniquePointer<Container> container = decltype(container)::makeEmpty();
	os::threads::Spin spin;
};

// Matching traits

using ServerMatchingTrait = ::flame_ide::TypeMappingTrait<
	os::network::UdpServer, Server
>;
using ClientMatchingTrait = ::flame_ide::TypeMappingTrait<
	os::network::UdpClient, Client
>;

using ServerDataMatchingTrait = ::flame_ide::TypeMappingTrait<
	Server, HandlerEndpointUdpData<Servers>
>;
using ClientDataMatchingTrait = ::flame_ide::TypeMappingTrait<
	Client, HandlerEndpointUdpData<Clients>
>;

// Integral constants

template<typename EndpointType>
using IsServer = ::flame_ide::IntegralConstant<
	bool
	, ::flame_ide::ComparingTypes<
		EndpointType, ::flame_ide::os::network::UdpServer
	>::VALUE || ::flame_ide::ComparingTypes<EndpointType, Server>::VALUE
>;

template<typename EndpointType>
using IsClient = ::flame_ide::IntegralConstant<
	bool
	, ::flame_ide::ComparingTypes<
		EndpointType, ::flame_ide::os::network::UdpClient
	>::VALUE || ::flame_ide::ComparingTypes<EndpointType, Client>::VALUE
>;

template<typename T>
using IsCommonEndpoint = ::flame_ide::IntegralConstant<
	bool, IsServer<T>::VALUE || IsClient<T>::VALUE
>;

template<typename T>
using IsHandlerEndpoint = ::flame_ide::IntegralConstant<
	bool, ::flame_ide::ComparingTypes<T, Server>::VALUE
			|| ::flame_ide::ComparingTypes<T, Client>::VALUE
>;
template<typename T>
using IsOsEndpoint = ::flame_ide::IntegralConstant<
	bool
	, ::flame_ide::ComparingTypes<T, ::flame_ide::os::network::UdpServer>::VALUE
			|| ::flame_ide::ComparingTypes<T, ::flame_ide::os::network::UdpClient>::VALUE
>;

// Mappers

// Gets os::network::{ UdpServer, UdpCinet } <-> { Server, Client }
template<typename EndpointType>
using EndpointTypeMapper = ::flame_ide::TypeMapper<
	EndpointType
	, typename ::flame_ide::ChooseType<
		IsServer<EndpointType>::VALUE, ServerMatchingTrait, ClientMatchingTrait
	>::Type
>;

template<typename EndpointType>
using EndpointTypeMapper = ::flame_ide::TypeMapper<
	EndpointType
	, typename ::flame_ide::ChooseType<
		IsServer<EndpointType>::VALUE, ServerMatchingTrait, ClientMatchingTrait
	>::Type
>;

template<
	typename HandlerEndpoint
	, typename = typename ::flame_ide::EnableType<
		IsHandlerEndpoint<HandlerEndpoint>::VALUE, HandlerEndpoint
	>::Type
>
using HandlerEndpointDataMapper = ::flame_ide::TypeMapper<
	HandlerEndpoint
	, typename ::flame_ide::ChooseType<
		IsServer<HandlerEndpoint>::VALUE
		, ServerDataMatchingTrait
		, ClientDataMatchingTrait
	>::Type
>;

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPENDPOINT_HPP
