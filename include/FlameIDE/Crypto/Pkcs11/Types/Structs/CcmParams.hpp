#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CCM_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CCM_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct CcmParams: public WithParent<::CK_CCM_PARAMS>
{
	CcmParams() noexcept;

	CcmParams(const CcmParams &params) noexcept;
	CcmParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param dataLength
	/// @param nonce
	/// @param nonceLength
	/// @param aad
	/// @param aadLength
	/// @param macLength
	CcmParams(
			const decltype(Parent::ulDataLen) &dataLength
			, const decltype(Parent::pNonce) &nonce
			, const decltype(Parent::ulNonceLen) &nonceLength
			, const decltype(Parent::pAAD) &aad
			, const decltype(Parent::ulAADLen) &aadLength
			, const decltype(Parent::ulMACLen) &macLength
	) noexcept;

	CcmParams &operator=(const CcmParams &params) noexcept;
	CcmParams &operator=(const Parent &params) noexcept;

	using Parent::ulDataLen;
	using Parent::pNonce;
	using Parent::ulNonceLen;
	using Parent::pAAD;
	using Parent::ulAADLen;
	using Parent::ulMACLen;
};

using CcmParamsPtr = ::CK_CCM_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_CCM_PARAMS_HPP
