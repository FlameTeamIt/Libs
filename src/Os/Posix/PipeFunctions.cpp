#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/PipeFunctions.hpp>

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

namespace flame_ide
{namespace os
{

Status createPipes(PipeDescriptors &descriptors) noexcept
{
	Status status = pipe(reinterpret_cast<int*>(descriptors.descriptors));
	if (status)
	{
		return -errno;
	}
	if (fcntl(descriptors.descriptors[0]
			, F_SETPIPE_SZ
			, flame_ide::Constants::MAX_PIPE_BUFFER_SIZE) < 0)
	{
		return -errno;
	}
}

Status destroyPipes(PipeDescriptors &descriptors) noexcept
{
	Status status = STATUS_SUCCESS;
	if (close(descriptors.descriptors[0]) < 0)
	{
		descriptors.descriptors[0] = -errno;
		status = -1;
	}
	if (close(descriptors.descriptors[1]) < 0)
	{
		descriptors.descriptors[1] = -errno;
		status = -1;
	}
	return status;
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
