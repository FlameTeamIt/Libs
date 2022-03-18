#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_PARAMS
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_PARAMS

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Rc5Params: public WithParent<::CK_RC5_PARAMS>
{
	Rc5Params() noexcept;

	Rc5Params(const Rc5Params &params) noexcept;
	Rc5Params(const Parent &params) noexcept;

	Rc5Params(
			const decltype(Parent::ulWordsize) &wordSize
			, const decltype(Parent::ulRounds) &rounds
	) noexcept;

	Rc5Params &operator=(const Rc5Params &params) noexcept;
	Rc5Params &operator=(const Parent &params) noexcept;

	using Parent::ulWordsize;
	using Parent::ulRounds;
};

using Rc5ParamsPtr = CK_RC5_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_PARAMS
