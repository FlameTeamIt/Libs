#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DoubleRatchetRespondParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

DoubleRatchetRespondParams::DoubleRatchetRespondParams() noexcept
{}

DoubleRatchetRespondParams::DoubleRatchetRespondParams(
		const DoubleRatchetRespondParams &params
) noexcept
{
	operator=(params);
}

DoubleRatchetRespondParams::DoubleRatchetRespondParams(const Parent &params) noexcept
{
	operator=(params);
}

DoubleRatchetRespondParams::DoubleRatchetRespondParams(
		const decltype(Parent::sk) &sk
		, const decltype(Parent::own_prekey) &ownPrekey
		, const decltype(Parent::initiator_identity) &initiatorIdentity
		, const decltype(Parent::own_public_identity) &ownPublicIdentity
		, const decltype(Parent::bEncryptedHeader) &encryptedHeader
		, const decltype(Parent::eCurve) &curve
		, const decltype(Parent::aeadMechanism) &aeadMechanism
		, const decltype(Parent::kdfMechanism) &kdfMechanism
) noexcept
{
	this->sk = sk;
	own_prekey = ownPrekey;
	initiator_identity = initiatorIdentity;
	own_public_identity = ownPublicIdentity;
	bEncryptedHeader = encryptedHeader;
	eCurve = curve;
	this->aeadMechanism = aeadMechanism;
	this->kdfMechanism = kdfMechanism;
}

DoubleRatchetRespondParams &DoubleRatchetRespondParams::operator=(
		const DoubleRatchetRespondParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

DoubleRatchetRespondParams &DoubleRatchetRespondParams::operator=(const Parent &params) noexcept
{
	sk = params.sk;
	own_prekey = params.own_prekey;
	initiator_identity = params.initiator_identity;
	own_public_identity = params.own_public_identity;
	bEncryptedHeader = params.bEncryptedHeader;
	eCurve = params.eCurve;
	aeadMechanism = params.aeadMechanism;
	kdfMechanism = params.kdfMechanism;

	return *this;
}


}}} // flame_ide::pkcs11::structs
