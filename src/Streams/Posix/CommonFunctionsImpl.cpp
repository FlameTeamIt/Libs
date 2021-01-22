#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Threads/Thread.hpp>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

namespace flame_ide
{namespace streams
{

namespace // anonymous
{

Descriptors::ResultValue makeFifo(const char *fifoName, os::ActionType action) noexcept
{
	os::FileDescriptor fd = os::INVALID_DESCRIPTOR;
	os::Status status = mknod(fifoName, S_IFIFO | 0666, 0);
	if (status < 0)
	{
		if (errno != EEXIST)
		{
			return Descriptors::ResultValue{ os::INVALID_DESCRIPTOR, -errno };
		}
	}

	flame_ide::int_t flag = O_CREAT;
	if (action == os::ActionType::READER)
	{
		flag |= O_RDONLY | O_NONBLOCK;
	}
	else if (action == os::ActionType::WRITER)
	{
		flag |= O_WRONLY;
	}
	else
	{
		return { os::INVALID_DESCRIPTOR, -EINVAL };
	}

	status = ::open(fifoName, flag);
	if (status < 0)
	{
		status = -errno;
	}
	else
	{
		fd = status;
		status = os::STATUS_SUCCESS;
	}
	return Descriptors::ResultValue{ fd, status };
}

os::Status commonClose(Descriptors::ResultValue descriptor)
{
	if (!descriptor.status)
	{
		auto result = close(descriptor.fd);
		if (result < 0)
		{
			return -errno;
		}
		return result;
	}
	else
	{
		return descriptor.status;
	}
}

} // anonymous

Descriptors::ResultValue makeNamedReader(const char *pipeName) noexcept
{
	Descriptors::ResultValue fd = makeFifo(pipeName, os::ActionType::READER);
	return fd;
}

Descriptors::ResultValue makeNamedWriter(const char *pipeName) noexcept
{
	Descriptors::ResultValue fd = makeFifo(pipeName, os::ActionType::WRITER);
	return fd;
}

os::Status destroyNamedReader(Descriptors::ResultValue descriptor) noexcept
{
	return commonClose(descriptor);
}

os::Status destroyNamedWriter(Descriptors::ResultValue descriptor) noexcept
{
	return commonClose(descriptor);
}

}}
