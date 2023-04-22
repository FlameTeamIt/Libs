#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

OtpParams::OtpParams() noexcept
{}

OtpParams::OtpParams(const OtpParams &params) noexcept
{
	operator=(params);
}

OtpParams::OtpParams(const Parent &params) noexcept
{
	operator=(params);
}

OtpParams::OtpParams(
		const decltype(Parent::pParams) &params
		, const decltype(Parent::ulCount) &count
) noexcept
{
	pParams = params;
	ulCount = count;
}

OtpParams &OtpParams::operator=(const OtpParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

OtpParams &OtpParams::operator=(const Parent &params) noexcept
{
	pParams = params.pParams;
	ulCount = params.ulCount;

	return *this;
}

}}} // flame_ide::pkcs11::structs
