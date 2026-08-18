#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_SERVER_HANDLE_TEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_SERVER_HANDLE_TEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class ServerHandleTest: public ::AbstractTest
{
public:
	ServerHandleTest();
	virtual ~ServerHandleTest();

private:
	virtual int vStart();
};


}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_SERVER_HANDLE_TEST_HPP
