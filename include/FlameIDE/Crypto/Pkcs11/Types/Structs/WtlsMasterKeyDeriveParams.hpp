#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_MASTER_KEY_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_MASTER_KEY_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct WtlsMasterKeyDeriveParams: public WithParent<::CK_WTLS_MASTER_KEY_DERIVE_PARAMS>
{
	WtlsMasterKeyDeriveParams() noexcept;

	WtlsMasterKeyDeriveParams(const WtlsMasterKeyDeriveParams &params) noexcept;
	WtlsMasterKeyDeriveParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param digestMechanism
	/// @param randomInfo
	/// @param version
	WtlsMasterKeyDeriveParams(
			const decltype(Parent::DigestMechanism) &digestMechanism
			, const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pVersion) &version
	) noexcept;

	WtlsMasterKeyDeriveParams &operator=(const WtlsMasterKeyDeriveParams &params) noexcept;
	WtlsMasterKeyDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::DigestMechanism;
	using Parent::RandomInfo;
	using Parent::pVersion;
};
using WtlsMasterKeyDeriveParamsPtr = ::CK_WTLS_MASTER_KEY_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_MASTER_KEY_DERIVE_PARAMS_HPP
