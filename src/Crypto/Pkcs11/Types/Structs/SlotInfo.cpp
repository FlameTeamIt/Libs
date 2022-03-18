#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SlotInfo.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

SlotInfo::SlotInfo() noexcept
{}

SlotInfo::SlotInfo(const SlotInfo &info) noexcept
		: SlotInfo(static_cast<const Parent &>(info))
{}

SlotInfo::SlotInfo(const SlotInfo::Parent &info) noexcept
{
	operator=(info);
}

SlotInfo::SlotInfo(const decltype(Parent::slotDescription) &slotDescription
		, const decltype(Parent::manufacturerID) &manufacturerId
		, const decltype(Parent::flags) &flags
		, const decltype(Parent::hardwareVersion) &hardwareVersion
		, const decltype(Parent::firmwareVersion) &firmwareVersion) noexcept
{
	copy(this->slotDescription, slotDescription);
	copy(this->manufacturerID, manufacturerId);
	this->flags = flags;

	this->hardwareVersion = hardwareVersion;
	this->firmwareVersion = firmwareVersion;
}

SlotInfo &SlotInfo::operator=(const SlotInfo &info) noexcept
{
	return operator=(static_cast<const Parent &>(info));
}

SlotInfo &SlotInfo::operator=(const Parent &info) noexcept
{
	copy(slotDescription, info.slotDescription);
	copy(manufacturerID, info.manufacturerID);
	flags = info.flags;

	hardwareVersion = info.hardwareVersion;
	firmwareVersion = info.firmwareVersion;

	return *this;
}

}}} // flame_ide::pkcs11::structs
