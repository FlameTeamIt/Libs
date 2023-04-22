#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_INITIATE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_INITIATE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct ExtendedTripleDiffieHellmanInitiateParams: public WithParent<::CK_X3DH_INITIATE_PARAMS>
{
	ExtendedTripleDiffieHellmanInitiateParams() noexcept;

	ExtendedTripleDiffieHellmanInitiateParams(
			const ExtendedTripleDiffieHellmanInitiateParams &params
	) noexcept;
	ExtendedTripleDiffieHellmanInitiateParams(const Parent &params) noexcept;

	ExtendedTripleDiffieHellmanInitiateParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::pPeer_identity) &peerIdentity
			, const decltype(Parent::pPeer_prekey) &peerPrekey
			, const decltype(Parent::pPrekey_signature) &prekeySignature
			, const decltype(Parent::pOnetime_key) &onetimeKey
			, const decltype(Parent::pOwn_identity) &ownIdentity
			, const decltype(Parent::pOwn_ephemeral) &ownEphemeral
	) noexcept;

	ExtendedTripleDiffieHellmanInitiateParams &operator=(
			const ExtendedTripleDiffieHellmanInitiateParams &params
	) noexcept;
	ExtendedTripleDiffieHellmanInitiateParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::pPeer_identity;
	using Parent::pPeer_prekey;
	using Parent::pPrekey_signature;
	using Parent::pOnetime_key;
	using Parent::pOwn_identity;
	using Parent::pOwn_ephemeral;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_INITIATE_PARAMS_HPP
