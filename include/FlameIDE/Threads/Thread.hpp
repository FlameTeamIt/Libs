#ifndef THREAD_HPP
#define THREAD_HPP

#include "Types.hpp"
#include "Semaphore.hpp"
#include "Descriptor.hpp"

class Thread
{
public:
	enum class Status
	{
		NOT_RUN,
		STARTING,
		READY,
		PERFOMING,
		SLEEP,
		FINISHED
	};


	Thread();
	virtual ~Thread();

	void start();
	void join();
	void cancel();

	Status getStatus() const;

protected:
	virtual void run() = 0;
	void setStatus(Status newStatus);

	void enableCancel();
	void disableCancel();

private:
	Thread(const Thread &) = delete;
	Thread(Thread &&) = delete;
	Thread &operator=(const Thread &) = delete;
	Thread &operator=(Thread &&) = delete;

	Descriptor descriptor;
	Status status;
	Semaphore semaphore;

	static void *threadTask(void *data);
};

#endif // THREAD_HPP
