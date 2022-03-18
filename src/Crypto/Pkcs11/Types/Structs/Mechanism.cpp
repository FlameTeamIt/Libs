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

Mechanism::Mechanism(const decltype(Parent::mechanism) &mechanism
		, const decltype(Parent::pParameter) &parameter
		, const decltype(Parent::ulParameterLen) &parameterLength) noexcept
{
	this->mechanism = mechanism;
	this->pParameter = parameter;
	this->ulParameterLen = parameterLength;
}

Mechanism &Mechanism::operator=(const Mechanism &mechanism) noexcept
{
	return operator=(static_cast<const Parent &>(mechanism));
}

Mechanism &Mechanism::operator=(const Parent &mechanism) noexcept
{
	this->mechanism = mechanism.mechanism;
	this->pParameter = mechanism.pParameter;
	this->ulParameterLen = mechanism.ulParameterLen;
	return *this;
}

}}} // flame_ide::pkcs11::structs
