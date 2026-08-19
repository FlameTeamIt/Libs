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
	bool isExistMemberStructContainMember = (
			HasMemember<ExistMember>::VALUE == true
	);
	bool isNotExistMemberStructContainMember = (
			HasMemember<NotExistMember>::VALUE == false
	);
	IN_CASE_CHECK(isExistMemberStructContainMember);
	IN_CASE_CHECK_END(isNotExistMemberStructContainMember);
}

}}} // flame_ide::common::tests
