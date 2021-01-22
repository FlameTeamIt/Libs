#include <FlameIDE/Crypto/Pkcs11/ObjectHandle.hpp>

namespace flame_ide
{
namespace pkcs11
{

ObjectHandle::ObjectHandle() noexcept : value{ INVALID_VALUE }
{}

ObjectHandle::ObjectHandle(ObjectHandle &&handle) noexcept
{
	value = handle.value;
	handle.value = INVALID_VALUE;
}

ObjectHandle::ObjectHandle(Value initValue) noexcept : value(initValue)
{}

ObjectHandle &ObjectHandle::operator=(ObjectHandle &&handle) noexcept
{
	value = handle.value;
	handle.value = INVALID_VALUE;
	return *this;
}

ObjectHandle::operator Value() noexcept
{
	return value;
}

} // namespace pkcs11
} // namespace flame_ide
