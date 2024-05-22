#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_RANDOM_DATA_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_RANDOM_DATA_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct WtlsRandomData: public WithParent<::CK_WTLS_RANDOM_DATA>
{
	WtlsRandomData() noexcept;

	WtlsRandomData(const WtlsRandomData &params) noexcept;
	WtlsRandomData(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param clientRandom
	/// @param clientRandomLength
	/// @param serverRandom
	/// @param serverRandomLength
	WtlsRandomData(
			const decltype(Parent::pClientRandom) &clientRandom
			, const decltype(Parent::ulClientRandomLen) &clientRandomLength
			, const decltype(Parent::pServerRandom) &serverRandom
			, const decltype(Parent::ulServerRandomLen) &serverRandomLength
	) noexcept;

	WtlsRandomData &operator=(const WtlsRandomData &params) noexcept;
	WtlsRandomData &operator=(const Parent &params) noexcept;

	using Parent::pClientRandom;
	using Parent::ulClientRandomLen;
	using Parent::pServerRandom;
	using Parent::ulServerRandomLen;
};

using WtlsRandomDataPtr = CK_WTLS_RANDOM_DATA_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_WTLS_RANDOM_DATA_HPP
