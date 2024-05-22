#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_INITIALIZE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_INITIALIZE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct DoubleRatchetInitializeParams: public WithParent<::CK_X2RATCHET_INITIALIZE_PARAMS>
{
	DoubleRatchetInitializeParams() noexcept;

	DoubleRatchetInitializeParams(const DoubleRatchetInitializeParams &params) noexcept;
	DoubleRatchetInitializeParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param sk
	/// @param peerPublicPrekey
	/// @param peerPublicIdentity
	/// @param ownPublicIdentity
	/// @param encryptedHeader
	/// @param curve
	/// @param aeadMechanism
	/// @param kdfMechanism
	DoubleRatchetInitializeParams(
			const decltype(Parent::sk) &sk
			, const decltype(Parent::peer_public_prekey) &peerPublicPrekey
			, const decltype(Parent::peer_public_identity) &peerPublicIdentity
			, const decltype(Parent::own_public_identity) &ownPublicIdentity
			, const decltype(Parent::bEncryptedHeader) &encryptedHeader
			, const decltype(Parent::eCurve) &curve
			, const decltype(Parent::aeadMechanism) &aeadMechanism
			, const decltype(Parent::kdfMechanism) &kdfMechanism
	) noexcept;

	DoubleRatchetInitializeParams &operator=(
			const DoubleRatchetInitializeParams &params
	) noexcept;
	DoubleRatchetInitializeParams &operator=(const Parent &params) noexcept;

	using Parent::sk;
	using Parent::peer_public_prekey;
	using Parent::peer_public_identity;
	using Parent::own_public_identity;
	using Parent::bEncryptedHeader;
	using Parent::eCurve;
	using Parent::aeadMechanism;
	using Parent::kdfMechanism;
};

using DoubleRatchetInitializeParamsPtr = ::CK_X2RATCHET_INITIALIZE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_INITIALIZE_PARAMS_HPP
