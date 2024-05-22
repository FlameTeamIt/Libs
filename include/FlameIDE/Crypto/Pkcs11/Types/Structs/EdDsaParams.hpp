#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_EDDSA_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_EDDSA_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct EdDsaParams: public WithParent<::CK_EDDSA_PARAMS>
{
	EdDsaParams() noexcept;

	EdDsaParams(const EdDsaParams &params) noexcept;
	EdDsaParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param flag
	/// @param contextDataLength
	/// @param contextData
	EdDsaParams(
			const decltype(Parent::phFlag) &flag
			, const decltype(Parent::ulContextDataLen) &contextDataLength
			, const decltype(Parent::pContextData) &contextData
	) noexcept;

	EdDsaParams &operator=(const EdDsaParams &params) noexcept;
	EdDsaParams &operator=(const Parent &params) noexcept;

	using Parent::phFlag;
	using Parent::ulContextDataLen;
	using Parent::pContextData;
};

using EdDsaParamsPtr = ::CK_EDDSA_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_EDDSA_PARAMS_HPP
