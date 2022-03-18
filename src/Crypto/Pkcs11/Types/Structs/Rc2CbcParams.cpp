#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc2CbcParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Rc2CbcParams::Rc2CbcParams() noexcept
{}

Rc2CbcParams::Rc2CbcParams(const Rc2CbcParams &params) noexcept
{
	operator=(params);
}

Rc2CbcParams::Rc2CbcParams(const Parent &params) noexcept
{
	operator=(params);
}

Rc2CbcParams::Rc2CbcParams(
		const decltype(Parent::ulEffectiveBits) &effectiveBits
		, const decltype(Parent::iv) &iv
) noexcept
{
	ulEffectiveBits = effectiveBits;
	copy(this->iv, iv);
}

Rc2CbcParams &Rc2CbcParams::operator=(const Rc2CbcParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Rc2CbcParams &Rc2CbcParams::operator=(const Parent &params) noexcept
{
	ulEffectiveBits = params.ulEffectiveBits;
	copy(iv, params.iv);

	return *this;
}

}}} // flame_ide::pkcs11::structs
