#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SeedCbcEncryptDataParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

SeedCbcEncryptDataParams::SeedCbcEncryptDataParams() noexcept
{}

SeedCbcEncryptDataParams::SeedCbcEncryptDataParams(
		const SeedCbcEncryptDataParams &params
) noexcept
{
	operator=(params);
}

SeedCbcEncryptDataParams::SeedCbcEncryptDataParams(const Parent &params) noexcept
{
	operator=(params);
}

SeedCbcEncryptDataParams::SeedCbcEncryptDataParams(
		const decltype(Parent::iv) &iv
		, const decltype(Parent::pData) &data
		, const decltype(Parent::length) &dataLength
) noexcept
{
	copy(this->iv, iv);
	pData = data;
	length = dataLength;
}

SeedCbcEncryptDataParams &SeedCbcEncryptDataParams::operator=(
		const SeedCbcEncryptDataParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

SeedCbcEncryptDataParams &SeedCbcEncryptDataParams::operator=(const Parent &params) noexcept
{
	copy(this->iv, params.iv);
	pData = params.pData;
	length = params.length;

	return *this;
}

}}} // flame_ide::pkcs11::structs
