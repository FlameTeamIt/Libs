#include <FlameIDE/Crypto/Pkcs11/Mechanism.hpp>

namespace flame_ide
{
namespace pkcs11
{

Mechanism::Mechanism(EnumType type, ParameterPtr paramterPtr
		, ParameterSize paramterSize) noexcept
		: Parent{ enums::value(type), paramterPtr, paramterSize }
{}

Mechanism::EnumType &Mechanism::getType() noexcept
{
	return enums::reference<EnumType>(mechanism);
}

Mechanism::EnumType Mechanism::getType() const noexcept
{
	return enums::reference<EnumType>(getConstReference(mechanism));
}

Mechanism::ParameterPtr &Mechanism::getParameterPointer() noexcept
{
	return pParameter;
}

Mechanism::ParameterPtrToConst Mechanism::getParameterPointer() const noexcept
{
	return pParameter;
}

Mechanism::ParameterSize &Mechanism::getParameterSize() noexcept
{
	return ulParameterLen;
}

Mechanism::ParameterSize Mechanism::getParameterSize() const noexcept
{
	return ulParameterLen;
}

Mechanism::ParameterRange Mechanism::getParameterReange() noexcept
{
	byte_t *begin = reinterpret_cast<byte_t *>(pParameter);
	byte_t *end = begin + ulParameterLen;
	ParameterRange range{ begin, end };
	return range;
}

Mechanism::ConstParameterRange Mechanism::getParameterReange() const noexcept
{
	const byte_t *begin = reinterpret_cast<const byte_t *>(pParameter);
	const byte_t *end = begin + ulParameterLen;
	ConstParameterRange range{ begin, end };
	return range;
}

void Mechanism::set(EnumType type, ParameterPtr paramterPtr
		, ParameterSize paramterSize) noexcept
{
	mechanism = enums::value(type);
	pParameter = paramterPtr;
	ulParameterLen = paramterSize;
}

} // namespace pkcs11
} // namespace flame_ide
