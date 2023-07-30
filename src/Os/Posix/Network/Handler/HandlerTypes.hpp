#ifndef POSIX_HANDLERTYPES_HPP
#define POSIX_HANDLERTYPES_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>

#	if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <signal.h>

namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

using SignalAction = struct ::sigaction;
using SignalActionHandler = decltype(SignalAction{}.sa_sigaction);

using DescriptorIterator = flame_ide::templates::defaults::CircularForwardIterator<
	::flame_ide::os::SocketDescriptor *
>;

#		if !defined(FLAME_SIGNAL_NUMBER)
#			define FLAME_SIGNAL_POLLING SIGPOLL
#		endif // !defined(FLAME_SIGNAL_NUMBER)

}}}} // flame_ide::os::network::posix

namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

class Registration
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

private:
	struct Queue
	{
		DescriptorIterator first;
		DescriptorIterator last;
		threads::Spin spin;
	};

	static bool setGlobal(Registration &registration) noexcept;
	static bool resetGlobal(Registration &registration) noexcept;

	static void registerQueue(Queue &queue, DescriptorIterator iterator);
	static os::SocketDescriptor pop(Queue &queue) noexcept;
	static void push(Queue &queue, os::SocketDescriptor descriptor) noexcept;

private:
	SignalAction action;
	SignalAction oldAction = SignalAction{};

	Queue udpQueue;
	Queue tcpQueue;
};

}}}} // flame_ide::os::network::posix

namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

class Worker: private threads::ThreadCrtp<Worker>
{
	friend class threads::ThreadCrtp<Worker>;

public:
	Worker() noexcept;
	~Worker() noexcept;

	void start();
	void stop();

private:
	void body() noexcept;

private:
	void processUdp() noexcept;
	void processTcp() noexcept;

	bool needStop() noexcept;

private:
	mutable threads::Spin spinStopWorker;
	bool stopWorker = true;
};

}}}} // flame_ide::os::network::posix

#		define FLAMEIDE_HANDLERTYPES_NAMESPACE ::flame_ide::os::network::posix

#	endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // POSIX_HANDLERTYPES_HPP
