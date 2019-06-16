#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>

#include <FlameIDE/Threads/Thread.hpp>

namespace flame_ide
{namespace streams
{

namespace // anonymous
{

class MakeNamedPipeThread: public threads::Thread
{
public:
	MakeNamedPipeThread(const char *initFifoName, os::ActionType initAction) :
			fifoName(initFifoName)
			, action(initAction)
	{}

	Descriptors getResult() const
	{
		return descriptors;
	}

private:
	virtual void vRun() override
	{
		descriptors = makeNamedPipe(fifoName, action);
	}

	const char *fifoName;
	os::ActionType action;
	Descriptors descriptors;
};

} // anonymous

Descriptors makeNamedBidirectional(const char *pipeName) noexcept
{
	Descriptors descriptors{};
	MakeNamedPipeThread thread{ pipeName, os::ActionType::WRITER };

	thread.run();
	descriptors.reader = makeNamedReader(pipeName);
	thread.join();
	descriptors.writer = thread.getResult().writer;

	return descriptors;
}

Descriptors makeNamedPipe(const char *pipeName, os::ActionType action) noexcept
{
	Descriptors descriptors{};
	switch (action)
	{
		case os::ActionType::READER:
		{
			descriptors.reader = makeNamedReader(pipeName);
			break;
		}

		case os::ActionType::WRITER:
		{
			descriptors.writer = makeNamedWriter(pipeName);
			break;
		}

		case os::ActionType::BIDIRECTIONAL:
		{
			descriptors = makeNamedBidirectional(pipeName);
		}
	}
	return descriptors;
}

}}
