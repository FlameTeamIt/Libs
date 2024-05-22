#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedTripleDiffieHellmanRespondParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

ExtendedTripleDiffieHellmanRespondParams::ExtendedTripleDiffieHellmanRespondParams() noexcept
{}

ExtendedTripleDiffieHellmanRespondParams::ExtendedTripleDiffieHellmanRespondParams(
		const ExtendedTripleDiffieHellmanRespondParams &params
) noexcept
{
	operator=(params);
}

ExtendedTripleDiffieHellmanRespondParams::ExtendedTripleDiffieHellmanRespondParams(
		const Parent &params
) noexcept
{
	operator=(params);
}

ExtendedTripleDiffieHellmanRespondParams::ExtendedTripleDiffieHellmanRespondParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::pIdentity_id) &identityId
		, const decltype(Parent::pPrekey_id) &prekeyId
		, const decltype(Parent::pOnetime_id) &onetimeId
		, const decltype(Parent::pInitiator_identity) &initiatorIdentity
		, const decltype(Parent::pInitiator_ephemeral) &initiatorEphemeral
) noexcept
{
	this->kdf = kdf;
	pIdentity_id = identityId;
	pPrekey_id = prekeyId;
	pOnetime_id = onetimeId;
	pInitiator_identity = initiatorIdentity;
	pInitiator_ephemeral = initiatorEphemeral;
}

ExtendedTripleDiffieHellmanRespondParams &ExtendedTripleDiffieHellmanRespondParams::operator=(
		const ExtendedTripleDiffieHellmanRespondParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ExtendedTripleDiffieHellmanRespondParams &ExtendedTripleDiffieHellmanRespondParams::operator=(
		const Parent &params
) noexcept
{
	kdf = params.kdf;
	pIdentity_id = params.pIdentity_id;
	pPrekey_id = params.pPrekey_id;
	pOnetime_id = params.pOnetime_id;
	pInitiator_identity = params.pInitiator_identity;
	pInitiator_ephemeral = params.pInitiator_ephemeral;

	return *this;
}

}}} // flame_ide::pkcs11::structs
