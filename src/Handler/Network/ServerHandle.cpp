#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ServerHandle::operator bool() const noexcept
{
	return data && callbackGetCommunicationHandle;
}

Handler::CommunicationHandle Handler::ServerHandle::getCommunicationHandle() noexcept
{
	return callbackGetCommunicationHandle(data);
}

}}} // namespace flame_ide::handler::network
