#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Attribute.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

Attribute::Attribute() noexcept
		: Attribute(Parent{})
{}

Attribute::Attribute(const Attribute &attribute) noexcept
		: Attribute(static_cast<const Parent &>(attribute))
{}

Attribute::Attribute(const decltype(Parent::type) &type
		, const decltype(Parent::pValue) &value
		, const decltype(Parent::ulValueLen) &valueLength) noexcept
{
	this->type = type;
	this->pValue = value;
	this->ulValueLen = valueLength;
}

Attribute::Attribute(const Parent &attribute) noexcept
{
	operator=(attribute);
}

Attribute &Attribute::operator=(const Attribute &attribute) noexcept
{
	return operator=(static_cast<const Parent &>(attribute));
}

Attribute &Attribute::operator=(const Parent &attribute) noexcept
{
	type = attribute.type;
	pValue = attribute.pValue;
	ulValueLen = attribute.ulValueLen;
	return *this;
}

}}} // flame_ide::pkcs11::structs
