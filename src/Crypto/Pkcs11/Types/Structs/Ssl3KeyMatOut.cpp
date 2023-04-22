#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3KeyMatOut.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Ssl3KeyMatOut::Ssl3KeyMatOut() noexcept
{}

Ssl3KeyMatOut::Ssl3KeyMatOut(const Ssl3KeyMatOut &params) noexcept
{
	operator=(params);
}

Ssl3KeyMatOut::Ssl3KeyMatOut(const Parent &params) noexcept
{
	operator=(params);
}

Ssl3KeyMatOut::Ssl3KeyMatOut(
		const decltype(Parent::hClientMacSecret) &clientMacSecret
		, const decltype(Parent::hServerMacSecret) &serverMacSecret
		, const decltype(Parent::hClientKey) &clientKey
		, const decltype(Parent::hServerKey) &serverKey
		, const decltype(Parent::pIVClient) &ivClient
		, const decltype(Parent::pIVServer) &ivServer
) noexcept
{
	hClientMacSecret = clientMacSecret;
	hServerMacSecret = serverMacSecret;
	hClientKey = clientKey;
	hServerKey = serverKey;
	pIVClient = ivClient;
	pIVServer = ivServer;
}

Ssl3KeyMatOut &Ssl3KeyMatOut::operator=(const Ssl3KeyMatOut &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Ssl3KeyMatOut &Ssl3KeyMatOut::operator=(const Parent &params) noexcept
{
	hClientMacSecret = params.hClientMacSecret;
	hServerMacSecret = params.hServerMacSecret;
	hClientKey = params.hClientKey;
	hServerKey = params.hServerKey;
	pIVClient = params.pIVClient;
	pIVServer = params.pIVServer;

	return *this;
}

}}} // flame_ide::pkcs11::structs
