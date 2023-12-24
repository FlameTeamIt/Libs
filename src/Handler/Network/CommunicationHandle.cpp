#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::CommunicationHandle::operator bool() const noexcept
{
	return object && callbackBytesToRead && callbackReceive && callbackSend;
}

Types::ssize_t Handler::CommunicationHandle::bytesToRead() const noexcept
{
	return callbackBytesToRead(&object);
}

Types::ssize_t
Handler::CommunicationHandle::receive(templates::Range<byte_t *> bytes) noexcept
{
	return callbackReceive(&object, bytes);
}

Types::ssize_t
Handler::CommunicationHandle::send(templates::Range<const byte_t *> bytes) noexcept
{
	return callbackSend(&object, bytes);
}

}}} // namespace flame_ide::handler::network
