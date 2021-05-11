#include <FlameIDE/../../src/Crypto/Pkcs11/InitializeArgsCallbacks.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Threads/Mutex.hpp>
#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

namespace flame_ide
{
namespace pkcs11
{

namespace // anonymous
{

using ReturnType = enums::ReturnType;

using Mutex = threads::Mutex;
using MutexAllocator = templates::allocator::ObjectAllocator<Mutex>;
using MutexPtr = DefaultTraits<Mutex>::Pointer;

ReturnType createMutexWrapper(MutexPtr &value) noexcept
{
	MutexAllocator allocator;
	MutexPtr mutexPtr = allocator.construct();
	if (mutexPtr)
	{
		value = mutexPtr;
		return ReturnType::OK;
	}
	else
	{
		return ReturnType::HOST_MEMORY;
	}
}

ReturnType destroyMutexWrapper(MutexPtr &mutex) noexcept
{
	MutexAllocator allocator;
	allocator.destroy(mutex);
	return ReturnType::OK;
}

ReturnType lockMutexWrapper(Mutex &mutex) noexcept
{
	if (mutex.getState() == Mutex::State::UNLOCKED)
	{
		mutex.lock();
	}
	return ReturnType::OK;
}

ReturnType unlockMutexWrapper(Mutex &mutex) noexcept
{
	if (mutex.getState() == Mutex::State::LOCKED)
	{
		mutex.unlock();
	}
	return ReturnType::OK;
}

inline MutexPtr getMutex(CK_VOID_PTR mutex) noexcept
{
	return reinterpret_cast<MutexPtr>(mutex);
}

} // namespace anonymous

CK_RV createMutex(CK_VOID_PTR_PTR mutex) noexcept
{
	if (mutex)
	{
		MutexPtr mutexPtr = nullptr;
		ReturnType result = flame_ide::pkcs11::createMutexWrapper(mutexPtr);
		*mutex = mutexPtr;

		return pkcs11::enums::value(result);
	}
	return pkcs11::enums::value(ReturnType::ARGUMENTS_BAD);
}

CK_RV destroyMutex(CK_VOID_PTR mutex) noexcept
{
	if (mutex)
	{
		MutexPtr mutexPtr = getMutex(mutex);
		ReturnType result = flame_ide::pkcs11::destroyMutexWrapper(mutexPtr);
		return pkcs11::enums::value(result);
	}
	return pkcs11::enums::value(ReturnType::ARGUMENTS_BAD);
}

CK_RV lockMutex(CK_VOID_PTR mutex) noexcept
{
	if (mutex)
	{
		MutexPtr mutexPtr = getMutex(mutex);
		ReturnType result = flame_ide::pkcs11::lockMutexWrapper(*mutexPtr);
		return pkcs11::enums::value(result);
	}
	return pkcs11::enums::value(ReturnType::ARGUMENTS_BAD);
}

CK_RV unlockMutex(CK_VOID_PTR mutex) noexcept
{
	if (mutex)
	{
		MutexPtr mutexPtr = getMutex(mutex);
		ReturnType result = flame_ide::pkcs11::unlockMutexWrapper(*mutexPtr);
		return pkcs11::enums::value(result);
	}
	return pkcs11::enums::value(ReturnType::ARGUMENTS_BAD);
}

} // namespace pkcs11
} // namespace flame_ide
