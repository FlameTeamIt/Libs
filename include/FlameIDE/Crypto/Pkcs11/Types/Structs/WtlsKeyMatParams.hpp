#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct WtlsKeyMatParams: public WithParent<::CK_WTLS_KEY_MAT_PARAMS>
{
	WtlsKeyMatParams() noexcept;

	WtlsKeyMatParams(const WtlsKeyMatParams &params) noexcept;
	WtlsKeyMatParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param digestMechanism
	/// @param macSizeInBits
	/// @param keySizeInBits
	/// @param ivSizeInBits
	/// @param sequenceNumber
	/// @param isExport
	/// @param randomInfo
	/// @param returnedKeyMaterial
	WtlsKeyMatParams(
			const decltype(Parent::DigestMechanism) &digestMechanism
			, const decltype(Parent::ulMacSizeInBits) &macSizeInBits
			, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
			, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
			, const decltype(Parent::ulSequenceNumber) &sequenceNumber
			, const decltype(Parent::bIsExport) &isExport
			, const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
	) noexcept;

	WtlsKeyMatParams &operator=(const WtlsKeyMatParams &params) noexcept;
	WtlsKeyMatParams &operator=(const Parent &params) noexcept;

	using Parent::DigestMechanism;
	using Parent::ulMacSizeInBits;
	using Parent::ulKeySizeInBits;
	using Parent::ulIVSizeInBits;
	using Parent::ulSequenceNumber;
	using Parent::bIsExport;
	using Parent::RandomInfo;
	using Parent::pReturnedKeyMaterial;
};
using WtlsKeyMatParamsPtr = ::CK_WTLS_KEY_MAT_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_KEY_MAT_PARAMS_HPP
