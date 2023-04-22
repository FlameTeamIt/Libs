#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_DERIVATION_STRING_DATA_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_DERIVATION_STRING_DATA_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct KeyDerivationStringData: public WithParent<::CK_KEY_DERIVATION_STRING_DATA>
{
	KeyDerivationStringData() noexcept;

	KeyDerivationStringData(const KeyDerivationStringData &params) noexcept;
	KeyDerivationStringData(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param data
	/// @param length
	KeyDerivationStringData(
			const decltype(Parent::pData) &data
			, const decltype(Parent::ulLen) &length
	) noexcept;

	KeyDerivationStringData &operator=(const KeyDerivationStringData &params) noexcept;
	KeyDerivationStringData &operator=(const Parent &params) noexcept;

	using Parent::pData;
	using Parent::ulLen;
};

using KeyDerivationStringDataPtr = ::CK_KEY_DERIVATION_STRING_DATA_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_DERIVATION_STRING_DATA_HPP
