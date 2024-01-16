#include <FlameIDE/../../src/Templates/Tests/BinaryTreesTest.hpp>

#include <FlameIDE/Templates/BinaryTrees.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

using Set = templates::Set<int>;
using Map = templates::Map<int, int>;

BinaryTreesTest::BinaryTreesTest() : AbstractTest("BinaryTrees")
{}

BinaryTreesTest::~BinaryTreesTest() = default;

int BinaryTreesTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init - default"
		, [this]() { return defaultInitialization(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"init - copy array"
		, [this]() { return pushCopyInitialization(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"init - emplace array"
		, [this]() { return pushEmplaceInitialization(); }
	));
	return ResultType::SUCCESS;
}

int BinaryTreesTest::defaultInitialization()
{
	[[maybe_unused]] Set set;
	[[maybe_unused]] Map map;
	return ResultType::SUCCESS;
}

int BinaryTreesTest::pushCopyInitialization()
{
	const Set::Type setValues[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	const Map::Type mapValues[] = {
			{ 1, 10 }, { 2, 20 }, { 3, 30 }, { 4, 40 }
			, { 5, 50 }, { 6, 60 }, { 7, 70 }, { 8, 80 }
	};

	[[maybe_unused]] Set set{ setValues };
	[[maybe_unused]] Map map{ mapValues };

	return ResultType::SUCCESS;
}

int BinaryTreesTest::pushEmplaceInitialization()
{
	[[maybe_unused]] Set set{ { 1, 2, 3, 4, 5, 6, 7, 8 } };
	[[maybe_unused]] Map map{ {
			Map::Type{ 1, 10 }, Map::Type{ 2, 20 }
			, Map::Type{ 3, 30 }, Map::Type{ 4, 40 }
			, Map::Type{ 5, 50 }, Map::Type{ 6, 60 }
			, Map::Type{ 7, 70 }, Map::Type{ 8, 80 }
	} };

	return ResultType::SUCCESS;
}

}}} // namespace flame_ide::templates::test
