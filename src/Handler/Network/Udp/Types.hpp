#ifndef HANDLER_INTERNAL_UDP_TYPES_HPP
#define HANDLER_INTERNAL_UDP_TYPES_HPP

#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

enum class MessageState
{
	EMPTY
	, PROCESSING
	, READY
};

template<typename Container>
struct HandlerEndpointUdpData
{
	templates::UniquePointer<Container> container = decltype(container)::makeEmpty();
	os::threads::Spin spin;
};

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{
}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_TYPES_HPP
