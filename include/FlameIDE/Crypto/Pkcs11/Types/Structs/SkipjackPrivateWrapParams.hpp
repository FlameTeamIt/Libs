#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_PRIVATE_WRAP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_PRIVATE_WRAP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct SkipjackPrivateWrapParams: public WithParent<::CK_SKIPJACK_PRIVATE_WRAP_PARAMS>
{
	SkipjackPrivateWrapParams() noexcept;

	SkipjackPrivateWrapParams(const SkipjackPrivateWrapParams &params) noexcept;
	SkipjackPrivateWrapParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param passwordLength
	/// @param password
	/// @param publicDataLength
	/// @param publicData
	/// @param pAndGLength
	/// @param qLen
	/// @param randomLength
	/// @param randomA
	/// @param primeP
	/// @param baseG
	/// @param subprimeQ
	SkipjackPrivateWrapParams(
			const decltype (Parent::ulPasswordLen) &passwordLength
			, const decltype(Parent::pPassword) &password
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
			, const decltype(Parent::ulPAndGLen) &pAndGLength
			, const decltype(Parent::ulQLen) &qLen
			, const decltype(Parent::ulRandomLen) &randomLength
			, const decltype(Parent::pRandomA) &randomA
			, const decltype(Parent::pPrimeP) &primeP
			, const decltype(Parent::pBaseG) &baseG
			, const decltype(Parent::pSubprimeQ) &subprimeQ
	) noexcept;

	SkipjackPrivateWrapParams &operator=(const SkipjackPrivateWrapParams &params) noexcept;
	SkipjackPrivateWrapParams &operator=(const Parent &params) noexcept;

	using Parent::ulPasswordLen;
	using Parent::pPassword;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
	using Parent::ulPAndGLen;
	using Parent::ulQLen;
	using Parent::ulRandomLen;
	using Parent::pRandomA;
	using Parent::pPrimeP;
	using Parent::pBaseG;
	using Parent::pSubprimeQ;
};

using SkipjackPrivateWrapParamsPtr = CK_SKIPJACK_PRIVATE_WRAP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_PRIVATE_WRAP_PARAMS_HPP
