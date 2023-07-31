#ifndef WINDOWS_WORKER_HPP
#define WINDOWS_WORKER_HPP

#include <FlameIDE/Common/ReferenceWrapper.hpp>

#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{
struct Udp;
}}}};

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{
struct Tcp;
}}}};

namespace flame_ide
{namespace os
{namespace network
{namespace windows
{

class Worker: private threads::ThreadCrtp<Worker>
{
	friend class threads::ThreadCrtp<Worker>;

public:
	Worker() noexcept;
	~Worker() noexcept;

	void set(udp::Udp &udp, tcp::Tcp &tcp) noexcept;

	void start() noexcept;
	void stop() noexcept;

private:
	void body() noexcept;

private:
	void processUdp() noexcept;
	void processTcp() noexcept;

	bool needStop() noexcept;

private:
	ReferenceWrapper<udp::Udp> udp;
	ReferenceWrapper<tcp::Tcp> tcp;

	mutable threads::Spin spinStopWorker;
	bool stopWorker = true;

};

}}}} // flame_ide::os::network::windows

#endif // WINDOWS_WORKER_HPP
