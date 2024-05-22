#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcDh1DeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

ElipticCurveDiffieHellman1DeriveParams::ElipticCurveDiffieHellman1DeriveParams() noexcept
		: ElipticCurveDiffieHellman1DeriveParams(Parent{})
{}

ElipticCurveDiffieHellman1DeriveParams::ElipticCurveDiffieHellman1DeriveParams(const ElipticCurveDiffieHellman1DeriveParams &params) noexcept
		: ElipticCurveDiffieHellman1DeriveParams(static_cast<const Parent &>(params))
{}

ElipticCurveDiffieHellman1DeriveParams::ElipticCurveDiffieHellman1DeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

ElipticCurveDiffieHellman1DeriveParams::ElipticCurveDiffieHellman1DeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulSharedDataLen) &sharedDataLength
		, const decltype(Parent::pSharedData) &sharedData
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
) noexcept
{
	this->kdf = kdf;
	this->ulSharedDataLen = sharedDataLength;
	this->pSharedData = sharedData;
	this->ulPublicDataLen = publicDataLength;
	this->pPublicData = publicData;
}

ElipticCurveDiffieHellman1DeriveParams &ElipticCurveDiffieHellman1DeriveParams::operator=(const ElipticCurveDiffieHellman1DeriveParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ElipticCurveDiffieHellman1DeriveParams &ElipticCurveDiffieHellman1DeriveParams::operator=(const Parent &params) noexcept
{
	kdf = params.kdf;
	ulSharedDataLen = params.ulSharedDataLen;
	pSharedData = params.pSharedData;
	ulPublicDataLen = params.ulPublicDataLen;
	pPublicData = params.pPublicData;
	return *this;
}

}}} // flame_ide::pkcs11::structs
