#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_CBC_PARAMS
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_CBC_PARAMS

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provide the parameters to the CKM_RC2_CBC mechanism
struct Rc2CbcParams: public WithParent<::CK_RC2_CBC_PARAMS>
{
	Rc2CbcParams() noexcept;

	Rc2CbcParams(const Rc2CbcParams &params) noexcept;
	Rc2CbcParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param effectiveBits Effective bits (1-1024)
	/// @param iv IV for CBC mode
	Rc2CbcParams(
			const decltype(Parent::ulEffectiveBits) &effectiveBits
			, const decltype(Parent::iv) &iv
	) noexcept;

	Rc2CbcParams &operator=(const Rc2CbcParams &params) noexcept;
	Rc2CbcParams &operator=(const Parent &params) noexcept;

	using Parent::ulEffectiveBits; ///< Effective bits (1-1024)
	using Parent::iv;              ///< IV for CBC mode
};

using Rc2CbcParamsPtr = CK_RC2_CBC_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_CBC_PARAMS
