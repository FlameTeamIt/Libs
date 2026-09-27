#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

void Message::write(
		::flame_ide::VoidTraits::PointerToConst data
		, ::flame_ide::Types::size_t dataSize
) noexcept
{
	if (!data)
		return;
	if (decltype(bytes)::CAPACITY <= dataSize)
		return;

	flame_ide::os::threads::Locker lock{ spin };
	flame_ide::copy(bytes.begin().operator->(), data, dataSize);
	size = dataSize;
	state = MessageState::READY;
}

::flame_ide::templates::Range<::flame_ide::byte_t *> Message::range() noexcept
{
	return ::flame_ide::templates::makeRange(
			bytes.begin().operator->(), bytes.end().operator->()
	);
}

}}}} // namespace flame_ide::handler::network::udp
