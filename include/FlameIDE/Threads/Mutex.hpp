#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <pthread.h>
#include "Templates/PthreadObject.hpp"
#include "Templates/Locker.hpp"

class Mutex: public PthreadObject<pthread_mutex_t, pthread_mutexattr_t>
{
public:
	class Locker: public ::Locker<Mutex>
	{
	public:
		Locker(Mutex &mutex) : ::Locker<Mutex>(mutex)
		{
			get().lock();
		}

		~Locker()
		{
			get().unlock();
		}
	};

	Mutex();
	Mutex(bool locked);
	virtual ~Mutex();

	void lock();
	bool tryLock();

	void unlock();

private:
	typedef PthreadObject<pthread_mutex_t, pthread_mutexattr_t> Parent;
	virtual void init();
	virtual void clear();
};

#endif // MUTEX_HPP
