#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcMqvDeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

EcMqvDeriveParams::EcMqvDeriveParams() noexcept
		: EcMqvDeriveParams(Parent{})
{}

EcMqvDeriveParams::EcMqvDeriveParams(const EcMqvDeriveParams &params) noexcept
		: EcMqvDeriveParams(static_cast<const Parent &>(params))
{}

EcMqvDeriveParams::EcMqvDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

EcMqvDeriveParams::EcMqvDeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulSharedDataLen) &sharedDataLength
		, const decltype(Parent::pSharedData) &sharedData
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
		, const decltype(Parent::ulPrivateDataLen) &privateDataLength
		, const decltype(Parent::hPrivateData) &privateData
		, const decltype(Parent::ulPublicDataLen2) &publicDataLength2
		, const decltype(Parent::pPublicData2) &publicData2
		, const decltype(Parent::publicKey) &publicKey
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
	this->publicKey = publicKey;
}

EcMqvDeriveParams &EcMqvDeriveParams::operator=(const EcMqvDeriveParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

EcMqvDeriveParams &EcMqvDeriveParams::operator=(const Parent &params) noexcept
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
	publicKey = params.publicKey;
	return *this;
}

}}} // flame_ide::pkcs11::structs
