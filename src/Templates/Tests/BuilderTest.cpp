#include "BuilderTest.hpp"
#include "TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

namespace // anonymous
{

class TestBuildStep1 : public builder_utils::Substep<
	TestBuildStep1, TestClass, int, int(0)
>
{
public:
	using Me = TestBuildStep1;
	using Parent = builder_utils::Substep<
		Me, TestClass, int, int(0)
	>;
	friend Parent;

//	static_assert(
//			IsStaticCastable<Parent, Me>::VALUE
//			, "'DerivedStep' argument cannot staticly casted" " "
//					"to base class 'Substep<>'"
//	);

	TestBuildStep1() = default;

	TestBuildStep1(long l, int i, short s, char c) : Parent(l, i, s, c)
	{}

protected:
	void initImpl(long l, int i, short s, char c)
	{
		args = decltype(args){ l, i, s, c };
	}

	void doImpl()
	{
		getResult() = TestClass(
			args.get<0>(), args.get<1>()
			, args.get<2>(), args.get<3>()
		);
	}

private:
	templates::Tuple<long, int, short, char> args;
};

} // anonymous

BuilderTest::BuilderTest() = default;
BuilderTest::~BuilderTest() = default;

int BuilderTest::vStart()
{
	IN_CASE_CHECK(createBuildStep())

	return ResultType::SUCCESS;
}

int BuilderTest::createBuildStep()
{
	templates::Tuple<long, int, short, char> args{
			long(1000), int(10), short(1), char('1') };

	TestClass referenceValue{
			args.get<0>(), args.get<1>()
			, args.get<2>(), args.get<3>()
	};

	TestBuildStep1 step1(
			args.get<0>(), args.get<1>()
			, args.get<2>(), args.get<3>()
	);
	step1();

	auto &result = step1.getResult();

	IN_CASE_CHECK_END(result == referenceValue)
}

}}}
