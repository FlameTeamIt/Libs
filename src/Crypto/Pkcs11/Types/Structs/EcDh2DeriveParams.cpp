#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcDh2DeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

ElipticCurveDiffieHellman2DeriveParams::ElipticCurveDiffieHellman2DeriveParams() noexcept
		: ElipticCurveDiffieHellman2DeriveParams(Parent{})
{}

ElipticCurveDiffieHellman2DeriveParams::ElipticCurveDiffieHellman2DeriveParams(
		const ElipticCurveDiffieHellman2DeriveParams &params
) noexcept
		: ElipticCurveDiffieHellman2DeriveParams(static_cast<const Parent &>(params))
{}

ElipticCurveDiffieHellman2DeriveParams::ElipticCurveDiffieHellman2DeriveParams(
		const Parent &params
) noexcept
{
	operator=(params);
}

ElipticCurveDiffieHellman2DeriveParams::ElipticCurveDiffieHellman2DeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulSharedDataLen) &sharedDataLength
		, const decltype(Parent::pSharedData) &sharedData
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
		, const decltype(Parent::ulPrivateDataLen) &privateDataLength
		, const decltype(Parent::hPrivateData) &privateData
		, const decltype(Parent::ulPublicDataLen2) &publicDataLength2
		, const decltype(Parent::pPublicData2) &publicData2
) noexcept
{
	this->kdf = kdf;
	this->ulSharedDataLen = sharedDataLength;
	this->pSharedData = sharedData;
	this->ulPublicDataLen = publicDataLength;
	this->pPublicData = publicData;
	this->ulPrivateDataLen = privateDataLength;
	this->hPrivateData = privateData;
	this->ulPublicDataLen2 = publicDataLength2;
	this->pPublicData2 = publicData2;
}

ElipticCurveDiffieHellman2DeriveParams &ElipticCurveDiffieHellman2DeriveParams::operator=(
		const ElipticCurveDiffieHellman2DeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ElipticCurveDiffieHellman2DeriveParams &ElipticCurveDiffieHellman2DeriveParams::operator=(
		const Parent &params
) noexcept
{
	kdf = params.kdf;
	ulSharedDataLen = params.ulSharedDataLen;
	pSharedData = params.pSharedData;
	ulPublicDataLen = params.ulPublicDataLen;
	pPublicData = params.pPublicData;
	ulPrivateDataLen = params.ulPrivateDataLen;
	hPrivateData = params.hPrivateData;
	ulPublicDataLen2 = params.ulPublicDataLen2;
	pPublicData2 = params.pPublicData2;
	return *this;
}

}}} // flame_ide::pkcs11::structs
