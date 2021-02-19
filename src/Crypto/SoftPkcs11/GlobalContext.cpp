#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

using namespace flame_ide::pkcs11;

GlobalContext &GlobalContext::get() noexcept
{
	static GlobalContext globalContext;
	return globalContext;
}

Mutex GlobalContext::createMutex() noexcept
{
	if (enums::value(
			initFlags
			& enums::InitializeArgsFlags::LIBRARY_CANT_CREATE_OS_THREADS
	))
	{
		return Mutex {
				externalCallbacks.create, externalCallbacks.destroy
				, externalCallbacks.lock, externalCallbacks.unlock
		};
	}
	else
	{
		return Mutex{};
	}
}

}}
