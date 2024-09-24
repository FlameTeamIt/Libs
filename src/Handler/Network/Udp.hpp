#ifndef HANDLERINTERNALUDP_HPP
#define HANDLERINTERNALUDP_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Udp.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Handler::Udp
{
public:
	using CallbackGetSessionHandle = Handler::ServerHandle::CallbackGetSessionHandle;

	using CallbackBytesToRead = Handler::SessionHandle::CallbackBytesToRead;
	using CallbackReceive = Handler::SessionHandle::CallbackReceive;
	using CallbackSend = Handler::SessionHandle::CallbackSend;

public:
	// TODO
	Handler::ExpectedServerHandle push(os::network::UdpServer &&server) noexcept;
	// TODO
	Handler::ExpectedSessionHandle push(os::network::UdpClient &&client) noexcept;

	// TODO
	Handler::ExpectedUdpServer pop(Handler::ServerHandle &handle);
	// TODO
	Handler::ExpectedUdpClient pop(Handler::SessionHandle &handle);

	/// @brief serverHandleCallback
	/// @return
	CallbackGetSessionHandle serverHandleCallback() const noexcept;

private:
	///
	/// \brief serverToCommunicationData
	/// \param object
	/// \return
	///
	static udp::ServerCommunicationData *serverToCommunicationData(
			Handler::SessionHandle::Object &object
	) noexcept;

	///
	/// \brief serverToConstCommunicationData
	/// \param object
	/// \return
	///
	static const udp::ServerCommunicationData *serverToConstCommunicationData(
			const Handler::SessionHandle::Object &object
	) noexcept;

	///
	/// \brief serverCallbackBytesToRead
	/// \return
	///
	static CallbackBytesToRead serverCallbackBytesToRead() noexcept;

	///
	/// \brief serverCallbackReceive
	/// \return
	///
	static CallbackReceive serverCallbackReceive() noexcept;

	///
	/// \brief serverCallbackSend
	/// \return
	///
	// TODO
	static CallbackSend serverCallbackSend() noexcept;

private:
	udp::Udp udp;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNALUDP_HPP
