#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PRF_DATA_PARAM_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PRF_DATA_PARAM_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct PrfDataParam: public WithParent<::CK_PRF_DATA_PARAM>
{
	PrfDataParam() noexcept;

	PrfDataParam(const PrfDataParam &params) noexcept;
	PrfDataParam(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param type
	/// @param value
	/// @param valueLength
	PrfDataParam(
			const decltype(Parent::type) &type
			, const decltype(Parent::pValue) &value
			, const decltype(Parent::ulValueLen) &valueLength
	) noexcept;

	PrfDataParam &operator=(const PrfDataParam &params) noexcept;
	PrfDataParam &operator=(const Parent &params) noexcept;

	using Parent::type;
	using Parent::pValue;
	using Parent::ulValueLen;
};

using PrfDataParamPtr = ::CK_PRF_DATA_PARAM_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_PRF_DATA_PARAM_HPP
