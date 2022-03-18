#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeyDerivationStringData.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

KeyDerivationStringData::KeyDerivationStringData() noexcept
{}

KeyDerivationStringData::KeyDerivationStringData(
		const KeyDerivationStringData &params
) noexcept
{
	operator=(params);
}

KeyDerivationStringData::KeyDerivationStringData(const Parent &params) noexcept
{
	operator=(params);
}

KeyDerivationStringData::KeyDerivationStringData(
		const decltype(Parent::pData) &data
		, const decltype(Parent::ulLen) &length
) noexcept
{
	pData = data;
	ulLen = length;
}

KeyDerivationStringData &KeyDerivationStringData::operator=(
		const KeyDerivationStringData &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

KeyDerivationStringData &KeyDerivationStringData::operator=(const Parent &params) noexcept
{
	pData = params.pData;
	ulLen = params.ulLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
