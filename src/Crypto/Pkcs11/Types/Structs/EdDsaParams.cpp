#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EdDsaParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

EdDsaParams::EdDsaParams() noexcept
{}

EdDsaParams::EdDsaParams(const EdDsaParams &params) noexcept
{
	operator=(params);
}

EdDsaParams::EdDsaParams(const Parent &params) noexcept
{
	operator=(params);
}

EdDsaParams::EdDsaParams(
		const decltype(Parent::phFlag) &flag
		, const decltype(Parent::ulContextDataLen) &contextDataLength
		, const decltype(Parent::pContextData) &contextData
) noexcept
{
	phFlag = flag;
	ulContextDataLen = contextDataLength;
	pContextData = contextData;
}

EdDsaParams &EdDsaParams::operator=(const EdDsaParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

EdDsaParams &EdDsaParams::operator=(const Parent &params) noexcept
{
	phFlag = params.phFlag;
	ulContextDataLen = params.ulContextDataLen;
	pContextData = params.pContextData;

	return *this;
}


}}} // flame_ide::pkcs11::structs
