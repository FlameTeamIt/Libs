#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DSA_PARAMETER_GEN_PARAM_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DSA_PARAMETER_GEN_PARAM_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct DsaParameterGenParam: public WithParent<::CK_DSA_PARAMETER_GEN_PARAM>
{
	DsaParameterGenParam() noexcept;

	DsaParameterGenParam(const DsaParameterGenParam &params) noexcept;
	DsaParameterGenParam(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param hash
	/// @param seed
	/// @param seedLength
	/// @param index
	DsaParameterGenParam(
			const decltype(Parent::hash) &hash
			, const decltype(Parent::pSeed) &seed
			, const decltype(Parent::ulSeedLen) &seedLength
			, const decltype(Parent::ulIndex) &index
	) noexcept;

	DsaParameterGenParam &operator=(const DsaParameterGenParam &params) noexcept;
	DsaParameterGenParam &operator=(const Parent &params) noexcept;

	using Parent::hash;
	using Parent::pSeed;
	using Parent::ulSeedLen;
	using Parent::ulIndex;
};
using DsaParameterGenParamPtr = ::CK_DSA_PARAMETER_GEN_PARAM_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DSA_PARAMETER_GEN_PARAM_HPP
