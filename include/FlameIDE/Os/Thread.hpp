#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

class Thread
{
public:
	Thread() noexcept;
	Thread(Thread &&) noexcept;
	Thread(const Thread &) = delete;
	Thread(ThreadTask task, bool needJoin = true) noexcept;

	~Thread() noexcept;

	Thread &operator=(Thread &&) noexcept;
	Thread &operator=(const Thread &) = delete;

	void run() noexcept;

	void join() noexcept;

	void detach() noexcept;

	bool setTask(ThreadTask task, bool needJoin = true) noexcept;

	Status status() const noexcept;

	ThreadContext &native() noexcept;

	const ThreadContext &native() const noexcept;

private:
	ThreadContext context;
	ThreadTask task;
	Status lastStatus;
	bool needJoin;
};

}} // namespace flame_ide::os
