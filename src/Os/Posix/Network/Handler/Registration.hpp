#ifndef POSIX_REGISTRATION_HPP
#define POSIX_REGISTRATION_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpTypes.hpp>

#include <signal.h>

namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

using DescriptorIterator = templates::defaults::CircularForwardIterator<
	::flame_ide::os::SocketDescriptor *
>;

using AcceptedConnectionInterator = templates::defaults::CircularForwardIterator<
	tcp::AcceptedConnection *
>;

using SignalAction = struct ::sigaction;
using SignalActionHandler = decltype(SignalAction{}.sa_sigaction);

#if !defined(FLAME_SIGNAL_POLLING)
#	define FLAME_SIGNAL_POLLING SIGPOLL
#endif // !defined(FLAME_SIGNAL_POLLING)

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
	static bool setGlobal(Registration &registration) noexcept;
	static bool resetGlobal(Registration &registration) noexcept;

	static os::Status registrate(os::SocketDescriptor descriptor) noexcept;
	static os::Status registrate(tcp::AcceptedConnection connection) noexcept;

	static void deregistrate(os::SocketDescriptor descriptor) noexcept;
	static void deregistrate(tcp::AcceptedConnection connection) noexcept;

	template<typename Iterator>
	static void registerQueue(Queue<Iterator> &queue, Iterator iterator)
	{
		threads::Locker locker{ queue.spin };

		if (queue.first)
			return;

		queue.first = queue.last = iterator;
	}

	template<
		typename Iterator
		, typename T = typename templates::iterator_utils::GetType<Iterator>::Type
	>
	static T pop(Queue<Iterator> &queue) noexcept
	{
		struct Descriptor
		{
			os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
			operator os::SocketDescriptor() const noexcept
			{
				return descriptor;
			}
		};
		using Type = typename ChooseType<
			ComparingTypes<os::SocketDescriptor, T>::VALUE
			, Descriptor
			, tcp::AcceptedConnection
		>::Type;

		T value = Type{};
		{
			const threads::Locker locker{ queue.spin };
			if (queue.first == queue.last)
				return value;

			value = *queue.first;
		}

		Registration::deregistrate(value);
		{
			const threads::Locker locker{ queue.spin };
			*queue.first = os::SOCKET_INVALID.descriptor;
			++queue.first;
		}
		return value;
	}

	template<
		typename Iterator
		, typename T = typename templates::iterator_utils::GetType<Iterator>::Type
	>
	static void push(Queue<Iterator> &queue, T descriptor) noexcept
	{
		struct Descriptor
		{
			os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
			constexpr operator os::SocketDescriptor() const noexcept
			{
				return descriptor;
			}
		};
		using Type = typename ChooseType<
			ComparingTypes<os::SocketDescriptor, T>::VALUE
			, Descriptor
			, tcp::AcceptedConnection
		>::Type;

		if (descriptor == Type{})
			return;

		auto result = registrate(descriptor);
		if (result < 0)
			return;

		{
			const threads::Locker locker{ queue.spin };
			*queue.last = descriptor;
			++queue.last;
		}
	}

private:
	SignalAction action;
	SignalAction oldAction = SignalAction{};

	Queue<DescriptorIterator> udpQueue;
	Queue<DescriptorIterator> tcpQueue;
	Queue<AcceptedConnectionInterator> acceptedQueue;
};

class GlobalRegistration: public NonCreational
{
	friend class Worker;
	static Registration *get() noexcept;
};

}}}} // flame_ide::os::network::posix

#endif // POSIX_REGISTRATION_HPP
