#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_RANDOM_DATA_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_RANDOM_DATA_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Ssl3RandomData: public WithParent<::CK_SSL3_RANDOM_DATA>
{
	Ssl3RandomData() noexcept;

	Ssl3RandomData(const Ssl3RandomData &params) noexcept;
	Ssl3RandomData(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param serverRandomLength
	/// @param serverRandom
	/// @param clientRandomLength
	/// @param clientRandom
	Ssl3RandomData(
			const decltype(Parent::ulServerRandomLen) &serverRandomLength
			, const decltype(Parent::pServerRandom) &serverRandom
			, const decltype(Parent::ulClientRandomLen) &clientRandomLength
			, const decltype(Parent::pClientRandom) &clientRandom
	) noexcept;

	Ssl3RandomData &operator=(const Ssl3RandomData &params) noexcept;
	Ssl3RandomData &operator=(const Parent &params) noexcept;

	using Parent::pClientRandom;
	using Parent::ulClientRandomLen;
	using Parent::pServerRandom;
	using Parent::ulServerRandomLen;
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SSL3_RANDOM_DATA_HPP
