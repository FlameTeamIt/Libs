#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsKeyMatOut.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

WtlsKeyMatOut::WtlsKeyMatOut() noexcept
{}

WtlsKeyMatOut::WtlsKeyMatOut(const WtlsKeyMatOut &params) noexcept
{
	operator=(params);
}

WtlsKeyMatOut::WtlsKeyMatOut(const Parent &params) noexcept
{
	operator=(params);
}

WtlsKeyMatOut::WtlsKeyMatOut(
		const decltype(Parent::hMacSecret) &macSecret
		, const decltype(Parent::hKey) &key
		, const decltype(Parent::pIV) &iv
) noexcept
{
	hMacSecret = macSecret;
	hKey = key;
	pIV = iv;
}

WtlsKeyMatOut &WtlsKeyMatOut::operator=(const WtlsKeyMatOut &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

WtlsKeyMatOut &WtlsKeyMatOut::operator=(const Parent &params) noexcept
{
	hMacSecret = params.hMacSecret;
	hKey = params.hKey;
	pIV = params.pIV;

	return *this;
}

}}} // flame_ide::pkcs11::structs
