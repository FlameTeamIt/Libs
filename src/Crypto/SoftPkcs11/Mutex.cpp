#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mutex.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

using namespace flame_ide::pkcs11;

namespace
{

template<typename T>
value_types::ReturnType Stub(T)
{
	return static_cast<value_types::ReturnType>(enums::ReturnType::OK);
}

}

Mutex::Mutex() noexcept
	: Mutex(Stub<Context*>, Stub<Context>, Stub<Context>, Stub<Context>)
{}

Mutex::Mutex(Mutex &&mutex) noexcept
	: destroyMutex(mutex.destroyMutex)
	, lockMutex(mutex.lockMutex)
	, unlockMutex(mutex.unlockMutex)
	, context(mutex.context)
	, lastStatus(mutex.lastStatus)
{
	mutex.context = nullptr;
}

Mutex::Mutex(callbacks::CreateMutex createMutex
		, callbacks::DestroyMutex destroyMutex
		, callbacks::LockMutex lockMutex
		, callbacks::UnlockMutex unlockMutex) noexcept
	: destroyMutex(destroyMutex)
	, lockMutex(lockMutex)
	, unlockMutex(unlockMutex)
{
	if (!createMutex || !destroyMutex || !lockMutex || !unlockMutex)
	{
		lastStatus = enums::ReturnType::ARGUMENTS_BAD;
		return;
	}
	lastStatus = static_cast<enums::ReturnType>(createMutex(&context));
}

Mutex::~Mutex() noexcept
{
	destroy();
}

Mutex &Mutex::operator=(Mutex &&mutex) noexcept
{
	destroyMutex = mutex.destroyMutex;
	lockMutex = mutex.lockMutex;
	unlockMutex = mutex.unlockMutex;
	context = mutex.context;
	lastStatus = mutex.lastStatus;

	mutex.context = nullptr;

	return *this;
}

void Mutex::lock() noexcept
{
	lastStatus = static_cast<enums::ReturnType>(lockMutex(context));
}

void Mutex::unlock() noexcept
{
	lastStatus = static_cast<enums::ReturnType>(lockMutex(context));
}

void Mutex::destroy() noexcept
{
	lastStatus = static_cast<enums::ReturnType>(destroyMutex(context));
	context = nullptr;
}

enums::ReturnType Mutex::getLastStatus() const noexcept
{
	return lastStatus;
}

}} // namespace flame_ide::soft_pkcs11
