#include <FlameIDE/../../src/Os/Tests/LibraryTest.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

LibraryTest::LibraryTest() : ::AbstractTest("Library")
{}

LibraryTest::~LibraryTest() = default;

int LibraryTest::vStart()
{
	return SUCCESS;
}

}}} // namespace flame_ide::os::tests
