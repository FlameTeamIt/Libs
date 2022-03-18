#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct OtpParams: public WithParent<::CK_OTP_PARAMS>
{
	OtpParams() noexcept;

	OtpParams(const OtpParams &params) noexcept;
	OtpParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param params
	/// @param count
	OtpParams(
			const decltype(Parent::pParams) &params
			, const decltype(Parent::ulCount) &count
	) noexcept;

	OtpParams &operator=(const OtpParams &params) noexcept;
	OtpParams &operator=(const Parent &params) noexcept;

	using Parent::pParams;
	using Parent::ulCount;
};

using OtpParamsPtr = ::CK_OTP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAMS_HPP
