#include <FlameIDE/../../src/Templates/Tests/BinaryTreesTest.hpp>

#include <FlameIDE/Templates/BinaryTrees.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

BinaryTreesTest::BinaryTreesTest() : AbstractTest("BinaryTrees")
{}

BinaryTreesTest::~BinaryTreesTest() = default;

int BinaryTreesTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init - default"
		, [this]() { return defaultInitialization(); }
	));
	return ResultType::SUCCESS;
}

int BinaryTreesTest::defaultInitialization()
{
	return ResultType::SUCCESS;
}

}}} // namespace flame_ide::templates::test
