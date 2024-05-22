#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Ssl3KeyMatParams: public WithParent<::CK_SSL3_KEY_MAT_PARAMS>
{
	Ssl3KeyMatParams() noexcept;

	Ssl3KeyMatParams(const Ssl3KeyMatParams &params) noexcept;
	Ssl3KeyMatParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param macSizeInBits
	/// @param keySizeInBits
	/// @param ivSizeInBits
	/// @param isExport
	/// @param randomInfo
	/// @param returnedKeyMaterial
	Ssl3KeyMatParams(
			const decltype(Parent::ulMacSizeInBits) &macSizeInBits
			, const decltype(Parent::ulKeySizeInBits) &keySizeInBits
			, const decltype(Parent::ulIVSizeInBits) &ivSizeInBits
			, const decltype(Parent::bIsExport) &isExport
			, const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pReturnedKeyMaterial) &returnedKeyMaterial
	) noexcept;

	Ssl3KeyMatParams &operator=(const Ssl3KeyMatParams &params) noexcept;
	Ssl3KeyMatParams &operator=(const Parent &params) noexcept;

	using Parent::ulMacSizeInBits;
	using Parent::ulKeySizeInBits;
	using Parent::ulIVSizeInBits;
	using Parent::bIsExport;
	using Parent::RandomInfo;
	using Parent::pReturnedKeyMaterial;
};
using Ssl3KeyMatParamsPtr = CK_SSL3_KEY_MAT_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_PARAMS_HPP
