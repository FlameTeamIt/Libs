#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Interface.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Interface::Interface() noexcept
		: Interface(Parent{})
{}

Interface::Interface(const Interface &iface) noexcept
{
	operator=(iface);
}

Interface::Interface(const Parent &iface) noexcept
{
	operator=(iface);
}

Interface::Interface(
		const decltype(Parent::pInterfaceName) &interfaceName
		, const decltype(Parent::pFunctionList) &functionList
		, const decltype(Parent::flags) &flags
) noexcept
{
	pInterfaceName = interfaceName;
	pFunctionList = functionList;
	this->flags = flags;
}

Interface &Interface::operator=(const Interface &iface) noexcept
{
	return operator=(static_cast<const Parent &>(iface));
}

Interface &Interface::operator=(const Parent &iface) noexcept
{
	pInterfaceName = iface.pInterfaceName;
	pFunctionList = iface.pFunctionList;
	flags = iface.flags;

	return *this;
}

}}} // flame_ide::pkcs11::structs
