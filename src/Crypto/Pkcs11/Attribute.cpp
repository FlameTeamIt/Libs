#include <FlameIDE/Crypto/Pkcs11/Attribute.hpp>

namespace flame_ide
{
namespace pkcs11
{

Attribute::Attribute(EnumType initType, ValuePtr initPtr, ValueSize initSize) noexcept
		: Parent{ enums::value(initType), initPtr, initSize }
{}

Attribute::EnumType &Attribute::getType() noexcept
{
	return enums::reference<EnumType>(type);
}

const enums::Attribute &Attribute::getType() const noexcept
{
	return enums::reference<EnumType>(getConstReference(type));
}

Attribute::ValuePtr &Attribute::getValuePointer() noexcept
{
	return pValue;
}

const Attribute::ValuePtr &Attribute::getValuePointer() const noexcept
{
	return pValue;
}

Attribute::ValueSize &Attribute::getValueSize() noexcept
{
	return ulValueLen;
}

const Attribute::ValueSize &Attribute::getValueSize() const noexcept
{
	return ulValueLen;
}

Attribute::ValueRange Attribute::getValueRange() noexcept
{
	byte_t *begin = reinterpret_cast<byte_t *>(pValue);
	byte_t *end = begin + getValueSize();
	ValueRange valueRange(begin, end);
	return valueRange;
}

Attribute::ConstValueRange Attribute::getValueRange() const noexcept
{
	const byte_t *begin = reinterpret_cast<byte_t *>(pValue);
	const byte_t *end = begin + getValueSize();
	ConstValueRange valueRange(begin, end);
	return valueRange;
}


void Attribute::set(EnumType newValue, ValuePtr newValuePointer
		, ValueSize newValueSize) noexcept
{
	Attribute attr{ newValue, newValuePointer, newValueSize };
	*this = attr;
}

} // namespace pkcs11
} // namespace flame_ide
