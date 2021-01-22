#include "ExpectedTest.hpp"
#include "TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

ExpectedTest::ExpectedTest() : AbstractTest("Expected")
{}

ExpectedTest::~ExpectedTest()
{}

int ExpectedTest::vStart()
{
	using Expected = templates::Expected<TestClass, int>;

	bool isError = false;
	bool isResult = false;

	auto checkError = [&isError](int)
	{
		isError = true;
	};

	auto checkResult = [&isResult](TestClass&&)
	{
		isResult = true;
	};

	// positive scenario
	{
		Expected expected{ TestClass{ long(1000), int(100), short(10), char('1') } };
		expected.ifResult(checkResult)
				.ifError(checkError)
				.done();
		if (!(isError == false && isResult == true))
		{
			return -1;
		}
	}

	isError = false;
	isResult = false;

	// negative scenario
	{
		Expected expected{ int(-100500) };
		expected.ifResult(checkResult)
				.ifError(checkError)
				.done();
		if (!(isError == true && isResult == false))
		{
			return -1;
		}
	}

	return 0;
}

}}}
