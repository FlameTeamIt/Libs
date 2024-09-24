#include <FlameIDE/../../src/Handler/Network/Udp.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ExpectedServerHandle Handler::Udp::push(os::network::UdpServer &&server) noexcept
{
	udp::Server *udpServer = udp.push(move(server));
	if (!udpServer)
		return { os::STATUS_FAILED };

	Handler::ServerHandle handle;
	handle.data = udpServer;
	handle.callbackGetSessionHandle = serverHandleCallback();
	flame_ide::unused(handle);

	// TODO
	return { os::STATUS_FAILED };
}

Handler::ExpectedSessionHandle Handler::Udp::push(os::network::UdpClient &&client) noexcept
{
	udp::Client *udpClient = udp.push(move(client));
	flame_ide::unused(udpClient);

	Handler::SessionHandle handle;
	flame_ide::unused(handle);

	return { os::STATUS_FAILED };
}

Handler::ExpectedUdpServer Handler::Udp::pop(Handler::ServerHandle &handle)
{
	flame_ide::unused(handle);

	// TODO
	return { os::STATUS_FAILED };
}

Handler::ExpectedUdpClient Handler::Udp::pop(Handler::SessionHandle &handle)
{
	flame_ide::unused(handle);

	// TODO
	return { os::STATUS_FAILED };
}

Handler::Udp::CallbackGetSessionHandle Handler::Udp::serverHandleCallback() const noexcept
{
	static const auto callback = [](udp::Server *handlerServer)
			-> Handler::ExpectedSessionHandle
	{
		if (!handlerServer)
			return { os::STATUS_FAILED };

		// В очередь приходят сообщения
		auto *message = handlerServer->input().getFilledMessage();
		if (!message)
			return { os::STATUS_FAILED };

		// TODO: надо в самом сообщении это делать
		{
			flame_ide::os::threads::Locker messageLock{ message->spin };
			if (message->state != udp::MessageState::READY)
				return { os::STATUS_FAILED };

			message->state = udp::MessageState::PROCESSING;
		}

		Handler::SessionHandle sessionHandle;
		sessionHandle.object = Handler::SessionHandle::Object{
				udp::ServerCommunicationData{ message, &handlerServer->output() }
		};
		sessionHandle.callbackBytesToRead = Handler::Udp::serverCallbackBytesToRead();
		sessionHandle.callbackReceive = Handler::Udp::serverCallbackReceive();
		sessionHandle.callbackSend = Handler::Udp::serverCallbackSend();
		::flame_ide::unused(sessionHandle);

		return { os::STATUS_FAILED };
	};
	return reinterpret_cast<CallbackGetSessionHandle>(+callback);
};

udp::ServerCommunicationData *
Handler::Udp::serverToCommunicationData(Handler::SessionHandle::Object &object) noexcept
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
	static const auto callback = [](const Handler::SessionHandle::Object *object)
			-> ::flame_ide::Types::ssize_t
	{
		const auto *data = Handler::Udp::serverToConstCommunicationData(*object);
		flame_ide::os::threads::Locker lock{ data->message->spin };
		return data->message->size;
	};
	return reinterpret_cast<CallbackBytesToRead>(+callback);
}

Handler::Udp::CallbackReceive Handler::Udp::serverCallbackReceive() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object *object
			, ::flame_ide::templates::Range<byte_t *> range
	) -> ::flame_ide::Types::ssize_t
	{
		auto *data = Handler::Udp::serverToCommunicationData(*object);
		if (!data)
			return -1;

		const auto *message = data->message;
		if (!message)
			return -1;

		::flame_ide::Types::ssize_t readData = -1;
		{
			flame_ide::os::threads::Locker lock{ message->spin };

			const auto min = ::flame_ide::minimum<::flame_ide::Types::ssize_t>(
					(range.end() - range.begin()), message->size
			);
			::flame_ide::templates::copy(
					message->bytes.begin(), message->bytes.begin() + min, range.begin()
			);

			data->message->state = udp::MessageState::EMPTY;
			data->message->size = 0;

			readData = min;
		}
		return readData;
	};
	return reinterpret_cast<CallbackReceive>(+callback);
}

Handler::Udp::CallbackSend Handler::Udp::serverCallbackSend() noexcept
{
	static const auto callback = [](
			Handler::SessionHandle::Object *object
			, ::flame_ide::templates::Range<const byte_t *> range
	) -> ::flame_ide::Types::ssize_t
	{
		auto *data = Handler::Udp::serverToCommunicationData(*object);
		if (!data)
			return -1;

		auto *message = data->output->getEmptyMessage();
		if (!message)
			return -1;

		{
			flame_ide::os::threads::Locker lock{ message->spin };

			const auto min = ::flame_ide::minimum<::flame_ide::Types::ssize_t>(
					(range.end() - range.begin()), message->bytes.capacity()
			);
			::flame_ide::templates::copy(
					range.begin(), range.begin() + min, message->bytes.begin()
			);

			message->state = udp::MessageState::READY;
			message->size = min;
		}
		return message->size;
	};
	return reinterpret_cast<CallbackSend>(+callback);
}

}}} // namespace flame_ide::handler::network
