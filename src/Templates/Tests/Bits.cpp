#include "Bits.hpp"

#include <bitset>

namespace flame_ide
{namespace test
{

Bits::Bits() : AbstractTest("Bits")
{}

Bits::~Bits()
{}

int Bits::vStart()
{
	IN_TEST_CHECK_END(minimalType());
}

bool Bits::minimalType()
{
	using Type3 = templates::bits::MinimalType<3>;
	using Type9 = templates::bits::MinimalType<9>;
	using Type18 = templates::bits::MinimalType<18>;
	using Type33 = templates::bits::MinimalType<33>;
	using Type65 = templates::bits::MinimalType<65>;

	using Types = flame_ide::Types;

	CHECK_RESULT_SUCCESS(doTestCase(
		std::string("Bits::minimalType(") + std::to_string(Type3::COUNT_BITS) + " bits)"
		, [&]()
		{
			bool result = flame_ide::isSameTypes<Type3::Type, Types::uichar_t>();
			IN_CASE_CHECK_END(result);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		std::string("Bits::minimalType(") + std::to_string(Type9::COUNT_BITS) + " bits)"
		, [&]()
		{
			bool result = flame_ide::isSameTypes<Type9::Type, Types::ushort_t>();
			IN_CASE_CHECK_END(result);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		std::string("Bits::minimalType(") + std::to_string(Type18::COUNT_BITS) + " bits)"
		, [&]()
		{
			bool result = flame_ide::isSameTypes<Type18::Type, Types::uint_t>();
			IN_CASE_CHECK_END(result);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		std::string("Bits::minimalType(") + std::to_string(Type33::COUNT_BITS) + " bits)"
		, [&]()
		{
			bool result = flame_ide::isSameTypes<Type33::Type, Types::ulong_t>();
			IN_CASE_CHECK_END(result);
		}
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
		std::string("Bits::minimalType(") + std::to_string(Type65::COUNT_BITS) + " bits)"
		, [&]()
		{
			bool result = flame_ide::isSameTypes<Type65::Type, void>();
			IN_CASE_CHECK_END(result);
		}
	));
}

}}
