#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/ThreadFunctions.hpp>

#include <pthread.h>
#include <errno.h>

namespace flame_ide
{namespace os
{

Status createThread(ThreadContext &context
		, ThreadTaskTrait::TaskType &task
		, ThreadTaskTrait::ArgumentType &argument)
{
	auto attributes = context.attributes.getDefaultNativeAttributes();
	if (pthread_create(&context.object, attributes, task, argument))
	{
		return -errno;
	}
	return 0;
}

Status joinThread(ThreadContext &context)
{
	if (pthread_join(context.object, nullptr))
	{
		return -errno;
	}
	return 0;
}

Status detachThread(ThreadContext &context)
{
	if (pthread_detach(context.object))
	{
		return -errno;
	}
	return 0;
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
