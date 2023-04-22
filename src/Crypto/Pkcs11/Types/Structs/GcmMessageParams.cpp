#include <FlameIDE/Crypto/Pkcs11/Types/Structs/GcmMessageParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

GcmMessageParams::GcmMessageParams() noexcept
{}

GcmMessageParams::GcmMessageParams(const GcmMessageParams &params) noexcept
{
	operator=(params);
}

GcmMessageParams::GcmMessageParams(const Parent &params) noexcept
{
	operator=(params);
}

GcmMessageParams::GcmMessageParams(
		const decltype(Parent::pIv) &iv
		, const decltype(Parent::ulIvLen) &ivLength
		, const decltype(Parent::ulIvFixedBits) &ivFixedBits
		, const decltype(Parent::ivGenerator) &ivGenerator
		, const decltype(Parent::pTag) &tag
		, const decltype(Parent::ulTagBits) &tagBits
) noexcept
{
	pIv = iv;
	ulIvLen = ivLength;
	ulIvFixedBits = ivFixedBits;
	this->ivGenerator = ivGenerator;
	pTag = tag;
	ulTagBits = tagBits;
}

GcmMessageParams &GcmMessageParams::operator=(const GcmMessageParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

GcmMessageParams &GcmMessageParams::operator=(const Parent &params) noexcept
{
	pIv = params.pIv;
	ulIvLen = params.ulIvLen;
	ulIvFixedBits = params.ulIvFixedBits;
	ivGenerator = params.ivGenerator;
	pTag = params.pTag;
	ulTagBits = params.ulTagBits;

	return *this;
}

}}} // flame_ide::pkcs11::structs
