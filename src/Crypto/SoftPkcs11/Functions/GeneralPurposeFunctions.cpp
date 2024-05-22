#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/GeneralPurposeFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/InitializeArgs.hpp>

#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace general_purpose
{

pkcs11::value_types::ReturnType initialize(pkcs11::value_types::ValuePtr arguments)
{
	if (!arguments)
	{
		return pkcs11::enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}

	pkcs11::structs::InitializeArgs& initializeArgs
			= *static_cast<pkcs11::structs::InitializeArgs*>(arguments);

	GlobalContext &context = GlobalContext::get();
	if (pkcs11::enums::value(pkcs11::enums::InitializeArgsFlags::OS_LOCKING_OK)
			& initializeArgs.flags)
	{
//		context.setExternalCallbacks(
//				initializeArgs.CreateMutex
//				, initializeArgs.DestroyMutex
//				, initializeArgs.LockMutex
//				, initializeArgs.UnlockMutex
//		);
	}

	return pkcs11::enums::value(context.getStatus());
}

pkcs11::value_types::ReturnType finalize(pkcs11::value_types::ValuePtr /* reserved */)
{
	// TODO
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getInfo(pkcs11::structs::InfoPtr info)
{
	if (!info)
	{
		return pkcs11::enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}

	pkcs11::structs::Info tmpInfo = {
		flame_ide::pkcs11::structs::Version{}
		, decltype(pkcs11::structs::Info::Parent::manufacturerID){ "NONE" }
		, pkcs11::value_types::Flags{}
		, decltype(pkcs11::structs::Info::Parent::libraryDescription){ "Flame Soft PKCS#11" }
		, pkcs11::structs::Version{ 0, 0 }
	};
	*info = tmpInfo;
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getFunctionList(
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

pkcs11::value_types::ReturnType getIterfaceList(
		pkcs11::structs::InterfacePtr interfaces
		, pkcs11::value_types::UlongPtr count
)
{
	if ((!interfaces && !count) || !count)
	{
		return pkcs11::enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
	}
	if (!interfaces)
	{
		*count = 1;
		return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
	}
	interfaces[0] = *GlobalContext::get().getInterface();
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getIterface(
		pkcs11::value_types::Utf8CharPtr interfaceName
		, pkcs11::structs::VersionPtr version
		, pkcs11::structs::InterfacePtrPtr interface
		, pkcs11::value_types::Flags flags
)
{
	// TODO
	flame_ide::unused(version);
	flame_ide::unused(interface);
	flame_ide::unused(flags);

	const pkcs11::value_types::Utf8Char mainInterfaceName[] = "PKCS 11";
	if (templates::U8String::rawStringLength(interfaceName) != sizeof(mainInterfaceName) - 1)
	{

	}

	return pkcs11::enums::value(pkcs11::enums::ReturnType::ARGUMENTS_BAD);
}

}}}} // flame_ide::soft_pkcs11::functions::general_purpose
