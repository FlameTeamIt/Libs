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

ReturnType createMutexWrapper(MutexPtr &value)
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

ReturnType destroyMutexWrapper(MutexPtr &mutex)
{
	MutexAllocator allocator;
	allocator.destroy(mutex);
	return ReturnType::OK;
}

ReturnType lockMutexWrapper(Mutex &mutex)
{
	if (mutex.getState() == Mutex::State::UNLOCKED)
	{
		mutex.lock();
	}
	return ReturnType::OK;
}

ReturnType unlockMutexWrapper(Mutex &mutex)
{
	if (mutex.getState() == Mutex::State::LOCKED)
	{
		mutex.unlock();
	}
	return ReturnType::OK;
}

} // namespace anonymous

CK_RV createMutex(CK_VOID_PTR_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(*mutex);
		ReturnType result = flame_ide::pkcs11::createMutexWrapper(mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV destroyMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::destroyMutexWrapper(mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV lockMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::lockMutexWrapper(*mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV unlockMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::unlockMutexWrapper(*mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

} // namespace pkcs11
} // namespace flame_ide
