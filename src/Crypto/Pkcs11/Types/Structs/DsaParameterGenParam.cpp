#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DsaParameterGenParam.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

DsaParameterGenParam::DsaParameterGenParam() noexcept
{}

DsaParameterGenParam::DsaParameterGenParam(const DsaParameterGenParam &params) noexcept
{
	operator=(params);
}

DsaParameterGenParam::DsaParameterGenParam(const Parent &params) noexcept
{
	operator=(params);
}

DsaParameterGenParam::DsaParameterGenParam(
		const decltype(Parent::hash) &hash
		, const decltype(Parent::pSeed) &seed
		, const decltype(Parent::ulSeedLen) &seedLength
		, const decltype(Parent::ulIndex) &index
) noexcept
{
	this->hash = hash;
	pSeed = seed;
	ulSeedLen = seedLength;
	ulIndex = index;
}

DsaParameterGenParam &DsaParameterGenParam::operator=(
		const DsaParameterGenParam &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

DsaParameterGenParam &DsaParameterGenParam::operator=(const Parent &params) noexcept
{
	hash = params.hash;
	pSeed = params.pSeed;
	ulSeedLen = params.ulSeedLen;
	ulIndex = params.ulIndex;

	return *this;
}

}}} // flame_ide::pkcs11::structs
