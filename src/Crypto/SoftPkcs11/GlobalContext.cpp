#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface.hpp>

#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

using namespace flame_ide::pkcs11;

GlobalContext::GlobalContext() noexcept
		: interface{ functionList3 }
{}

GlobalContext::~GlobalContext() noexcept
{}

// TODO
pkcs11::enums::ReturnType GlobalContext::initialize(
		const pkcs11::structs::InitializeArgs &args
) noexcept
{
}

// TODO
pkcs11::enums::ReturnType GlobalContext::finalize() noexcept
{}

// TODO
pkcs11::structs::Info GlobalContext::getInfo() noexcept
{}

// TODO
structs::FunctionListPtr GlobalContext::getFunctionList() noexcept
{
	return &functionList;
}

// TODO
void GlobalContext::getInterfaceList()
{}

// TODO
structs::InterfacePtr GlobalContext::getInterface() noexcept
{
	return &interface;
}

Mutex GlobalContext::createMutex() noexcept
{
	if (enums::value(initFlags & enums::InitializeArgsFlags::OS_LOCKING_OK))
	{
		return Mutex {
				callbacks().external.create
				, callbacks().external.destroy
				, callbacks().external.lock
				, callbacks().external.unlock
		};
	}
	else
	{
		return Mutex{};
	}
}

enums::ReturnType GlobalContext::getStatus() const noexcept
{
	return status;
}

const CallbackAggregator &GlobalContext::callbacks() const
{
	return callbackAggregator;
}

void GlobalContext::setExternalCallbacks(
		pkcs11::callbacks::CreateMutex create
		, pkcs11::callbacks::DestroyMutex destroy
		, pkcs11::callbacks::LockMutex lock
		, pkcs11::callbacks::UnlockMutex unlock
)
{
	callbackAggregator.external = ExternalCallbacks {
			create, destroy, lock, unlock
	};
}


GlobalContext &GlobalContext::get() noexcept
{
	static GlobalContext globalContext;
	return globalContext;
}

//

GlobalContext::Pkcs11Interface::Pkcs11Interface(pkcs11::structs::FunctionList3 &functionList)
		: name{ "PKCS 11" }
{
	pInterfaceName = name;
	pFunctionList = &functionList;
	flags = 0;
}

}} // namespace flame_ide::soft_pkcs11
