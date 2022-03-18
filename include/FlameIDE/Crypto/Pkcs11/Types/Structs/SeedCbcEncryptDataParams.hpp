#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SEED_CBC_ENCRYPT_DATA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SEED_CBC_ENCRYPT_DATA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct SeedCbcEncryptDataParams: public WithParent<::CK_SEED_CBC_ENCRYPT_DATA_PARAMS>
{
	SeedCbcEncryptDataParams() noexcept;

	SeedCbcEncryptDataParams(const SeedCbcEncryptDataParams &params) noexcept;
	SeedCbcEncryptDataParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param data
	/// @param dataLength
	SeedCbcEncryptDataParams(
			const decltype(Parent::iv) &iv
			, const decltype(Parent::pData) &data
			, const decltype(Parent::length) &dataLength
	) noexcept;

	SeedCbcEncryptDataParams &operator=(const SeedCbcEncryptDataParams &params) noexcept;
	SeedCbcEncryptDataParams &operator=(const Parent &params) noexcept;

	// [16]
	using Parent::iv;
	using Parent::pData;
	using Parent::length;
};

using SeedCbcEncryptDataParamsPtr = ::CK_SEED_CBC_ENCRYPT_DATA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SEED_CBC_ENCRYPT_DATA_PARAMS_HPP
