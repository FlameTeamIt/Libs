#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_MESSAGE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_MESSAGE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct GcmMessageParams: public WithParent<::CK_GCM_MESSAGE_PARAMS>
{
	GcmMessageParams() noexcept;

	GcmMessageParams(const GcmMessageParams &params) noexcept;
	GcmMessageParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param ivLength
	/// @param ivFixedBits
	/// @param ivGenerator
	/// @param tag
	/// @param tagBits
	GcmMessageParams(
			const decltype(Parent::pIv) &iv
			, const decltype(Parent::ulIvLen) &ivLength
			, const decltype(Parent::ulIvFixedBits) &ivFixedBits
			, const decltype(Parent::ivGenerator) &ivGenerator
			, const decltype(Parent::pTag) &tag
			, const decltype(Parent::ulTagBits) &tagBits
	) noexcept;

	GcmMessageParams &operator=(const GcmMessageParams &params) noexcept;
	GcmMessageParams &operator=(const Parent &params) noexcept;

	using Parent::pIv;
	using Parent::ulIvLen;
	using Parent::ulIvFixedBits;
	using Parent::ivGenerator;
	using Parent::pTag;
	using Parent::ulTagBits;
};

using GcmMessageParamsPtr = ::CK_GCM_MESSAGE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_MESSAGE_PARAMS_HPP
