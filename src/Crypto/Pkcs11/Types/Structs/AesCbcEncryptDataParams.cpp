#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AesCbcEncryptDataParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

AesCbcEncryptDataParams::AesCbcEncryptDataParams() noexcept
{}

AesCbcEncryptDataParams::AesCbcEncryptDataParams(
		const AesCbcEncryptDataParams &params
) noexcept
{
	operator=(params);
}

AesCbcEncryptDataParams::AesCbcEncryptDataParams(const Parent &params) noexcept
{
	operator=(params);
}

AesCbcEncryptDataParams::AesCbcEncryptDataParams(
		const decltype(Parent::iv) &iv
		, const decltype(Parent::pData) &data
		, const decltype(Parent::length) &dataLength
) noexcept
{
	copy(this->iv, iv);
	pData = data;
	length = dataLength;
}

AesCbcEncryptDataParams &AesCbcEncryptDataParams::operator=(
		const AesCbcEncryptDataParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

AesCbcEncryptDataParams &AesCbcEncryptDataParams::operator=(const Parent &params) noexcept
{
	copy(iv, params.iv);
	pData = params.pData;
	length = params.length;

	return *this;
}

}}} // flame_ide::pkcs11::structs
