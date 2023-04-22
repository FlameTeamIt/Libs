#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct GcmParams: public WithParent<::CK_GCM_PARAMS>
{
	GcmParams() noexcept;

	GcmParams(const GcmParams &params) noexcept;
	GcmParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param iv
	/// @param ivLength
	/// @param ibBits
	/// @param aad
	/// @param aadLength
	/// @param tagBits
	GcmParams(
			const decltype(Parent::pIv) &iv
			, const decltype(Parent::ulIvLen) &ivLength
			, const decltype(Parent::ulIvBits) &ibBits
			, const decltype(Parent::pAAD) &aad
			, const decltype(Parent::ulAADLen) &aadLength
			, const decltype(Parent::ulTagBits) &tagBits
	) noexcept;

	GcmParams &operator=(const GcmParams &params) noexcept;
	GcmParams &operator=(const Parent &params) noexcept;

	using Parent::pIv;
	using Parent::ulIvLen;
	using Parent::ulIvBits;
	using Parent::pAAD;
	using Parent::ulAADLen;
	using Parent::ulTagBits;
};

using GcmParamsPtr = ::CK_GCM_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_PARAMS_HPP
