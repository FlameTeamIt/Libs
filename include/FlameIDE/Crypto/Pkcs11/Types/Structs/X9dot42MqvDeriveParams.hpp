#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_MQV_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_MQV_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct X9dot42MqvDeriveParams: public WithParent<::CK_X9_42_MQV_DERIVE_PARAMS>
{
	X9dot42MqvDeriveParams() noexcept;

	X9dot42MqvDeriveParams(const X9dot42MqvDeriveParams &params) noexcept;
	X9dot42MqvDeriveParams(const Parent &params) noexcept;

	X9dot42MqvDeriveParams(
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
	) noexcept;

	X9dot42MqvDeriveParams &operator=(const X9dot42MqvDeriveParams &params) noexcept;
	X9dot42MqvDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulOtherInfoLen;
	using Parent::pOtherInfo;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
	using Parent::ulPrivateDataLen;
	using Parent::hPrivateData;
	using Parent::ulPublicDataLen2;
	using Parent::pPublicData2;
	using Parent::publicKey;
};
using X9dot42MqvDeriveParamsPtr = CK_X9_42_MQV_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_MQV_DERIVE_PARAMS_HPP
