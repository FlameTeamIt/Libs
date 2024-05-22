#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CBC_ENCRYPT_DATA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CBC_ENCRYPT_DATA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct AesCbcEncryptDataParams: public WithParent<::CK_AES_CBC_ENCRYPT_DATA_PARAMS>
{
	AesCbcEncryptDataParams() noexcept;

	AesCbcEncryptDataParams(const AesCbcEncryptDataParams &params) noexcept;
	AesCbcEncryptDataParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param rounds
	/// @param dataLength
	///
	AesCbcEncryptDataParams(
			const decltype(Parent::iv) &iv
			, const decltype(Parent::pData) &rounds
			, const decltype(Parent::length) &dataLength
	) noexcept;

	AesCbcEncryptDataParams &operator=(const AesCbcEncryptDataParams &params) noexcept;
	AesCbcEncryptDataParams &operator=(const Parent &params) noexcept;

	using Parent::iv; // [16]
	using Parent::pData;
	using Parent::length;
};

using AesCbcEncryptDataParamsPtr = CK_AES_CBC_ENCRYPT_DATA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CBC_ENCRYPT_DATA_PARAMS_HPP
