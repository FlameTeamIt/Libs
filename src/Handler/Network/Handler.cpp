#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

#include <FlameIDE/../../src/Handler/Network/Internal.hpp>

// private functions
namespace flame_ide
{namespace handler
{namespace network
{
namespace // anonymous
{

Handler::Internal *makeInternal() noexcept;
void destroyInternal(Handler::Internal *&internal) noexcept;

} // namespace anonymous
}}} // namespace flame_ide::handler::network

// Handler
namespace flame_ide
{namespace handler
{namespace network
{

Handler::Handler() noexcept : internal{ makeInternal() }
{}

Handler::Handler(Handler &&handler) noexcept
{
	operator=(flame_ide::move(handler));
}

Handler::~Handler() noexcept
{
	stop();

	if (!internal)
		return;

	destroyInternal(internal);
}

Handler &Handler::operator=(Handler &&handler) noexcept
{
	internal = handler.internal;
	handler.internal = nullptr;

	return *this;
}

Handler::ServerHandle Handler::push(os::network::UdpServer &&server) noexcept
{
	return internal->push(flame_ide::move(server));
}

Handler::CommunicationHandle Handler::push(os::network::UdpClient &&client) noexcept
{
	return internal->push(flame_ide::move(client));
}

Handler::ServerHandle Handler::push(os::network::TcpServer &&server) noexcept
{
	return internal->push(flame_ide::move(server));
}

Handler::CommunicationHandle Handler::push(os::network::TcpClient &&client) noexcept
{
	return internal->push(flame_ide::move(client));
}

os::Status Handler::pop(const ServerHandle &, os::network::UdpServer &/*server*/) noexcept
{
	return os::STATUS_FAILED;
}

os::Status Handler::pop(const CommunicationHandle &, os::network::UdpClient &/*client*/) noexcept
{
	return os::STATUS_FAILED;
}

os::Status Handler::pop(const ServerHandle &, os::network::TcpServer &/*server*/) noexcept
{
	return os::STATUS_FAILED;
}

os::Status Handler::pop(const CommunicationHandle &, os::network::TcpClient &/*client*/) noexcept
{
	return os::STATUS_FAILED;
}

os::Status Handler::start() noexcept
{
	return os::STATUS_FAILED;
}

os::Status Handler::stop() noexcept
{
	return os::STATUS_FAILED;
}

}}} // namespace flame_ide::handler::network

// private functions
namespace flame_ide
{namespace handler
{namespace network
{
namespace // anonymous
{

using InternalAllocator = templates::allocator::ObjectAllocator<Handler::Internal>;

Handler::Internal *makeInternal() noexcept
{
	return InternalAllocator{}.construct();
}

void destroyInternal(Handler::Internal *&internal) noexcept
{
	InternalAllocator{}.destroy(internal);
}

} // namespace anonymous
}}} // namespace flame_ide::os::network
