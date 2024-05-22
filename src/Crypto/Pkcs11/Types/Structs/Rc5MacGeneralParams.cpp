#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5MacGeneralParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Rc5MacGeneralParams::Rc5MacGeneralParams() noexcept
{}

Rc5MacGeneralParams::Rc5MacGeneralParams(const Rc5MacGeneralParams &params) noexcept
{
	operator=(params);
}

Rc5MacGeneralParams::Rc5MacGeneralParams(const Parent &params) noexcept
{
	operator=(params);
}

Rc5MacGeneralParams::Rc5MacGeneralParams(
		const decltype(Parent::ulWordsize) &wordSize
		, const decltype(Parent::ulRounds) &rounds
		, const decltype(Parent::ulMacLength) &macLength
) noexcept
{
	ulWordsize = wordSize;
	ulRounds = rounds;
	ulMacLength = macLength;
}

Rc5MacGeneralParams &Rc5MacGeneralParams::operator=(const Rc5MacGeneralParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Rc5MacGeneralParams &Rc5MacGeneralParams::operator=(const Parent &params) noexcept
{
	ulWordsize = params.ulWordsize;
	ulRounds = params.ulRounds;
	ulMacLength = params.ulMacLength;

	return *this;
}

}}} // flame_ide::pkcs11::structs
