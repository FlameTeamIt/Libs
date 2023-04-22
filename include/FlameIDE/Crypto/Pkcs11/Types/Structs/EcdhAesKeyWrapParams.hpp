#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH_AES_KEY_WRAP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH_AES_KEY_WRAP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct EcdhAesKeyWrapParams: public WithParent<::CK_ECDH_AES_KEY_WRAP_PARAMS>
{
	EcdhAesKeyWrapParams() noexcept;

	EcdhAesKeyWrapParams(const EcdhAesKeyWrapParams &params) noexcept;
	EcdhAesKeyWrapParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param aesKeyBits
	/// @param kdf
	/// @param sharedDataLength
	/// @param sharedData
	EcdhAesKeyWrapParams(
			const decltype(Parent::ulAESKeyBits) &aesKeyBits
			, const decltype(Parent::kdf) &kdf
			, const decltype(Parent::ulSharedDataLen) &sharedDataLength
			, const decltype(Parent::pSharedData) &sharedData
	) noexcept;

	EcdhAesKeyWrapParams &operator=(const EcdhAesKeyWrapParams &params) noexcept;
	EcdhAesKeyWrapParams &operator=(const Parent &params) noexcept;

	using Parent::ulAESKeyBits;
	using Parent::kdf;
	using Parent::ulSharedDataLen;
	using Parent::pSharedData;
};

using EcdhAesKeyWrapParamsPtr = ::CK_ECDH_AES_KEY_WRAP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ECDH_AES_KEY_WRAP_PARAMS_HPP
