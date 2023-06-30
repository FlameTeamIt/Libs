#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Mechanism.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

Mechanism::Mechanism() noexcept
		: Mechanism(Parent{})
{}

Mechanism::Mechanism(const Mechanism &mechanism) noexcept
		: Mechanism(static_cast<const Parent &>(mechanism))
{}

Mechanism::Mechanism(const Parent &mechanism) noexcept
{
	operator=(mechanism);
}

Mechanism::Mechanism(const decltype(Parent::mechanism) &mechanismInit
		, const decltype(Parent::pParameter) &parameter
		, const decltype(Parent::ulParameterLen) &parameterLength) noexcept
{
	this->mechanism = mechanismInit;
	this->pParameter = parameter;
	this->ulParameterLen = parameterLength;
}

Mechanism &Mechanism::operator=(const Mechanism &mechanismInit) noexcept
{
	return operator=(static_cast<const Parent &>(mechanismInit));
}

Mechanism &Mechanism::operator=(const Parent &mechanismInit) noexcept
{
	this->mechanism = mechanismInit.mechanism;
	this->pParameter = mechanismInit.pParameter;
	this->ulParameterLen = mechanismInit.ulParameterLen;
	return *this;
}

}}} // flame_ide::pkcs11::structs
