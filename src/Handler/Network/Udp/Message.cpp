#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

void Message::onWrite(MessageWriter &writer) noexcept
{
	os::threads::Locker lock{ spin };
	writer(*this);
	state = MessageState::READY;
}

void Message::onRead(MessageReader &reader) noexcept
{
	os::threads::Locker lock{ spin };
	reader(*this);
	state = MessageState::EMPTY;
}

::flame_ide::templates::Range<::flame_ide::byte_t *> Message::range() noexcept
{
	return ::flame_ide::templates::makeRange(
			bytes.begin().operator->(), bytes.end().operator->()
	);
}

}}}} // namespace flame_ide::handler::network::udp
