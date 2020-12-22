#include "AsIntegralTypeTest.hpp"

#include <FlameIDE/Templates/AsIntegralType.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

AsIntegralTypeTest::AsIntegralTypeTest() : AbstractTest("AsIntegralType")
{}

AsIntegralTypeTest::~AsIntegralTypeTest() = default;

int AsIntegralTypeTest::vStart()
{
	using AsInt = AsIntegralType<flame_ide::int_t>;
	AsInt value = 10;

	flame_ide::int_t intValue = value;
	IN_TEST_CHECK(value == intValue);

	AsInt value1 = value;
	IN_TEST_CHECK(value1 == value);
	IN_TEST_CHECK(value1 == intValue);

	AsInt value2 = 12;
	IN_TEST_CHECK(value2 > value);
	IN_TEST_CHECK(value2 > value1);
	IN_TEST_CHECK(value2 > intValue);
	IN_TEST_CHECK(value2 >= value);
	IN_TEST_CHECK(value2 >= value1);
	IN_TEST_CHECK(value2 >= intValue);

	AsInt value3 = 9;
	IN_TEST_CHECK(value3 < value);
	IN_TEST_CHECK(value3 < value1);
	IN_TEST_CHECK(value3 < value2);
	IN_TEST_CHECK(value3 < intValue);
	IN_TEST_CHECK(value3 <= value);
	IN_TEST_CHECK(value3 <= value1);
	IN_TEST_CHECK(value3 <= value2);
	IN_TEST_CHECK(value3 <= intValue);

	value3 <<= 2;
	IN_TEST_CHECK(value3 == 36);
	IN_TEST_CHECK(value3 > value);
	IN_TEST_CHECK(value3 > value1);
	IN_TEST_CHECK(value3 > value2);
	IN_TEST_CHECK(value3 > intValue);
	IN_TEST_CHECK(value3 >= value);
	IN_TEST_CHECK(value3 >= value1);
	IN_TEST_CHECK(value3 >= value2);
	IN_TEST_CHECK(value3 >= intValue);

	value = value1 / 2;
	IN_TEST_CHECK(value == 5);
	IN_TEST_CHECK(value1 == 10);

	value *= 2;
	IN_TEST_CHECK(value == 10);
	IN_TEST_CHECK(value == value1);

	return 0;
}

}}}
