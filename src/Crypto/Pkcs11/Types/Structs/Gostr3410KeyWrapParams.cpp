#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Gostr3410KeyWrapParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Gostr3410KeyWrapParams::Gostr3410KeyWrapParams() noexcept
{}

Gostr3410KeyWrapParams::Gostr3410KeyWrapParams(const Gostr3410KeyWrapParams &params) noexcept
{
	operator=(params);
}

Gostr3410KeyWrapParams::Gostr3410KeyWrapParams(const Parent &params) noexcept
{
	operator=(params);
}

Gostr3410KeyWrapParams::Gostr3410KeyWrapParams(
		const decltype(Parent::pWrapOID) &wrapOid
		, const decltype(Parent::ulWrapOIDLen) &wrapOidLength
		, const decltype(Parent::pUKM) &ukm
		, const decltype(Parent::ulUKMLen) &ukmLength
		, const decltype(Parent::hKey) &keyHandle
) noexcept
{
	pWrapOID = wrapOid;
	ulWrapOIDLen = wrapOidLength;
	pUKM = ukm;
	ulUKMLen = ukmLength;
	hKey = keyHandle;
}

Gostr3410KeyWrapParams &Gostr3410KeyWrapParams::operator=(
		const Gostr3410KeyWrapParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Gostr3410KeyWrapParams &Gostr3410KeyWrapParams::operator=(const Parent &params) noexcept
{
	pWrapOID = params.pWrapOID;
	ulWrapOIDLen = params.ulWrapOIDLen;
	pUKM = params.pUKM;
	ulUKMLen = params.ulUKMLen;
	hKey = params.hKey;

	return *this;
}

}}} // flame_ide::pkcs11::structs
