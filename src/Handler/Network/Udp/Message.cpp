#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

::flame_ide::templates::Range<::flame_ide::byte_t *> Message::range() noexcept
{
	return ::flame_ide::templates::makeRange(
			bytes.begin().operator->(), bytes.end().operator->()
	);
}

}}}} // namespace flame_ide::handler::network::udp
