#ifndef HANDLER_INTERNAL_UDP_MESSAGE_HPP
#define HANDLER_INTERNAL_UDP_MESSAGE_HPP

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct Message
{
	::flame_ide::templates::StaticArray<
		::flame_ide::byte_t, Constants::MESSAGE_SIZE
	> bytes;
	::flame_ide::Types::ssize_t size = 0;
	MessageState state = MessageState::EMPTY;

	mutable os::threads::Spin spin;

protected:
	::flame_ide::templates::Range<::flame_ide::byte_t *> range() noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_MESSAGE_HPP
