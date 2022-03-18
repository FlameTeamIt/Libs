#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CcmMessageParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

CcmMessageParams::CcmMessageParams() noexcept
{}

CcmMessageParams::CcmMessageParams(const CcmMessageParams &params) noexcept
{
	operator=(params);
}

CcmMessageParams::CcmMessageParams(const Parent &params) noexcept
{
	operator=(params);
}

CcmMessageParams::CcmMessageParams(
		const decltype(Parent::ulDataLen) &dataLength
		, const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceLen) &nonceLength
		, const decltype(Parent::ulNonceFixedBits) &nonceFixedBits
		, const decltype(Parent::nonceGenerator) &nonceGenerator
		, const decltype(Parent::pMAC) &mac
		, const decltype(Parent::ulMACLen) &macLength
) noexcept
{
	ulDataLen = dataLength;
	pNonce = nonce;
	ulNonceLen = nonceLength;
	ulNonceFixedBits = nonceFixedBits;
	this->nonceGenerator = nonceGenerator;
	pMAC = mac;
	ulMACLen = macLength;
}

CcmMessageParams &CcmMessageParams::operator=(const CcmMessageParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

CcmMessageParams &CcmMessageParams::operator=(const Parent &params) noexcept
{
	ulDataLen = params.ulDataLen;
	pNonce = params.pNonce;
	ulNonceLen = params.ulNonceLen;
	ulNonceFixedBits = params.ulNonceFixedBits;
	nonceGenerator = params.nonceGenerator;
	pMAC = params.pMAC;
	ulMACLen = params.ulMACLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
