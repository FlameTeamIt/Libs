#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

Types::ssize_t ServerCommunicationData::bytesToRead() const noexcept
{
	if (!message)
		return os::STATUS_FAILED;

	os::threads::Locker locker{ message->spin };
	return message->size;
}

Types::ssize_t ServerCommunicationData::receive(templates::Range<byte_t *> range) noexcept
{
	if (!message)
		return os::STATUS_FAILED;

	::flame_ide::Types::ssize_t readData = -1;
	{
		flame_ide::os::threads::Locker lock{ message->spin };

		const auto min = ::flame_ide::minimum<::flame_ide::Types::ssize_t>(
				(range.end() - range.begin()), message->size
		);
		::flame_ide::templates::copy(
				message->bytes.begin(), message->bytes.begin() + min, range.begin()
		);

		message->state = udp::MessageState::EMPTY;
		message->size = 0;

		readData = min;
	}
	return readData;
}

Types::ssize_t
ServerCommunicationData::send(templates::Range<const byte_t *> range) noexcept
{
	if (!output)
		return os::STATUS_FAILED;

	auto *message = output->getEmptyMessage();
	if (!message)
		return os::STATUS_FAILED;
	{
		flame_ide::os::threads::Locker lock{ message->spin };

		const auto min = ::flame_ide::minimum<::flame_ide::Types::ssize_t>(
				(range.end() - range.begin()), message->bytes.capacity()
		);
		::flame_ide::templates::copy(
				range.begin(), range.begin() + min, message->bytes.begin()
		);

		message->state = udp::MessageState::READY;
		message->size = min;
	}
	return message->size;
}

}}}} // namespace flame_ide::handler::network::udp
