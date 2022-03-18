#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS2_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS2_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Pkcs5Pbkd2Params2: public WithParent<::CK_PKCS5_PBKD2_PARAMS2>
{
	Pkcs5Pbkd2Params2() noexcept;

	Pkcs5Pbkd2Params2(const Pkcs5Pbkd2Params2 &params) noexcept;
	Pkcs5Pbkd2Params2(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param saltSource
	/// @param saltSourceData
	/// @param saltSourceDataLength
	/// @param iterations
	/// @param prf
	/// @param prfData
	/// @param prfDataLength
	/// @param password
	/// @param passwordLength
	Pkcs5Pbkd2Params2(
			const decltype(Parent::saltSource) &saltSource
			, const decltype(Parent::pSaltSourceData) &saltSourceData
			, const decltype(Parent::ulSaltSourceDataLen) &saltSourceDataLength
			, const decltype(Parent::iterations) &iterations
			, const decltype(Parent::prf) &prf
			, const decltype(Parent::pPrfData) &prfData
			, const decltype(Parent::ulPrfDataLen) &prfDataLength
			, const decltype(Parent::pPassword) &password
			, const decltype(Parent::ulPasswordLen) &passwordLength
	) noexcept;

	Pkcs5Pbkd2Params2 &operator=(const Pkcs5Pbkd2Params2 &params) noexcept;
	Pkcs5Pbkd2Params2 &operator=(const Parent &params) noexcept;

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

using Pkcs5Pbkd2Params2Ptr = ::CK_PKCS5_PBKD2_PARAMS2_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PKCS5_PBKD2_PARAMS2_HPP
