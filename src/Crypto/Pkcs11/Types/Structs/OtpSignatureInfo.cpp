#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpSignatureInfo.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

OtpSignatureInfo::OtpSignatureInfo() noexcept
{}

OtpSignatureInfo::OtpSignatureInfo(const OtpSignatureInfo &params) noexcept
{
	operator=(params);
}

OtpSignatureInfo::OtpSignatureInfo(const Parent &params) noexcept
{
	operator=(params);
}

OtpSignatureInfo::OtpSignatureInfo(
		const decltype(Parent::pParams) &params
		, const decltype(Parent::ulCount) &count
) noexcept
{
	pParams = params;
	ulCount = count;
}

OtpSignatureInfo &OtpSignatureInfo::operator=(const OtpSignatureInfo &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

OtpSignatureInfo &OtpSignatureInfo::operator=(const Parent &params) noexcept
{
	pParams = params.pParams;
	ulCount = params.ulCount;

	return *this;
}

}}} // flame_ide::pkcs11::structs
