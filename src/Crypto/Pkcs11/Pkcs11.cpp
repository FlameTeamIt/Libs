#include <FlameIDE/Crypto/Pkcs11/Pkcs11.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Callbacks.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

Pkcs11Library::Pkcs11Library(const char *name, const char *directory) noexcept
		: os::Library(name, directory)
{}

Pkcs11Library::~Pkcs11Library() noexcept
{
	finalize();
}

templates::SharedPointer<Pkcs11Library>
Pkcs11Library::create(const char *name, const char *directory) noexcept
{
	return templates::SharedPointer<Pkcs11Library>(name, directory);
}

templates::SharedPointer<Pkcs11Library>
Pkcs11Library::create(const char *name, const char *directory
		, pkcs11::structs::InitializeArgs args) noexcept
{
	auto library = create(name, directory);
	library->initialize(args);
	return library;
}

pkcs11::enums::ReturnType
Pkcs11Library::initialize(const pkcs11::wrapper::InitializeArgs &args) noexcept
{
	// Initialize function list
	auto result = initializeFunctionList();
	if (result != pkcs11::enums::ReturnType::OK)
	{
		return result;
	}

	// Interface list
	result = initializeInterfaceList();
	if (result != pkcs11::enums::ReturnType::OK
			&& result != pkcs11::enums::ReturnType::FUNCTION_NOT_SUPPORTED)
	{
		return result;
	}

	// Main initialization
	if ((result = initializeMain(args.getOriginal())) != pkcs11::enums::ReturnType::OK)
	{
		return result;
	}

	// Cryptoki info
	if ((result = initializeInfo()) != pkcs11::enums::ReturnType::OK)
	{
		return result;
	}

	status = pkcs11::enums::ReturnType::OK;
	return status;
}

pkcs11::enums::ReturnType
Pkcs11Library::finalize() noexcept
{
	pkcs11::enums::ReturnType result = pkcs11::enums::ReturnType::OK;
	auto functionList = getFunctionList();
	functionList.ifResult(
			[&result](FunctionList functionList)
			{
				result = pkcs11::enums::toReturnType(functionList->C_Finalize(nullptr));
			}
	).ifError(
			[&result](auto error)
			{
				result = error;
			}
	);
	return result;
}

Pkcs11Expected<pkcs11::structs::Info>
Pkcs11Library::getInfo() const noexcept
{
	return createPkcs11Expected(info, status);
}

Pkcs11Expected<FunctionList>
Pkcs11Library::getFunctionList() const noexcept
{
	return createPkcs11Expected(FunctionList(&functionList), status);
}

Pkcs11Expected<const pkcs11::structs::InterfaceList *>
Pkcs11Library::getInterfaceList() const noexcept
{
	const pkcs11::structs::InterfaceList *ifaceListPtr = nullptr;
	pkcs11::enums::ReturnType returnError;
	ifaceList.ifResult(
			[&ifaceListPtr](const auto &ifaceList)
			{
				ifaceListPtr = &ifaceList;
			}
	).ifError(
			[&returnError](auto error)
			{
				returnError = error;
			}
	).done();
	Pkcs11Expected<const pkcs11::structs::InterfaceList *> expectedInterfaceList;
	if (ifaceListPtr)
	{
		expectedInterfaceList = ifaceListPtr;
	}
	else
	{
		expectedInterfaceList = returnError;
	}
	return expectedInterfaceList;
}

Pkcs11Expected<const pkcs11::structs::Interface *>
Pkcs11Library::getInterface() const noexcept
{
	const pkcs11::structs::Interface *ifacePtr = nullptr;
	pkcs11::enums::ReturnType returnError;
	ifaceList.ifResult(
			[&ifacePtr](const auto &ifaceList)
			{
				// TODO
				ifacePtr = &ifaceList[0];
			}
	).ifError(
			[&returnError](auto error)
			{
				returnError = error;
			}
	).done();

	Pkcs11Expected<const pkcs11::structs::Interface *> expectedInterface;
	if (ifacePtr)
	{
		expectedInterface = ifacePtr;
	}
	else
	{
		expectedInterface = returnError;
	}
	return expectedInterface;
}

