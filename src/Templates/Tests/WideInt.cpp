#include "WideInt.hpp"

#include <Templates/AlignObject.hpp>

namespace flame_ide
{namespace test
{

namespace
{

} // anonymous

WideInt::WideInt() : AbstractTest("WideInt")
{
}

int WideInt::vStart()
{
	using flame_ide::templates::uint40_t;
	using flame_ide::templates::Types;

	// initialization
	{
		uint40_t int40(Types::llong_t(0x0102030405060708));
	}

	// assign
	{
		uint40_t int40(Types::llong_t(0x0102030405060708));
		int40 = Types::llong_t(0x0807060504030201);
	}

	// convertion
	{
		uint40_t int40 = Types::llong_t(0x0807060504030201);
		llong_t value = int40;
		if (value != Types::llong_t(0x0000000504030201))
		{
			return -1;
		}
	}

	{
		uint40_t int40(Types::llong_t(0x0102030405060708));
		int40.reset();
	}

	// binary operations
	{
		// shift left

		// shift right
	}

	return 0;
}

}}
