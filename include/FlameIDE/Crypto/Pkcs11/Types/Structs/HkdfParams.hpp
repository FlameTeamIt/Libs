#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HKDF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HKDF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct HkdfParams: public WithParent<::CK_HKDF_PARAMS>
{
	HkdfParams() noexcept;

	HkdfParams(const HkdfParams &params) noexcept;
	HkdfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param extract
	/// @param expand
	/// @param prfHashMechanism
	/// @param saltType
	/// @param salt
	/// @param saltLength
	/// @param saltKey
	/// @param info
	/// @param infoLength
	HkdfParams(
			const decltype(Parent::bExtract) &extract
			, const decltype(Parent::bExpand) &expand
			, const decltype(Parent::prfHashMechanism) &prfHashMechanism
			, const decltype(Parent::ulSaltType) &saltType
			, const decltype(Parent::pSalt) &salt
			, const decltype(Parent::ulSaltLen) &saltLength
			, const decltype(Parent::hSaltKey) &saltKey
			, const decltype(Parent::pInfo) &info
			, const decltype(Parent::ulInfoLen) &infoLength
	) noexcept;

	HkdfParams &operator=(const HkdfParams &params) noexcept;
	HkdfParams &operator=(const Parent &params) noexcept;

	using Parent::bExtract;
	using Parent::bExpand;
	using Parent::prfHashMechanism;
	using Parent::ulSaltType;
	using Parent::pSalt;
	using Parent::ulSaltLen;
	using Parent::hSaltKey;
	using Parent::pInfo;
	using Parent::ulInfoLen;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HKDF_PARAMS_HPP
