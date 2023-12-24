#ifndef FLAMEIDE_OS_NETWORK_HANDLER_HPP
#define FLAMEIDE_OS_NETWORK_HANDLER_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits.hpp>

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/Object.hpp>

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
{namespace handler
{namespace network
{

///
/// @brief The Handler class
///
class Handler
{
public:
	class Internal;

public:
	class ServerHandle;
	class CommunicationHandle;

public:
	Handler() noexcept;
	Handler(const Handler &) noexcept = delete;
	Handler(Handler &&handler) noexcept;

	~Handler() noexcept;

	Handler &operator=(const Handler &) noexcept = delete;
	Handler &operator=(Handler &&handler) noexcept;

	ServerHandle push(os::network::UdpServer &&server) noexcept;
	CommunicationHandle push(os::network::UdpClient &&client) noexcept;

	ServerHandle push(os::network::TcpServer &&server) noexcept;
	CommunicationHandle push(os::network::TcpClient &&client) noexcept;

	os::Status pop(const ServerHandle &, os::network::UdpServer &server) noexcept;
	os::Status pop(const CommunicationHandle &, os::network::UdpClient &client) noexcept;

	os::Status pop(const ServerHandle &, os::network::TcpServer &server) noexcept;
	os::Status pop(const CommunicationHandle &, os::network::TcpClient &client) noexcept;

	os::Status start() noexcept;
	os::Status stop() noexcept;

private:
	Internal *internal = nullptr;
};

}}} // namespace flame_ide::handler::network

// Handler::ServerHandle
namespace flame_ide
{namespace handler
{namespace network
{

class Handler::ServerHandle
{
public:
	ServerHandle() noexcept = default;
	ServerHandle(ServerHandle &&) noexcept = default;
	~ServerHandle() noexcept = default;

	ServerHandle &operator=(const ServerHandle &) noexcept = default;
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

}}} // namespace flame_ide::handler::network

// Handler::CommunicationHandle
namespace flame_ide
{namespace handler
{namespace network
{

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
	static constexpr Types::size_t OBJECT_SIZE = 64;

	using Object = templates::Object<OBJECT_SIZE>;
	using CallbackBytesToRead = Types::ssize_t (*)(const Object *);
	using CallbackReceive = Types::ssize_t (*)(
			Object *, flame_ide::templates::Range<byte_t *>
	);
	using CallbackSend = Types::ssize_t (*)(
			Object *, flame_ide::templates::Range<const byte_t *>
	);

private:
	Object object;
	CallbackBytesToRead callbackBytesToRead = nullptr;
	CallbackReceive callbackReceive = nullptr;
	CallbackSend callbackSend = nullptr;
};

}}} // namespace flame_ide::handler::network

#endif // FLAMEIDE_OS_NETWORK_HANDLER_HPP
