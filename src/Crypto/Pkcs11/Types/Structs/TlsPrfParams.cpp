#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsPrfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

TlsPrfParams::TlsPrfParams() noexcept
{}

TlsPrfParams::TlsPrfParams(const TlsPrfParams &params) noexcept
{
	operator=(params);
}

TlsPrfParams::TlsPrfParams(const Parent &params) noexcept
{
	operator=(params);
}

TlsPrfParams::TlsPrfParams(
		const decltype(Parent::pSeed) &seed
		, const decltype(Parent::ulSeedLen) &seedLength
		, const decltype(Parent::pLabel) &label
		, const decltype(Parent::ulLabelLen) &labelLength
		, const decltype(Parent::pOutput) &output
		, const decltype(Parent::pulOutputLen) &outputLength
) noexcept
{
	pSeed = seed;
	ulSeedLen = seedLength;
	pLabel = label;
	ulLabelLen = labelLength;
	pOutput = output;
	pulOutputLen = outputLength;
}

TlsPrfParams &TlsPrfParams::operator=(const TlsPrfParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

TlsPrfParams &TlsPrfParams::operator=(const Parent &params) noexcept
{
	pSeed = params.pSeed;
	ulSeedLen = params.ulSeedLen;
	pLabel = params.pLabel;
	ulLabelLen = params.ulLabelLen;
	pOutput = params.pOutput;
	pulOutputLen = params.pulOutputLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
