#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ServerHandle::~ServerHandle()
{
	if (operator bool())
		callbackDeregistrate(this);
}

Handler::ServerHandle::operator bool() const noexcept
{
	return object && callbackGetSessionHandle && callbackDeregistrate;
}

Handler::ExpectedSessionHandle Handler::ServerHandle::getSessionHandle() noexcept
{
	return callbackGetSessionHandle(object);
}

}}} // namespace flame_ide::handler::network
