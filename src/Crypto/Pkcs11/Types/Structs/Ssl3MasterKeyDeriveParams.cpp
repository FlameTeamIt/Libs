#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3MasterKeyDeriveParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Ssl3MasterKeyDeriveParams::Ssl3MasterKeyDeriveParams() noexcept
{}

Ssl3MasterKeyDeriveParams::Ssl3MasterKeyDeriveParams(const Ssl3MasterKeyDeriveParams &params) noexcept
{
	operator=(params);
}

Ssl3MasterKeyDeriveParams::Ssl3MasterKeyDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

Ssl3MasterKeyDeriveParams::Ssl3MasterKeyDeriveParams(
		const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pVersion) &version
) noexcept
{
	RandomInfo = randomInfo;
	pVersion = version;
}

Ssl3MasterKeyDeriveParams &Ssl3MasterKeyDeriveParams::operator=(
		const Ssl3MasterKeyDeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Ssl3MasterKeyDeriveParams &Ssl3MasterKeyDeriveParams::operator=(
		const Parent &params
) noexcept
{
	RandomInfo = params.RandomInfo;
	pVersion = params.pVersion;

	return *this;
}

}}} // flame_ide::pkcs11::structs
