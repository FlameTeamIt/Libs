#ifndef FLAMEIDE_THREADS_MUTEX_HPP
#define FLAMEIDE_THREADS_MUTEX_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace threads
{

class Mutex
{
public:
	Mutex() noexcept;
	~Mutex() noexcept;

	void lock() noexcept;
	void unlock() noexcept;

	struct Guard
	{
		Guard(Mutex &) noexcept;

		~Guard() noexcept;

		Mutex &mutex;
	};

private:

};

}}

#endif // FLAMEIDE_THREADS_MUTEX_HPP
