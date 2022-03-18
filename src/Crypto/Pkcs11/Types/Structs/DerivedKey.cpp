#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DerivedKey.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

DerivedKey::DerivedKey() noexcept
{}

DerivedKey::DerivedKey(const DerivedKey &params) noexcept
{
	operator=(params);
}

DerivedKey::DerivedKey(const Parent &params) noexcept
{
	operator=(params);
}

DerivedKey::DerivedKey(
		const decltype(Parent::pTemplate) &attribute
		, const decltype(Parent::ulAttributeCount) &attributeCount
		, const decltype(Parent::phKey) &keyHandle
) noexcept
{
	pTemplate = attribute;
	ulAttributeCount = attributeCount;
	phKey = keyHandle;
}

DerivedKey &DerivedKey::operator=(const DerivedKey &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

DerivedKey &DerivedKey::operator=(const Parent &params) noexcept
{
	pTemplate = params.pTemplate;
	ulAttributeCount = params.ulAttributeCount;
	phKey = params.phKey;

	return *this;
}

}}} // flame_ide::pkcs11::structs
