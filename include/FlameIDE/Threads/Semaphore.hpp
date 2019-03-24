#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <pthread.h>
#include <semaphore.h>
#include "Templates/PthreadObject.hpp"
#include "Templates/Locker.hpp"

class Semaphore: PthreadObject<sem_t, int>
{
public:
	class Locker: public ::Locker<Semaphore>
	{
	public:
		Locker(Semaphore &semaphore): ::Locker<Semaphore>(semaphore)
		{
			get().wait();
		}

		~Locker()
		{
			get().post();
		}
	};

	Semaphore();
	Semaphore(unsigned int startValue);
	~Semaphore();

	int value();
	void post();
	void wait();
	bool tryWait();

private:
	virtual void init();
	void init(unsigned int startValue);
	virtual void clear();
};

#endif // SEMAPHORE_HPP
