#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CCM_MESSAGE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CCM_MESSAGE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct CcmMessageParams: public WithParent<::CK_CCM_MESSAGE_PARAMS>
{
	CcmMessageParams() noexcept;

	CcmMessageParams(const CcmMessageParams &params) noexcept;
	CcmMessageParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param dataLength
	/// @param nonce
	/// @param nonceLength
	/// @param nonceFixedBits
	/// @param nonceGenerator
	/// @param mac
	/// @param macLength
	CcmMessageParams(
			const decltype(Parent::ulDataLen) &dataLength
			, const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceLen) &nonceLength
			, const decltype(Parent::ulNonceFixedBits) &nonceFixedBits
			, const decltype(Parent::nonceGenerator) &nonceGenerator
			, const decltype(Parent::pMAC) &mac
			, const decltype(Parent::ulMACLen) &macLength
	) noexcept;

	CcmMessageParams &operator=(const CcmMessageParams &params) noexcept;
	CcmMessageParams &operator=(const Parent &params) noexcept;

	using Parent::ulDataLen;
	using Parent::pNonce;
	using Parent::ulNonceLen;
	using Parent::ulNonceFixedBits;
	using Parent::nonceGenerator;
	using Parent::pMAC;
	using Parent::ulMACLen;
};

using CcmMessageParamsPtr = ::CK_CCM_MESSAGE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_GCM_MESSAGE_PARAMS_HPP
