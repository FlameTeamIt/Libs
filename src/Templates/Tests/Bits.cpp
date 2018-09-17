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
	if (!minimalType())
		return -1;

	return 0;
}

bool Bits::minimalType()
{
	using Type3 = templates::bits::MinimalType<3>;
	using Type9 = templates::bits::MinimalType<9>;
	using Type18 = templates::bits::MinimalType<18>;
	using Type33 = templates::bits::MinimalType<33>;
	using Type65 = templates::bits::MinimalType<65>;

	using Types = flame_ide::Types;

	std::cout << "---> Bits::minimalType()" << std::endl;

	if (!flame_ide::isSameTypes<Type3::Type, Types::uichar_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type3::COUNT_BITS << " bits -> Types::uchar_t" << std::endl;
	}

	if (!flame_ide::isSameTypes<Type9::Type, Types::ushort_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type9::COUNT_BITS << " bits -> Types::ushort_t" << std::endl;
	}

	if (!flame_ide::isSameTypes<Type18::Type, Types::uint_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type18::COUNT_BITS << " bits -> Types::uint_t" << std::endl;
	}

	if (!flame_ide::isSameTypes<Type33::Type, Types::ulong_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type33::COUNT_BITS << " bits -> Types::ulong_t" << std::endl;
	}

	if (!flame_ide::isSameTypes<Type65::Type, void>())
	{
		return false;
	}
	else
	{
		std::cout << Type65::COUNT_BITS << " bits -> is too more." << std::endl;
	}

	return true;
}

}}
