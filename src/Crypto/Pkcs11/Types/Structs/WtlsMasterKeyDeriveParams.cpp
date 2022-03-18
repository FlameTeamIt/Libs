#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsMasterKeyDeriveParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

WtlsMasterKeyDeriveParams::WtlsMasterKeyDeriveParams() noexcept
{}

WtlsMasterKeyDeriveParams::WtlsMasterKeyDeriveParams(
		const WtlsMasterKeyDeriveParams &params
) noexcept
{
	operator=(params);
}

WtlsMasterKeyDeriveParams::WtlsMasterKeyDeriveParams(const Parent &params) noexcept
{
	operator=(params);
}

/// @brief Constructor
/// @param digestMechanism
/// @param randomInfo
/// @param version
WtlsMasterKeyDeriveParams::WtlsMasterKeyDeriveParams(
		const decltype(Parent::DigestMechanism) &digestMechanism
		, const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pVersion) &version
) noexcept
{
	DigestMechanism = digestMechanism;
	RandomInfo = randomInfo;
	pVersion = version;
}

WtlsMasterKeyDeriveParams &WtlsMasterKeyDeriveParams::operator=(
		const WtlsMasterKeyDeriveParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

WtlsMasterKeyDeriveParams &WtlsMasterKeyDeriveParams::operator=(
		const Parent &params
) noexcept
{
	DigestMechanism = params.DigestMechanism;
	RandomInfo = params.RandomInfo;
	pVersion = params.pVersion;

	return *this;
}

}}} // flame_ide::pkcs11::structs
