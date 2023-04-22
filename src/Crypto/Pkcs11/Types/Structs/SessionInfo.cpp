#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SessionInfo.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

SessionInfo::SessionInfo() noexcept
		: SessionInfo(Parent{})
{}

SessionInfo::SessionInfo(const SessionInfo &info) noexcept
		: SessionInfo(static_cast<const Parent &>(info))
{}

SessionInfo::SessionInfo(const Parent &info) noexcept
{
	operator=(info);
}

SessionInfo::SessionInfo(const decltype(Parent::slotID) &slotId
		, const decltype(Parent::state) &state
		, const decltype(Parent::flags) &flags
		, const decltype(Parent::ulDeviceError) &deviceError) noexcept
{
	this->slotID = slotId;
	this->state = state;
	this->flags = flags;
	this->ulDeviceError = deviceError;
}

SessionInfo &SessionInfo::operator=(const SessionInfo &info) noexcept
{
	return operator=(static_cast<const Parent &>(info));
}

SessionInfo &SessionInfo::operator=(const Parent &info) noexcept
{
	slotID = info.slotID;
	state = info.state;
	flags = info.flags;
	ulDeviceError = info.ulDeviceError;
	return *this;
}

}}} // flame_ide::pkcs11::structs
