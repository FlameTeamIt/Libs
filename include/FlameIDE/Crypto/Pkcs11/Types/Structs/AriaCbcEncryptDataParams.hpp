#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ARIA_CBC_ENCRYPT_DATA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ARIA_CBC_ENCRYPT_DATA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct AriaCbcEncryptDataParams: public WithParent<::CK_ARIA_CBC_ENCRYPT_DATA_PARAMS>
{
	AriaCbcEncryptDataParams() noexcept;

	AriaCbcEncryptDataParams(const AriaCbcEncryptDataParams &params) noexcept;
	AriaCbcEncryptDataParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param data
	/// @param dataLength
	AriaCbcEncryptDataParams(
			const decltype(Parent::iv) &iv
			, const decltype(Parent::pData) &data
			, const decltype(Parent::length) &dataLength
	) noexcept;

	AriaCbcEncryptDataParams &operator=(const AriaCbcEncryptDataParams &params) noexcept;
	AriaCbcEncryptDataParams &operator=(const Parent &params) noexcept;

	// [16]
	using Parent::iv;
	using Parent::pData;
	using Parent::length;
};
using AriaCbcEncryptDataParamsPtr = ::CK_ARIA_CBC_ENCRYPT_DATA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ARIA_CBC_ENCRYPT_DATA_PARAMS_HPP
