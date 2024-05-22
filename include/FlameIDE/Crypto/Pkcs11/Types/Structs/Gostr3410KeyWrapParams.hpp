#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_KEY_WRAP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_KEY_WRAP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Gostr3410KeyWrapParams: public WithParent<::CK_GOSTR3410_KEY_WRAP_PARAMS>
{
	Gostr3410KeyWrapParams() noexcept;

	Gostr3410KeyWrapParams(const Gostr3410KeyWrapParams &params) noexcept;
	Gostr3410KeyWrapParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param wrapOid
	/// @param wrapOidLength
	/// @param ukm
	/// @param ukmLength
	/// @param keyHandle
	Gostr3410KeyWrapParams(
			const decltype(Parent::pWrapOID) &wrapOid
			, const decltype(Parent::ulWrapOIDLen) &wrapOidLength
			, const decltype(Parent::pUKM) &ukm
			, const decltype(Parent::ulUKMLen) &ukmLength
			, const decltype(Parent::hKey) &keyHandle
	) noexcept;

	Gostr3410KeyWrapParams &operator=(const Gostr3410KeyWrapParams &params) noexcept;
	Gostr3410KeyWrapParams &operator=(const Parent &params) noexcept;

	using Parent::pWrapOID;
	using Parent::ulWrapOIDLen;
	using Parent::pUKM;
	using Parent::ulUKMLen;
	using Parent::hKey;
};

using Gostr3410KeyWrapParamsPtr = ::CK_GOSTR3410_KEY_WRAP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_KEY_WRAP_PARAMS_HPP
