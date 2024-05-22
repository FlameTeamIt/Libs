#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH2_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH2_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Parameters to the CKM_ECMQV_DERIVE mechanism, where each party
/// contributes two key pairs
struct ElipticCurveDiffieHellman2DeriveParams: public WithParent<::CK_ECDH2_DERIVE_PARAMS>
{
	ElipticCurveDiffieHellman2DeriveParams() noexcept;
	ElipticCurveDiffieHellman2DeriveParams(
			const ElipticCurveDiffieHellman2DeriveParams &params
	) noexcept;
	ElipticCurveDiffieHellman2DeriveParams(const Parent &params) noexcept;

	ElipticCurveDiffieHellman2DeriveParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulSharedDataLen) &sharedDataLength
			, const decltype(Parent::pSharedData) &sharedData
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
			, const decltype(Parent::ulPrivateDataLen) &privateDataLength
			, const decltype(Parent::hPrivateData) &privateData
			, const decltype(Parent::ulPublicDataLen2) &publicDataLength2
			, const decltype(Parent::pPublicData2) &publicData2
	) noexcept;

	ElipticCurveDiffieHellman2DeriveParams &operator=(
			const ElipticCurveDiffieHellman2DeriveParams &params
	) noexcept;
	ElipticCurveDiffieHellman2DeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulSharedDataLen;
	using Parent::pSharedData;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
	using Parent::ulPrivateDataLen;
	using Parent::hPrivateData;
	using Parent::ulPublicDataLen2;
	using Parent::pPublicData2;
};
using Ecdh2DeriveParamsPtr = ::CK_ECDH2_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH2_DERIVE_PARAMS_HPP
