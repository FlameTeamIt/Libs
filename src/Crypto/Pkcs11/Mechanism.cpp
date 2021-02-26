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
	return static_cast<ParameterPtrToConst>(pParameter);
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
	auto begin = reinterpret_cast<ParameterRange::Iterator>(pParameter);
	auto end = begin + ulParameterLen;
	ParameterRange range{ begin, end };
	return range;
}

Mechanism::ConstParameterRange Mechanism::getParameterReange() const noexcept
{
	auto begin = reinterpret_cast<ConstParameterRange::Iterator>(pParameter);
	auto end = begin + ulParameterLen;
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

void Mechanism::set(EnumType type, ParameterRange paramter) noexcept
{
	set(type, paramter.begin(), paramter.end() - paramter.begin());
}

} // namespace pkcs11
} // namespace flame_ide
