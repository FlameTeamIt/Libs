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

Handler::ExpectedServerHandle Handler::pushUdp(os::network::UdpServer &&server) noexcept
{
	auto result = internal->udp().push(flame_ide::move(server));
	result.ifResultGet(
			[this](ServerHandle &result)
			{
				auto &handleData = result.object.get<Udp::ServerHandleData>();
				const auto &endpoint = handleData.server->endpoint().get();
				internal->registrar().add(endpoint);

				handleData.handler = this;
				result.callbackDeregistrate =
						internal->udp().serverCallbackDeregistrate();
			}
	);
	return flame_ide::move(result);
}

Handler::ExpectedSessionHandle Handler::pushUdp(os::network::UdpClient &&client) noexcept
{
	auto result = internal->udp().push(flame_ide::move(client));
	result.ifResultGet(
			[this](SessionHandle &result)
			{
				auto &handleData = result.object.get<Udp::SessionHandleData>();
				const auto &endpoint = handleData.data.client->endpoint().get();
				internal->registrar().add(endpoint);

				handleData.handler = this;
				result.callbackDeregistrate =
						internal->udp().clientCallbackDeregistrate();
			}
	);

	return flame_ide::move(result);
}

Handler::ExpectedServerHandle Handler::pushTcp(os::network::TcpServer &&server) noexcept
{
	auto result = internal->tcp().push(flame_ide::move(server));
	// const decltype(result) &constResult = result;
	// constResult.ifResult(
	// 		[this](const auto &result)
	// 		{
	// 			const auto &endpoint = *static_cast<const os::network::TcpServer *>(
	// 					result.data
	// 			);
	// 			internal->registrar().add(endpoint);
	// 		}
	// );
	return flame_ide::move(result);
}

Handler::ExpectedSessionHandle Handler::pushTcp(os::network::TcpClient &&client) noexcept
{
	auto result = internal->tcp().push(flame_ide::move(client));
	const decltype(result) &constResult = result;
	constResult.ifResult(
			[](const auto &)
			{
				// TODO
				// const auto &endpoint = result.object.get<udp::ClientCommunicationData>()
				// 		.client->endpoint().get();
				// internal->registrar().add(endpoint);
			}
	);

	return result;
}

Handler::ExpectedUdpServer Handler::popUdp(ServerHandle &handle) noexcept
{
	return internal->udp().pop(handle);
}

Handler::ExpectedUdpClient Handler::popUdp(SessionHandle &handle) noexcept
{
	return internal->udp().pop(handle);
}

Handler::ExpectedTcpServer Handler::popTcp(ServerHandle &handle) noexcept
{
	return internal->tcp().pop(handle);
}

Handler::ExpectedTcpClient Handler::popTcp(SessionHandle &handle) noexcept
{
	return internal->tcp().pop(handle);
}

os::Status Handler::start() noexcept
{
	return internal->start();
}

os::Status Handler::stop() noexcept
{
	return internal->stop();
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
