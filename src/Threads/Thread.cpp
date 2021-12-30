#include <FlameIDE/Threads/Thread.hpp>


namespace flame_ide
{namespace threads
{

Thread::Thread() : object{ reinterpret_cast<os::ThreadTaskTrait::TaskType>(task), true }
{}

Thread::Thread(Thread &&thread) noexcept
{
	operator=(move(thread));
}

Thread::~Thread() noexcept
{}

Thread &Thread::operator=(Thread &&thread) noexcept
{
	object = move(thread.object);
	return *this;
}

void Thread::run() noexcept
{
	object.run();
}

void Thread::join() noexcept
{
	object.join();
}

void Thread::detach() noexcept
{
	object.detach();
}

os::Status Thread::getStatus() const noexcept
{
	return object.status();
}

// private

os::ThreadTaskTrait::ReturnType
Thread::task(Thread *thread) noexcept
{
	thread->vRun();
	return os::ThreadTaskTrait::ReturnType{};
}

}} // namespace flame_ide::threads
