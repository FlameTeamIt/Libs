#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Pkcs5Pbkd2Params: public WithParent<::CK_PKCS5_PBKD2_PARAMS>
{
	Pkcs5Pbkd2Params() noexcept;

	Pkcs5Pbkd2Params(const Pkcs5Pbkd2Params &params) noexcept;
	Pkcs5Pbkd2Params(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param saltSource
	/// @param saltSourceData
	/// @param saltSourceDataLength
	/// @param iterations
	/// @param prf
	/// @param prfData
	/// @param prfDataLen
	/// @param Password
	/// @param PasswordLength
	Pkcs5Pbkd2Params(
			const decltype(Parent::saltSource) &saltSource
			, const decltype(Parent::pSaltSourceData) &saltSourceData
			, const decltype(Parent::ulSaltSourceDataLen) &saltSourceDataLength
			, const decltype(Parent::iterations) &iterations
			, const decltype(Parent::prf) &prf
			, const decltype(Parent::pPrfData) &prfData
			, const decltype(Parent::ulPrfDataLen) &prfDataLen
			, const decltype(Parent::pPassword) &password
			, const decltype(Parent::ulPasswordLen) &passwordLength
	) noexcept;

	Pkcs5Pbkd2Params &operator=(const Pkcs5Pbkd2Params &params) noexcept;
	Pkcs5Pbkd2Params &operator=(const Parent &params) noexcept;

	using Parent::saltSource;
	using Parent::pSaltSourceData;
	using Parent::ulSaltSourceDataLen;
	using Parent::iterations;
	using Parent::prf;
	using Parent::pPrfData;
	using Parent::ulPrfDataLen;
	using Parent::pPassword;
	using Parent::ulPasswordLen;
};

using Pkcs5Pbkd2ParamsPtr = ::CK_PKCS5_PBKD2_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS_HPP
