#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KIP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KIP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct KipParams: public WithParent<::CK_KIP_PARAMS>
{
	KipParams() noexcept;

	KipParams(const KipParams &params) noexcept;
	KipParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param mechanism
	/// @param key
	/// @param seed
	/// @param seedLength
	KipParams(
			const decltype(Parent::pMechanism) &mechanism
			, const decltype(Parent::hKey) &key
			, const decltype(Parent::pSeed) &seed
			, const decltype(Parent::ulSeedLen) &seedLength
	) noexcept;

	KipParams &operator=(const KipParams &params) noexcept;
	KipParams &operator=(const Parent &params) noexcept;

	using Parent::pMechanism;
	using Parent::hKey;
	using Parent::pSeed;
	using Parent::ulSeedLen;
};

using KipParamsPtr = ::CK_KIP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KIP_PARAMS_HPP
