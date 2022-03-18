#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpParam.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

OtpParam::OtpParam() noexcept
{}

OtpParam::OtpParam(const OtpParam &params) noexcept
{
	operator=(params);
}

OtpParam::OtpParam(const Parent &params) noexcept
{
	operator=(params);
}

OtpParam::OtpParam(
		const decltype(Parent::type) &type
		, const decltype(Parent::pValue) &value
		, const decltype(Parent::ulValueLen) &valueLength
) noexcept
{
	this->type = type;
	pValue = value;
	ulValueLen = valueLength;
}

OtpParam &OtpParam::operator=(const OtpParam &params) noexcept
{
	return operator=(static_cast<const Parent>(params));
}

OtpParam &OtpParam::operator=(const Parent &params) noexcept
{
	type = params.type;
	pValue = params.pValue;
	ulValueLen = params.ulValueLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
