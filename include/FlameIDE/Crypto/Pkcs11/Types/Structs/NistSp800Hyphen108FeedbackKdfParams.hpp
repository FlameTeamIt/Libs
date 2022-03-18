#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_FEEDBACK_KDF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_FEEDBACK_KDF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct NistSp800Hyphen108FeedbackKdfParams:
		public WithParent<::CK_SP800_108_FEEDBACK_KDF_PARAMS>
{
	NistSp800Hyphen108FeedbackKdfParams() noexcept;

	NistSp800Hyphen108FeedbackKdfParams(
			const NistSp800Hyphen108FeedbackKdfParams &params
	) noexcept;
	NistSp800Hyphen108FeedbackKdfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param prfType
	/// @param dataParamsCount
	/// @param dataParams
	/// @param ivLength
	/// @param iv
	/// @param additionalDerivedKeysCount
	/// @param additionalDerivedKeys
	NistSp800Hyphen108FeedbackKdfParams(
			const decltype(Parent::prfType) &prfType
			, const decltype(Parent::ulNumberOfDataParams) &dataParamsCount
			, const decltype(Parent::pDataParams) &dataParams
			, const decltype(Parent::ulIVLen) &ivLength
			, const decltype(Parent::pIV) &iv
			, const decltype(Parent::ulAdditionalDerivedKeys) &additionalDerivedKeysCount
			, const decltype(Parent::pAdditionalDerivedKeys) &additionalDerivedKeys
	) noexcept;

	NistSp800Hyphen108FeedbackKdfParams &operator=(
			const NistSp800Hyphen108FeedbackKdfParams &params
	) noexcept;
	NistSp800Hyphen108FeedbackKdfParams &operator=(const Parent &params) noexcept;

	using Parent::prfType;
	using Parent::ulNumberOfDataParams;
	using Parent::pDataParams;
	using Parent::ulIVLen;
	using Parent::pIV;
	using Parent::ulAdditionalDerivedKeys;
	using Parent::pAdditionalDerivedKeys;
};
using NistSp800Hyphen108FeedbackKdfParamsPtr = ::CK_SP800_108_FEEDBACK_KDF_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_FEEDBACK_KDF_PARAMS_HPP
