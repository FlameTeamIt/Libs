#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedEdDsaParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

ExtendedEdDsaParams::ExtendedEdDsaParams() noexcept
{}

ExtendedEdDsaParams::ExtendedEdDsaParams(const ExtendedEdDsaParams &params) noexcept
{
	operator=(params);
}

ExtendedEdDsaParams::ExtendedEdDsaParams(const Parent &params) noexcept
{
	operator=(params);
}

ExtendedEdDsaParams::ExtendedEdDsaParams(
		const decltype(Parent::hash) &hash
) noexcept
{
	this->hash = hash;
}

ExtendedEdDsaParams &ExtendedEdDsaParams::operator=(const ExtendedEdDsaParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ExtendedEdDsaParams &ExtendedEdDsaParams::operator=(const Parent &params) noexcept
{
	hash = params.hash;

	return *this;
}

}}} // flame_ide::pkcs11::structs
