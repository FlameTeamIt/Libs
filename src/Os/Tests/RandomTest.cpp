#include <FlameIDE/../../src/Os/Tests/RandomTest.hpp>

#include <FlameIDE/Os/Random.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

RandomTest::RandomTest() : ::AbstractTest("Random")
{}

RandomTest::~RandomTest() = default;

int RandomTest::vStart()
{
	constexpr size_t BUF_SIZE = 15;

	char buf[BUF_SIZE];
	if (flame_ide::os::RandomRange(buf, BUF_SIZE)  != BUF_SIZE)
	{
		std::cout << "OS-dependent random failed" << std::endl;
		return FAILED;
	}
	else
	{
		std::cout << "First byte of random buf: " << static_cast<int>(buf[0]) << std::endl;
	}

	std::cout << "Random() test (int): " << flame_ide::os::Random() << std::endl;
	std::cout << "Random() test (short): " << flame_ide::os::Random<short>() << std::endl;
	return SUCCESS;
}

}}} // namespace flame_ide::os::tests

