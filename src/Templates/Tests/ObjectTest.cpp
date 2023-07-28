#include <FlameIDE/../../src/Templates/Tests/ObjectTest.hpp>

#include <FlameIDE/Templates/Object.hpp>

#include <FlameIDE/Common/Traits/Numbers.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

constexpr Types::size_t TEST_CLASS_SIZE = sizeof(::TestClass);

ObjectTest::ObjectTest() : ::AbstractTest("Object")
{}

ObjectTest::~ObjectTest() = default;

int ObjectTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"initializing"
			, [this]()
			{
				return init();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"moving"
			, [this]()
			{
				return moving();
			}
	));
	return ::AbstractTest::ResultType::SUCCESS;
}

int ObjectTest::init()
{
	const TestClass expectedValue = { 1000, 100, 10, 1 };

	Object<TEST_CLASS_SIZE> object;
	IN_CASE_CHECK(!object.operator bool());

	object = TestClass{ 1000, 100, 10, 1 };
	IN_CASE_CHECK(object.operator bool());
	IN_CASE_CHECK(expectedValue == object.get<TestClass>());

	return ::AbstractTest::ResultType::SUCCESS;
}

int ObjectTest::moving()
{
	const TestClass expectedValue = { 1000, 100, 10, 1 };

	Object<TEST_CLASS_SIZE> object;
	object = TestClass{ 1000, 100, 10, 1 };

	{
		Object<TEST_CLASS_SIZE> movedObject = flame_ide::move(object);
		IN_CASE_CHECK(!object.operator bool());
		IN_CASE_CHECK(movedObject.operator bool());
		IN_CASE_CHECK(expectedValue == movedObject.get<TestClass>());
	}

	return ::AbstractTest::ResultType::SUCCESS;
}

}}} // flame_ide::templates::test

