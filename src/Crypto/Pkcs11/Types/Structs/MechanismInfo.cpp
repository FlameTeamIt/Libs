#include <FlameIDE/Crypto/Pkcs11/Types/Structs/MechanismInfo.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

MechanismInfo::MechanismInfo() noexcept
		: MechanismInfo(Parent{})
{}

MechanismInfo::MechanismInfo(const MechanismInfo &info) noexcept
		: MechanismInfo(static_cast<const Parent &>(info))
{}

MechanismInfo::MechanismInfo(const Parent &info) noexcept
{
	operator=(info);
}

MechanismInfo::MechanismInfo(const decltype(Parent::ulMinKeySize) &minKeySize
		, const decltype(Parent::ulMaxKeySize) &maxKeySize
		, const decltype(Parent::flags) &flags) noexcept
{
	this->ulMinKeySize = minKeySize;
	this->ulMaxKeySize = maxKeySize;
	this->flags = flags;
}

MechanismInfo &MechanismInfo::operator=(const MechanismInfo &info) noexcept
{
	return operator=(static_cast<const Parent &>(info));
}

MechanismInfo &MechanismInfo::operator=(const Parent &info) noexcept
{
	ulMinKeySize = info.ulMinKeySize;
	ulMaxKeySize = info.ulMaxKeySize;
	flags = info.flags;
	return *this;
}

}}} // flame_ide::pkcs11::structs
