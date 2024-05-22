#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_KDF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_KDF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct TlsKdfParams: public WithParent<::CK_TLS_KDF_PARAMS>
{
	TlsKdfParams() noexcept;

	TlsKdfParams(const TlsKdfParams &params) noexcept;
	TlsKdfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param prfMechanism
	/// @param label
	/// @param labelLength
	/// @param randomInfo
	/// @param contextData
	/// @param contextDataLength
	TlsKdfParams(
			const decltype(Parent::prfMechanism) &prfMechanism
			, const decltype(Parent::pLabel) &label
			, const decltype(Parent::ulLabelLength) &labelLength
			, const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pContextData) &contextData
			, const decltype(Parent::ulContextDataLength) &contextDataLength
	) noexcept;

	TlsKdfParams &operator=(const TlsKdfParams &params) noexcept;
	TlsKdfParams &operator=(const Parent &params) noexcept;

	using Parent::prfMechanism;
	using Parent::pLabel;
	using Parent::ulLabelLength;
	using Parent::RandomInfo;
	using Parent::pContextData;
	using Parent::ulContextDataLength;
};

using TlsKdfParamsPtr = ::CK_TLS_KDF_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_KDF_PARAMS_HPP
