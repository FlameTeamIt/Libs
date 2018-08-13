#include "Bits.hpp"
#include <Templates/ArrayBits.hpp>

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

	if (!arrayBits())
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

	if (!templates::isSameTypes<Type3::Type, Types::uichar_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type3::COUNT_BITS << " bits -> Types::uchar_t" << std::endl;
	}

	if (!templates::isSameTypes<Type9::Type, Types::ushort_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type9::COUNT_BITS << " bits -> Types::ushort_t" << std::endl;
	}

	if (!templates::isSameTypes<Type18::Type, Types::uint_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type18::COUNT_BITS << " bits -> Types::uint_t" << std::endl;
	}

	if (!templates::isSameTypes<Type33::Type, Types::ulong_t>())
	{
		return false;
	}
	else
	{
		std::cout << Type33::COUNT_BITS << " bits -> Types::ulong_t" << std::endl;
	}

	if (!templates::isSameTypes<Type65::Type, void>())
	{
		return false;
	}
	else
	{
		std::cout << Type65::COUNT_BITS << " bits -> is too more." << std::endl;
	}

	return true;
}

bool Bits::arrayBits()
{
	constexpr flame_ide::Types::short_t int16 = 32144;
	constexpr std::bitset<16> bitsInt16(int16);

	templates::bits::ArrayBits<16> bits16(int16);

	std::cout << "---> Bits::arrayBits()" << std::endl;

	std::cout << "Bitset: " << bitsInt16 << std::endl;

	std::cout << "ArrayBits: ";
	for (flame_ide::Types::size_t i = 0; i < sizeof(flame_ide::Types::short_t) * 8; ++i)
	{
		std::cout << !!bits16[i];
	}
	std::cout << std::endl;

	std::cout << "Set bit:" << std::endl;
	{
		constexpr flame_ide::Types::size_t INDEX_1 = 4;
		constexpr flame_ide::Types::size_t INDEX_0 = 5;

		std::cout << "Current value[5]: " << !!bits16[INDEX_0] << std::endl;
//		bits16[INDEX_0] = !bits16[INDEX_0];
		std::cout << "Edited  value[5]: " << !!bits16[INDEX_0] << std::endl;

		std::cout << "Current value[4]: " << !!bits16[INDEX_1] << std::endl;
		bits16.set(INDEX_1, !bits16[INDEX_1]);
		std::cout << "Edited  value[4]: " << !!bits16[INDEX_1] << std::endl;
	}
	std::cout << std::endl;

	return true;
}

}}
