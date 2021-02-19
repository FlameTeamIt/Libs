#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MUTEX_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MUTEX_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Callbacks.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

class Mutex final
{
public:
	using Context = CK_VOID_PTR;

public:
	Mutex() noexcept;

	Mutex(const Mutex &mutex) = delete;

	Mutex(Mutex &&mutex) noexcept;

	Mutex(flame_ide::pkcs11::callbacks::CreateMutex create
			, flame_ide::pkcs11::callbacks::DestroyMutex destroy
			, flame_ide::pkcs11::callbacks::LockMutex lock
			, flame_ide::pkcs11::callbacks::UnlockMutex unlock) noexcept;


	~Mutex() noexcept;

	Mutex &operator=(const Mutex &mutex) noexcept = delete;
	Mutex &operator=(Mutex &&mutex) noexcept;

	void lock() noexcept;

	void unlock() noexcept;

	void destroy() noexcept;

	flame_ide::pkcs11::enums::ReturnType getLastStatus() const noexcept;

private:
	flame_ide::pkcs11::callbacks::DestroyMutex destroyMutex;

	flame_ide::pkcs11::callbacks::LockMutex lockMutex;
	flame_ide::pkcs11::callbacks::UnlockMutex unlockMutex;

	Context context = nullptr;
	flame_ide::pkcs11::enums::ReturnType lastStatus =
			flame_ide::pkcs11::enums::ReturnType::OK;
};

}} // namespace flame_ide::soft_pkcs11


#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MUTEX_HPP
