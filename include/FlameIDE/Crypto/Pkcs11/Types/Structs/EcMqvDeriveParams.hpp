#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECMQV_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECMQV_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct EcMqvDeriveParams: public WithParent<::CK_ECMQV_DERIVE_PARAMS>
{
	EcMqvDeriveParams() noexcept;
	EcMqvDeriveParams(const EcMqvDeriveParams &params) noexcept;
	EcMqvDeriveParams(const Parent &params) noexcept;

	EcMqvDeriveParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulSharedDataLen) &sharedDataLen
			, const decltype(Parent::pSharedData) &sharedData
			, const decltype(Parent::ulPublicDataLen) &publicDataLen
			, const decltype(Parent::pPublicData) &publicData
			, const decltype(Parent::ulPrivateDataLen) &privateDataLen
			, const decltype(Parent::hPrivateData) &privateData
			, const decltype(Parent::ulPublicDataLen2) &publicDataLen2
			, const decltype(Parent::pPublicData2) &publicData2
			, const decltype(Parent::publicKey) &publicKey
	) noexcept;

	EcMqvDeriveParams &operator=(const EcMqvDeriveParams &params) noexcept;
	EcMqvDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulSharedDataLen;
	using Parent::pSharedData;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
	using Parent::ulPrivateDataLen;
	using Parent::hPrivateData;
	using Parent::ulPublicDataLen2;
	using Parent::pPublicData2;
	using Parent::publicKey;
};
using EcmqvDeriveparamsPtr = ::CK_ECMQV_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECMQV_DERIVE_PARAMS_HPP
