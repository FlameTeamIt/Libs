#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_KEY_MAT_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_KEY_MAT_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Tls12KeyMatParams: public WithParent<::CK_TLS12_KEY_MAT_PARAMS>
{
	Tls12KeyMatParams() noexcept;

	Tls12KeyMatParams(const Tls12KeyMatParams &params) noexcept;
	Tls12KeyMatParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param macSizeInBits
	/// @param keySizeInBits
	/// @param ivSizeInBits
	/// @param isExport
	/// @param randomInfo
	/// @param returnedKeyMaterial
	/// @param prfHashMechanism
	Tls12KeyMatParams(
			const decltype(Parent::ulMacSizeInBits) &macSizeInBits
			, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
			, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
			, const decltype(Parent::bIsExport) &isExport
			, const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
			, const decltype(Parent::prfHashMechanism) &prfHashMechanism
	) noexcept;

	Tls12KeyMatParams &operator=(const Tls12KeyMatParams &params) noexcept;
	Tls12KeyMatParams &operator=(const Parent &params) noexcept;

	using Parent::ulMacSizeInBits;
	using Parent::ulKeySizeInBits;
	using Parent::ulIVSizeInBits;
	using Parent::bIsExport;
	using Parent::RandomInfo;
	using Parent::pReturnedKeyMaterial;
	using Parent::prfHashMechanism;
};

using Tls12KeyMatParamsPtr = ::CK_TLS12_KEY_MAT_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_KEY_MAT_PARAMS_HPP
