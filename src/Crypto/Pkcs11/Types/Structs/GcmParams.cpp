#include <FlameIDE/Crypto/Pkcs11/Types/Structs/GcmParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

GcmParams::GcmParams() noexcept
{}

GcmParams::GcmParams(const GcmParams &params) noexcept
{
	operator=(params);
}

GcmParams::GcmParams(const Parent &params) noexcept
{
	operator=(params);
}

GcmParams::GcmParams(
		const decltype(Parent::pIv) &iv
		, const decltype(Parent::ulIvLen) &ivLength
		, const decltype(Parent::ulIvBits) &ibBits
		, const decltype(Parent::pAAD) &aad
		, const decltype(Parent::ulAADLen) &aadLength
		, const decltype(Parent::ulTagBits) &tagBits
) noexcept
{
	pIv = iv;
	ulIvLen = ivLength;
	ulIvBits = ibBits;
	pAAD = aad;
	ulAADLen = aadLength;
	ulTagBits = tagBits;
}

GcmParams &GcmParams::operator=(const GcmParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

GcmParams &GcmParams::operator=(const Parent &params) noexcept
{
	pIv = params.pIv;
	ulIvLen = params.ulIvLen;
	ulIvBits = params.ulIvBits;
	pAAD = params.pAAD;
	ulAADLen = params.ulAADLen;
	ulTagBits = params.ulTagBits;

	return *this;
}

}}} // flame_ide::pkcs11::structs
