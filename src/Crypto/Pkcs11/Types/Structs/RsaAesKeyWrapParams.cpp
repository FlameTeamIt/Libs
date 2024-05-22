#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaAesKeyWrapParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

RsaAesKeyWrapParams::RsaAesKeyWrapParams() noexcept
{}

RsaAesKeyWrapParams::RsaAesKeyWrapParams(const RsaAesKeyWrapParams &params) noexcept
{
	operator=(params);
}

RsaAesKeyWrapParams::RsaAesKeyWrapParams(const Parent &params) noexcept
{
	operator=(params);
}

RsaAesKeyWrapParams::RsaAesKeyWrapParams(
		const decltype(Parent::ulAESKeyBits) &aesKeyBits
		, const decltype(Parent::pOAEPParams) &oaepParams
) noexcept
{
	ulAESKeyBits = aesKeyBits;
	pOAEPParams = oaepParams;
}

RsaAesKeyWrapParams &RsaAesKeyWrapParams::operator=(const RsaAesKeyWrapParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

RsaAesKeyWrapParams &RsaAesKeyWrapParams::operator=(const Parent &params) noexcept
{
	ulAESKeyBits = params.ulAESKeyBits;
	pOAEPParams = params.pOAEPParams;

	return *this;
}

}}} // flame_ide::pkcs11::structs
