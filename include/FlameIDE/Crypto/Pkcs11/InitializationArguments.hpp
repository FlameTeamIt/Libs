#ifndef FLAMEIDE_CRYPTO_PKCS11_INITIALIZATIONARGUMENTS_HPP
#define FLAMEIDE_CRYPTO_PKCS11_INITIALIZATIONARGUMENTS_HPP

#include "cryptoki/pkcs11.h"

namespace flame_ide
{
namespace pkcs11
{

/// @brief The InitializationArguments class
class InitializationArguments : public CK_C_INITIALIZE_ARGS
{
public:
	using ResevedType = decltype(CK_C_INITIALIZE_ARGS::pReserved);
	using CallbackCreateMutex = decltype(CK_C_INITIALIZE_ARGS::CreateMutex);
	using CallbackDestroyMutex = decltype(CK_C_INITIALIZE_ARGS::DestroyMutex);
	using CallbackLockMutex = decltype(CK_C_INITIALIZE_ARGS::LockMutex);
	using CallbackUnlockMutex = decltype(CK_C_INITIALIZE_ARGS::UnlockMutex);

	/// @brief The Callbacks struct
	struct Callbacks
	{
		CallbackCreateMutex createMutexCallback = {};
		CallbackDestroyMutex destroyMutexCallback = {};
		CallbackLockMutex lockMutexCallback = {};
		CallbackUnlockMutex unlockMutexCallback = {};
	};

	/// @brief The Flags enum
	enum class Flags : CK_FLAGS
	{
		NO_FLAGS
		, LIBRARY_CANT_CREATE_OS_THREADS = CKF_LIBRARY_CANT_CREATE_OS_THREADS
		, OS_LOCKING_OK = CKF_OS_LOCKING_OK
	};

	InitializationArguments() noexcept;
	InitializationArguments(const InitializationArguments &args) noexcept;
	InitializationArguments(InitializationArguments &&args) noexcept;

	/// @brief InitializationArguments
	/// @param callbacks
	/// @param flags
	/// @param reseved
	InitializationArguments(const Callbacks &callbacks, Flags flags
			, ResevedType reseved) noexcept;

	InitializationArguments &operator=(const InitializationArguments &args) noexcept;
	InitializationArguments &operator=(InitializationArguments &&args) noexcept;

	/// @brief setCallbacks
	/// @param callbacks
	void setCallbacks(const Callbacks &callbacks) noexcept;

private:
	using CK_C_INITIALIZE_ARGS::CreateMutex;
	using CK_C_INITIALIZE_ARGS::DestroyMutex;
	using CK_C_INITIALIZE_ARGS::LockMutex;
	using CK_C_INITIALIZE_ARGS::UnlockMutex;
	using CK_C_INITIALIZE_ARGS::flags;
	using CK_C_INITIALIZE_ARGS::pReserved;
};

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_INITIALIZATIONARGUMENTS_HPP
