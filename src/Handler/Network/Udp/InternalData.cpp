#include <FlameIDE/../../src/Handler/Network/Udp/InternalData.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace callbacks
{

// server

Types::ssize_t serverBytesToRead(const udp::ServerCommunicationData *data) noexcept
{
	if (!data || !data->message)
		return os::STATUS_FAILED;

	os::threads::Locker locker{ data->message->spin };
	return data->message->size;
}

Types::ssize_t
serverReceive(
		udp::ServerCommunicationData *data, templates::Range<byte_t *> range
) noexcept
{
	flame_ide::unused(range);

	if (!data || !data->message)
		return os::STATUS_FAILED;

	return os::STATUS_FAILED;
}

Types::ssize_t
serverSend(
		udp::ServerCommunicationData *data, templates::Range<const byte_t *> range
) noexcept
{
	flame_ide::unused(range);

	if (!data || !data->output)
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
}

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

}}}}} // namespace flame_ide::os::network::udp::callbacks
