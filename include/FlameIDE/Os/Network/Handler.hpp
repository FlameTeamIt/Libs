#ifndef FLAMEIDE_OS_NETWORK_HANDLER_HPP
#define FLAMEIDE_OS_NETWORK_HANDLER_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits.hpp>

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/AlignObject.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class NetworkBase;

class UdpServer;
class UdpClient;

class TcpServer;
class TcpClient;

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

class Handler
{
public:
	class Internal;

public:
	struct Info;
	class ServerHandle;
	class CommunicationHandle;

public:
	Handler() noexcept;
	Handler(const Handler &) noexcept = delete;
	Handler(Handler &&handler) noexcept;

	~Handler() noexcept;

	Handler &operator=(const Handler &) noexcept = delete;
	Handler &operator=(Handler &&handler) noexcept;

	ServerHandle push(UdpServer &&server) noexcept;
	CommunicationHandle push(UdpClient &&client) noexcept;

	ServerHandle push(TcpServer &&server) noexcept;
	CommunicationHandle push(TcpClient &&client) noexcept;

	Status pop(const ServerHandle &, UdpServer &server) noexcept;
	Status pop(const CommunicationHandle &, UdpClient &client) noexcept;

	Status pop(const ServerHandle &, TcpServer &server) noexcept;
	Status pop(const CommunicationHandle &, TcpClient &client) noexcept;

	const Info &getInfo() const noexcept;

	Status start() noexcept;
	Status stop() noexcept;

private:
	Internal *internal = nullptr;
};

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

struct Handler::Info
{
	struct Udp
	{
		const Types::size_t maxMessageSize;

		const Types::size_t maxServers;
		const Types::size_t serverInputQueueSize;
		const Types::size_t serverOutputQueueSize;

		const Types::size_t maxClients;
		const Types::size_t clientInputQueueSize;
		const Types::size_t clientOutputQueueSize;

		Types::size_t currentServers;
		Types::size_t currentCients;
	};
	struct Tcp
	{
		const Types::size_t maxServers;
		const Types::size_t maxServerConnections;
		const Types::size_t connectionInputBufferSize;
		const Types::size_t connectionOutputBufferSize;

		const Types::size_t maxClients;
		const Types::size_t clientInputBufferSize;
		const Types::size_t clientOutputBufferSize;

		Types::size_t currentServers;
		Types::size_t currentCients;
	};

	Udp udp;
	Tcp tcp;
};

class Handler::ServerHandle
{
public:
	ServerHandle() noexcept = default;
	ServerHandle(ServerHandle &&) noexcept = default;
	~ServerHandle() noexcept = default;

	ServerHandle &operator=(ServerHandle &&) noexcept = default;

	operator bool() const noexcept;

	Handler::CommunicationHandle getCommunicationHandle() noexcept;

private:
	friend class Handler::Internal;

private:
	using CallbackGetCommunicationHandle = Handler::CommunicationHandle (*)(void *);

private:
	void *data = nullptr;
	CallbackGetCommunicationHandle callbackGetCommunicationHandle = nullptr;
};

class Handler::CommunicationHandle
{
public:
	CommunicationHandle() noexcept = default;
	CommunicationHandle(CommunicationHandle &&) noexcept = default;
	~CommunicationHandle() noexcept = default;

	CommunicationHandle &operator=(CommunicationHandle &&) noexcept = default;

	operator bool() const noexcept;

	Types::ssize_t bytesToRead() const noexcept;

	Types::ssize_t receive(flame_ide::templates::Range<byte_t *>) noexcept;
	Types::ssize_t send(flame_ide::templates::Range<const byte_t *>) noexcept;

private:
	friend class Handler::Internal;
	friend class Handler::ServerHandle;

private:
	using CallbackBytesToRead = Types::ssize_t (*)(void *data);
	using CallbackReceive = Types::ssize_t (*)(
			void *data, flame_ide::templates::Range<byte_t *>
	);
	using CallbackSend = Types::ssize_t (*)(
			void *data, flame_ide::templates::Range<const byte_t *>
	);

private:
	void *data[2] = { nullptr, nullptr };
	CallbackBytesToRead callbackBytesToRead = nullptr;
	CallbackReceive callbackReceive = nullptr;
	CallbackSend callbackSend = nullptr;
};

}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_HANDLER_HPP
