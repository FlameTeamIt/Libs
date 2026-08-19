#ifndef HANDLER_INTERNAL_WORKERS_HPP
#define HANDLER_INTERNAL_WORKERS_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Workers.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Workers
{
public:
	Workers(Handler::Udp &udp) noexcept;
	~Workers() noexcept;

	///
	/// @brief start
	/// @return
	///
	// TODO
	void start() noexcept;

	///
	/// @brief stop
	/// @return
	///
	// TODO
	void stop() noexcept;

	///
	/// \brief udp
	/// \return
	///
	udp::Workers &udp() noexcept;

private:
	udp::Workers udpWorkers;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLER_INTERNAL_WORKERS_HPP
