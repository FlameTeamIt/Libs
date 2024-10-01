#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::SessionHandle::operator bool() const noexcept
{
	return object && callbackBytesToRead && callbackReceive && callbackSend;
}

Types::ssize_t Handler::SessionHandle::bytesToRead() const noexcept
{
	return callbackBytesToRead(&object);
}

Types::ssize_t
Handler::SessionHandle::receive(templates::Range<byte_t *> bytes) noexcept
{
	return callbackReceive(&object, bytes);
}

Types::ssize_t
Handler::SessionHandle::send(templates::Range<const byte_t *> bytes) noexcept
{
	return callbackSend(&object, bytes);
}

}}} // namespace flame_ide::handler::network
