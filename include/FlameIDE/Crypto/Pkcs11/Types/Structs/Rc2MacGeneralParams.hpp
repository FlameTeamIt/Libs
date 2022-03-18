#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_MAC_GENERAL_PARAMS
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_MAC_GENERAL_PARAMS

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provide the parameters for the CKM_RC2_MAC_GENERAL mechanism
struct Rc2MacGeneralParams: public WithParent<::CK_RC2_MAC_GENERAL_PARAMS>
{
	Rc2MacGeneralParams() noexcept;

	Rc2MacGeneralParams(const Rc2MacGeneralParams &params) noexcept;
	Rc2MacGeneralParams(const Parent &params) noexcept;

	/// @brief Contructor
	/// @param effectiveBits Effective bits (1-1024)
	/// @param maxLength Length of MAC in bytes
	Rc2MacGeneralParams(
			const decltype(Parent::ulEffectiveBits) &effectiveBits
			, const decltype(Parent::ulMacLength) &maxLength
	) noexcept;

	Rc2MacGeneralParams &operator=(const Rc2MacGeneralParams &params) noexcept;
	Rc2MacGeneralParams &operator=(const Parent &params) noexcept;

	using Parent::ulEffectiveBits; ///< Effective bits (1-1024)
	using Parent::ulMacLength;     ///< Length of MAC in bytes
};

using Rc2MacGeneralParamsPtr = CK_RC2_MAC_GENERAL_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC2_MAC_GENERAL_PARAMS
