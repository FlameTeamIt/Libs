#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5CbcParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Rc5CbcParams::Rc5CbcParams() noexcept
{}

Rc5CbcParams::Rc5CbcParams(const Rc5CbcParams &params) noexcept
{
	operator=(params);
}

Rc5CbcParams::Rc5CbcParams(const Parent &params) noexcept
{
	operator=(params);
}

Rc5CbcParams::Rc5CbcParams(
		const decltype(Parent::ulWordsize) &wordSize
		, const decltype(Parent::ulRounds) &rounds
		, const decltype(Parent::pIv) &iv
		, const decltype(Parent::ulIvLen) &ivLength
) noexcept
{
	ulWordsize = wordSize;
	ulRounds = rounds;
	pIv = iv;
	ulIvLen = ivLength;
}

Rc5CbcParams &Rc5CbcParams::operator=(const Rc5CbcParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Rc5CbcParams &Rc5CbcParams::operator=(const Parent &params) noexcept
{
	ulWordsize = params.ulWordsize;
	ulRounds = params.ulRounds;
	pIv = params.pIv;
	ulIvLen = params.ulIvLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
