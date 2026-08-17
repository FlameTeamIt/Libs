#ifndef HANDLER_INTERNAL_UDP_TYPE_MAPPING_HPP
#define HANDLER_INTERNAL_UDP_TYPE_MAPPING_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>

// Forwards

namespace flame_ide
{namespace os
{namespace network
{

class UdpServer;
class UdpClient;

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

class Server;
class Servers;

class Client;
class Clients;

template<typename Container>
struct HandlerEndpointUdpData;

}}}} // / namespace flame_ide::handler::network::udp

// Mapping

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

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

// Gets os::network::{ UdpServer, UdpClient } <-> { Server, Client }
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

#endif // HANDLER_INTERNAL_UDP_TYPE_MAPPING_HPP
