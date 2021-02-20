#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/GeneralPurposeFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

#include <FlameIDE/Crypto/Pkcs11/InitializeArgs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace general_purpose
{

using namespace pkcs11;

value_types::ReturnType initialize(pkcs11::value_types::ValuePtr arguments)
{
	if (!arguments)
	{
		return enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}

	pkcs11::InitializeArgs initializeArgs {
		*static_cast<pkcs11::structs::InitializeArgsPtr>(arguments)
	};
	auto &context = GlobalContext::get();
	if (enums::value(
			enums::InitializeArgsFlags::OS_LOCKING_OK & initializeArgs.getFlags()
	))
	{
		context.externalCallbacks.create = initializeArgs.getCreateMutex();
		context.externalCallbacks.destroy = initializeArgs.getDestroyMutex();
		context.externalCallbacks.lock = initializeArgs.getLockMutex();
		context.externalCallbacks.unlock = initializeArgs.getUnlockMutex();
	}
	context.initFlags = initializeArgs.getFlags();

	// TODO

	return pkcs11::enums::value(context.getStatus());
}

value_types::ReturnType finalize(pkcs11::value_types::ValuePtr /* reserved */)
{
	// TODO

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

value_types::ReturnType getInfo(pkcs11::structs::InfoPtr info)
{
	if (!info)
	{
		return enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}

	structs::Info tmpInfo = {
		GlobalContext::get().oasisVersion
		, ""
		, value_types::Flags{}
		, "Flame Soft PKCS#11"
		, structs::Version{ 0, 0 }
	};
	*info = tmpInfo;
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

value_types::ReturnType getFunctionList(
		pkcs11::structs::FunctionListPtrPtr functionList
)
{
	if (!functionList)
	{
		pkcs11::enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}

	*functionList = GlobalContext::get().getFunctionList();
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::service
