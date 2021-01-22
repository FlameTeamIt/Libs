#include <FlameIDE/Crypto/Pkcs11/InitializeArgs.hpp>

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

ReturnType createMutex(MutexPtr &value)
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

ReturnType destroyMutex(MutexPtr &mutex)
{
	MutexAllocator allocator;
	allocator.destroy(mutex);
	return ReturnType::OK;
}

ReturnType lockMutex(Mutex &mutex)
{
	if (mutex.getState() == Mutex::State::UNLOCKED)
	{
		mutex.lock();
	}
	return ReturnType::OK;
}

ReturnType unlockMutex(Mutex &mutex)
{
	if (mutex.getState() == Mutex::State::LOCKED)
	{
		mutex.unlock();
	}
	return ReturnType::OK;
}

namespace cryptoki
{

CK_RV createMutex(CK_VOID_PTR_PTR mutex)
{
	if (mutex)
	{
		if (*mutex)
		{
			MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(*mutex);
			ReturnType result = flame_ide::pkcs11::createMutex(mutexPtr);
			return static_cast<CK_RV>(result);
		}
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV destroyMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::destroyMutex(mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV lockMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::lockMutex(*mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

CK_RV unlockMutex(CK_VOID_PTR mutex)
{
	if (mutex)
	{
		MutexPtr mutexPtr = reinterpret_cast<MutexPtr>(mutex);
		ReturnType result = flame_ide::pkcs11::unlockMutex(*mutexPtr);
		return static_cast<CK_RV>(result);
	}
	return static_cast<CK_RV>(ReturnType::ARGUMENTS_BAD);
}

} // namespace cryptoki

} // namespace anonymous

InitializeArgs::InitializeArgs() noexcept :
		CK_C_INITIALIZE_ARGS{
				cryptoki::createMutex, cryptoki::destroyMutex
				, cryptoki::lockMutex, cryptoki::unlockMutex
				, static_cast<CK_FLAGS>(Flags::OS_LOCKING_OK)
				, nullptr
		}
{}

InitializeArgs::InitializeArgs(const InitializeArgs &args)
		noexcept :
		CK_C_INITIALIZE_ARGS{
				args.CreateMutex, args.DestroyMutex
				, args.LockMutex, args.UnlockMutex
				, args.flags, args.pReserved
		}
{}

InitializeArgs::InitializeArgs(InitializeArgs &&args)
	noexcept :
	CK_C_INITIALIZE_ARGS{
		args.CreateMutex, args.DestroyMutex
		, args.LockMutex, args.UnlockMutex
		, args.flags, args.pReserved
	}
{
	args.setCallbacks(Callbacks{});
	args.flags = static_cast<value_types::Flags>(Flags::OS_LOCKING_OK);
	args.pReserved = nullptr;
}

InitializeArgs::InitializeArgs(const Callbacks &callbacks
		, Flags initFlags, Reseved reseved) noexcept :
		CK_C_INITIALIZE_ARGS{
				callbacks.createMutexCallback, callbacks.destroyMutexCallback
				, callbacks.lockMutexCallback, callbacks.unlockMutexCallback
				, static_cast<CK_FLAGS>(initFlags), reseved
		}
{}

InitializeArgs &InitializeArgs::operator=(
		const InitializeArgs &args) noexcept
{
	setCallbacks(Callbacks{
			args.CreateMutex
			, args.DestroyMutex
			, args.LockMutex
			, args.UnlockMutex
	});
	flags = args.flags;
	pReserved = args.pReserved;

	return *this;
}

InitializeArgs &InitializeArgs::operator=(
		InitializeArgs &&args) noexcept
{
	this->operator=(static_cast<const InitializeArgs &>(args));

	args.setCallbacks(Callbacks{});
	args.pReserved = nullptr;

	return *this;
}

void InitializeArgs::setCallbacks(const Callbacks &callbacks) noexcept
{
	CreateMutex = callbacks.createMutexCallback;
	DestroyMutex = callbacks.destroyMutexCallback;
	LockMutex = callbacks.lockMutexCallback;
	UnlockMutex = callbacks.unlockMutexCallback;
}

} // namespace pkcs11
} // namespace flame_ide