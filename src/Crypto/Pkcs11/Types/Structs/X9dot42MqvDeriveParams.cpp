#include <FlameIDE/Crypto/Pkcs11/Types/Structs/X9dot42MqvDeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

X9dot42MqvDeriveParams::X9dot42MqvDeriveParams() noexcept
		: X9dot42MqvDeriveParams(Parent{})
{}

X9dot42MqvDeriveParams::X9dot42MqvDeriveParams(const X9dot42MqvDeriveParams &params) noexcept
		: X9dot42MqvDeriveParams(static_cast<const Parent &>(params))
{}

X9dot42MqvDeriveParams::X9dot42MqvDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

X9dot42MqvDeriveParams::X9dot42MqvDeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulOtherInfoLen) &otherInfoLength
		, const decltype(Parent::pOtherInfo) &otherInfo
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
	this->ulOtherInfoLen = otherInfoLength;
	this->pOtherInfo = otherInfo;
	this->ulPublicDataLen = publicDataLength;
	this->pPublicData = publicData;
	this->ulPrivateDataLen = privateDataLength;
	this->hPrivateData = privateData;
	this->ulPublicDataLen2 = publicDataLength2;
	this->pPublicData2 = publicData2;
	this->publicKey = publicKey;
}

X9dot42MqvDeriveParams &X9dot42MqvDeriveParams::operator=(
		const X9dot42MqvDeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

X9dot42MqvDeriveParams &X9dot42MqvDeriveParams::operator=(const Parent &params) noexcept
{
	kdf = params.kdf;
	ulOtherInfoLen = params.ulOtherInfoLen;
	pOtherInfo = params.pOtherInfo;
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
