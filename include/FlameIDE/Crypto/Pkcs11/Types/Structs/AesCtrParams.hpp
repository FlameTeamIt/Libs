#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CTR_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CTR_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct AesCtrParams: public WithParent<::CK_AES_CTR_PARAMS>
{
	AesCtrParams() noexcept;

	AesCtrParams(const AesCtrParams &params) noexcept;
	AesCtrParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param counterBits
	/// @param counterBlock
	AesCtrParams(
			const decltype(Parent::ulCounterBits) &counterBits
			, const decltype(Parent::cb) &counterBlock
	) noexcept;

	AesCtrParams &operator=(const AesCtrParams &params) noexcept;
	AesCtrParams &operator=(const Parent &params) noexcept;

	using Parent::ulCounterBits;
	using Parent::cb; // [16]
};

using AesCtrParamsPtr = ::CK_AES_CTR_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_AES_CTR_PARAMS_HPP
