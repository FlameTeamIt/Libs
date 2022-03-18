#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Info.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

Info::Info() noexcept
		: Info(Parent{})
{}

Info::Info(const Info &info) noexcept
		: Info(static_cast<const Parent &>(info))
{}

Info::Info(const Info::Parent &info) noexcept
{
	operator=(info);
}

Info::Info(const decltype(Parent::cryptokiVersion) &cryptokiVersion
		, const decltype(Parent::manufacturerID) &manufacturerId
		, const decltype(Parent::flags) &flags
		, const decltype(Parent::libraryDescription) &libraryDescription
		, const decltype(Parent::libraryVersion) &libraryVersion) noexcept
{
	this->cryptokiVersion = cryptokiVersion;
	copy(this->manufacturerID, manufacturerId);
	this->flags = flags;
	copy(this->libraryDescription, libraryDescription);
	this->libraryVersion = libraryVersion;
}

Info &Info::operator=(const Info &info) noexcept
{
	return operator=(static_cast<const Parent &>(info));
}

Info &Info::operator=(const Info::Parent &info) noexcept
{
	cryptokiVersion = info.cryptokiVersion;
	copy(manufacturerID, info.manufacturerID);
	flags = info.flags;
	copy(libraryDescription, info.libraryDescription);
	libraryVersion = info.libraryVersion;
	return *this;
}

}}} // flame_ide::pkcs11::structs
