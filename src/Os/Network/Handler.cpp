#include <FlameIDE/Os/Network/Handler.hpp>

#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternal.hpp>

// private functions
namespace flame_ide
{namespace os
{namespace network
{
namespace // anonymous
{

Handler::Internal *makeInternal() noexcept;
void destroyInternal(Handler::Internal *&internal) noexcept;

} // namespace anonymous
}}} // namespace flame_ide::os::network

// Handler
namespace flame_ide
{namespace os
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

Handler::ServerHandle Handler::push(UdpServer &&server) noexcept
{
	return internal->push(flame_ide::move(server));
}

Handler::CommunicationHandle Handler::push(UdpClient &&client) noexcept
{
	return internal->push(flame_ide::move(client));
}

Handler::ServerHandle Handler::push(TcpServer &&server) noexcept
{
	return internal->push(flame_ide::move(server));
}

Handler::CommunicationHandle Handler::push(TcpClient &&client) noexcept
{
	return internal->push(flame_ide::move(client));
}

Status Handler::pop(const ServerHandle &, UdpServer &/*server*/) noexcept
{
	return os::STATUS_FAILED;
}

Status Handler::pop(const CommunicationHandle &, UdpClient &/*client*/) noexcept
{
	return os::STATUS_FAILED;
}

Status Handler::pop(const ServerHandle &, TcpServer &/*server*/) noexcept
{
	return os::STATUS_FAILED;
}

Status Handler::pop(const CommunicationHandle &, TcpClient &/*client*/) noexcept
{
	return os::STATUS_FAILED;
}

const Handler::Info &Handler::getInfo() const noexcept
{
	// TODO
	static const Handler::Info::Udp udp {
			/* maxMessageSize = */ udp::Constants::MESSAGE_SIZE
			, /* maxServers = */ udp::Constants::NUMBER_OF_SERVERS
			, /* serverInputQueueSize = */ udp::Constants::SERVER_INPUT_QUEUE_SIZE
			, /* serverOutputQueueSize = */ udp::Constants::SERVER_OUTPUT_QUEUE_SIZE

			, /* maxClients = */ udp::Constants::NUMBER_OF_CLIENTS
			, /* clientInputQueueSize = */ udp::Constants::CLIENT_INPUT_QUEUE_SIZE
			, /* clientOutputQueueSize = */ udp::Constants::CLIENT_OUTPUT_QUEUE_SIZE

			, /* currentServers = */ 0
			, /* currentCients = */ 0
	};
	static const Handler::Info::Tcp tcp {
			/* maxServers = */ tcp::Constants::NUMBER_OF_SERVERS
			, /* maxServerConnections = */ tcp::Constants::NUMBER_OF_SERVERS_CONNECTIONS
			, /* connectionInputBufferSize = */ tcp::Constants::SERVER_INPUT_BUFFER_SIZE
			, /* connectionOutputBufferSize = */ tcp::Constants::SERVER_OUTPUT_BUFFER_SIZE

			, /* maxClients = */ tcp::Constants::NUMBER_OF_CLIENTS
			, /* clientInputBufferSize = */ tcp::Constants::CLIENT_INPUT_BUFFER_SIZE
			, /* clientOutputBufferSize = */ tcp::Constants::CLIENT_OUTPUT_BUFFER_SIZE

			, /* currentServers = */ 0
			, /* currentCients = */ 0
	};

	static const Handler::Info config { udp, tcp };
	return config;
}

Status Handler::start() noexcept
{
	return os::STATUS_FAILED;
}

Status Handler::stop() noexcept
{
	return os::STATUS_FAILED;
}

}}} // namespace flame_ide::os::network

// Subclasses
namespace flame_ide
{namespace os
{namespace network
{

// Handler::ServerHandle

Handler::ServerHandle::operator bool() const noexcept
{
	return data && callbackGetCommunicationHandle;
}

Handler::CommunicationHandle Handler::ServerHandle::getCommunicationHandle() noexcept
{
	return callbackGetCommunicationHandle(data);
}

// Handler::CommunicationHandle

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

}}} // namespace flame_ide::os::network

// private functions
namespace flame_ide
{namespace os
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
