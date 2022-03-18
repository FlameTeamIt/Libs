#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_AES_KEY_WRAP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_AES_KEY_WRAP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct RsaAesKeyWrapParams: public WithParent<::CK_RSA_AES_KEY_WRAP_PARAMS>
{
	RsaAesKeyWrapParams() noexcept;

	RsaAesKeyWrapParams(const RsaAesKeyWrapParams &params) noexcept;
	RsaAesKeyWrapParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param aesKeyBits
	/// @param oaepParams
	RsaAesKeyWrapParams(
			const decltype(Parent::ulAESKeyBits) &aesKeyBits
			, const decltype(Parent::pOAEPParams) &oaepParams
	) noexcept;

	RsaAesKeyWrapParams &operator=(const RsaAesKeyWrapParams &params) noexcept;
	RsaAesKeyWrapParams &operator=(const Parent &params) noexcept;

	using Parent::ulAESKeyBits;
	using Parent::pOAEPParams;
};

using RsaAesKeyWrapParamsPtr = ::CK_RSA_AES_KEY_WRAP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RSA_AES_KEY_WRAP_PARAMS_HPP
