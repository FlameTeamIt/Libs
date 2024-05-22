#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaPkcsOaepParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

RsaPkcsOaepParams::RsaPkcsOaepParams() noexcept
		: RsaPkcsOaepParams(Parent{})
{}

RsaPkcsOaepParams::RsaPkcsOaepParams(const RsaPkcsOaepParams &params) noexcept
		: RsaPkcsOaepParams(static_cast<const Parent &>(params))
{}

RsaPkcsOaepParams::RsaPkcsOaepParams(const Parent &params) noexcept
{
	operator=(params);
}

RsaPkcsOaepParams::RsaPkcsOaepParams(
		const decltype(Parent::hashAlg) &hashAlg
		, const decltype(Parent::mgf) &mgf
		, const decltype(Parent::source) &source
		, const decltype(Parent::pSourceData) &sourceData
		, const decltype(Parent::ulSourceDataLen) &sourceDataLength
) noexcept
{
	this->hashAlg = hashAlg;
	this->mgf = mgf;
	this->source = source;
	this->pSourceData = sourceData;
	this->ulSourceDataLen = sourceDataLength;
}

RsaPkcsOaepParams &RsaPkcsOaepParams::operator=(const RsaPkcsOaepParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

RsaPkcsOaepParams &RsaPkcsOaepParams::operator=(const Parent &params) noexcept
{
	hashAlg = params.hashAlg;
	mgf = params.mgf;
	source = params.source;
	pSourceData = params.pSourceData;
	ulSourceDataLen = params.ulSourceDataLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
