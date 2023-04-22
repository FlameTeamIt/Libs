#include <FlameIDE/Crypto/Pkcs11/Types/Structs/PbeParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

PbeParams::PbeParams() noexcept
{}

PbeParams::PbeParams(const PbeParams &params) noexcept
{
	operator=(params);
}

PbeParams::PbeParams(const Parent &params) noexcept
{
	operator=(params);
}

PbeParams::PbeParams(
		const decltype(Parent::pInitVector) &initVector
		, const decltype(Parent::pPassword) &password
		, const decltype(Parent::ulPasswordLen) &passwordLength
		, const decltype(Parent::pSalt) &salt
		, const decltype(Parent::ulSaltLen) &saltLength
		, const decltype(Parent::ulIteration) &iteration
) noexcept
{
	pInitVector = initVector;
	pPassword = password;
	ulPasswordLen = passwordLength;
	pSalt = salt;
	ulSaltLen = saltLength;
	ulIteration = iteration;
}

PbeParams &PbeParams::operator=(const PbeParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

PbeParams &PbeParams::operator=(const Parent &params) noexcept
{
	pInitVector = params.pInitVector;
	pPassword = params.pPassword;
	ulPasswordLen = params.ulPasswordLen;
	pSalt = params.pSalt;
	ulSaltLen = params.ulSaltLen;
	ulIteration = params.ulIteration;

	return *this;
}

}}} // flame_ide::pkcs11::structs
