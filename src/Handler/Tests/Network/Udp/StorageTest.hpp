#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_STORAGETEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_STORAGETEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class StorageTest: public ::AbstractTest
{
public:
	StorageTest();
	virtual ~StorageTest();

private:
	virtual int vStart();

private:
	int init();

	int serverPushPop();
	int clientPushPop();

	int maxServersPushPop();
	int maxClientsPushPop();

	int processServer();
	int processClient();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_STORAGETEST_HPP
