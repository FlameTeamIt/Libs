#include "FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp"
#include <FlameIDE/Crypto/Pkcs11/Pkcs11.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SlotInfo.hpp>

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

Slot::Slot(templates::SharedPointer<Pkcs11Library> library
		, pkcs11::value_types::SlotId id)
	: library{ move(library) }
	, id{ id }
{}

templates::SharedPointer<Slot>
Slot::create(templates::SharedPointer<Pkcs11Library> library
		, pkcs11::value_types::SlotId id)
{
	return templates::SharedPointer<Slot>(move(library), id);
}

const templates::SharedPointer<Pkcs11Library> &
Slot::getLibrary() const
{
	return library;
}

pkcs11::value_types::SlotId
Slot::getSlotId() const
{
	return id;
}

// Interface

Pkcs11Expected<pkcs11::structs::SlotInfo>
Slot::getSlotInfo() const
{
	Pkcs11Expected<pkcs11::structs::SlotInfo> expectedSlotInfo;
	auto functionList = library->getFunctionList();
	functionList.ifResult(
			[&expectedSlotInfo, this](FunctionList &&functionList)
			{
				pkcs11::structs::SlotInfo slotInfo;
				auto result = pkcs11::enums::toReturnType(
						functionList->C_GetSlotInfo(id, &slotInfo)
				);
				if (result != pkcs11::enums::ReturnType::OK)
				{
					expectedSlotInfo = result;
					return;
				}
				expectedSlotInfo = slotInfo;
			}
	).ifError(
			[&expectedSlotInfo](auto &&error)
			{
				expectedSlotInfo = error;
			}
	);
	return expectedSlotInfo;
}

pkcs11::enums::ReturnType
Slot::waitForSlotEvent(pkcs11::enums::WaitForSlotEventFlags waitFlags)
{
	auto result = pkcs11::enums::ReturnType::OK;
	auto functionList = library->getFunctionList();
	functionList.ifResult(
			[flags = pkcs11::enums::value(waitFlags), &result, this](FunctionList &&functionList)
			{
				result = pkcs11::enums::toReturnType(
						functionList->C_WaitForSlotEvent(flags, &id, nullptr)
				);
			}
	).ifError(
			[&result](auto &&error)
			{
				result = error;
			}
	);
	return result;
}

}}} // namespace flame_ide::pkcs11::wrapper
