#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3RandomData.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Ssl3RandomData::Ssl3RandomData() noexcept
{}

Ssl3RandomData::Ssl3RandomData(const Ssl3RandomData &params) noexcept
{
	operator=(params);
}

Ssl3RandomData::Ssl3RandomData(const Parent &params) noexcept
{
	operator=(params);
}

Ssl3RandomData::Ssl3RandomData(
		const decltype(Parent::ulServerRandomLen) &serverRandomLength
		, const decltype(Parent::pServerRandom) &serverRandom
		, const decltype(Parent::ulClientRandomLen) &clientRandomLength
		, const decltype(Parent::pClientRandom) &clientRandom
) noexcept
{
	ulServerRandomLen = serverRandomLength;
	pServerRandom = serverRandom;
	ulClientRandomLen = clientRandomLength;
	pClientRandom = clientRandom;
}

Ssl3RandomData &Ssl3RandomData::operator=(const Ssl3RandomData &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Ssl3RandomData &Ssl3RandomData::operator=(const Parent &params) noexcept
{
	pClientRandom = params.pClientRandom;
	ulClientRandomLen = params.ulClientRandomLen;
	pServerRandom = params.pServerRandom;
	ulServerRandomLen = params.ulServerRandomLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
