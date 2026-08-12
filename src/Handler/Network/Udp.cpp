#include <FlameIDE/../../src/Handler/Network/Udp.hpp>

#include <FlameIDE/Os/Async/Network/Registrar.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ExpectedServerHandle
Handler::Udp::push(os::network::UdpServer &&server) noexcept
{
	udp::Server *udpServer = storage.push(move(server));
	if (!udpServer)
		return { os::STATUS_FAILED };

	Handler::ServerHandle handle;
	handle.object = Handler::ServerHandle::Object{
			ServerHandleData{ nullptr, udpServer }
	};
	handle.callbackGetSessionHandle = serverHandleCallback();
	handle.callbackDeregistrate = nullptr;
	return { flame_ide::move(handle) };
}

Handler::ExpectedSessionHandle
Handler::Udp::push(os::network::UdpClient &&client) noexcept
{
	udp::Client *udpClient = storage.push(move(client));
	if (!udpClient)
		return { os::STATUS_FAILED };

	Handler::SessionHandle handle;
	handle.object = Handler::SessionHandle::Object{
			SessionHandleData{ nullptr, udp::ClientCommunicationData{ udpClient } }
	};
	handle.callbackBytesToRead = Handler::Udp::clientCallbackBytesToRead();
	handle.callbackReceive = Handler::Udp::clientCallbackReceive();
	handle.callbackSend = Handler::Udp::clientCallbackSend();
	handle.callbackDeregistrate = nullptr;
	return { flame_ide::move(handle) };
}

Handler::ExpectedUdpServer Handler::Udp::pop(Handler::ServerHandle &handle)
{
	if (!(handle.object && handle.callbackGetSessionHandle))
		return { os::STATUS_FAILED };

	auto data = handle.object.move<ServerHandleData>();
	auto server = storage.pop(data.server);
	if (!server)
		return { os::STATUS_FAILED };

	handle.callbackGetSessionHandle = nullptr;
	handle.callbackDeregistrate = nullptr;
	return { flame_ide::move(server) };
}

Handler::ExpectedUdpClient Handler::Udp::pop(Handler::SessionHandle &handle)
{
	if(!(handle.object && handle.callbackBytesToRead && handle.callbackReceive
			&& handle.callbackSend))
		return { os::STATUS_FAILED };

	auto data = handle.object.move<SessionHandleData>();
	auto client = storage.pop(data.data.client);
	if (!client)
		return { os::STATUS_FAILED };

	handle.callbackBytesToRead = nullptr;
	handle.callbackReceive = nullptr;
	handle.callbackSend = nullptr;
	handle.callbackDeregistrate = nullptr;
	return { flame_ide::move(client) };
}

// server

Handler::Udp::CallbackGetSessionHandle Handler::Udp::serverHandleCallback() const noexcept
{
	static const auto callback = [](ServerHandle::Object &object)
			-> Handler::ExpectedSessionHandle
	{
		static const auto empty = [](void *) -> void {};

		if (!object)
			return { os::STATUS_FAILED };

		auto *server = object.get<ServerHandleData>().server;

		// В очередь приходят сообщения
		auto *message = server->input().getFilledMessage();
		if (!message)
			return { os::STATUS_FAILED };

		{
			flame_ide::os::threads::Locker messageLock{ message->spin };
			if (message->state != udp::MessageState::READY)
				return { os::STATUS_FAILED };

			message->state = udp::MessageState::PROCESSING;
		}

		Handler::SessionHandle sessionHandle;
		sessionHandle.object = Handler::SessionHandle::Object{
				udp::ServerCommunicationData{ message, &server->output() }
		};
		sessionHandle.callbackBytesToRead = Handler::Udp::serverCallbackBytesToRead();
		sessionHandle.callbackReceive = Handler::Udp::serverCallbackReceive();
		sessionHandle.callbackSend = Handler::Udp::serverCallbackSend();
		sessionHandle.callbackDeregistrate =
				reinterpret_cast<Handler::Udp::CallbackSessionDeregistrate>(+empty);

		return { flame_ide::move(sessionHandle) };
	};
	return reinterpret_cast<CallbackGetSessionHandle>(+callback);
};

