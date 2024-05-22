#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Salsa20ChaCha20Poly1305Params: public WithParent<::CK_SALSA20_CHACHA20_POLY1305_PARAMS>
{
	Salsa20ChaCha20Poly1305Params() noexcept;

	Salsa20ChaCha20Poly1305Params(const Salsa20ChaCha20Poly1305Params &params) noexcept;
	Salsa20ChaCha20Poly1305Params(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param nonce
	/// @param nonceLength
	/// @param aad
	/// @param aadLength
	Salsa20ChaCha20Poly1305Params(
			const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceLen) &nonceLength
			, const decltype(Parent::pAAD) &aad
			, const decltype(Parent::ulAADLen) &aadLength
	) noexcept;

	Salsa20ChaCha20Poly1305Params &operator=(
			const Salsa20ChaCha20Poly1305Params &params
	) noexcept;
	Salsa20ChaCha20Poly1305Params &operator=(const Parent &params) noexcept;

	using Parent::pNonce;
	using Parent::ulNonceLen;
	using Parent::pAAD;
	using Parent::ulAADLen;
};

using Salsa20ChaCha20Poly1305ParamsPtr = ::CK_SALSA20_CHACHA20_POLY1305_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_CHACHA20_POLY1305_PARAMS_HPP
