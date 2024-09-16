#include <FlameIDE/../../src/Handler/Network/Udp/InternalData.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace callbacks
{

// client

// TODO
Types::ssize_t clientBytesToRead(void */*data*/) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t clientReceive(void */*data*/, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// TODO
Types::ssize_t clientSend(void */*data*/, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// server

Types::ssize_t serverBytesToRead(const udp::ServerCommunicationData *data) noexcept
{
	if (!data || !data->message)
		return os::STATUS_FAILED;

	os::threads::Locker{ data->message->spin };

	return data->message->size;
}

Types::ssize_t
serverReceive(
		udp::ServerCommunicationData *data, templates::Range<byte_t *> range
) noexcept
{
	if (!data || !data->message)
		return os::STATUS_FAILED;

	Types::ssize_t numberToRead = 0;
	auto &message = *data->message;
	{
		os::threads::Locker{ message.spin };

		const Types::ssize_t rangeSize = range.end() - range.begin();
		const Types::ssize_t messageSize = message.size;
		const Types::ssize_t toRead = (rangeSize < messageSize)
				? rangeSize
				: messageSize;

		auto begin = range.begin();
		for (Types::ssize_t i = 0; i < toRead; ++i, ++begin)
		{
			*begin = message.bytes[i];
		}
		message.size = 0;
		message.client = decltype(message.client){};
		message.state = MessageState::EMPTY;

		numberToRead = toRead;
	}
	return numberToRead;
}

Types::ssize_t
serverSend(
		udp::ServerCommunicationData *data, templates::Range<const byte_t *> range
) noexcept
{
	if (!data || !data->output)
		return os::STATUS_FAILED;

	auto &output = *data->output;
	Server::Message *message = nullptr;
	{
		os::threads::Locker locker{ output.spin };
		message = output.last->pointer();
		{
			os::threads::Locker locker{ message->spin };
			message->state = MessageState::PROCESSING;
		}
		++output.last;
	}

	const Types::ssize_t rangeSize = range.end() - range.begin();
	{
		os::threads::Locker locker{ message->spin };
		message->size = rangeSize;
		message->client = data->client;

		auto begin = range.begin();
		for (Types::ssize_t i = 0; i < rangeSize; ++i, ++begin)
		{
			message->bytes[i] = *begin;
		}

		message->state = MessageState::READY;
	}
	return rangeSize;
}

}}}}} // namespace flame_ide::os::network::udp::callbacks
