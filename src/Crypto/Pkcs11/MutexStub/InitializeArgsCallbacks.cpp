#include <FlameIDE/../../src/Crypto/Pkcs11/InitializeArgsCallbacks.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>
#include <FlameIDE/Threads/Mutex.hpp>

namespace flame_ide
{
namespace pkcs11
{

value_types::ReturnType createMutex(value_types::MutexPtrPtr) noexcept
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

value_types::ReturnType destroyMutex(value_types::MutexPtr) noexcept
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

value_types::ReturnType lockMutex(value_types::MutexPtr) noexcept
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

value_types::ReturnType unlockMutex(value_types::MutexPtr) noexcept
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

} // namespace pkcs11
} // namespace flame_ide
