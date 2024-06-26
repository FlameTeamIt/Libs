#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Os/Threads/Thread.hpp>

#include <errno.h>

namespace flame_ide
{namespace streams
{

namespace // anonymous
{

///
/// @brief The MakeNamedPipeThread class
///
class MakeNamedPipeThread: public os::threads::ThreadBase
{
public:
	MakeNamedPipeThread(const char *initPipeName, os::ActionType initAction) :
			pipeName(initPipeName), action(initAction)
	{}

	Descriptors getResult() const
	{
		return descriptors;
	}

private:
	virtual void vRun() noexcept override
	{
		descriptors = makeNamedPipe(pipeName, action);
	}

	const char *pipeName;
	os::ActionType action;
	Descriptors descriptors;
};

///
/// @brief The DestroyNamedPipeThread class
///
class DestroyNamedPipeThread: public os::threads::ThreadBase
{
public:
	DestroyNamedPipeThread(Descriptors::ResultValue initFd, os::ActionType initAction) :
			fd{ initFd }, action{ initAction }
	{}

	os::Status getResult() const
	{
		return fd.status;
	}

private:
	virtual void vRun() noexcept override
	{
		if (action == os::ActionType::READER)
		{

		}
		else if (action == os::ActionType::WRITER)
		{

		}
		else
		{
			fd.status = -EINVAL;
		}
	}

	Descriptors::ResultValue fd;
	os::ActionType action;
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

Descriptors destroyNamedPipe(Descriptors descriptors) noexcept
{
	DestroyNamedPipeThread thread{ descriptors.reader, os::ActionType::READER };
	thread.run();
	auto status = destroyNamedWriter(descriptors.writer);

	Descriptors resultDescriptors {
		Descriptors::ResultValue{ os::INVALID_DESCRIPTOR, thread.getResult() }
		, Descriptors::ResultValue{ os::INVALID_DESCRIPTOR, status }
	};
	return resultDescriptors;
}

}}
