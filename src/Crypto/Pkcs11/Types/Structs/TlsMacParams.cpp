#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsMacParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

TlsMacParams::TlsMacParams() noexcept
{}

TlsMacParams::TlsMacParams(const TlsMacParams &params) noexcept
{
	operator=(params);
}

TlsMacParams::TlsMacParams(const Parent &params) noexcept
{
	operator=(params);
}

TlsMacParams::TlsMacParams(
		const decltype(Parent::prfHashMechanism) &prfHashMechanism
		, const decltype(Parent::ulMacLength) &macLength
		, const decltype(Parent::ulServerOrClient) &serverOrClient
) noexcept
{
	this->prfHashMechanism = prfHashMechanism;
	ulMacLength = macLength;
	ulServerOrClient = serverOrClient;
}

TlsMacParams &TlsMacParams::operator=(const TlsMacParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

TlsMacParams &TlsMacParams::operator=(const Parent &params) noexcept
{
	prfHashMechanism = params.prfHashMechanism;
	ulMacLength = params.ulMacLength;
	ulServerOrClient = params.ulServerOrClient;

	return *this;
}

//
//
//

}}} // flame_ide::pkcs11::structs
