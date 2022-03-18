#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AriaCbcEncryptDataParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

AriaCbcEncryptDataParams::AriaCbcEncryptDataParams() noexcept
{}

AriaCbcEncryptDataParams::AriaCbcEncryptDataParams(
		const AriaCbcEncryptDataParams &params
) noexcept
{
	operator=(params);
}

AriaCbcEncryptDataParams::AriaCbcEncryptDataParams(const Parent &params) noexcept
{
	operator=(params);
}

AriaCbcEncryptDataParams::AriaCbcEncryptDataParams(
		const decltype(Parent::iv) &iv
		, const decltype(Parent::pData) &data
		, const decltype(Parent::length) &dataLength
) noexcept
{
	copy(this->iv, iv);
	pData = data;
	length = dataLength;
}

AriaCbcEncryptDataParams &AriaCbcEncryptDataParams::operator=(const AriaCbcEncryptDataParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

AriaCbcEncryptDataParams &AriaCbcEncryptDataParams::operator=(const Parent &params) noexcept
{
	copy(this->iv, params.iv);
	pData = params.pData;
	length = params.length;

	return *this;
}

}}} // flame_ide::pkcs11::structs
