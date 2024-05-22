#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3KeyMatParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Ssl3KeyMatParams::Ssl3KeyMatParams() noexcept
{}

Ssl3KeyMatParams::Ssl3KeyMatParams(const Ssl3KeyMatParams &params) noexcept
{
	operator=(params);
}

Ssl3KeyMatParams::Ssl3KeyMatParams(const Parent &params) noexcept
{
	operator=(params);
}

Ssl3KeyMatParams::Ssl3KeyMatParams(
		const decltype(Parent::ulMacSizeInBits) &macSizeInBits
		, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
		, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
		, const decltype(Parent::bIsExport) &isExport
		, const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
) noexcept
{
	ulMacSizeInBits = macSizeInBits;
	ulKeySizeInBits = keySizeInBits;
	ulIVSizeInBits = ivSizeInBits;
	bIsExport = isExport;
	RandomInfo = randomInfo;
	pReturnedKeyMaterial = returnedKeyMaterial;
}

Ssl3KeyMatParams &Ssl3KeyMatParams::operator=(const Ssl3KeyMatParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Ssl3KeyMatParams &Ssl3KeyMatParams::operator=(const Parent &params) noexcept
{
	ulMacSizeInBits = params.ulMacSizeInBits;
	ulKeySizeInBits = params.ulKeySizeInBits;
	ulIVSizeInBits = params.ulIVSizeInBits;
	bIsExport = params.bIsExport;
	RandomInfo = params.RandomInfo;
	pReturnedKeyMaterial = params.pReturnedKeyMaterial;

	return *this;
}

}}} // flame_ide::pkcs11::structs
