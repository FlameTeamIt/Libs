#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct CamelliaCbcEncryptDataParams: public WithParent<::CK_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS>
{
	CamelliaCbcEncryptDataParams() noexcept;

	CamelliaCbcEncryptDataParams(const CamelliaCbcEncryptDataParams &params) noexcept;
	CamelliaCbcEncryptDataParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param data
	/// @param dataLength
	CamelliaCbcEncryptDataParams(
			const decltype(Parent::iv) &iv
			, const decltype(Parent::pData) &data
			, const decltype(Parent::length) &dataLength
	) noexcept;

	CamelliaCbcEncryptDataParams &operator=(const CamelliaCbcEncryptDataParams &params) noexcept;
	CamelliaCbcEncryptDataParams &operator=(const Parent &params) noexcept;

	using Parent::iv; // [16]
	using Parent::pData;
	using Parent::length;
};
using CamelliaCbcEncryptDataParamsPtr = ::CK_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS_HPP
