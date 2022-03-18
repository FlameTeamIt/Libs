#include <FlameIDE/Crypto/Pkcs11/Types/Structs/X9dot42DiffieHellman1DeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

X9dot42DiffieHellman1DeriveParams::X9dot42DiffieHellman1DeriveParams() noexcept
{}

X9dot42DiffieHellman1DeriveParams::X9dot42DiffieHellman1DeriveParams(
		const X9dot42DiffieHellman1DeriveParams &params
) noexcept
		: X9dot42DiffieHellman1DeriveParams(static_cast<const Parent &>(params))
{}

X9dot42DiffieHellman1DeriveParams::X9dot42DiffieHellman1DeriveParams(
		const Parent &params
) noexcept
{
	operator=(params);
}

X9dot42DiffieHellman1DeriveParams::X9dot42DiffieHellman1DeriveParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulOtherInfoLen) &otherInfoLength
		, const decltype(Parent::pOtherInfo) &otherInfo
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
) noexcept
{
	this->kdf = kdf;
	this->ulOtherInfoLen = otherInfoLength;
	this->pOtherInfo = otherInfo;
	this->ulPublicDataLen = publicDataLength;
	this->pPublicData = publicData;
}

X9dot42DiffieHellman1DeriveParams &X9dot42DiffieHellman1DeriveParams::operator=(
		const X9dot42DiffieHellman1DeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

X9dot42DiffieHellman1DeriveParams &X9dot42DiffieHellman1DeriveParams::operator=(
		const Parent &params
) noexcept
{
	kdf = params.kdf;
	ulOtherInfoLen = params.ulOtherInfoLen;
	pOtherInfo = params.pOtherInfo;
	ulPublicDataLen = params.ulPublicDataLen;
	pPublicData = params.pPublicData;
	return *this;
}

}}} // flame_ide::pkcs11::structs
