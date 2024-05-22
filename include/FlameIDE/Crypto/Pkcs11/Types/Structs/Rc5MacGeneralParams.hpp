#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_MAC_GENERAL_PARAMS
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_MAC_GENERAL_PARAMS

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Provide the parameters for the CKM_RC5_MAC_GENERAL mechanism
struct Rc5MacGeneralParams: public WithParent<::CK_RC5_MAC_GENERAL_PARAMS>
{
	Rc5MacGeneralParams() noexcept;

	Rc5MacGeneralParams(const Rc5MacGeneralParams &params) noexcept;
	Rc5MacGeneralParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param wordSize Wordsize in bits
	/// @param rounds Number of rounds
	/// @param macLength Length of MAC in bytes
	Rc5MacGeneralParams(
			const decltype(Parent::ulWordsize) &wordSize
			, const decltype(Parent::ulRounds) &rounds
			, const decltype(Parent::ulMacLength) &macLength
	) noexcept;

	Rc5MacGeneralParams &operator=(const Rc5MacGeneralParams &params) noexcept;
	Rc5MacGeneralParams &operator=(const Parent &params) noexcept;

	using Parent::ulWordsize;
	using Parent::ulRounds;
	using Parent::ulMacLength;
};

using Rc5MacGeneralParamsPtr = CK_RC5_MAC_GENERAL_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_RC5_MAC_GENERAL_PARAMS
