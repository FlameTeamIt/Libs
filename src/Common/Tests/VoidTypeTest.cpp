#include <FlameIDE/../../src/Common/Tests/VoidTypeTest.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

struct ExistMember
{
	int member = 0;
};

struct NotExistMember
{};

template<class T, class = VoidType<>>
struct HasMemember: public FalseType
{};

template<class T>
struct HasMemember<T, VoidType<decltype(&T::member)>>: public TrueType
{};

VoidTypeTest::VoidTypeTest() : AbstractTest("VoidType")
{}

VoidTypeTest::~VoidTypeTest() = default;

int VoidTypeTest::vStart()
{
	IN_CASE_CHECK(HasMemember<ExistMember>::VALUE == TrueType::VALUE);
	IN_CASE_CHECK_END(HasMemember<NotExistMember>::VALUE == FalseType::VALUE);
}

}}} // flame_ide::common::tests
