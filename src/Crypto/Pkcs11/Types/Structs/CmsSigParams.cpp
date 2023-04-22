#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CmsSigParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

CmsSigParams::CmsSigParams() noexcept
{}

CmsSigParams::CmsSigParams(const CmsSigParams &params) noexcept
{
	operator=(params);
}

CmsSigParams::CmsSigParams(const Parent &params) noexcept
{
	operator=(params);
}

CmsSigParams::CmsSigParams(
		const decltype(Parent::certificateHandle) &certificateHandle
		, const decltype(Parent::pSigningMechanism) &signingMechanism
		, const decltype(Parent::pDigestMechanism) &digestMechanism
		, const decltype(Parent::pContentType) &contentType
		, const decltype(Parent::pRequestedAttributes) &requestedAttributes
		, const decltype(Parent::ulRequestedAttributesLen) &requestedAttributesLength
		, const decltype(Parent::pRequiredAttributes) &requiredAttributes
		, const decltype(Parent::ulRequiredAttributesLen) &requiredAttributesLength
) noexcept
{
	this->certificateHandle = certificateHandle;
	pSigningMechanism = signingMechanism;
	pDigestMechanism = digestMechanism;
	pContentType = contentType;
	pRequestedAttributes = requestedAttributes;
	ulRequestedAttributesLen = requestedAttributesLength;
	pRequiredAttributes = requiredAttributes;
	ulRequiredAttributesLen = requiredAttributesLength;
}

CmsSigParams &CmsSigParams::operator=(const CmsSigParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

CmsSigParams &CmsSigParams::operator=(const Parent &params) noexcept
{
	certificateHandle = params.certificateHandle;
	pSigningMechanism = params.pSigningMechanism;
	pDigestMechanism = params.pDigestMechanism;
	pContentType = params.pContentType;
	pRequestedAttributes = params.pRequestedAttributes;
	ulRequestedAttributesLen = params.ulRequestedAttributesLen;
	pRequiredAttributes = params.pRequiredAttributes;
	ulRequiredAttributesLen = params.ulRequiredAttributesLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
