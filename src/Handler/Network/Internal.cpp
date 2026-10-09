#include <FlameIDE/../../src/Handler/Network/Internal.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::Internal::Internal() noexcept
		: workers{ udpData }
		, notificators{
				workers.udp().serverNotifier()
				, workers.udp().clientNotifier()
		}
{
	os::async::network::Registrar registration;

	registration.setNotificator(notificators.udpServer);
	registration.setNotificator(notificators.udpClient);

	// TODO
	registration.setNotificator(notificators.tcpServer);
	registration.setNotificator(notificators.tcpAcceptedConnecton);
	registration.setNotificator(notificators.tcpClient);
}

Handler::Internal::~Internal() noexcept
{
	os::async::network::Registrar{}.unsetNotificators();
}

Handler::Udp &Handler::Internal::udp() noexcept
{
	return udpData;
}

Handler::Tcp &Handler::Internal::tcp() noexcept
{
	return tcpData;
}

os::Status Handler::Internal::start() noexcept
{
	return workers.start(), os::STATUS_SUCCESS;
}

os::Status Handler::Internal::stop() noexcept
{
	return workers.stop(), os::STATUS_SUCCESS;
}

}}} // namespace flame_ide::os::network
