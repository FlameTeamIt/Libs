#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_XEDDSA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_XEDDSA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct ExtendedEdDsaParams: public WithParent<::CK_XEDDSA_PARAMS>
{
	ExtendedEdDsaParams() noexcept;

	ExtendedEdDsaParams(const ExtendedEdDsaParams &params) noexcept;
	ExtendedEdDsaParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param hash
	explicit ExtendedEdDsaParams(
			const decltype(Parent::hash) &hash
	) noexcept;

	ExtendedEdDsaParams &operator=(const ExtendedEdDsaParams &params) noexcept;
	ExtendedEdDsaParams &operator=(const Parent &params) noexcept;

	using Parent::hash;
};

using ExtendedEdDsaParamsPtr = ::CK_XEDDSA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_XEDDSA_PARAMS_HPP
