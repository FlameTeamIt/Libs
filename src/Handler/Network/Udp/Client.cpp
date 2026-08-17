#include <FlameIDE/../../src/Handler/Network/Udp/Client.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>
#include <FlameIDE/Templates/RaiiCaller.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

void ClientMessage::fill(flame_ide::os::network::UdpClient &endpoint)
{
	os::threads::Locker locker{ spin };

	auto waitResult = endpoint.wait();
	if (waitResult < 0)
		return;

	this->size = endpoint.receive(this->range());
	this->state = MessageState::READY;
}

Types::ssize_t ClientCommunicationData::bytesToRead() const noexcept
{
	if (!client)
		return os::STATUS_FAILED;

	return client->input().getFilledMessageSize();
}

Types::ssize_t
ClientCommunicationData::receive(templates::Range<byte_t *> range) noexcept
{
	if (!client)
		return os::STATUS_FAILED;

	ReferenceWrapper<ClientMessage> message = client->input().getFilledMessage();
	if (!message)
		return os::STATUS_FAILED;

	const auto raiiClear = flame_ide::templates::makeRaiiCaller(
			[&message]()
			{
				message->spin.lock();
				message->state = MessageState::PROCESSING;
			}
			, [&message]()
			{
				message->size = 0;
				message->state = MessageState::EMPTY;
				message->spin.unlock();
			}
	);

	const auto readBytes = flame_ide::minimum(
			Types::ssize_t{ message->size }
			, Types::ssize_t{ range.end() - range.begin() }
	);
	decltype(readBytes) result = flame_ide::templates::copy(
			message->bytes.begin(), message->bytes.begin() + readBytes
			, range.begin()
	);
	if (readBytes != result)
		return os::STATUS_FAILED;

	return readBytes;
}

Types::ssize_t
ClientCommunicationData::send(templates::Range<const byte_t *> range) noexcept
{
	if (!client)
		return os::STATUS_FAILED;

	ReferenceWrapper<ClientMessage> message = client->output().getEmptyMessage();
	if (!message)
		return os::STATUS_FAILED;

	const auto raiiClear = flame_ide::templates::makeRaiiCaller(
			[&message]()
			{
				message->spin.lock();
				message->state = MessageState::PROCESSING;
			}
			, [&message]()
			{
				message->state = MessageState::READY;
				message->spin.unlock();
			}
	);

	const auto wroteBytes = flame_ide::minimum(
			Types::ssize_t{ message->size }
			, Types::ssize_t{ range.end() - range.begin() }
	);
	decltype(wroteBytes) result = flame_ide::templates::copy(
			range.begin(), range.begin() + wroteBytes
			, message->bytes.begin()
	);
	if (wroteBytes != result)
		return os::STATUS_FAILED;
	return wroteBytes;
}

}}}} // namespace flame_ide::handler::network::udp
