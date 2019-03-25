#include <FlameIDE/Threads/Semaphore.hpp>

namespace flame_ide
{namespace threads
{

Semaphore::Poster::Poster(Semaphore &initSem) noexcept : sem(initSem)
{
	sem.post();
}

Semaphore::Poster::~Poster() noexcept
{
	sem.wait();
}

}}
