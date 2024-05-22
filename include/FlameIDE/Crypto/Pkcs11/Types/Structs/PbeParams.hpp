#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PBE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PBE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct PbeParams: public WithParent<::CK_PBE_PARAMS>
{
	PbeParams() noexcept;

	PbeParams(const PbeParams &params) noexcept;
	PbeParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param initVector
	/// @param password
	/// @param passwordLength
	/// @param salt
	/// @param saltLength
	/// @param iteration
	PbeParams(
			const decltype(Parent::pInitVector) &initVector
			, const decltype(Parent::pPassword) &password
			, const decltype(Parent::ulPasswordLen) &passwordLength
			, const decltype(Parent::pSalt) &salt
			, const decltype(Parent::ulSaltLen) &saltLength
			, const decltype(Parent::ulIteration) &iteration
	) noexcept;

	PbeParams &operator=(const PbeParams &params) noexcept;
	PbeParams &operator=(const Parent &params) noexcept;

	using Parent::pInitVector;
	using Parent::pPassword;
	using Parent::ulPasswordLen;
	using Parent::pSalt;
	using Parent::ulSaltLen;
	using Parent::ulIteration;
};

using PbeParamsPtr = ::CK_PBE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PBE_PARAMS_HPP
