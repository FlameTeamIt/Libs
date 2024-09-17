#include <FlameIDE/../../src/Common/Tests/FunctionalTraitTest.hpp>

#include <FlameIDE/Common/Traits/Functional.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

FunctionalTraitTest::FunctionalTraitTest() noexcept : ::AbstractTest{ "FunctionalTrait" }
{}

FunctionalTraitTest::~FunctionalTraitTest() noexcept = default;

int FunctionalTraitTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"TypeMapper"
			, [this] { return typeMapper(); }
	));
	return ResultType::SUCCESS;
}

int FunctionalTraitTest::typeMapper()
{
	using T1 = long long;
	using T2 = unsigned long long;
	using T3 = double;
	using TestTypeMatchingTrait = TypeMappingTrait<T1, T2>;

	using T2Result = TypeMapper<T1, TestTypeMatchingTrait>::Type;
	using T1Result = TypeMapper<T2, TestTypeMatchingTrait>::Type;
	// using T3Result = TypeMapper<T3, TestTypeMatchingTrait>::Type; // static assert
	using T3Result = TypeMapper<T3, TestTypeMatchingTrait, false>::Type;

	const bool t1ComparationResult = ComparingTypes<T1, T1Result>::VALUE;
	const bool t2ComparationResult = ComparingTypes<T2, T2Result>::VALUE;
	const bool t3ComparationResult = ComparingTypes<Empty, T3Result>::VALUE;

	IN_CASE_CHECK(t1ComparationResult == true);
	IN_CASE_CHECK(t2ComparationResult == true);
	IN_CASE_CHECK(t3ComparationResult == true);

	return ResultType::SUCCESS;
}

}}} // namespace flame_ide::common::tests
