#include <FlameIDE/Threads/Semaphore.hpp>

namespace flame_ide
{namespace threads
{

Semaphore::Waiter::Waiter(Semaphore &initSem) noexcept : sem(initSem)
{
	sem.wait();
}

Semaphore::Waiter::~Waiter() noexcept
{
	sem.post();
}

}}
