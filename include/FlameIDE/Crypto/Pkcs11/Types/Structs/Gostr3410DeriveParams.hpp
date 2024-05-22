#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Gostr3410DeriveParams: public WithParent<::CK_GOSTR3410_DERIVE_PARAMS>
{
	Gostr3410DeriveParams() noexcept;

	Gostr3410DeriveParams(const Gostr3410DeriveParams &params) noexcept;
	Gostr3410DeriveParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param kdf
	/// @param publicData
	/// @param publicDataLength
	/// @param ukm
	/// @param ukmLength
	Gostr3410DeriveParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::pPublicData) &publicData
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pUKM) &ukm
			, const decltype(Parent::ulUKMLen) &ukmLength
	) noexcept;

	Gostr3410DeriveParams &operator=(const Gostr3410DeriveParams &params) noexcept;
	Gostr3410DeriveParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::pPublicData;
	using Parent::ulPublicDataLen;
	using Parent::pUKM;
	using Parent::ulUKMLen;
};

using Gostr3410DeriveParamsPtr = ::CK_GOSTR3410_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GOSTR3410_DERIVE_PARAMS_HPP
