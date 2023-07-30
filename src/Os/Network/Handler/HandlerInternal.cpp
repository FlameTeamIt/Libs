#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternal.hpp>

// private callbacks for UDP - difinition
namespace flame_ide
{namespace os
{namespace network
{namespace udp
{namespace callbacks
{
namespace // anonymous
{

// client

Types::ssize_t clientBytesToRead(void *data) noexcept;

Types::ssize_t clientReceive(void *data, templates::Range<byte_t *>) noexcept;

Types::ssize_t clientSend(void *data, templates::Range<const byte_t *>) noexcept;

// server

Types::ssize_t serverBytesToRead(void *data) noexcept;

Types::ssize_t serverReceive(void *data, templates::Range<byte_t *>) noexcept;

Types::ssize_t serverSend(void *data, templates::Range<const byte_t *>) noexcept;

} // namespace anonymous
}}}}} // namespace flame_ide::os::network::udp::callbacks

// private callbacks for TCP - difinition
namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{namespace callbacks
{
namespace // anonymous
{

// client

Types::ssize_t clientBytesToRead(void *data) noexcept;

Types::ssize_t clientReceive(void *data, templates::Range<byte_t *>) noexcept;

Types::ssize_t clientSend(void *data, templates::Range<const byte_t *>) noexcept;

// server

Types::ssize_t serverBytesToRead(void *data) noexcept;

Types::ssize_t serverReceive(void *data, templates::Range<byte_t *>) noexcept;

Types::ssize_t serverSend(void *data, templates::Range<const byte_t *>) noexcept;

} // namespace anonymous
}}}}} // namespace flame_ide::os::network::udp::callbacks

// Handler::Internal implementation
namespace flame_ide
{namespace os
{namespace network
{

Handler::Internal::Internal() noexcept
{}

Handler::Internal::~Internal() = default;

Handler::ServerHandle Handler::Internal::push(UdpServer &&/*server*/) noexcept
{
//	udp::Server *data = nullptr;
//	for (auto &i : udp.servers)
//	{
//		if (i.server)
//			continue;

//		data = &i;
//		break;
//	}
//	if (!data)
//		return {};
//	data->server = flame_ide::move(server);

	ServerHandle handle;
	{
		static auto callbackGetCommunicationHandle = [](void */*data*/)
				-> Handler::CommunicationHandle
		{
//			if (!data)
//				return {};

//			udp::Server &serverData = *static_cast<udp::Server *>(data);
//			if (!serverData.inputMessages.size())
//				return {};

//			udp::Server::Message *message =
//					serverData.inputMessages.begin().operator->();

			Handler::CommunicationHandle handle;
			handle.data[0] = nullptr;
			handle.data[1] = nullptr; // ?
			handle.callbackBytesToRead = udp::callbacks::serverBytesToRead;
			handle.callbackReceive = udp::callbacks::serverReceive;
			handle.callbackSend = udp::callbacks::serverSend;
			return handle;
		};
		handle.callbackGetCommunicationHandle = callbackGetCommunicationHandle;
	}
//	handle.data = data;
	return handle;
}

Handler::CommunicationHandle Handler::Internal::push(UdpClient &&/*client*/) noexcept
{
//	udp::Client *data = nullptr;
//	for (auto &i : udp.clients)
//	{
//		if (i.client)
//			continue;

//		data = &i;
//		break;
//	}
//	if (!data)
//		return {};
//	data->client = flame_ide::move(client);

	Handler::CommunicationHandle handle;
	handle.data[0] = nullptr; // ?
	handle.data[1] = nullptr; // ?
	handle.callbackBytesToRead = udp::callbacks::clientBytesToRead;
	handle.callbackReceive = udp::callbacks::clientReceive;
	handle.callbackSend = udp::callbacks::clientSend;
	return handle;
}

Handler::ServerHandle Handler::Internal::push(TcpServer &&/*server*/) noexcept
{
//	tcp::Server *data = nullptr;
//	for (auto &i : tcp.servers)
//	{
//		if (i.server)
//			continue;
//		data = &i;
//		break;
//	}
//	if (!data)
//		return {};
//	data->server = flame_ide::move(server);

	Handler::ServerHandle handle;
	{
		static auto callbackGetCommunicationHandle = [](void */*data*/)
				-> Handler::CommunicationHandle
		{
			Handler::CommunicationHandle handle;
			handle.data[0] = nullptr; // ?
			handle.data[1] = nullptr; // ?
			handle.callbackBytesToRead = tcp::callbacks::serverBytesToRead;
			handle.callbackReceive = tcp::callbacks::serverReceive;
			handle.callbackSend = tcp::callbacks::serverSend;
			return handle;
		};
		handle.callbackGetCommunicationHandle = callbackGetCommunicationHandle;
	}
	return handle;
}

Handler::CommunicationHandle Handler::Internal::push(TcpClient &&/*client*/) noexcept
{
//	tcp::Client *data = nullptr;
//	for (auto &i : tcp.clients)
//	{
//		if (i.client)
//			continue;
//		data = &i;
//		break;
//	}
//	if (!data)
//		return {};
//	data->client = flame_ide::move(client);

	Handler::CommunicationHandle handle;
	handle.data[0] = nullptr; // ?
	handle.data[1] = nullptr; // ?
	handle.callbackBytesToRead = tcp::callbacks::clientBytesToRead;
	handle.callbackReceive = tcp::callbacks::clientReceive;
	handle.callbackSend = tcp::callbacks::clientSend;
	return handle;
}

}}} // namespace flame_ide::os::network

// private callbacks for UDP - implementation
namespace flame_ide
{namespace os
{namespace network
{namespace udp
{namespace callbacks
{
namespace // anonymous
{

// client

Types::ssize_t clientBytesToRead(void */*data*/) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t clientReceive(void */*data*/, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t clientSend(void */*data*/, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// server

Types::ssize_t serverBytesToRead(void */*data*/) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t serverReceive(void */*data*/, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t serverSend(void */*data*/, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

} // namespace anonymous
}}}}} // namespace flame_ide::os::network::udp::callbacks

// private callbacks for TCP - implementation
namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{namespace callbacks
{
namespace // anonymous
{

// client

Types::ssize_t clientBytesToRead(void */*data*/) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t clientReceive(void */*data*/, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t clientSend(void */*data*/, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

// server

Types::ssize_t serverBytesToRead(void */*data*/) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t serverReceive(void */*data*/, templates::Range<byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

Types::ssize_t serverSend(void */*data*/, templates::Range<const byte_t *>) noexcept
{
	return os::STATUS_FAILED;
}

} // namespace anonymous
}}}}} // namespace flame_ide::os::network::udp::callbacks
