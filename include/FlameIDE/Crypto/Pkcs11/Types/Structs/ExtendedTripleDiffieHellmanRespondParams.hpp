#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_RESPOND_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_RESPOND_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct ExtendedTripleDiffieHellmanRespondParams: public WithParent<::CK_X3DH_RESPOND_PARAMS>
{
	ExtendedTripleDiffieHellmanRespondParams() noexcept;

	ExtendedTripleDiffieHellmanRespondParams(const ExtendedTripleDiffieHellmanRespondParams &params) noexcept;
	ExtendedTripleDiffieHellmanRespondParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param kdf
	/// @param identityId
	/// @param prekeyId
	/// @param onetimeId
	/// @param initiatorIdentity
	/// @param initiatorEphemeral
	ExtendedTripleDiffieHellmanRespondParams(
			const decltype(Parent::kdf) &kdf
			, const decltype(Parent::pIdentity_id) &identityId
			, const decltype(Parent::pPrekey_id) &prekeyId
			, const decltype(Parent::pOnetime_id) &onetimeId
			, const decltype(Parent::pInitiator_identity) &initiatorIdentity
			, const decltype(Parent::pInitiator_ephemeral) &initiatorEphemeral
	) noexcept;

	ExtendedTripleDiffieHellmanRespondParams &operator=(const ExtendedTripleDiffieHellmanRespondParams &params) noexcept;
	ExtendedTripleDiffieHellmanRespondParams &operator=(const Parent &params) noexcept;

	using Parent::kdf;
	using Parent::pIdentity_id;
	using Parent::pPrekey_id;
	using Parent::pOnetime_id;
	using Parent::pInitiator_identity;
	using Parent::pInitiator_ephemeral;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X3DH_RESPOND_PARAMS_HPP
