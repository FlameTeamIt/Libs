#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc2MacGeneralParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Rc2MacGeneralParams::Rc2MacGeneralParams() noexcept
{}

Rc2MacGeneralParams::Rc2MacGeneralParams(const Rc2MacGeneralParams &params) noexcept
{
	operator=(params);
}

Rc2MacGeneralParams::Rc2MacGeneralParams(const Parent &params) noexcept
{
	operator=(params);
}

Rc2MacGeneralParams::Rc2MacGeneralParams(
		const decltype(Parent::ulEffectiveBits) &effectiveBits
		, const decltype(Parent::ulMacLength) &maxLength
) noexcept
{
	ulEffectiveBits = effectiveBits;
	ulMacLength = maxLength;
}

Rc2MacGeneralParams &Rc2MacGeneralParams::operator=(const Rc2MacGeneralParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Rc2MacGeneralParams &Rc2MacGeneralParams::operator=(const Parent &params) noexcept
{
	ulEffectiveBits = params.ulEffectiveBits;
	ulMacLength = params.ulMacLength;

	return *this;
}


}}} // flame_ide::pkcs11::structs
