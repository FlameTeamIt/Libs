#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Pkcs5Pbkd2Params2.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Pkcs5Pbkd2Params2::Pkcs5Pbkd2Params2() noexcept
{}

Pkcs5Pbkd2Params2::Pkcs5Pbkd2Params2(const Pkcs5Pbkd2Params2 &params) noexcept
{
	operator=(params);
}

Pkcs5Pbkd2Params2::Pkcs5Pbkd2Params2(const Parent &params) noexcept
{
	operator=(params);
}

Pkcs5Pbkd2Params2::Pkcs5Pbkd2Params2(
		const decltype(Parent::saltSource) &saltSource
		, const decltype(Parent::pSaltSourceData) &saltSourceData
		, const decltype(Parent::ulSaltSourceDataLen) &saltSourceDataLength
		, const decltype(Parent::iterations) &iterations
		, const decltype(Parent::prf) &prf
		, const decltype(Parent::pPrfData) &prfData
		, const decltype(Parent::ulPrfDataLen) &prfDataLength
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
	ulPrfDataLen = prfDataLength;
	pPassword = password;
	ulPasswordLen = passwordLength;
}

Pkcs5Pbkd2Params2 &Pkcs5Pbkd2Params2::operator=(const Pkcs5Pbkd2Params2 &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Pkcs5Pbkd2Params2 &Pkcs5Pbkd2Params2::operator=(const Parent &params) noexcept
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
