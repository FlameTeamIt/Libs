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
	Status status = pipe(reinterpret_cast<int*>(&descriptors.pair));
	if (status)
	{
		return Status{ -errno };
	}
	if (fcntl(descriptors.pair.descriptors[0]
			, F_SETPIPE_SZ
			, flame_ide::Constants::PIPE_BUFFER_SIZE) < 0)
	{
		return Status{ -errno };
	}
	return 0;
}

void destroyPipes(PipeDescriptors &pipe)
{
	close(pipe.pair.descriptors[0]);
	close(pipe.pair.descriptors[1]);
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
