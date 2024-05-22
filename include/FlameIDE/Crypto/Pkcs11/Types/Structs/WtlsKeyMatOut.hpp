#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_OUT_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_OUT_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct WtlsKeyMatOut: public WithParent<::CK_WTLS_KEY_MAT_OUT>
{
	WtlsKeyMatOut() noexcept;

	WtlsKeyMatOut(const WtlsKeyMatOut &params) noexcept;
	WtlsKeyMatOut(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param macSecret
	/// @param key
	/// @param iv
	WtlsKeyMatOut(
			const decltype(Parent::hMacSecret) &macSecret
			, const decltype(Parent::hKey) &key
			, const decltype(Parent::pIV) &iv
	) noexcept;

	WtlsKeyMatOut &operator=(const WtlsKeyMatOut &params) noexcept;
	WtlsKeyMatOut &operator=(const Parent &params) noexcept;

	using Parent::hMacSecret;
	using Parent::hKey;
	using Parent::pIV;
};
using WtlsKeyMatOutPtr = ::CK_WTLS_KEY_MAT_OUT_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_OUT_HPP
