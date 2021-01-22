#include <FlameIDE/Threads/Mutex.hpp>

namespace flame_ide
{namespace threads
{

Mutex::Locker::Locker(Mutex &initMtx) noexcept : mtx(initMtx)
{
	mtx.lock();
}

Mutex::Locker::~Locker() noexcept
{
	mtx.unlock();
}

Mutex::UniqueLocker::UniqueLocker(Mutex &initMtx) noexcept : mtx(&initMtx)
{
	mtx->lock();
}

Mutex::UniqueLocker::~UniqueLocker() noexcept
{
	mtx->unlock();
}

}}
