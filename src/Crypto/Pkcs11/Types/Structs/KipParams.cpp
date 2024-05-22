#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KipParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

KipParams::KipParams() noexcept
{}

KipParams::KipParams(const KipParams &params) noexcept
{
	operator=(params);
}

KipParams::KipParams(const Parent &params) noexcept
{
	operator=(params);
}

KipParams::KipParams(
		const decltype(Parent::pMechanism) &mechanism
		, const decltype(Parent::hKey) &key
		, const decltype(Parent::pSeed) &seed
		, const decltype(Parent::ulSeedLen) &seedLength
) noexcept
{
	pMechanism = mechanism;
	hKey = key;
	pSeed = seed;
	ulSeedLen = seedLength;
}

KipParams &KipParams::operator=(const KipParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

KipParams &KipParams::operator=(const Parent &params) noexcept
{
	pMechanism = params.pMechanism;
	hKey = params.hKey;
	pSeed = params.pSeed;
	ulSeedLen = params.ulSeedLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
