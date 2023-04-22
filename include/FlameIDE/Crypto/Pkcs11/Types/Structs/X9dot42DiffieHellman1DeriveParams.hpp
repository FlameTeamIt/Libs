#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH1_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH1_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief parameters to the CKM_X9_42_DH_DERIVE key derivation mechanism,
/// where each party contributes one key pair
struct X9dot42DiffieHellman1DeriveParams: public WithParent<::CK_X9_42_DH1_DERIVE_PARAMS>
{
	X9dot42DiffieHellman1DeriveParams() noexcept;
	X9dot42DiffieHellman1DeriveParams(
			const X9dot42DiffieHellman1DeriveParams &params
	) noexcept;
	X9dot42DiffieHellman1DeriveParams(const Parent &params) noexcept;

	X9dot42DiffieHellman1DeriveParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulOtherInfoLen) &otherInfoLength
			, const decltype(Parent::pOtherInfo) &otherInfo
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
	) noexcept;

	X9dot42DiffieHellman1DeriveParams &operator=(
			const X9dot42DiffieHellman1DeriveParams &params
	) noexcept;
	X9dot42DiffieHellman1DeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::ulOtherInfoLen;
	using Parent::pOtherInfo;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
};
using X9dot42DiffieHellman1DeriveParamsPtr = ::CK_X9_42_DH1_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X9_42_DH1_DERIVE_PARAMS_HPP
