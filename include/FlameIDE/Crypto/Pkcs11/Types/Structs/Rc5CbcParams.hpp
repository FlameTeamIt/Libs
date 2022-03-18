#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_CBC_PARAMS
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_CBC_PARAMS

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provide the parameters to the CKM_RC5_CBC mechanism
struct Rc5CbcParams: public WithParent<::CK_RC5_CBC_PARAMS>
{
	Rc5CbcParams() noexcept;

	Rc5CbcParams(const Rc5CbcParams &params) noexcept;
	Rc5CbcParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param wordSize Wordsize in bits
	/// @param rounds Number of rounds */
	/// @param iv Pointer to IV
	/// @param ivLength Length of IV in bytes
	Rc5CbcParams(
			const decltype(Parent::ulWordsize) &wordSize
			, const decltype(Parent::ulRounds) &rounds
			, const decltype(Parent::pIv) &iv
			, const decltype(Parent::ulIvLen) &ivLength
	) noexcept;

	Rc5CbcParams &operator=(const Rc5CbcParams &params) noexcept;
	Rc5CbcParams &operator=(const Parent &params) noexcept;

	using Parent::ulWordsize;
	using Parent::ulRounds;
	using Parent::pIv;
	using Parent::ulIvLen;
};

using Rc5CbcParamsPtr = CK_RC5_CBC_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_CBC_PARAMS
