#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DES_CBC_ENCRYPT_DATA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DES_CBC_ENCRYPT_DATA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct DesCbcEncryptDataParams: public WithParent<::CK_DES_CBC_ENCRYPT_DATA_PARAMS>
{
	DesCbcEncryptDataParams() noexcept;

	DesCbcEncryptDataParams(const DesCbcEncryptDataParams &params) noexcept;
	DesCbcEncryptDataParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param data
	/// @param dataLength
	DesCbcEncryptDataParams(
			const decltype(Parent::iv) &iv
			, const decltype(Parent::pData) &data
			, const decltype(Parent::length) &dataLength
	) noexcept;

	DesCbcEncryptDataParams &operator=(const DesCbcEncryptDataParams &params) noexcept;
	DesCbcEncryptDataParams &operator=(const Parent &params) noexcept;

	using Parent::iv;
	using Parent::pData;
	using Parent::length;
};

using DesCbcEncryptDataParamsPtr = CK_DES_CBC_ENCRYPT_DATA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DES_CBC_ENCRYPT_DATA_PARAMS_HPP
