#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_VERSION_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_VERSION_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

struct Version: public WithParent<::CK_VERSION>
{
	Version() noexcept;
	Version(const Version &version) noexcept;
	Version(const Parent &version) noexcept;

	Version(const decltype(Parent::major) &major
			, const decltype(Parent::minor) &minor) noexcept;

	Version &operator=(const Version &version) noexcept;
	Version &operator=(const Parent &version) noexcept;

	using Parent::major; ///< Integer portion of version number
	using Parent::minor; ///< 1/100ths portion of version number
};
using VersionPtr = ::CK_VERSION_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_VERSION_HPP