Pkcs11Expected<pkcs11::value_types::Ulong>
Pkcs11Library::getSlotIdCount(pkcs11::enums::Bool present) const noexcept
{
	pkcs11::value_types::Ulong slotIdCount = 0;
	auto result = pkcs11::enums::ReturnType::OK;
	auto functionList = getFunctionList();
	functionList.ifResult(
			[&slotIdCount, &result, present](FunctionList functionList)
			{
				result = pkcs11::enums::toReturnType(
						functionList->C_GetSlotList(
								pkcs11::enums::value(present), nullptr, &slotIdCount
						)
				);
			}
	).ifError(
			[&result](auto error)
			{
				result = error;
			}
	);
	return createPkcs11Expected(slotIdCount, result);
}

Pkcs11Expected<pkcs11::structs::SlotIdList>
Pkcs11Library::getSlotIdList(pkcs11::enums::Bool present) const noexcept
{
	pkcs11::structs::SlotIdList slotIds;
	auto slotIdCount = getSlotIdCount(present);
	auto result = pkcs11::enums::ReturnType::OK;
	slotIdCount.ifResult(
			[this, &slotIds, &result, present](pkcs11::value_types::Ulong slotIdCount)
			{
				slotIds.reserve(slotIdCount);
				slotIds.resize(slotIdCount);
				auto functionList = getFunctionList();
				functionList.ifResult(
						[&slotIds, &slotIdCount, &result, present](FunctionList functionList)
						{
							result = pkcs11::enums::toReturnType(
									functionList->C_GetSlotList(
											pkcs11::enums::value(present), slotIds.data()
											, &slotIdCount
									)
							);
						}
				);
			}
	).ifError(
			[&result](auto error)
			{
				result = error;
			}
	);

	Pkcs11Expected<pkcs11::structs::SlotIdList> expectedSlotIds;
	if (result == pkcs11::enums::ReturnType::OK)
	{
		expectedSlotIds = move(slotIds);
	}
	else
	{
		expectedSlotIds = result;
	}
	return expectedSlotIds;
}

// private

pkcs11::enums::ReturnType
Pkcs11Library::initializeFunctionList() noexcept
{
	auto getFunctionList = find<pkcs11::callbacks::GetFunctionList>(
			pkcs11::callbacks::names::GetFunctionList
	);
	if (!getFunctionList)
	{
		return status;
	}

	pkcs11::structs::FunctionListPtr functionListPtr;
	auto result = pkcs11::enums::toReturnType(
			getFunctionList(&functionListPtr)
	);

	if (result != pkcs11::enums::ReturnType::OK)
	{
		return result;
	}
	functionList = *functionListPtr;

	return result;
}

pkcs11::enums::ReturnType
Pkcs11Library::initializeInterfaceList() noexcept
{
	auto getInterfaceList = find<pkcs11::callbacks::GetInterfaceList>(
			pkcs11::callbacks::names::GetInterfaceList
	);
	if (!getInterfaceList)
	{
		return pkcs11::enums::ReturnType::FUNCTION_NOT_SUPPORTED;
	}

	pkcs11::value_types::Ulong count = 0;
	auto result = pkcs11::enums::toReturnType(
			getInterfaceList(nullptr, &count)
	);
	if (result != pkcs11::enums::ReturnType::OK)
	{
		return result;
	}
	if (count)
	{
		pkcs11::structs::InterfaceList list;
		list.reserve(count);
		result = pkcs11::enums::toReturnType(
				getInterfaceList(list.data(), &count)
		);
		if (result != pkcs11::enums::ReturnType::OK)
		{
			ifaceList = result;
			return result;
		}
		ifaceList = flame_ide::move(list);
	}

	return result;
}

pkcs11::enums::ReturnType
Pkcs11Library::initializeMain(pkcs11::structs::InitializeArgs args) noexcept
{
	return pkcs11::enums::toReturnType(
			functionList.C_Initialize(&args)
	);
}

pkcs11::enums::ReturnType
Pkcs11Library::initializeInfo() noexcept
{
	return pkcs11::enums::toReturnType(
			functionList.C_GetInfo(&info)
	);
}

}}} // namespace flame_ide::pkcs11::wrapper
