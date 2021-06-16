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

templates::Expected<PipeDescriptors, Status> createPipes() noexcept
{
	PipeDescriptors descriptors = { -1, -1 };
	Status status = pipe(reinterpret_cast<int*>(&descriptors.pair));
	if (status)
	{
		return Status{ -errno };
	}
	if (fcntl(descriptors.pair.descriptors[0]
			, F_SETPIPE_SZ
			, flame_ide::Constants::MAX_PIPE_BUFFER_SIZE) < 0)
	{
		return Status{ -errno };
	}
	return descriptors;
}

void destroyPipes(PipeDescriptors &pipe)
{
	close(pipe.pair.descriptors[0]);
	close(pipe.pair.descriptors[1]);
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
