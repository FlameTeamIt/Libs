#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#include <FlameIDE/Common/PrimitiveTypes.hpp>

#include "InternalPosixFunctions.hpp"

namespace flame_ide
{namespace streams
{

os::FileDescriptor makeFifo(const char *fifoName, os::ActionType action) noexcept
{
	os::Status status1 = unlink(fifoName);
	os::Status status = mknod(fifoName, S_IFIFO | 0666, 0);
	if (status < 0)
	{
		if (errno != EEXIST)
		{
			return -errno;
		}
	}

	flame_ide::int_t flag = O_CREAT;
	switch(action)
	{
		case os::ActionType::READER:
		{
			flag |= O_RDONLY | O_NONBLOCK;
			break;
		}
		case os::ActionType::WRITER:
		{
			flag |= O_WRONLY;
			break;
		}
		case os::ActionType::BIDIRECTIONAL:
		{
			flag |= O_RDWR;
			break;
		}
	}

	status = ::open(fifoName, flag);
	if (status < 0)
	{
		status = -errno;
		auto *data = strerror(-status);
		return status;
	}
	return static_cast<os::FileDescriptor>(status);
}

}}
