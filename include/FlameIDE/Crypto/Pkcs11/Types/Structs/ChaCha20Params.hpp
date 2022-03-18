#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CHACHA20_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CHACHA20_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct ChaCha20Params: public WithParent<::CK_CHACHA20_PARAMS>
{
	ChaCha20Params() noexcept;

	ChaCha20Params(const ChaCha20Params &params) noexcept;
	ChaCha20Params(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param blockCounter
	/// @param blockCounterBits
	/// @param nonce
	/// @param nonceBits
	ChaCha20Params(
			const decltype(Parent::pBlockCounter) &blockCounter
			, const decltype(Parent::blockCounterBits) &blockCounterBits
			, const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceBits) &nonceBits
	) noexcept;

	ChaCha20Params &operator=(const ChaCha20Params &params) noexcept;
	ChaCha20Params &operator=(const Parent &params) noexcept;

	using Parent::pBlockCounter;
	using Parent::blockCounterBits;
	using Parent::pNonce;
	using Parent::ulNonceBits;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CHACHA20_PARAMS_HPP
