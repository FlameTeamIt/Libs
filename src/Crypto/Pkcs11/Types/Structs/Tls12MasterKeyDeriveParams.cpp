#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Tls12MasterKeyDeriveParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Tls12MasterKeyDeriveParams::Tls12MasterKeyDeriveParams() noexcept
{}

Tls12MasterKeyDeriveParams::Tls12MasterKeyDeriveParams(
		const Tls12MasterKeyDeriveParams &params
) noexcept
{
	operator=(params);
}

Tls12MasterKeyDeriveParams::Tls12MasterKeyDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

Tls12MasterKeyDeriveParams::Tls12MasterKeyDeriveParams(
		const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pVersion) &version
		, const decltype(Parent::prfHashMechanism) &prfHashMechanism
) noexcept
{
	RandomInfo = randomInfo;
	pVersion = version;
	this->prfHashMechanism = prfHashMechanism;
}

Tls12MasterKeyDeriveParams &Tls12MasterKeyDeriveParams::operator=(
		const Tls12MasterKeyDeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Tls12MasterKeyDeriveParams &Tls12MasterKeyDeriveParams::operator=(
		const Parent &params
) noexcept
{
	RandomInfo = params.RandomInfo;
	pVersion = params.pVersion;
	prfHashMechanism = params.prfHashMechanism;

	return *this;
}

}}} // flame_ide::pkcs11::structs
