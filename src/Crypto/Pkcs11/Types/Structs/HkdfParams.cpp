#include <FlameIDE/Crypto/Pkcs11/Types/Structs/HkdfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

HkdfParams::HkdfParams() noexcept
{}

HkdfParams::HkdfParams(const HkdfParams &params) noexcept
{
	operator=(params);
}

HkdfParams::HkdfParams(const Parent &params) noexcept
{
	operator=(params);
}

HkdfParams::HkdfParams(
		const decltype(Parent::bExtract) &extract
		, const decltype(Parent::bExpand) &expand
		, const decltype(Parent::prfHashMechanism) &prfHashMechanism
		, const decltype(Parent::ulSaltType) &saltType
		, const decltype(Parent::pSalt) &salt
		, const decltype(Parent::ulSaltLen) &saltLength
		, const decltype(Parent::hSaltKey) &saltKey
		, const decltype(Parent::pInfo) &info
		, const decltype(Parent::ulInfoLen) &infoLength
) noexcept
{
	bExtract = extract;
	bExpand = expand;
	this->prfHashMechanism = prfHashMechanism;
	ulSaltType = saltType;
	pSalt = salt;
	ulSaltLen = saltLength;
	hSaltKey = saltKey;
	pInfo = info;
	ulInfoLen = infoLength;
}

HkdfParams &HkdfParams::operator=(const HkdfParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

HkdfParams &HkdfParams::operator=(const Parent &params) noexcept
{
	bExtract = params.bExtract;
	bExpand = params.bExpand;
	prfHashMechanism = params.prfHashMechanism;
	ulSaltType = params.ulSaltType;
	pSalt = params.pSalt;
	ulSaltLen = params.ulSaltLen;
	hSaltKey = params.hSaltKey;
	pInfo = params.pInfo;
	ulInfoLen = params.ulInfoLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
