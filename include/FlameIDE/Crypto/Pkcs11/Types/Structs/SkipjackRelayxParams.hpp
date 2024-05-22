#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_RELAYX_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_RELAYX_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct SkipjackRelayxParams: public WithParent<::CK_SKIPJACK_RELAYX_PARAMS>
{
	SkipjackRelayxParams() noexcept;

	SkipjackRelayxParams(const SkipjackRelayxParams &params) noexcept;
	SkipjackRelayxParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param oldWrappedLength
	/// @param oldWrapped
	/// @param oldPasswordLength
	/// @param oldPassword
	/// @param oldPublicDataLength
	/// @param oldPublicData
	/// @param oldRandomLength
	/// @param oldRandomA
	/// @param NewPasswordLength
	/// @param newPassword
	/// @param newPublicDataLength
	/// @param newPublicData
	/// @param newRandomLength
	/// @param newRandomA
	SkipjackRelayxParams(
			const decltype(Parent::ulOldWrappedXLen) &oldWrappedLength
			, const decltype(Parent::pOldWrappedX) &oldWrapped
			, const decltype(Parent::ulOldPasswordLen) &oldPasswordLength
			, const decltype(Parent::pOldPassword) &oldPassword
			, const decltype(Parent::ulOldPublicDataLen) &oldPublicDataLength
			, const decltype(Parent::pOldPublicData) &oldPublicData
			, const decltype(Parent::ulOldRandomLen) &oldRandomLength
			, const decltype(Parent::pOldRandomA) &oldRandomA
			, const decltype(Parent::ulNewPasswordLen) &NewPasswordLength
			, const decltype(Parent::pNewPassword) &newPassword
			, const decltype(Parent::ulNewPublicDataLen) &newPublicDataLength
			, const decltype(Parent::pNewPublicData) &newPublicData
			, const decltype(Parent::ulNewRandomLen) &newRandomLength
			, const decltype(Parent::pNewRandomA) &newRandomA
	) noexcept;

	SkipjackRelayxParams &operator=(const SkipjackRelayxParams &params) noexcept;
	SkipjackRelayxParams &operator=(const Parent &params) noexcept;

	using Parent::ulOldWrappedXLen;
	using Parent::pOldWrappedX;
	using Parent::ulOldPasswordLen;
	using Parent::pOldPassword;
	using Parent::ulOldPublicDataLen;
	using Parent::pOldPublicData;
	using Parent::ulOldRandomLen;
	using Parent::pOldRandomA;
	using Parent::ulNewPasswordLen;
	using Parent::pNewPassword;
	using Parent::ulNewPublicDataLen;
	using Parent::pNewPublicData;
	using Parent::ulNewRandomLen;
	using Parent::pNewRandomA;
};

using SkipjackRelayxParamsPtr = CK_SKIPJACK_RELAYX_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SKIPJACK_RELAYX_PARAMS_HPP
