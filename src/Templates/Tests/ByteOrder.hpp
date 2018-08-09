#ifndef TEST_BYTEORDER_HPP
#define TEST_BYTEORDER_HPP

#include <tests/Test.hpp>

#include <Templates/ByteOrder.hpp>

namespace flame_ide
{namespace test
{

class ByteOrderTest: public AbstractTest
{
public:
	ByteOrderTest() : AbstractTest("ByteOrder")
	{}
	~ByteOrderTest() = default;

private:
	virtual int vStart();
};

}}

#endif // TEST_BYTEORDER_HPP
