#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAM_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAM_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct OtpParam: public WithParent<::CK_OTP_PARAM>
{
	OtpParam() noexcept;

	OtpParam(const OtpParam &params) noexcept;
	OtpParam(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param type
	/// @param value
	/// @param valueLength
	OtpParam(
			const decltype(Parent::type) &type
			, const decltype(Parent::pValue) &value
			, const decltype(Parent::ulValueLen) &valueLength
	) noexcept;

	OtpParam &operator=(const OtpParam &params) noexcept;
	OtpParam &operator=(const Parent &params) noexcept;

	using Parent::type;
	using Parent::pValue;
	using Parent::ulValueLen;
};

using OtpParamPtr = ::CK_OTP_PARAM_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_OTP_PARAM_HPP
