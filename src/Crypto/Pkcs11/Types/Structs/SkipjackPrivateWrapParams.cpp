#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SkipjackPrivateWrapParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

SkipjackPrivateWrapParams::SkipjackPrivateWrapParams() noexcept
{}

SkipjackPrivateWrapParams::SkipjackPrivateWrapParams(
		const SkipjackPrivateWrapParams &params
) noexcept
{
	operator=(params);
}

SkipjackPrivateWrapParams::SkipjackPrivateWrapParams(const Parent &params) noexcept
{
	operator=(params);
}

SkipjackPrivateWrapParams::SkipjackPrivateWrapParams(
		const decltype (Parent::ulPasswordLen) &passwordLength
		, const decltype(Parent::pPassword) &password
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
		, const decltype(Parent::ulPAndGLen) &pAndGLength
		, const decltype(Parent::ulQLen) &qLen
		, const decltype(Parent::ulRandomLen) &randomLength
		, const decltype(Parent::pRandomA) &randomA
		, const decltype(Parent::pPrimeP) &primeP
		, const decltype(Parent::pBaseG) &baseG
		, const decltype(Parent::pSubprimeQ) &subprimeQ
) noexcept
{
	ulPasswordLen = passwordLength;
	pPassword = password;
	ulPublicDataLen = publicDataLength;
	pPublicData = publicData;
	ulPAndGLen = pAndGLength;
	ulQLen = qLen;
	ulRandomLen = randomLength;
	pRandomA = randomA;
	pPrimeP = primeP;
	pBaseG = baseG;
	pSubprimeQ = subprimeQ;
}

SkipjackPrivateWrapParams &SkipjackPrivateWrapParams::operator=(
		const SkipjackPrivateWrapParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

SkipjackPrivateWrapParams &SkipjackPrivateWrapParams::operator=(const Parent &params) noexcept
{
	ulPasswordLen = params.ulPasswordLen;
	pPassword = params.pPassword;
	ulPublicDataLen = params.ulPublicDataLen;
	pPublicData = params.pPublicData;
	ulPAndGLen = params.ulPAndGLen;
	ulQLen = params.ulQLen;
	ulRandomLen = params.ulRandomLen;
	pRandomA = params.pRandomA;
	pPrimeP = params.pPrimeP;
	pBaseG = params.pBaseG;
	pSubprimeQ = params.pSubprimeQ;

	return *this;
}

}}} // flame_ide::pkcs11::structs
