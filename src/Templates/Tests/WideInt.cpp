#include "WideInt.hpp"

#include <FlameIDE/Templates/AlignObject.hpp>

namespace flame_ide
{namespace test
{

using flame_ide::templates::uint40_t;
using flame_ide::Types;

WideInt::WideInt() : AbstractTest("WideInt")
{}

int WideInt::vStart()
{

	// initialization
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				uichar_t(0x04)
				, uichar_t(0x05)
				, uichar_t(0x06)
				, uichar_t(0x07)
				, uichar_t(0x08)
		} };
		CHECK_RESULT_SUCCESS(doTestCase(
				"initialization"
				, [&]()
				{
					IN_CASE_CHECK_END(data == dataValid);
				}
		));
	}

	// assign
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		int40 = Types::long_t(0x0807060504030201);
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				Types::uichar_t(0x05)
				, Types::uichar_t(0x04)
				, Types::uichar_t(0x03)
				, Types::uichar_t(0x02)
				, Types::uichar_t(0x01)
		} };
		CHECK_RESULT_SUCCESS(doTestCase(
				"assign"
				, [&]()
				{
					IN_CASE_CHECK_END(data == dataValid);
				}
		));
	}

	// convertion
	{
		uint40_t int40 = Types::long_t(0x0807060504030201);
		long_t longValue = int40;
		CHECK_RESULT_SUCCESS(doTestCase(
				"convertion to long_t"
				, [&]()
				{
					IN_CASE_CHECK_END(longValue == Types::long_t(0x0000000504030201));
				}
		));

		int40 = Types::short_t(0x1020);
		Types::short_t shortValue = int40;
		CHECK_RESULT_SUCCESS(doTestCase(
				"convertion to short_t"
				, [&]()
				{
					IN_CASE_CHECK_END(shortValue == 0x1020);
				}
		));
	}

	// reset
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		int40.reset();
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
		} };
		CHECK_RESULT_SUCCESS(doTestCase(
				"reset"
				, [&]()
				{
					IN_CASE_CHECK_END(data == dataValid);
				}
		));
	}

	// binary operations
	{
		// bitwize negation
		{
			uint40_t int40(Types::long_t(0x0000000102030405));
			int40 = ~int40;
			uint40_t::Data data = int40.getData();
			uint40_t::Data dataValid {{
					Types::uichar_t(~0x01)
					, Types::uichar_t(~0x02)
					, Types::uichar_t(~0x03)
					, Types::uichar_t(~0x04)
					, Types::uichar_t(~0x05)
			}};
			CHECK_RESULT_SUCCESS(doTestCase(
					"bitwize negation"
					, [&]()
					{
						IN_CASE_CHECK_END(data == dataValid);
					}
			));
		}

		// shift left

		// shift right
	}

	return 0;
}

}}
