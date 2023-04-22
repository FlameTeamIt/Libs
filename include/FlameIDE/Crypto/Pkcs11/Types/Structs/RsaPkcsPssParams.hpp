#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_PSS_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_PSS_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Parameters to the CKM_RSA_PKCS_PSS mechanism(s)
struct RsaPkcsPssParams: public WithParent<::CK_RSA_PKCS_PSS_PARAMS>
{
	RsaPkcsPssParams() noexcept;
	RsaPkcsPssParams(const RsaPkcsPssParams &params) noexcept;
	RsaPkcsPssParams(const Parent &params) noexcept;

	RsaPkcsPssParams(
			const decltype(Parent::hashAlg) &hashAlg
			, const decltype(Parent::mgf) &mgf
			, const decltype(Parent::sLen) &length
	) noexcept;

	RsaPkcsPssParams &operator=(const RsaPkcsPssParams &params) noexcept;
	RsaPkcsPssParams &operator=(const Parent &params) noexcept;

	using Parent::hashAlg;
	using Parent::mgf;
	using Parent::sLen;
};
using RsaPkcsPssParamsPtr = ::CK_RSA_PKCS_PSS_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_PSS_PARAMS_HPP
