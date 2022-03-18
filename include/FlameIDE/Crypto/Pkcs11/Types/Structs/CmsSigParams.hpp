#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CMS_SIG_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CMS_SIG_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct CmsSigParams: public WithParent<::CK_CMS_SIG_PARAMS>
{
	CmsSigParams() noexcept;

	CmsSigParams(const CmsSigParams &params) noexcept;
	CmsSigParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param certificateHandle
	/// @param signingMechanism
	/// @param digestMechanism
	/// @param contentType
	/// @param requestedAttributes
	/// @param requestedAttributesLength
	/// @param requiredAttributes
	/// @param requiredAttributesLength
	CmsSigParams(
			const decltype(Parent::certificateHandle) &certificateHandle
			, const decltype(Parent::pSigningMechanism) &signingMechanism
			, const decltype(Parent::pDigestMechanism) &digestMechanism
			, const decltype(Parent::pContentType) &contentType
			, const decltype(Parent::pRequestedAttributes) &requestedAttributes
			, const decltype(Parent::ulRequestedAttributesLen) &requestedAttributesLength
			, const decltype(Parent::pRequiredAttributes) &requiredAttributes
			, const decltype(Parent::ulRequiredAttributesLen) &requiredAttributesLength
	) noexcept;

	CmsSigParams &operator=(const CmsSigParams &params) noexcept;
	CmsSigParams &operator=(const Parent &params) noexcept;

	using Parent::certificateHandle;
	using Parent::pSigningMechanism;
	using Parent::pDigestMechanism;
	using Parent::pContentType;
	using Parent::pRequestedAttributes;
	using Parent::ulRequestedAttributesLen;
	using Parent::pRequiredAttributes;
	using Parent::ulRequiredAttributesLen;
};

using CmsSigParamsPtr = ::CK_CMS_SIG_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CMS_SIG_PARAMS_HPP
