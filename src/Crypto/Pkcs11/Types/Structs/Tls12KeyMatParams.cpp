#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Tls12KeyMatParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Tls12KeyMatParams::Tls12KeyMatParams() noexcept
{}

Tls12KeyMatParams::Tls12KeyMatParams(const Tls12KeyMatParams &params) noexcept
{
	operator=(params);
}

Tls12KeyMatParams::Tls12KeyMatParams(const Parent &params) noexcept
{
	operator=(params);
}

Tls12KeyMatParams::Tls12KeyMatParams(
		const decltype(Parent::ulMacSizeInBits) &macSizeInBits
		, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
		, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
		, const decltype(Parent::bIsExport) &isExport
		, const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
		, const decltype(Parent::prfHashMechanism) &prfHashMechanism
) noexcept
{
	ulMacSizeInBits = macSizeInBits;
	ulKeySizeInBits = keySizeInBits;
	ulIVSizeInBits = ivSizeInBits;
	bIsExport = isExport;
	RandomInfo = randomInfo;
	pReturnedKeyMaterial = returnedKeyMaterial;
	this->prfHashMechanism = prfHashMechanism;
}

Tls12KeyMatParams &Tls12KeyMatParams::operator=(const Tls12KeyMatParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Tls12KeyMatParams &Tls12KeyMatParams::operator=(const Parent &params) noexcept
{
	ulMacSizeInBits = params.ulMacSizeInBits;
	ulKeySizeInBits = params.ulKeySizeInBits;
	ulIVSizeInBits = params.ulIVSizeInBits;
	bIsExport = params.bIsExport;
	RandomInfo = params.RandomInfo;
	pReturnedKeyMaterial = params.pReturnedKeyMaterial;
	prfHashMechanism = params.prfHashMechanism;

	return *this;
}

}}} // flame_ide::pkcs11::structs
