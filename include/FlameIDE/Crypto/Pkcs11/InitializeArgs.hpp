#ifndef FLAMEIDE_CRYPTO_PKCS11_INITIALIZEARGS_HPP
#define FLAMEIDE_CRYPTO_PKCS11_INITIALIZEARGS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types.hpp>

namespace flame_ide
{
namespace pkcs11
{

/// @brief The INITIALIZEARGS class
class InitializeArgs : private structs::InitializeArgs
{
public:
	using Parent = structs::InitializeArgs;

	using Reseved = value_types::ValuePtr;
	using CallbackCreateMutex = callbacks::CreateMutex;
	using CallbackDestroyMutex = callbacks::DestroyMutex;
	using CallbackLockMutex = callbacks::LockMutex;
	using CallbackUnlockMutex = callbacks::UnlockMutex;

	/// @brief The Callbacks struct
	struct Callbacks
	{
		CallbackCreateMutex createMutexCallback = {};
		CallbackDestroyMutex destroyMutexCallback = {};
		CallbackLockMutex lockMutexCallback = {};
		CallbackUnlockMutex unlockMutexCallback = {};
	};

	using Flags = enums::InitializeArgsFlags;

	InitializeArgs() noexcept;
	InitializeArgs(const InitializeArgs &args) noexcept;
	InitializeArgs(InitializeArgs &&args) noexcept;

	/// @brief InitializeArgs
	/// @param args
	InitializeArgs(const structs::InitializeArgs &args) noexcept;

	/// @brief InitializeArgs
	/// @param callbacks
	/// @param flags
	/// @param reseved
	InitializeArgs(const Callbacks &callbacks, Flags flags
			, Reseved reseved) noexcept;

	InitializeArgs &operator=(const InitializeArgs &args) noexcept;
	InitializeArgs &operator=(InitializeArgs &&args) noexcept;

	/// @brief setCallbacks
	/// @param callbacks
	void setCallbacks(const Callbacks &callbacks) noexcept;

public:
	inline auto &getCreateMutex() noexcept
	{
		return CreateMutex;
	}
	inline const auto &getCreateMutex() const noexcept
	{
		return CreateMutex;
	}

	inline auto &getDestroyMutex() noexcept
	{
		return DestroyMutex;
	}
	inline const auto &getDestroyMutex() const noexcept
	{
		return DestroyMutex;
	}

	inline auto &getLockMutex() noexcept
	{
		return LockMutex;
	}
	inline const auto &getLockMutex() const noexcept
	{
		return LockMutex;
	}

	inline auto &getUnlockMutex() noexcept
	{
		return UnlockMutex;
	}
	inline const auto &getUnlockMutex() const noexcept
	{
		return UnlockMutex;
	}

	inline auto &getFlags() noexcept
	{
		return reinterpret_cast<Flags &>((flags));
	}
	inline const auto &getFlags() const noexcept
	{
		return reinterpret_cast<const Flags &>((flags));
	}

	inline auto &getReserved() noexcept
	{
		return pReserved;
	}
	inline const auto &getReserved() const noexcept
	{
		return pReserved;
	}

private:
	using Parent::CreateMutex;
	using Parent::DestroyMutex;
	using Parent::LockMutex;
	using Parent::UnlockMutex;
	using Parent::flags;
	using Parent::pReserved;
};

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_INITIALIZEARGS_HPP
