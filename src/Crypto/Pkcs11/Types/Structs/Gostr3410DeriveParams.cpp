#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Gostr3410DeriveParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Gostr3410DeriveParams::Gostr3410DeriveParams() noexcept
{}

Gostr3410DeriveParams::Gostr3410DeriveParams(const Gostr3410DeriveParams &params) noexcept
{
	operator=(params);
}

Gostr3410DeriveParams::Gostr3410DeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

Gostr3410DeriveParams::Gostr3410DeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::pPublicData) &publicData
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pUKM) &ukm
		, const decltype(Parent::ulUKMLen) &ukmLength
) noexcept
{
	this->kdf = kdf;
	pPublicData = publicData;
	ulPublicDataLen = publicDataLength;
	pUKM = ukm;
	ulUKMLen = ukmLength;
}

Gostr3410DeriveParams &Gostr3410DeriveParams::operator=(
		const Gostr3410DeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Gostr3410DeriveParams &Gostr3410DeriveParams::operator=(const Parent &params) noexcept
{
	kdf = params.kdf;
	pPublicData = params.pPublicData;
	ulPublicDataLen = params.ulPublicDataLen;
	pUKM = params.pUKM;
	ulUKMLen = params.ulUKMLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
