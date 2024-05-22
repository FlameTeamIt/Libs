#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CcmParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

CcmParams::CcmParams() noexcept
{}

CcmParams::CcmParams(const CcmParams &params) noexcept
{
	operator=(params);
}

CcmParams::CcmParams(const Parent &params) noexcept
{
	operator=(params);
}

CcmParams::CcmParams(
		const decltype(Parent::ulDataLen) &dataLength
		, const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceLen) &nonceLength
		, const decltype(Parent::pAAD) &aad
		, const decltype(Parent::ulAADLen) &aadLength
		, const decltype(Parent::ulMACLen) &macLength
) noexcept
{
	ulDataLen = dataLength;
	pNonce = nonce;
	ulNonceLen = nonceLength;
	pAAD = aad;
	ulAADLen = aadLength;
	ulMACLen = macLength;
}

CcmParams &CcmParams::operator=(const CcmParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

CcmParams &CcmParams::operator=(const Parent &params) noexcept
{
	ulDataLen = params.ulDataLen;
	pNonce = params.pNonce;
	ulNonceLen = params.ulNonceLen;
	pAAD = params.pAAD;
	ulAADLen = params.ulAADLen;
	ulMACLen = params.ulMACLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
