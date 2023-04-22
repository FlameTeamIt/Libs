#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH2_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH2_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Parameters to the CKM_X9_42_DH_HYBRID_DERIVE and CKM_X9_42_MQV_DERIVE
/// key derivation mechanisms, where each party contributes two key pairs
struct X9dot42DiffieHellman2DeriveParams: public WithParent<::CK_X9_42_DH2_DERIVE_PARAMS>
{
	X9dot42DiffieHellman2DeriveParams() noexcept;
	X9dot42DiffieHellman2DeriveParams(
			const X9dot42DiffieHellman2DeriveParams &params
	) noexcept;
	X9dot42DiffieHellman2DeriveParams(const Parent &params) noexcept;

	X9dot42DiffieHellman2DeriveParams(const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulOtherInfoLen) &otherInfoLength
			, const decltype(Parent::pOtherInfo) &otherInfo
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
			, const decltype(Parent::ulPrivateDataLen) &privateDataLength
			, const decltype(Parent::hPrivateData) &privateData
			, const decltype(Parent::ulPublicDataLen2) &publicDataLength2
			, const decltype(Parent::pPublicData2) &publicData2) noexcept;

	X9dot42DiffieHellman2DeriveParams &operator=(
			const X9dot42DiffieHellman2DeriveParams &params
	) noexcept;
	X9dot42DiffieHellman2DeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulOtherInfoLen;
	using Parent::pOtherInfo;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
	using Parent::ulPrivateDataLen;
	using Parent::hPrivateData;
	using Parent::ulPublicDataLen2;
	using Parent::pPublicData2;
};

using X9dot42DiffieHellman2DeriveParamsPtr = ::CK_X9_42_DH2_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH2_DERIVE_PARAMS_HPP
