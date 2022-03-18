#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaPkcsPssParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

RsaPkcsPssParams::RsaPkcsPssParams() noexcept
		: RsaPkcsPssParams(Parent{})
{}

RsaPkcsPssParams::RsaPkcsPssParams(const RsaPkcsPssParams &params) noexcept
		: RsaPkcsPssParams(static_cast<const Parent &>(params))
{}

RsaPkcsPssParams::RsaPkcsPssParams(const Parent &params) noexcept
{
	operator=(params);
}

RsaPkcsPssParams::RsaPkcsPssParams(
		const decltype(Parent::hashAlg) &hashAlg
		, const decltype(Parent::mgf) &mgf
		, const decltype(Parent::sLen) &length
) noexcept
{
	this->hashAlg = hashAlg;
	this->mgf = mgf;
	this->sLen = length;
}

RsaPkcsPssParams &RsaPkcsPssParams::operator=(const RsaPkcsPssParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

RsaPkcsPssParams &RsaPkcsPssParams::operator=(const Parent &params) noexcept
{
	hashAlg = params.hashAlg;
	mgf = params.mgf;
	sLen = params.sLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
