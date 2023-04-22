#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeaDeriveParams.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

KeaDeriveParams::KeaDeriveParams() noexcept
{}

KeaDeriveParams::KeaDeriveParams(const KeaDeriveParams &params) noexcept
		: KeaDeriveParams(static_cast<const Parent &>(params))
{}

KeaDeriveParams::KeaDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

KeaDeriveParams::KeaDeriveParams(
		const decltype(Parent::isSender) &isSender
		, const decltype(Parent::ulRandomLen) &randomLength
		, const decltype(Parent::pRandomA) &randomA
		, const decltype(Parent::pRandomB) &randomB
		, const decltype(Parent::ulPublicDataLen) &publicDataLength
		, const decltype(Parent::pPublicData) &publicData
) noexcept
{
	this->isSender = isSender;
	this->ulRandomLen = randomLength;
	this->pRandomA = randomA;
	this->pRandomB = randomB;
	this->ulPublicDataLen = publicDataLength;
	this->pPublicData = publicData;
}

KeaDeriveParams &KeaDeriveParams::operator=(const KeaDeriveParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

KeaDeriveParams &KeaDeriveParams::operator=(const Parent &params) noexcept
{
	isSender = params.isSender;
	ulRandomLen = params.ulRandomLen;
	pRandomA = params.pRandomA;
	pRandomB = params.pRandomB;
	ulPublicDataLen = params.ulPublicDataLen;
	pPublicData = params.pPublicData;

	return *this;
}

}}} // flame_ide::pkcs11::structs
