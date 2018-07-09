#include "WideInt.hpp"

#include <Templates/AlignObject.hpp>

namespace flame_ide
{namespace test
{


WideInt::WideInt() : AbstractTest("WideInt")
{
}

int WideInt::vStart()
{
	using flame_ide::templates::UInt40;
	using flame_ide::templates::Types;

	UInt40 int40(Types::llong_t(0x0102030405060708));

	return 0;
}

}}
