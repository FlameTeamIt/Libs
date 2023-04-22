#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DoubleRatchetInitializeParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

DoubleRatchetInitializeParams::DoubleRatchetInitializeParams() noexcept
{}

DoubleRatchetInitializeParams::DoubleRatchetInitializeParams(
		const DoubleRatchetInitializeParams &params
) noexcept
{
	operator=(params);
}

DoubleRatchetInitializeParams::DoubleRatchetInitializeParams(const Parent &params) noexcept
{
	operator=(params);
}

DoubleRatchetInitializeParams::DoubleRatchetInitializeParams(
		const decltype(Parent::sk) &sk
		, const decltype(Parent::peer_public_prekey) &peerPublicPrekey
		, const decltype(Parent::peer_public_identity) &peerPublicIdentity
		, const decltype(Parent::own_public_identity) &ownPublicIdentity
		, const decltype(Parent::bEncryptedHeader) &encryptedHeader
		, const decltype(Parent::eCurve) &curve
		, const decltype(Parent::aeadMechanism) &aeadMechanism
		, const decltype(Parent::kdfMechanism) &kdfMechanism
) noexcept
{
	this->sk = sk;
	peer_public_prekey = peerPublicPrekey;
	peer_public_identity = peerPublicIdentity;
	own_public_identity = ownPublicIdentity;
	bEncryptedHeader = encryptedHeader;
	eCurve = curve;
	this->aeadMechanism = aeadMechanism;
	this->kdfMechanism = kdfMechanism;
}

DoubleRatchetInitializeParams &DoubleRatchetInitializeParams::operator=(
		const DoubleRatchetInitializeParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

DoubleRatchetInitializeParams &DoubleRatchetInitializeParams::operator=(
		const Parent &params
) noexcept
{
	sk = params.sk;
	peer_public_prekey = params.peer_public_prekey;
	peer_public_identity = params.peer_public_identity;
	own_public_identity = params.own_public_identity;
	bEncryptedHeader = params.bEncryptedHeader;
	eCurve = params.eCurve;
	aeadMechanism = params.aeadMechanism;
	kdfMechanism = params.kdfMechanism;

	return *this;
}

}}} // flame_ide::pkcs11::structs
