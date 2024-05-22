#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DesCbcEncryptDataParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

DesCbcEncryptDataParams::DesCbcEncryptDataParams() noexcept
{}

DesCbcEncryptDataParams::DesCbcEncryptDataParams(
		const DesCbcEncryptDataParams &params
) noexcept
{
	operator=(params);
}

DesCbcEncryptDataParams::DesCbcEncryptDataParams(const Parent &params) noexcept
{
	operator=(params);
}

DesCbcEncryptDataParams::DesCbcEncryptDataParams(
		const decltype(Parent::iv) &iv
		, const decltype(Parent::pData) &data
		, const decltype(Parent::length) &dataLength
) noexcept
{
	copy(this->iv, iv);
	pData = data;
	length = dataLength;
}

DesCbcEncryptDataParams &DesCbcEncryptDataParams::operator=(
		const DesCbcEncryptDataParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

DesCbcEncryptDataParams &DesCbcEncryptDataParams::operator=(const Parent &params) noexcept
{
	copy(iv, params.iv);
	pData = params.pData;
	length = params.length;

	return *this;
}

}}} // flame_ide::pkcs11::structs
