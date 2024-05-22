#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH1_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH1_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Parameters to the CKM_ECDH1_DERIVE and
/// CKM_ECDH1_COFACTOR_DERIVE mechanisms, where each
/// party contributes one key pair
struct ElipticCurveDiffieHellman1DeriveParams: public WithParent<::CK_ECDH1_DERIVE_PARAMS>
{
	ElipticCurveDiffieHellman1DeriveParams() noexcept;
	ElipticCurveDiffieHellman1DeriveParams(
			const ElipticCurveDiffieHellman1DeriveParams &params
	) noexcept;
	ElipticCurveDiffieHellman1DeriveParams(const Parent &params) noexcept;

	ElipticCurveDiffieHellman1DeriveParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulSharedDataLen) &sharedDataLength
			, const decltype(Parent::pSharedData) &sharedData
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
	) noexcept;

	ElipticCurveDiffieHellman1DeriveParams &operator=(
			const ElipticCurveDiffieHellman1DeriveParams &params
	) noexcept;
	ElipticCurveDiffieHellman1DeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulSharedDataLen;
	using Parent::pSharedData;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
};
using Ecdh1DeriveParamsPtr = ::CK_ECDH1_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH1_DERIVE_PARAMS_HPP
