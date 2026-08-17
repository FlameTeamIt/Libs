#ifndef HANDLER_INTERNAL_UDP_HPP
#define HANDLER_INTERNAL_UDP_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Common/ReferenceWrapper.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Storage.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Handler::Udp
{
public:
	using CallbackGetSessionHandle = Handler::ServerHandle::CallbackGetSessionHandle;
	using CallbackServerDeregistrate = Handler::ServerHandle::CallbackDeregistrate;
	using CallbackSessionDeregistrate = Handler::SessionHandle::CallbackDeregistrate;

	using CallbackBytesToRead = Handler::SessionHandle::CallbackBytesToRead;
	using CallbackReceive = Handler::SessionHandle::CallbackReceive;
	using CallbackSend = Handler::SessionHandle::CallbackSend;

public:
	struct ServerHandleData
	{
		::flame_ide::ReferenceWrapper<Handler> handler;
		::flame_ide::ReferenceWrapper<udp::Server> server;
	};

	struct SessionHandleData
	{
		Handler *handler;
		udp::ClientCommunicationData data;
	};

public:
	Handler::ExpectedServerHandle push(os::network::UdpServer &&server) noexcept;
	Handler::ExpectedSessionHandle push(os::network::UdpClient &&client) noexcept;

	Handler::ExpectedUdpServer pop(Handler::ServerHandle &handle);
	Handler::ExpectedUdpClient pop(Handler::SessionHandle &handle);

	/// @brief serverHandleCallback
	/// @return
	CallbackGetSessionHandle serverHandleCallback() const noexcept;

	///
	/// @brief serverCallbackDeregistrate
	/// @return
	///
	static CallbackServerDeregistrate serverCallbackDeregistrate() noexcept;

	///
	/// @brief serverCallbackDeregistrate
	/// @return
	///
	static CallbackSessionDeregistrate clientCallbackDeregistrate() noexcept;

private:
	/// @brief serverToCommunicationData
	/// @param object
	/// @return
	static udp::ServerCommunicationData *serverToCommunicationData(
			Handler::SessionHandle::Object &object
	) noexcept;

	/// @brief serverToConstCommunicationData
	/// @param object
	/// @return
	static const udp::ServerCommunicationData *serverToConstCommunicationData(
			const Handler::SessionHandle::Object &object
	) noexcept;

	/// @brief serverCallbackBytesToRead
	/// @return
	///
	static CallbackBytesToRead serverCallbackBytesToRead() noexcept;

	///
	/// @brief serverCallbackReceive
	/// @return
	///
	static CallbackReceive serverCallbackReceive() noexcept;

	///
	/// @brief serverCallbackSend
	/// @return
	///
	static CallbackSend serverCallbackSend() noexcept;

	///
	/// @brief clientToCommunicationData
	/// @param object
	/// @return
	///
	static udp::ClientCommunicationData *clientToCommunicationData(
			Handler::SessionHandle::Object &object
	) noexcept;

	///
	/// @brief clientToConstCommunicationData
	/// @param object
	/// @return
	///
	static const udp::ClientCommunicationData *clientToConstCommunicationData(
			const Handler::SessionHandle::Object &object
	) noexcept;

	///
	/// @brief clientCallbackBytesToRead
	/// @return
	///
	static CallbackBytesToRead clientCallbackBytesToRead() noexcept;

	///
	/// @brief clientCallbackReceive
	/// @return
	///
	static CallbackReceive clientCallbackReceive() noexcept;

	///
	/// @brief clientCallbackSend
	/// @return
	///
	static CallbackSend clientCallbackSend() noexcept;

private:
	udp::Storage storage;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLER_INTERNAL_UDP_HPP
