#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedTripleDiffieHellmanInitiateParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

ExtendedTripleDiffieHellmanInitiateParams::ExtendedTripleDiffieHellmanInitiateParams() noexcept
{}

ExtendedTripleDiffieHellmanInitiateParams::ExtendedTripleDiffieHellmanInitiateParams(
		const ExtendedTripleDiffieHellmanInitiateParams &params
) noexcept
{
	operator=(params);
}

ExtendedTripleDiffieHellmanInitiateParams::ExtendedTripleDiffieHellmanInitiateParams(const Parent &params) noexcept
{
	operator=(params);
}

ExtendedTripleDiffieHellmanInitiateParams::ExtendedTripleDiffieHellmanInitiateParams(
		const decltype(Parent::kdf) &kdf
		, const decltype(Parent::pPeer_identity) &peerIdentity
		, const decltype(Parent::pPeer_prekey) &peerPrekey
		, const decltype(Parent::pPrekey_signature) &prekeySignature
		, const decltype(Parent::pOnetime_key) &onetimeKey
		, const decltype(Parent::pOwn_identity) &ownIdentity
		, const decltype(Parent::pOwn_ephemeral) &ownEphemeral
) noexcept
{
	this->kdf = kdf;
	pPeer_identity = peerIdentity;
	pPeer_prekey = peerPrekey;
	pPrekey_signature = prekeySignature;
	pOnetime_key = onetimeKey;
	pOwn_identity = ownIdentity;
	pOwn_ephemeral = ownEphemeral;
}

ExtendedTripleDiffieHellmanInitiateParams &ExtendedTripleDiffieHellmanInitiateParams::operator=(
		const ExtendedTripleDiffieHellmanInitiateParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ExtendedTripleDiffieHellmanInitiateParams &ExtendedTripleDiffieHellmanInitiateParams::operator=(
		const Parent &params
) noexcept
{
	kdf = params.kdf;
	pPeer_identity = params.pPeer_identity;
	pPeer_prekey = params.pPeer_prekey;
	pPrekey_signature = params.pPrekey_signature;
	pOnetime_key = params.pOnetime_key;
	pOwn_identity = params.pOwn_identity;
	pOwn_ephemeral = params.pOwn_ephemeral;

	return *this;
}

}}} // flame_ide::pkcs11::structs
