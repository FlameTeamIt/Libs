#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Version.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

Version::Version() noexcept
		: Version(Parent{0, 0})
{}

Version::Version(const Version &version) noexcept
		: Version(static_cast<const Parent &>(version))
{}

Version::Version(const Version::Parent &version) noexcept
{
	operator=(version);
}

Version::Version(const decltype(Parent::major) &major
		, const decltype(Parent::minor) &minor) noexcept
{
	this->major = major;
	this->minor = minor;
}

Version &Version::operator=(const Version &version) noexcept
{
	return operator=(static_cast<const Parent &>(version));
}

Version &Version::operator=(const Parent &version) noexcept
{
	major = version.major;
	minor = version.minor;
	return *this;
}

}}} // flame_ide::pkcs11::structs
