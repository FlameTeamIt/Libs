#include <FlameIDE/../../src/Crypto/Pkcs11/InitializeArgsCallbacks.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Threads/Mutex.hpp>
#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

namespace flame_ide
{
namespace pkcs11
{

CK_RV createMutex(CK_VOID_PTR_PTR)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

CK_RV destroyMutex(CK_VOID_PTR)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

CK_RV lockMutex(CK_VOID_PTR)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

CK_RV unlockMutex(CK_VOID_PTR)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

} // namespace pkcs11
} // namespace flame_ide
