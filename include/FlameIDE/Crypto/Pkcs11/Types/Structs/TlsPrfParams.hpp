#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_PRF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_PRF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct TlsPrfParams: public WithParent<::CK_TLS_PRF_PARAMS>
{
	TlsPrfParams() noexcept;

	TlsPrfParams(const TlsPrfParams &params) noexcept;
	TlsPrfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param seed
	/// @param seedLength
	/// @param label
	/// @param labelLength
	/// @param output
	/// @param outputLength
	TlsPrfParams(
			const decltype(Parent::pSeed) &seed
			, const decltype(Parent::ulSeedLen) &seedLength
			, const decltype(Parent::pLabel) &label
			, const decltype(Parent::ulLabelLen) &labelLength
			, const decltype(Parent::pOutput) &output
			, const decltype(Parent::pulOutputLen) &outputLength
	) noexcept;

	TlsPrfParams &operator=(const TlsPrfParams &params) noexcept;
	TlsPrfParams &operator=(const Parent &params) noexcept;

	using Parent::pSeed;
	using Parent::ulSeedLen;
	using Parent::pLabel;
	using Parent::ulLabelLen;
	using Parent::pOutput;
	using Parent::pulOutputLen;
};
using TlsPrfParamsPtr = CK_TLS_PRF_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_PRF_PARAMS_HPP
