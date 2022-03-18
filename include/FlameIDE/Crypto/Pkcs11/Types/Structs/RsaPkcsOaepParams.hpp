#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_OAEP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_OAEP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Parameters to the CKM_RSA_PKCS_OAEP mechanism
struct RsaPkcsOaepParams: public WithParent<::CK_RSA_PKCS_OAEP_PARAMS>
{
	RsaPkcsOaepParams() noexcept;
	RsaPkcsOaepParams(const RsaPkcsOaepParams &params) noexcept;
	RsaPkcsOaepParams(const Parent &params) noexcept;

	RsaPkcsOaepParams(
			const decltype(Parent::hashAlg) &hashAlg
			, const decltype(Parent::mgf) &mgf
			, const decltype(Parent::source) &source
			, const decltype(Parent::pSourceData) &sourceData
			, const decltype(Parent::ulSourceDataLen) &sourceDataLength
	) noexcept;

	RsaPkcsOaepParams &operator=(const RsaPkcsOaepParams &params) noexcept;
	RsaPkcsOaepParams &operator=(const Parent &params) noexcept;

	using Parent::hashAlg;
	using Parent::mgf;
	using Parent::source;
	using Parent::pSourceData;
	using Parent::ulSourceDataLen;
};
using RsaPkcsOaepParamsPtr = ::CK_RSA_PKCS_OAEP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_PKCS_OAEP_PARAMS_HPP
