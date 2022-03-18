#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TokenInfo.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

TokenInfo::TokenInfo() noexcept
		: TokenInfo(Parent{})
{}

TokenInfo::TokenInfo(const TokenInfo &info) noexcept
		: TokenInfo(static_cast<const Parent &>(info))
{}

TokenInfo::TokenInfo(const Parent &info) noexcept
{
	operator=(info);
}

TokenInfo::TokenInfo(const decltype(Parent::label) &label
		, const decltype(Parent::manufacturerID) &manufacturerId
		, const decltype(Parent::model) &model
		, const decltype(Parent::serialNumber) &serialNumber
		, const decltype(Parent::flags) &flags
		, const decltype(Parent::ulMaxSessionCount) &maxSessionCount
		, const decltype(Parent::ulSessionCount) &sessionCount
		, const decltype(Parent::ulMaxRwSessionCount) &maxRwSessionCount
		, const decltype(Parent::ulRwSessionCount) &rwSessionCount
		, const decltype(Parent::ulMaxPinLen) &maxPinLen
		, const decltype(Parent::ulMinPinLen) &minPinLen
		, const decltype(Parent::ulTotalPublicMemory) &totalPublicMemory
		, const decltype(Parent::ulFreePublicMemory) &freePublicMemory
		, const decltype(Parent::ulTotalPrivateMemory) &totalPrivateMemory
		, const decltype(Parent::ulFreePrivateMemory) &freePrivateMemory
		, const decltype(Parent::hardwareVersion) &hardwareVersion
		, const decltype(Parent::firmwareVersion) &firmwareVersion
		, const decltype(Parent::utcTime) &utcTime) noexcept
{
	copy(this->label, label);
	copy(this->manufacturerID, manufacturerId);
	copy(this->model, model);
	copy(this->serialNumber, serialNumber);
	this->flags = flags;

	this->ulMaxSessionCount = maxSessionCount;
	this->ulSessionCount = sessionCount;
	this->ulMaxRwSessionCount = maxRwSessionCount;
	this->ulRwSessionCount = rwSessionCount;
	this->ulMaxPinLen = maxPinLen;
	this->ulMinPinLen = minPinLen;
	this->ulTotalPublicMemory = totalPublicMemory;
	this->ulFreePublicMemory = freePublicMemory;
	this->ulTotalPrivateMemory = totalPrivateMemory;
	this->ulFreePrivateMemory = freePrivateMemory;
	this->hardwareVersion = hardwareVersion;
	this->firmwareVersion = firmwareVersion;
	copy(this->utcTime, utcTime);
}

TokenInfo &TokenInfo::operator=(const TokenInfo &info) noexcept
{
	return operator=(static_cast<const Parent &>(info));
}

TokenInfo &TokenInfo::operator=(const Parent &info) noexcept
{
	copy(label, info.label);
	copy(manufacturerID, info.manufacturerID);
	copy(model, info.model);
	copy(serialNumber, info.serialNumber);
	flags = info.flags;

	ulMaxSessionCount = info.ulMaxSessionCount;
	ulSessionCount = info.ulSessionCount;
	ulMaxRwSessionCount = info.ulMaxRwSessionCount;
	ulRwSessionCount = info.ulRwSessionCount;
	ulMaxPinLen = info.ulMaxPinLen;
	ulMinPinLen = info.ulMinPinLen;
	ulTotalPublicMemory = info.ulTotalPublicMemory;
	ulFreePublicMemory = info.ulFreePublicMemory;
	ulTotalPrivateMemory = info.ulTotalPrivateMemory;
	ulFreePrivateMemory = info.ulFreePrivateMemory;
	hardwareVersion = info.hardwareVersion;
	firmwareVersion = info.firmwareVersion;
	copy(utcTime, info.utcTime);

	return *this;
}

}}} // flame_ide::pkcs11::structs
