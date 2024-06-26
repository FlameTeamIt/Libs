#ifndef FLAMEIDE_SRC_OS_TESTS_NETWORK_IPV4TEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_NETWORK_IPV4TEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

class Ipv4Test: public ::AbstractTest
{
public:
	Ipv4Test();
	virtual ~Ipv4Test();

private:
	virtual int vStart();
};

}}}} // namespace flame_ide::os::network::tests

#endif // FLAMEIDE_SRC_OS_TESTS_NETWORK_IPV4TEST_HPP