Handler::Udp::CallbackServerDeregistrate
Handler::Udp::serverCallbackDeregistrate() noexcept
{
	static const auto callback = [](ServerHandle *handle) -> void
	{
		auto handleData = handle->object.get<Udp::ServerHandleData>();
		const auto server = handleData.handler->popUdp(*handle);
		flame_ide::unused(server);
	};
	return (+callback);
}

Handler::Udp::CallbackSessionDeregistrate
Handler::Udp::clientCallbackDeregistrate() noexcept
{
	static const auto callback = [](SessionHandle *handle) -> void
	{
		auto handleData = handle->object.get<Udp::SessionHandleData>();
		const auto client = handleData.handler->popUdp(*handle);
		flame_ide::unused(client);
	};
	return (+callback);
}

udp::ServerCommunicationData *Handler::Udp::serverToCommunicationData(
		Handler::SessionHandle::Object &object
) noexcept
{
	if (!object)
		return nullptr;

	return &object.get<udp::ServerCommunicationData>();
}

const udp::ServerCommunicationData *Handler::Udp::serverToConstCommunicationData(
		const Handler::SessionHandle::Object &object
) noexcept
{
	if (!object)
		return nullptr;

	return &object.get<udp::ServerCommunicationData>();
}

Handler::Udp::CallbackBytesToRead Handler::Udp::serverCallbackBytesToRead() noexcept
{
	static const auto callback = [](const Handler::SessionHandle::Object &object)
			-> ::flame_ide::Types::ssize_t
	{
		const auto *data = Handler::Udp::serverToConstCommunicationData(object);
		return data->bytesToRead();
	};
	return reinterpret_cast<CallbackBytesToRead>(+callback);
}

Handler::Udp::CallbackReceive Handler::Udp::serverCallbackReceive() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object &object
			, ::flame_ide::templates::Range<byte_t *> range
	) -> ::flame_ide::Types::ssize_t
	{
		auto *data = Handler::Udp::serverToCommunicationData(object);
		return data->receive(range);
	};
	return reinterpret_cast<CallbackReceive>(+callback);
}

Handler::Udp::CallbackSend Handler::Udp::serverCallbackSend() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object &object
			, ::flame_ide::templates::Range<const byte_t *> range
	) -> ::flame_ide::Types::ssize_t
	{
		auto *data = Handler::Udp::serverToCommunicationData(object);
		return data->send(range);
	};
	return reinterpret_cast<CallbackSend>(+callback);
}

// client

udp::ClientCommunicationData *Handler::Udp::clientToCommunicationData(
		Handler::SessionHandle::Object &object
) noexcept
{
	if (!object)
		return nullptr;

	return &object.get<udp::ClientCommunicationData>();
}

const udp::ClientCommunicationData *Handler::Udp::clientToConstCommunicationData(
		const Handler::SessionHandle::Object &object
) noexcept
{
	if (!object)
		return nullptr;

	return &object.get<udp::ClientCommunicationData>();
}

Handler::Udp::CallbackBytesToRead Handler::Udp::clientCallbackBytesToRead() noexcept
{
	static const auto callback = [](const Handler::SessionHandle::Object &object)
			-> Types::ssize_t
	{
		const auto *data = Handler::Udp::clientToConstCommunicationData(object);
		return data->bytesToRead();
	};

	return reinterpret_cast<CallbackBytesToRead>(+callback);
}

Handler::Udp::CallbackReceive Handler::Udp::clientCallbackReceive() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object &object
			, ::flame_ide::templates::Range<byte_t *> range
	) -> Types::ssize_t
	{
		auto *data = Handler::Udp::clientToCommunicationData(object);
		return data->receive(range);
	};

	return reinterpret_cast<CallbackReceive>(+callback);
}

Handler::Udp::CallbackSend Handler::Udp::clientCallbackSend() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object &object
			, ::flame_ide::templates::Range<const byte_t *> range
	) -> Types::ssize_t
	{
		auto *data = Handler::Udp::clientToCommunicationData(object);
		return data->send(range);
	};

	return reinterpret_cast<CallbackSend>(+callback);
}

}}} // namespace flame_ide::handler::network
