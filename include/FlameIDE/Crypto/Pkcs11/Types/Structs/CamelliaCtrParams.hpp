#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CTR_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CTR_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct CamelliaCtrParams: public WithParent<::CK_CAMELLIA_CTR_PARAMS>
{
	CamelliaCtrParams() noexcept;

	CamelliaCtrParams(const CamelliaCtrParams &params) noexcept;
	CamelliaCtrParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param counterBits
	/// @param counterBlock
	CamelliaCtrParams(
			const decltype(Parent::ulCounterBits) &counterBits
			, const decltype(Parent::cb) &counterBlock
	) noexcept;

	CamelliaCtrParams &operator=(const CamelliaCtrParams &params) noexcept;
	CamelliaCtrParams &operator=(const Parent &params) noexcept;

	using Parent::ulCounterBits;
	using Parent::cb; // [16]
};

using CamelliaCtrParamsPtr = ::CK_CAMELLIA_CTR_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CAMELLIA_CTR_PARAMS_HPP
