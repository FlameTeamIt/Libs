#ifndef FLAMEIDE_OS_NETWORK_HANDLER_HPP
#define FLAMEIDE_OS_NETWORK_HANDLER_HPP

#include <FlameIDE/Common/Expected.hpp>
#include <FlameIDE/Common/Traits.hpp>

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/Object.hpp>

namespace flame_ide
{namespace os
{namespace network
{

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
	class Tcp;
	class Udp;

public:
	class ServerHandle;
	class SessionHandle;

	using ExpectedServerHandle = Expected<ServerHandle, os::Status>;
	using ExpectedSessionHandle = Expected<SessionHandle, os::Status>;

	using ExpectedUdpServer = Expected<os::network::UdpServer, os::Status>;
	using ExpectedUdpClient = Expected<os::network::UdpClient, os::Status>;

	using ExpectedTcpServer = Expected<os::network::TcpServer, os::Status>;
	using ExpectedTcpClient = Expected<os::network::TcpClient, os::Status>;

public:
	Handler() noexcept;
	Handler(const Handler &) noexcept = delete;
	Handler(Handler &&handler) noexcept;
	~Handler() noexcept;

	Handler &operator=(const Handler &) noexcept = delete;

	Handler &operator=(Handler &&handler) noexcept;

	/// @brief pushUdp
	/// @param server
	/// @return
	ExpectedServerHandle pushUdp(os::network::UdpServer &&server) noexcept;

	/// @brief pushUdp
	/// @param client
	/// @return
	ExpectedSessionHandle pushUdp(os::network::UdpClient &&client) noexcept;

	/// @brief pushTcp
	/// @param server
	/// @return
	ExpectedServerHandle pushTcp(os::network::TcpServer &&server) noexcept;

	/// @brief pushTcp
	/// @param client
	/// @return
	ExpectedSessionHandle pushTcp(os::network::TcpClient &&client) noexcept;

	/// @brief pop
	/// @param server
	/// @return
	ExpectedUdpServer popUdp(ServerHandle &handle) noexcept;

	/// @brief pop
	/// @param client
	/// @return
	ExpectedUdpClient popUdp(SessionHandle &handle) noexcept;

	/// @brief pop
	/// @param server
	/// @return
	ExpectedTcpServer popTcp(ServerHandle &handle) noexcept;

	/// @brief pop
	/// @param client
	/// @return
	ExpectedTcpClient popTcp(SessionHandle &handle) noexcept;

	/// @brief start
	/// @return
	os::Status start() noexcept;

	/// @brief stop
	/// @return
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

	///
	/// @brief getSessionHandle
	/// @return
	///
	Handler::SessionHandle getSessionHandle() noexcept;

private:
	friend class Handler::Internal;
	friend class Handler::Udp;
	friend class Handler::Tcp;

	using CallbackGetSessionHandle = Handler::SessionHandle (*)(void *);

private:
	void *data = nullptr;
	CallbackGetSessionHandle callbackGetSessionHandle = nullptr;
};

}}} // namespace flame_ide::handler::network

// Handler::SessionHandle
namespace flame_ide
{namespace handler
{namespace network
{

class Handler::SessionHandle
{
public:
	SessionHandle() noexcept = default;
	SessionHandle(SessionHandle &&) noexcept = default;
	~SessionHandle() noexcept = default;

	SessionHandle &operator=(SessionHandle &&) noexcept = default;

	operator bool() const noexcept;

	///
	/// @brief bytesToRead
	/// @return
	///
	Types::ssize_t bytesToRead() const noexcept;

	///
	/// @brief receive
	/// @return
	///
	Types::ssize_t receive(flame_ide::templates::Range<byte_t *>) noexcept;

	///
	/// @brief send
	/// @return
	///
	Types::ssize_t send(flame_ide::templates::Range<const byte_t *>) noexcept;

private:
	friend class Handler::Internal;
	friend class Handler::Udp;
	friend class Handler::Tcp;
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
