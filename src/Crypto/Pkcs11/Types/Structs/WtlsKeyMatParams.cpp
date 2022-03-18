#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsKeyMatParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

WtlsKeyMatParams::WtlsKeyMatParams() noexcept
{}

WtlsKeyMatParams::WtlsKeyMatParams(const WtlsKeyMatParams &params) noexcept
{
	operator=(params);
}

WtlsKeyMatParams::WtlsKeyMatParams(const Parent &params) noexcept
{
	operator=(params);
}

WtlsKeyMatParams::WtlsKeyMatParams(
		const decltype(Parent::DigestMechanism) &digestMechanism
		, const decltype(Parent::ulMacSizeInBits) &macSizeInBits
		, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
		, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
		, const decltype(Parent::ulSequenceNumber) &sequenceNumber
		, const decltype(Parent::bIsExport) &isExport
		, const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
) noexcept
{
	DigestMechanism = digestMechanism;
	ulMacSizeInBits = macSizeInBits;
	ulKeySizeInBits = keySizeInBits;
	ulIVSizeInBits = ivSizeInBits;
	ulSequenceNumber = sequenceNumber;
	bIsExport = isExport;
	RandomInfo = randomInfo;
	pReturnedKeyMaterial = returnedKeyMaterial;
}

WtlsKeyMatParams &WtlsKeyMatParams::operator=(const WtlsKeyMatParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

WtlsKeyMatParams &WtlsKeyMatParams::operator=(const Parent &params) noexcept
{
	DigestMechanism = params.DigestMechanism;
	ulMacSizeInBits = params.ulMacSizeInBits;
	ulKeySizeInBits = params.ulKeySizeInBits;
	ulIVSizeInBits = params.ulIVSizeInBits;
	ulSequenceNumber = params.ulSequenceNumber;
	bIsExport = params.bIsExport;
	RandomInfo = params.RandomInfo;
	pReturnedKeyMaterial = params.pReturnedKeyMaterial;

	return *this;
}

}}} // flame_ide::pkcs11::structs
