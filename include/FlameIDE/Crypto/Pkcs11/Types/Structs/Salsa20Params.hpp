#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Salsa20Params: public WithParent<::CK_SALSA20_PARAMS>
{
	Salsa20Params() noexcept;

	Salsa20Params(const Salsa20Params &params) noexcept;
	Salsa20Params(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param blockCounter
	/// @param nonce
	/// @param nonceBits
	Salsa20Params(
			const decltype(Parent::pBlockCounter) &blockCounter
			, const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceBits) &nonceBits
	) noexcept;

	Salsa20Params &operator=(const Salsa20Params &params) noexcept;
	Salsa20Params &operator=(const Parent &params) noexcept;

	using Parent::pBlockCounter;
	using Parent::pNonce;
	using Parent::ulNonceBits;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SALSA20_PARAMS_HPP
