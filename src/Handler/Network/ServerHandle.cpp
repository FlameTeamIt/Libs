#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ServerHandle::operator bool() const noexcept
{
	return data && callbackGetSessionHandle;
}

Handler::SessionHandle Handler::ServerHandle::getSessionHandle() noexcept
{
	return callbackGetSessionHandle(data);
}

}}} // namespace flame_ide::handler::network
