#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcdhAesKeyWrapParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

EcdhAesKeyWrapParams::EcdhAesKeyWrapParams() noexcept
{}

EcdhAesKeyWrapParams::EcdhAesKeyWrapParams(const EcdhAesKeyWrapParams &params) noexcept
{
	operator=(params);
}

EcdhAesKeyWrapParams::EcdhAesKeyWrapParams(const Parent &params) noexcept
{
	operator=(params);
}

EcdhAesKeyWrapParams::EcdhAesKeyWrapParams(
		const decltype(Parent::ulAESKeyBits) &aesKeyBits
		, const decltype(Parent::kdf) &kdf
		, const decltype(Parent::ulSharedDataLen) &sharedDataLength
		, const decltype(Parent::pSharedData) &sharedData
) noexcept
{
	ulAESKeyBits = aesKeyBits;
	this->kdf = kdf;
	ulSharedDataLen = sharedDataLength;
	pSharedData = sharedData;
}

EcdhAesKeyWrapParams &EcdhAesKeyWrapParams::operator=(
		const EcdhAesKeyWrapParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

EcdhAesKeyWrapParams &EcdhAesKeyWrapParams::operator=(const Parent &params) noexcept
{
	ulAESKeyBits = params.ulAESKeyBits;
	kdf = params.kdf;
	ulSharedDataLen = params.ulSharedDataLen;
	pSharedData = params.pSharedData;

	return *this;
}

}}} // flame_ide::pkcs11::structs
