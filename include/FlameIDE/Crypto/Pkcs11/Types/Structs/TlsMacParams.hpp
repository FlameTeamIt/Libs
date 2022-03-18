#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_MAC_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_MAC_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provides the parameters to the CKM_TLS_MAC mechanism
struct TlsMacParams: public WithParent<::CK_TLS_MAC_PARAMS>
{
	TlsMacParams() noexcept;

	TlsMacParams(const TlsMacParams &params) noexcept;
	TlsMacParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param prfHashMechanism
	/// @param macLength
	/// @param serverOrClient
	TlsMacParams(
			const decltype(Parent::prfHashMechanism) &prfHashMechanism
			, const decltype(Parent::ulMacLength) &macLength
			, const decltype(Parent::ulServerOrClient) &serverOrClient
	) noexcept;

	TlsMacParams &operator=(const TlsMacParams &params) noexcept;
	TlsMacParams &operator=(const Parent &params) noexcept;

	using Parent::prfHashMechanism;
	using Parent::ulMacLength;
	using Parent::ulServerOrClient;
};

using TlsMacParamsPtr = ::CK_TLS_MAC_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TLS_MAC_PARAMS_HPP
