#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

struct Info: public WithParent<::CK_INFO>
{
	Info() noexcept;
	Info(const Info &info) noexcept;
	Info(const Parent &info) noexcept;

	Info(const decltype(Parent::cryptokiVersion) &cryptokiVersion
			, const decltype(Parent::manufacturerID) &manufacturerId
			, const decltype(Parent::flags) &flags
			, const decltype(Parent::libraryDescription) &libraryDescription
			, const decltype(Parent::libraryVersion) &libraryVersion) noexcept;

	Info &operator=(const Info &info) noexcept;
	Info &operator=(const Parent &info) noexcept;

	using Parent::cryptokiVersion;    ///< Cryptoki interface ver
	using Parent::manufacturerID;     ///< blank padded
	using Parent::flags;              ///< must be zero
	using Parent::libraryDescription; ///< blank padded
	using Parent::libraryVersion;     ///< version of library
};
using InfoPtr = ::CK_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INFO_HPP
