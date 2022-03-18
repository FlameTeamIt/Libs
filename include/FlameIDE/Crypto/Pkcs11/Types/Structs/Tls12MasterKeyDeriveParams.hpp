#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_MASTER_KEY_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_MASTER_KEY_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Tls12MasterKeyDeriveParams: public WithParent<::CK_TLS12_MASTER_KEY_DERIVE_PARAMS>
{
	Tls12MasterKeyDeriveParams() noexcept;

	Tls12MasterKeyDeriveParams(const Tls12MasterKeyDeriveParams &params) noexcept;
	Tls12MasterKeyDeriveParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param randomInfo
	/// @param version
	/// @param prfHashMechanism
	Tls12MasterKeyDeriveParams(
			const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pVersion) &version
			, const decltype(Parent::prfHashMechanism) &prfHashMechanism
	) noexcept;

	Tls12MasterKeyDeriveParams &operator=(const Tls12MasterKeyDeriveParams &params) noexcept;
	Tls12MasterKeyDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::RandomInfo;
	using Parent::pVersion;
	using Parent::prfHashMechanism;
};

using Tls12MasterKeyDeriveParamsPtr = ::CK_TLS12_MASTER_KEY_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS12_MASTER_KEY_DERIVE_PARAMS_HPP
