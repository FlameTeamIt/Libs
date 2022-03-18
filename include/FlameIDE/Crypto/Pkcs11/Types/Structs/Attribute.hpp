#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ATTRIBUTE_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ATTRIBUTE_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Define a ATTRIBUTE
struct Attribute: public WithParent<::CK_ATTRIBUTE>
{
	Attribute() noexcept;
	Attribute(const Attribute &attribute) noexcept;
	Attribute(const Parent &attribute) noexcept;

	Attribute(const decltype(Parent::type) &type
			, const decltype(Parent::pValue) &value
			, const decltype(Parent::ulValueLen) &valueLength) noexcept;

	Attribute &operator=(const Attribute &attribute) noexcept;
	Attribute &operator=(const Parent &attribute) noexcept;

	using Parent::type;       ///<
	using Parent::pValue;     ///<
	using Parent::ulValueLen; ///< In bytes
};
using AttributePtr = ::CK_ATTRIBUTE_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_ATTRIBUTE_HPP
