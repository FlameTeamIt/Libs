#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface.hpp>

#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

using namespace flame_ide::pkcs11;

Pkcs11Interface::Pkcs11Interface(pkcs11::structs::FunctionList3 &functionList)
		: name{ "PKCS 11" }
{
	pInterfaceName = name;
	pFunctionList = &functionList;
	flags = 0;
}

GlobalContext::GlobalContext() noexcept
		: interface{ functionList3 }
{}

GlobalContext::~GlobalContext() noexcept
{}

Mutex GlobalContext::createMutex() noexcept
{
	if (enums::value(initFlags & enums::InitializeArgsFlags::OS_LOCKING_OK))
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

structs::FunctionListPtr GlobalContext::getFunctionList() noexcept
{
	return &functionList;
}

structs::InterfacePtr GlobalContext::getInterface() noexcept
{
	return &interface;
}

enums::ReturnType GlobalContext::getStatus() const noexcept
{
	return status;
}

GlobalContext &GlobalContext::get() noexcept
{
	static GlobalContext globalContext;
	return globalContext;
}

}}
