#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_SIGNATURE_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_SIGNATURE_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct OtpSignatureInfo: public WithParent<::CK_OTP_SIGNATURE_INFO>
{
	OtpSignatureInfo() noexcept;

	OtpSignatureInfo(const OtpSignatureInfo &params) noexcept;
	OtpSignatureInfo(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param params
	/// @param count
	OtpSignatureInfo(
			const decltype(Parent::pParams) &params
			, const decltype(Parent::ulCount) &count
	) noexcept;

	OtpSignatureInfo &operator=(const OtpSignatureInfo &params) noexcept;
	OtpSignatureInfo &operator=(const Parent &params) noexcept;

	using Parent::pParams;
	using Parent::ulCount;
};

using OtpSignatureInfoPtr = ::CK_OTP_SIGNATURE_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_SIGNATURE_INFO_HPP
