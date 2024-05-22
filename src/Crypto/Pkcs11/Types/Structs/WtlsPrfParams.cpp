#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsPrfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

WtlsPrfParams::WtlsPrfParams() noexcept
{}

WtlsPrfParams::WtlsPrfParams(const WtlsPrfParams &params) noexcept
{
	operator=(params);
}

WtlsPrfParams::WtlsPrfParams(const Parent &params) noexcept
{
	operator=(params);
}

WtlsPrfParams::WtlsPrfParams(
		const decltype(Parent::DigestMechanism) &digestMechanism
		, const decltype(Parent::pSeed) &seed
		, const decltype(Parent::ulSeedLen) &seedLength
		, const decltype(Parent::pLabel) &label
		, const decltype(Parent::ulLabelLen) &labelLength
		, const decltype(Parent::pOutput) &output
		, const decltype(Parent::pulOutputLen) &outputLength
) noexcept
{
	DigestMechanism = digestMechanism;
	pSeed = seed;
	ulSeedLen = seedLength;
	pLabel = label;
	ulLabelLen = labelLength;
	pOutput = output;
	pulOutputLen = outputLength;
}

WtlsPrfParams &WtlsPrfParams::operator=(const WtlsPrfParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

WtlsPrfParams &WtlsPrfParams::operator=(const Parent &params) noexcept
{
	DigestMechanism = params.DigestMechanism;
	pSeed = params.pSeed;
	ulSeedLen = params.ulSeedLen;
	pLabel = params.pLabel;
	ulLabelLen = params.ulLabelLen;
	pOutput = params.pOutput;
	pulOutputLen = params.pulOutputLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
