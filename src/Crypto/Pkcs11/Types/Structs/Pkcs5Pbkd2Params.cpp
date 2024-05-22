#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Pkcs5Pbkd2Params.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Pkcs5Pbkd2Params::Pkcs5Pbkd2Params() noexcept
{}

Pkcs5Pbkd2Params::Pkcs5Pbkd2Params(const Pkcs5Pbkd2Params &params) noexcept
{
	operator=(params);
}

Pkcs5Pbkd2Params::Pkcs5Pbkd2Params(const Parent &params) noexcept
{
	operator=(params);
}

Pkcs5Pbkd2Params::Pkcs5Pbkd2Params(
		const decltype(Parent::saltSource) &saltSource
		, const decltype(Parent::pSaltSourceData) &saltSourceData
		, const decltype(Parent::ulSaltSourceDataLen) &saltSourceDataLength
		, const decltype(Parent::iterations) &iterations
		, const decltype(Parent::prf) &prf
		, const decltype(Parent::pPrfData) &prfData
		, const decltype(Parent::ulPrfDataLen) &prfDataLen
		, const decltype(Parent::pPassword) &password
		, const decltype(Parent::ulPasswordLen) &passwordLength
) noexcept
{
	this->saltSource = saltSource;
	pSaltSourceData = saltSourceData;
	ulSaltSourceDataLen = saltSourceDataLength;
	this->iterations = iterations;
	this->prf = prf;
	pPrfData = prfData;
	ulPrfDataLen = prfDataLen;
	pPassword = password;
	ulPasswordLen = passwordLength;
}

Pkcs5Pbkd2Params &Pkcs5Pbkd2Params::operator=(const Pkcs5Pbkd2Params &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Pkcs5Pbkd2Params &Pkcs5Pbkd2Params::operator=(const Parent &params) noexcept
{
	saltSource = params.saltSource;
	pSaltSourceData = params.pSaltSourceData;
	ulSaltSourceDataLen = params.ulSaltSourceDataLen;
	iterations = params.iterations;
	prf = params.prf;
	pPrfData = params.pPrfData;
	ulPrfDataLen = params.ulPrfDataLen;
	pPassword = params.pPassword;
	ulPasswordLen = params.ulPasswordLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
