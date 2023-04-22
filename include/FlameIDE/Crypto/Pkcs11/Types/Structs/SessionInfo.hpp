#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SESSION_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SESSION_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Information about a session
struct SessionInfo: public WithParent<::CK_SESSION_INFO>
{
	SessionInfo() noexcept;
	SessionInfo(const SessionInfo &info) noexcept;
	SessionInfo(const Parent &info) noexcept;

	SessionInfo(const decltype(Parent::slotID) &slotId
			, const decltype(Parent::state) &state
			, const decltype(Parent::flags) &flags
			, const decltype(Parent::ulDeviceError) &deviceError) noexcept;

	SessionInfo &operator=(const SessionInfo &info) noexcept;
	SessionInfo &operator=(const Parent &info) noexcept;

	using Parent::slotID;        ///< ?
	using Parent::state;         ///< ?
	using Parent::flags;         ///< Session flags
	using Parent::ulDeviceError; ///< Device-depend error code
};
using SessionInfoPtr = ::CK_SESSION_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SESSION_INFO_HPP
