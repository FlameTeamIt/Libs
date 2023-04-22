#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_PRF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_PRF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct WtlsPrfParams: public WithParent<::CK_WTLS_PRF_PARAMS>
{
	WtlsPrfParams() noexcept;

	WtlsPrfParams(const WtlsPrfParams &params) noexcept;
	WtlsPrfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param digestMechanism
	/// @param seed
	/// @param seedLength
	/// @param label
	/// @param labelLength
	/// @param output
	/// @param outputLength
	WtlsPrfParams(
			const decltype(Parent::DigestMechanism) &digestMechanism
			, const decltype(Parent::pSeed) &seed
			, const decltype(Parent::ulSeedLen) &seedLength
			, const decltype(Parent::pLabel) &label
			, const decltype(Parent::ulLabelLen) &labelLength
			, const decltype(Parent::pOutput) &output
			, const decltype(Parent::pulOutputLen) &outputLength
	) noexcept;

	WtlsPrfParams &operator=(const WtlsPrfParams &params) noexcept;
	WtlsPrfParams &operator=(const Parent &params) noexcept;

	using Parent::DigestMechanism;
	using Parent::pSeed;
	using Parent::ulSeedLen;
	using Parent::pLabel;
	using Parent::ulLabelLen;
	using Parent::pOutput;
	using Parent::pulOutputLen;
};
using WtlsPrfParamsPtr = ::CK_WTLS_PRF_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_PRF_PARAMS_HPP
