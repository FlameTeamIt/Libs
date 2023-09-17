#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/Os/Threads/Semaphore.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

namespace flame_ide
{namespace os
{namespace threads
{
namespace // anonymous
{

void unlockSemaphore(Semaphore *semaphore);
void unlockMutex(Mutex *mutex);
void unlockSpin(Spin *spin);

void lockSemaphore(Semaphore *semaphore);
void lockMutex(Mutex *mutex);
void lockSpin(Spin *spin);

bool tryLockSemaphore(Semaphore *semaphore);
bool tryLockMutex(Mutex *mutex);
bool tryLockSpin(Spin *spin);

os::Status getSemaphoreStatus(const Semaphore *semaphore);
os::Status getMutexStatus(const Mutex *mutex);
os::Status getSpinStatus(const Spin *spin);

} // namespace anonymous
}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

Locker::Locker(Semaphore &semaphore) noexcept
		: callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockSemaphore) }
		, data{ &semaphore }
{
	semaphore.wait();
}

Locker::Locker(Mutex &mutex) noexcept
		: callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockMutex) }
		, data{ &mutex }
{
	mutex.lock();
}

Locker::Locker(Spin &spin) noexcept
	: callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockSpin) }
	, data{ &spin }
{
	spin.lock();
}

Locker::~Locker() noexcept
{
	callbackUnlock(data);
}

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

UniqueLocker::UniqueLocker(UniqueLocker &&locker) noexcept
{
	operator=(move(locker));
}

UniqueLocker::UniqueLocker(Semaphore &semaphore) noexcept
		: callbackStatus{ reinterpret_cast<CallbackStatus>(getSemaphoreStatus) }
		, callbackLock{ reinterpret_cast<CallbackLock>(lockSemaphore) }
		, callbackTryLock{ reinterpret_cast<CallbackTryLock>(tryLockSemaphore) }
		, callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockSemaphore) }
		, data{ &semaphore }
{}

UniqueLocker::UniqueLocker(Semaphore &semaphore, Lock) noexcept
		: UniqueLocker(semaphore)
{
	lock();
}

UniqueLocker::UniqueLocker(Semaphore &semaphore, TryLock) noexcept
		: UniqueLocker(semaphore)
{
	tryLock();
}

UniqueLocker::UniqueLocker(Semaphore &semaphore, Unlock) noexcept
		: UniqueLocker(semaphore)
{
	unlock();
}

UniqueLocker::UniqueLocker(Mutex &mutex) noexcept
		: callbackStatus{ reinterpret_cast<CallbackStatus>(getMutexStatus) }
		, callbackLock{ reinterpret_cast<CallbackLock>(lockMutex) }
		, callbackTryLock{ reinterpret_cast<CallbackTryLock>(tryLockMutex) }
		, callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockMutex) }
		, data{ &mutex }
{}

UniqueLocker::UniqueLocker(Mutex &mutex, Lock) noexcept
		: UniqueLocker(mutex)
{
	lock();
}

UniqueLocker::UniqueLocker(Mutex &mutex, TryLock) noexcept
		: UniqueLocker(mutex)
{
	tryLock();
}

UniqueLocker::UniqueLocker(Mutex &mutex, Unlock) noexcept
		: UniqueLocker(mutex)
{
	unlock();
}

UniqueLocker::UniqueLocker(Spin &spin) noexcept
	: callbackStatus{ reinterpret_cast<CallbackStatus>(getSpinStatus) }
	, callbackLock{ reinterpret_cast<CallbackLock>(lockSpin) }
	, callbackTryLock{ reinterpret_cast<CallbackTryLock>(tryLockSpin) }
	, callbackUnlock{ reinterpret_cast<CallbackUnlock>(unlockSpin) }
	, data{ &spin }
{}

UniqueLocker::UniqueLocker(Spin &spin, Lock) noexcept
		: UniqueLocker(spin)
{
	lock();
}

UniqueLocker::UniqueLocker(Spin &spin, TryLock) noexcept
		: UniqueLocker(spin)
{
	tryLock();
}

UniqueLocker::UniqueLocker(Spin &spin, Unlock) noexcept
		: UniqueLocker(spin)
{
	unlock();
}

UniqueLocker::~UniqueLocker() noexcept
{
	if (locked)
		unlock();
}

UniqueLocker &UniqueLocker::operator=(UniqueLocker &&locker) noexcept
{
	callbackStatus = locker.callbackStatus;
	callbackLock = locker.callbackLock;
	callbackTryLock = locker.callbackTryLock;
	callbackUnlock = locker.callbackUnlock;
	data = locker.data;
	locked = locker.locked;

	locker.callbackStatus = nullptr;
	locker.callbackLock = nullptr;
	locker.callbackTryLock = nullptr;
	locker.callbackUnlock = nullptr;
	locker.data = nullptr;
	locked = false;

	return *this;
}

os::Status UniqueLocker::getStatus() const
{
	return callbackStatus(data);
}

os::Status UniqueLocker::lock() noexcept
{
	callbackLock(data);
	locked = true;
	return getStatus();
}

bool UniqueLocker::tryLock() noexcept
{
	if (locked)
		return callbackTryLock(data);

	locked = callbackTryLock(data);
	return locked;
}

os::Status UniqueLocker::unlock() noexcept
{
	callbackUnlock(data);
	locked = false;
	return getStatus();
}

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{
namespace // anonymous
{

// unlock

void unlockSemaphore(Semaphore *semaphore)
{
	semaphore->post();
}

void unlockMutex(Mutex *mutex)
{
	mutex->unlock();
}

void unlockSpin(Spin *spin)
{
	spin->unlock();
}

// lock

void lockSemaphore(Semaphore *semaphore)
{
	semaphore->wait();
}

void lockMutex(Mutex *mutex)
{
	mutex->lock();
}

void lockSpin(Spin *spin)
{
	spin->lock();
}

// tryLock

bool tryLockSemaphore(Semaphore *semaphore)
{
	return semaphore->tryWait();
}

bool tryLockMutex(Mutex *mutex)
{
	return mutex->tryLock();
}

bool tryLockSpin(Spin *spin)
{
	return spin->tryLock();
}

// getStatus

os::Status getSemaphoreStatus(const Semaphore *semaphore)
{
	return semaphore->getStatus();
}

os::Status getMutexStatus(const Mutex *mutex)
{
	return mutex->getStatus();
}

os::Status getSpinStatus(const Spin *spin)
{
	return spin->getStatus();
}

} // namespace anonymous
}}} // namespace flame_ide::os::threads
