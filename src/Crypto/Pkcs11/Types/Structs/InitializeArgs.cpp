#include <FlameIDE/Crypto/Pkcs11/Types/Structs/InitializeArgs.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

InitializeArgs::InitializeArgs() noexcept
		: InitializeArgs(Parent{})
{}

InitializeArgs::InitializeArgs(const InitializeArgs &initializeArgs) noexcept
		: InitializeArgs(static_cast<const Parent &>(initializeArgs))
{}

InitializeArgs::InitializeArgs(const Parent &initializeArgs) noexcept
{
	operator=(initializeArgs);
}

InitializeArgs::InitializeArgs(const decltype(Parent::CreateMutex) &createMutexCallback
		, const decltype(Parent::DestroyMutex) &destroyMutexCallback
		, const decltype(Parent::LockMutex) &lockMutexCallback
		, const decltype(Parent::UnlockMutex) &unlockMutexCallback
		, const decltype(Parent::flags) &flags
		, const decltype(Parent::pReserved) reserved) noexcept
{
	this->CreateMutex = createMutexCallback;
	this->DestroyMutex = destroyMutexCallback;
	this->LockMutex = lockMutexCallback;
	this->UnlockMutex = unlockMutexCallback;

	this->flags = flags;
	this->pReserved = reserved;
}

InitializeArgs &InitializeArgs::operator=(const InitializeArgs &initializeArgs) noexcept
{
	return operator=(static_cast<const Parent &>(initializeArgs));
}

InitializeArgs &InitializeArgs::operator=(const Parent &initializeArgs) noexcept
{
	CreateMutex = initializeArgs.CreateMutex;
	DestroyMutex = initializeArgs.DestroyMutex;
	LockMutex = initializeArgs.LockMutex;
	UnlockMutex = initializeArgs.UnlockMutex;

	flags = initializeArgs.flags;
	pReserved = initializeArgs.pReserved;

	return *this;
}

}}} // flame_ide::pkcs11::structs
