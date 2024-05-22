#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_MASTER_KEY_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_MASTER_KEY_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Ssl3MasterKeyDeriveParams: public WithParent<::CK_SSL3_MASTER_KEY_DERIVE_PARAMS>
{
	Ssl3MasterKeyDeriveParams() noexcept;

	Ssl3MasterKeyDeriveParams(const Ssl3MasterKeyDeriveParams &params) noexcept;
	Ssl3MasterKeyDeriveParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param randomInfo
	/// @param version
	Ssl3MasterKeyDeriveParams(
			const decltype(Parent::RandomInfo) &randomInfo
			, const decltype(Parent::pVersion) &version
	) noexcept;

	Ssl3MasterKeyDeriveParams &operator=(const Ssl3MasterKeyDeriveParams &params) noexcept;
	Ssl3MasterKeyDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::RandomInfo;
	using Parent::pVersion;
};
using Ssl3MasterKeyDeriveParamsPtr = CK_SSL3_MASTER_KEY_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_MASTER_KEY_DERIVE_PARAMS_HPP
