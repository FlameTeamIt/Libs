#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_OUT_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_OUT_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Ssl3KeyMatOut: public WithParent<::CK_SSL3_KEY_MAT_OUT>
{
	Ssl3KeyMatOut() noexcept;

	Ssl3KeyMatOut(const Ssl3KeyMatOut &params) noexcept;
	Ssl3KeyMatOut(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param clientMacSecret
	/// @param serverMacSecret
	/// @param clientKey
	/// @param serverKey
	/// @param ivClient
	/// @param ivServer
	Ssl3KeyMatOut(
			const decltype(Parent::hClientMacSecret) &clientMacSecret
			, const decltype(Parent::hServerMacSecret) &serverMacSecret
			, const decltype(Parent::hClientKey) &clientKey
			, const decltype(Parent::hServerKey) &serverKey
			, const decltype(Parent::pIVClient) &ivClient
			, const decltype(Parent::pIVServer) &ivServer
	) noexcept;

	Ssl3KeyMatOut &operator=(const Ssl3KeyMatOut &params) noexcept;
	Ssl3KeyMatOut &operator=(const Parent &params) noexcept;

	using Parent::hClientMacSecret;
	using Parent::hServerMacSecret;
	using Parent::hClientKey;
	using Parent::hServerKey;
	using Parent::pIVClient;
	using Parent::pIVServer;
};
using Ssl3KeyMatOutPtr = CK_SSL3_KEY_MAT_OUT_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_KEY_MAT_OUT_HPP
