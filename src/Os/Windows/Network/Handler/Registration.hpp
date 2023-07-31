#ifndef WINDOWS_REGISTRATION_HPP
#define WINDOWS_REGISTRATION_HPP

#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpTypes.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace windows
{

using DescriptorIterator = templates::defaults::CircularForwardIterator<
	::flame_ide::os::SocketDescriptor *
>;

using AcceptedConnectionInterator = templates::defaults::CircularForwardIterator<
	tcp::AcceptedConnection *
>;

}}}} // flame_ide::os::network::windows

namespace flame_ide
{namespace os
{namespace network
{namespace windows
{

class Registration: public threads::ThreadCrtp<Registration>
{
public:
	Registration() noexcept;
	~Registration() noexcept;

public:
	void registerUdpQueue(DescriptorIterator iterator);
	os::SocketDescriptor popUdp() noexcept;
	void pushUdp(os::SocketDescriptor descriptor) noexcept;

	void registerTcpQueue(DescriptorIterator iterator);
	os::SocketDescriptor popTcp() noexcept;
	void pushTcp(os::SocketDescriptor descriptor) noexcept;

	void registerAcceptedConnections(AcceptedConnectionInterator iterator);
	tcp::AcceptedConnection popAcceptedConnections() noexcept;
	void pushAcceptedConnections(tcp::AcceptedConnection connection) noexcept;

private:
	template<typename Iterator>
	struct Queue
	{
		Iterator first;
		Iterator last;
		threads::Spin spin;
	};

private:
	friend class threads::ThreadCrtp<Registration>;

private:
	void body() noexcept;

private:
	bool isRun() const noexcept;
	void start() noexcept;
	void stop() noexcept;

private:
	Queue<DescriptorIterator> udpQueue;
	Queue<DescriptorIterator> tcpQueue;
	Queue<AcceptedConnectionInterator> acceptedQueue;

	threads::Spin runSpin;
	bool run = false;
};

}}}} // flame_ide::os::network::windows

#endif // WINDOWS_REGISTRATION_HPP
