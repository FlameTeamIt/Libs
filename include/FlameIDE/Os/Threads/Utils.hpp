#ifndef FLAMEIDE_OS_THREADS_UTILS_HPP
#define FLAMEIDE_OS_THREADS_UTILS_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

class Semaphore;
class Mutex;
class Spin;

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

class Locker
{
public:
	Locker() noexcept = delete;
	Locker(const Locker &) noexcept = delete;
	Locker(Locker &&) noexcept = delete;

	Locker(Semaphore &semaphore) noexcept;
	Locker(Mutex &mutex) noexcept;
	Locker(Spin &spin) noexcept;
	~Locker() noexcept;

	Locker &operator=(const Locker &) noexcept = delete;
	Locker &operator=(Locker &&) noexcept = delete;

private:
	using CallbackUnlock = void (*)(void *);

private:
	CallbackUnlock callbackUnlock = nullptr;
	void *data;
};

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

class UniqueLocker
{
private:
	class Lock {};
	class TryLock {};
	class Unlock {};

public:
	static constexpr Lock LOCK{};
	static constexpr TryLock TRY_LOCK{};
	static constexpr Unlock UNLOCK{};

public:
	UniqueLocker() noexcept = delete;
	UniqueLocker(const UniqueLocker &) noexcept = default;
	UniqueLocker(UniqueLocker &&locker) noexcept;

	UniqueLocker(Semaphore &semaphore) noexcept;
	UniqueLocker(Semaphore &semaphore, Lock) noexcept;
	UniqueLocker(Semaphore &semaphore, TryLock) noexcept;
	UniqueLocker(Semaphore &semaphore, Unlock) noexcept;

	UniqueLocker(Mutex &mutex) noexcept;
	UniqueLocker(Mutex &mutex, Lock) noexcept;
	UniqueLocker(Mutex &mutex, TryLock) noexcept;
	UniqueLocker(Mutex &mutex, Unlock) noexcept;

	UniqueLocker(Spin &spin) noexcept;
	UniqueLocker(Spin &spin, Lock) noexcept;
	UniqueLocker(Spin &spin, TryLock) noexcept;
	UniqueLocker(Spin &spin, Unlock) noexcept;

	~UniqueLocker() noexcept;

	UniqueLocker &operator=(const UniqueLocker &) noexcept = default;
	UniqueLocker &operator=(UniqueLocker &&locker) noexcept;

	os::Status getStatus() const;

	os::Status lock() noexcept;
	bool tryLock() noexcept;
	os::Status unlock() noexcept;

private:
	enum class Status
	{
		LOCKED
		, UNLOCKED
	};

private:
	using CallbackStatus = os::Status (*)(const void *);
	using CallbackLock = void (*)(void *);
	using CallbackTryLock = bool (*)(void *);
	using CallbackUnlock = void (*)(void *);

private:
	CallbackStatus callbackStatus = nullptr;
	CallbackLock callbackLock = nullptr;
	CallbackTryLock callbackTryLock = nullptr;
	CallbackUnlock callbackUnlock = nullptr;
	void *data = nullptr;
	bool locked = false;
};

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_UTILS_HPP
