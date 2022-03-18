#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INITIALIZE_ARGS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INITIALIZE_ARGS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provides the optional arguments to C_Initialize
struct InitializeArgs: public WithParent<::CK_C_INITIALIZE_ARGS>
{
	InitializeArgs() noexcept;
	InitializeArgs(const InitializeArgs &initializeArgs) noexcept;
	InitializeArgs(const Parent &initializeArgs) noexcept;

	InitializeArgs(
			const decltype(Parent::CreateMutex) &createMutexCallback
			, const decltype(Parent::DestroyMutex) &destroyMutexCallback
			, const decltype(Parent::LockMutex) &lockMutexCallback
			, const decltype(Parent::UnlockMutex) &unlockMutexCallback
			, const decltype(Parent::flags) &flags
			, const decltype(Parent::pReserved) reserved = decltype(Parent::pReserved){}
	) noexcept;

	InitializeArgs &operator=(const InitializeArgs &initializeArgs) noexcept;
	InitializeArgs &operator=(const Parent &initializeArgs) noexcept;

	using Parent::CreateMutex;
	using Parent::DestroyMutex;
	using Parent::LockMutex;
	using Parent::UnlockMutex;
	using Parent::flags;
	using Parent::pReserved;
};
using InitializeArgsPtr = ::CK_C_INITIALIZE_ARGS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_INITIALIZE_ARGS_HPP
