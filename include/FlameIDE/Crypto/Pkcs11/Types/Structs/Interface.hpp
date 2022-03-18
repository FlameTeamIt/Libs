#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INTERFACE_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INTERFACE_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct Interface: public WithParent<::CK_INTERFACE>
{
	Interface() noexcept;
	Interface(const Interface &iface) noexcept;
	Interface(const Parent &iface) noexcept;

	Interface(
			const decltype(Parent::pInterfaceName) &interfaceName
			, const decltype(Parent::pFunctionList) &functionList
			, const decltype(Parent::flags) &flags
	) noexcept;

	Interface &operator=(const Interface &iface) noexcept;
	Interface &operator=(const Parent &iface) noexcept;

	using Parent::pInterfaceName;
	using Parent::pFunctionList;
	using Parent::flags;
};
using InterfacePtr = ::CK_INTERFACE_PTR;
using InterfacePtrPtr = ::CK_INTERFACE_PTR_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INTERFACE_HPP
