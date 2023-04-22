#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_RESPOND_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_RESPOND_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct DoubleRatchetRespondParams: public WithParent<::CK_X2RATCHET_RESPOND_PARAMS>
{
	DoubleRatchetRespondParams() noexcept;

	DoubleRatchetRespondParams(const DoubleRatchetRespondParams &params) noexcept;
	DoubleRatchetRespondParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param sk
	/// @param ownPrekey
	/// @param initiatorIdentity
	/// @param ownPublicIdentity
	/// @param encryptedHeader
	/// @param curve
	/// @param aeadMechanism
	/// @param kdfMechanism
	DoubleRatchetRespondParams(
			const decltype(Parent::sk) &sk
			, const decltype(Parent::own_prekey) &ownPrekey
			, const decltype(Parent::initiator_identity) &initiatorIdentity
			, const decltype(Parent::own_public_identity) &ownPublicIdentity
			, const decltype(Parent::bEncryptedHeader) &encryptedHeader
			, const decltype(Parent::eCurve) &curve
			, const decltype(Parent::aeadMechanism) &aeadMechanism
			, const decltype(Parent::kdfMechanism) &kdfMechanism
	) noexcept;

	DoubleRatchetRespondParams &operator=(const DoubleRatchetRespondParams &params) noexcept;
	DoubleRatchetRespondParams &operator=(const Parent &params) noexcept;

	using Parent::sk;
	using Parent::own_prekey;
	using Parent::initiator_identity;
	using Parent::own_public_identity;
	using Parent::bEncryptedHeader;
	using Parent::eCurve;
	using Parent::aeadMechanism;
	using Parent::kdfMechanism;
};

using DoubleRatchetRespondParamsPtr = ::CK_X2RATCHET_RESPOND_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_X2RATCHET_RESPOND_PARAMS_HPP
