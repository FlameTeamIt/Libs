#include <FlameIDE/Crypto/Pkcs11/InitializeArgs.hpp>

#include <FlameIDE/../../src/Crypto/Pkcs11/InitializeArgsCallbacks.hpp>

namespace flame_ide
{
namespace pkcs11
{

InitializeArgs::InitializeArgs() noexcept :
		structs::InitializeArgs {
				createMutex, destroyMutex
				, lockMutex, unlockMutex
				, enums::value(Flags::OS_LOCKING_OK)
				, nullptr
		}
{}

InitializeArgs::InitializeArgs(const InitializeArgs &args) noexcept :
		structs::InitializeArgs {
				args.CreateMutex, args.DestroyMutex
				, args.LockMutex, args.UnlockMutex
				, args.flags, args.pReserved
		}
{}

InitializeArgs::InitializeArgs(InitializeArgs &&args) noexcept :
		structs::InitializeArgs {
			args.CreateMutex, args.DestroyMutex
			, args.LockMutex, args.UnlockMutex
			, args.flags, args.pReserved
		}
{
	args.setCallbacks(Callbacks{});
	args.flags = static_cast<value_types::Flags>(Flags::OS_LOCKING_OK);
	args.pReserved = nullptr;
}

InitializeArgs::InitializeArgs(const structs::InitializeArgs &args) noexcept :
		structs::InitializeArgs { args }
{}


InitializeArgs::InitializeArgs(const Callbacks &callbacks
		, Flags initFlags, Reseved reseved) noexcept :
		structs::InitializeArgs{
				callbacks.createMutexCallback, callbacks.destroyMutexCallback
				, callbacks.lockMutexCallback, callbacks.unlockMutexCallback
				, static_cast<CK_FLAGS>(initFlags), reseved
		}
{}

InitializeArgs &InitializeArgs::operator=(const InitializeArgs &args) noexcept
{
	setCallbacks(Callbacks{
			args.CreateMutex , args.DestroyMutex
			, args.LockMutex, args.UnlockMutex
	});
	flags = args.flags;
	pReserved = args.pReserved;

	return *this;
}

InitializeArgs &InitializeArgs::operator=(InitializeArgs &&args) noexcept
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
