#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternal.hpp>

#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>


namespace flame_ide
{namespace os
{namespace network
{namespace udp
{
namespace // anonymous
{

struct ServerCommunicationData
{
	UdpServer::WithClient client;
	Server::Message *message;
	Server::ActualOutput *output;
};

} // namespace anonymous
}}}} // namespace flame_ide::os::network::udp

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

Types::ssize_t serverBytesToRead(const udp::ServerCommunicationData *message) noexcept;

Types::ssize_t serverReceive(
		udp::ServerCommunicationData *message, templates::Range<byte_t *> range
) noexcept;

Types::ssize_t serverSend(
		udp::ServerCommunicationData *data, templates::Range<const byte_t *>
) noexcept;

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

Handler::ServerHandle Handler::Internal::push(UdpServer &&server) noexcept
{
	if (!udp.servers)
		udp.servers = decltype(udp.servers){};

	if (server.native().descriptor == os::SOCKET_INVALID.descriptor)
		return Handler::ServerHandle{};

	udp::Server *data = nullptr;
	for (auto &i : *udp.servers)
	{
		if (i->server)
			continue;

		data = i.pointer();
		break;
	}
	if (!data)
		return Handler::ServerHandle{};
	data->server = flame_ide::move(server);

	ServerHandle handle;
	handle.data = data;
	handle.callbackGetCommunicationHandle = getServerHandleCallback();
	return handle;
}

Handler::CommunicationHandle Handler::Internal::push(UdpClient &&/*client*/) noexcept
{
	if (!udp.clients)
		udp.clients = decltype(udp.clients){};

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
//	handle.data[0] = nullptr; // ?
//	handle.data[1] = nullptr; // ?
//	handle.callbackBytesToRead = udp::callbacks::clientBytesToRead;
//	handle.callbackReceive = udp::callbacks::clientReceive;
//	handle.callbackSend = udp::callbacks::clientSend;
	return handle;
}

Handler::ServerHandle Handler::Internal::push(TcpServer &&server) noexcept
{
	if (!tcp.servers)
		tcp.servers = decltype(tcp.servers){};

	tcp::Server *data = nullptr;
	for (auto &i : *tcp.servers)
	{
		if (i->server)
			continue;
		data = i.pointer();
		break;
	}
	if (!data)
		return {};
	data->server = flame_ide::move(server);

	Handler::ServerHandle handle;
	{
		static auto callbackGetCommunicationHandle = [](void *data)
				-> Handler::CommunicationHandle
		{
			if (!data)
				return {};

			Handler::CommunicationHandle handle;
//			handle.data[0] = nullptr; // ?
//			handle.data[1] = nullptr; // ?
//			handle.callbackBytesToRead = tcp::callbacks::serverBytesToRead;
//			handle.callbackReceive = tcp::callbacks::serverReceive;
//			handle.callbackSend = tcp::callbacks::serverSend;
			return handle;
		};
		handle.callbackGetCommunicationHandle = callbackGetCommunicationHandle;
	}
	return handle;
}

Handler::CommunicationHandle Handler::Internal::push(TcpClient &&/*client*/) noexcept
{
	if (!tcp.clients)
		tcp.clients = decltype(tcp.clients){};

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
//	handle.data[0] = nullptr; // ?
//	handle.data[1] = nullptr; // ?
//	handle.callbackBytesToRead = tcp::callbacks::clientBytesToRead;
//	handle.callbackReceive = tcp::callbacks::clientReceive;
//	handle.callbackSend = tcp::callbacks::clientSend;
	return handle;
}

// private

Handler::ServerHandle::CallbackGetCommunicationHandle
Handler::Internal::getServerHandleCallback() const noexcept
{
	static auto callbackGetCommunicationHandle = [](void *data)
			-> Handler::CommunicationHandle
	{
		if (!data)
			return Handler::CommunicationHandle{};

		udp::Server &serverData = *static_cast<udp::Server *>(data);
		udp::Server::Message *inputMessage = nullptr;
		{
			auto &input = serverData.input;
			threads::Locker locker{ input.spin };

			if (input.first == input.last)
				return Handler::CommunicationHandle{};

			{
				auto *message = input.first->pointer();
				threads::Locker{ message->spin };

				inputMessage = message;
				inputMessage->state = udp::MessageState::PROCESSING;
			}
			++input.first;
		}

		Handler::CommunicationHandle handle;
		handle.object = decltype(handle.object){
				udp::ServerCommunicationData{
						inputMessage->client, inputMessage, &serverData.output
				}
		};
		handle.callbackBytesToRead =
				reinterpret_cast<Handler::CommunicationHandle::CallbackBytesToRead>(
						udp::callbacks::serverBytesToRead
				);
		handle.callbackReceive =
				reinterpret_cast<Handler::CommunicationHandle::CallbackReceive>(
						udp::callbacks::serverReceive
				);
		handle.callbackSend =
				reinterpret_cast<Handler::CommunicationHandle::CallbackSend>(
						udp::callbacks::serverSend
				);
		return handle;
	};
	return callbackGetCommunicationHandle;
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

Types::ssize_t serverBytesToRead(const udp::ServerCommunicationData *data) noexcept
{
	if (!data || !data->message)
		return os::STATUS_FAILED;

	threads::Locker{ data->message->spin };

	return data->message->size;
}

Types::ssize_t
serverReceive(
		udp::ServerCommunicationData *data, templates::Range<byte_t *> range
) noexcept
{
	if (!data || !data->message)
		return os::STATUS_FAILED;

	Types::ssize_t numberToRead = 0;
	auto &message = *data->message;
	{
		threads::Locker{ message.spin };

		const Types::ssize_t rangeSize = range.end() - range.begin();
		const Types::ssize_t messageSize = message.size;
		const Types::ssize_t toRead = (rangeSize < messageSize)
				? rangeSize
				: messageSize;

		auto begin = range.begin();
		for (Types::ssize_t i = 0; i < toRead; ++i, ++begin)
		{
			*begin = message.bytes[i];
		}
		message.size = 0;
		message.client = decltype(message.client){};
		message.state = MessageState::EMPTY;

		numberToRead = toRead;
	}
	return numberToRead;
}

Types::ssize_t
serverSend(
		udp::ServerCommunicationData *data, templates::Range<const byte_t *> range
) noexcept
{
	if (!data || !data->output)
		return os::STATUS_FAILED;

	auto &output = *data->output;
	Server::Message *message = nullptr;
	{
		threads::Locker locker{ output.spin };
		message = output.last->pointer();
		{
			threads::Locker locker{ message->spin };
			message->state = MessageState::PROCESSING;
		}
		++output.last;
	}

	const Types::ssize_t rangeSize = range.end() - range.begin();
	{
		threads::Locker locker{ message->spin };
		message->size = rangeSize;
		message->client = data->client;

		auto begin = range.begin();
		for (Types::ssize_t i = 0; i < rangeSize; ++i, ++begin)
		{
			message->bytes[i] = *begin;
		}

		message->state = MessageState::READY;
	}
	return rangeSize;
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
