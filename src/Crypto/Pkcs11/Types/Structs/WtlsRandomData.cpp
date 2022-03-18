#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsRandomData.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

WtlsRandomData::WtlsRandomData() noexcept
{}

WtlsRandomData::WtlsRandomData(const WtlsRandomData &params) noexcept
{
	operator=(params);
}

WtlsRandomData::WtlsRandomData(const Parent &params) noexcept
{
	operator=(params);
}

WtlsRandomData::WtlsRandomData(
		const decltype(Parent::pClientRandom) &clientRandom
		, const decltype(Parent::ulClientRandomLen) &clientRandomLength
		, const decltype(Parent::pServerRandom) &serverRandom
		, const decltype(Parent::ulServerRandomLen) &serverRandomLength
) noexcept
{
	pClientRandom = clientRandom;
	ulClientRandomLen = clientRandomLength;
	pServerRandom = serverRandom;
	ulServerRandomLen = serverRandomLength;
}

WtlsRandomData &WtlsRandomData::operator=(const WtlsRandomData &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

WtlsRandomData &WtlsRandomData::operator=(const Parent &params) noexcept
{
	pClientRandom = params.pClientRandom;
	ulClientRandomLen = params.ulClientRandomLen;
	pServerRandom = params.pServerRandom;
	ulServerRandomLen = params.ulServerRandomLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
