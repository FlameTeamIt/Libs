#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Specify a particular mechanism
struct Mechanism: public WithParent<::CK_MECHANISM>
{
	Mechanism() noexcept;
	Mechanism(const Mechanism &mechanism) noexcept;
	Mechanism(const Parent &mechanism) noexcept;

	Mechanism(const decltype(Parent::mechanism) &mechanism
			, const decltype(Parent::pParameter) &parameter
			, const decltype(Parent::ulParameterLen) &parameterLength) noexcept;

	Mechanism &operator=(const Mechanism &mechanism) noexcept;
	Mechanism &operator=(const Parent &mechanism) noexcept;

	using Parent::mechanism;      ///<
	using Parent::pParameter;     ///<
	using Parent::ulParameterLen; ///< In bytes
};
using MechanismPtr = ::CK_MECHANISM_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_HPP
