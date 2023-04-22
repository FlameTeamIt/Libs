#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_MSG_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_MSG_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Salsa20ChaCha20Poly1305MessageParams:
		public WithParent<::CK_SALSA20_CHACHA20_POLY1305_MSG_PARAMS>
{
	Salsa20ChaCha20Poly1305MessageParams() noexcept;

	Salsa20ChaCha20Poly1305MessageParams(
			const Salsa20ChaCha20Poly1305MessageParams &params
	) noexcept;
	Salsa20ChaCha20Poly1305MessageParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param nonce
	/// @param nonceLength
	/// @param tag
	Salsa20ChaCha20Poly1305MessageParams(
			const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceLen) &nonceLength
			, const decltype(Parent::pTag) &tag
	) noexcept;

	Salsa20ChaCha20Poly1305MessageParams &operator=(
			const Salsa20ChaCha20Poly1305MessageParams &params
	) noexcept;
	Salsa20ChaCha20Poly1305MessageParams &operator=(const Parent &params) noexcept;

	using Parent::pNonce;
	using Parent::ulNonceLen;
	using Parent::pTag;
};

using Salsa20ChaCha20Poly1305MessageParamsPtr = ::CK_SALSA20_CHACHA20_POLY1305_MSG_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_MSG_PARAMS_HPP
