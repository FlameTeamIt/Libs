#include <FlameIDE/../../src/Os/Threads/ThreadFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#define RETURN_RESULT(condition, result) \
{ \
	result = condition; \
	if (result != os::STATUS_SUCCESS) \
	{ \
		result = -errno; \
	} \
}

namespace flame_ide
{namespace os
{namespace threads
{namespace thread
{

os::Status init(os::ThreadContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_attr_init(&context.attributes), status);
	return status;
}

os::Status destroy(os::ThreadContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_attr_destroy(&context.attributes), status);
	return status;
}

os::Status create(os::ThreadContext &context, os::ThreadTaskTrait::Task task
		, os::ThreadTaskTrait::Argument arg) noexcept
{
	os::Status status = {};
	RETURN_RESULT(
			::pthread_create(&context.object, &context.attributes, task, arg)
			, status
	);
	return status;
}

os::Status detach(os::ThreadContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_detach(context.object), status);
	if (status != os::STATUS_SUCCESS)
	{
		return status;
	}
	if (!isEqual(os::THREAD_CONTEXT_INITIALIZER.attributes, context.attributes))
	{
		RETURN_RESULT(destroy(context), status);
		context = os::THREAD_CONTEXT_INITIALIZER;
	}
	return status;
}

os::Status join(os::ThreadContext &context, os::ThreadTaskTrait::Return &ret) noexcept
{
	os::Status status = {};
	os::ThreadTaskTrait::Return *const retValue = (ret) ? &ret : nullptr;
	RETURN_RESULT(::pthread_join(context.object, retValue), status);
	return status;
}

// FIXME: Придумать решение; это не работает
os::Status isWorking(const os::ThreadContext &thread) noexcept
{
	auto status = ::pthread_kill(thread.object, os::posix::Signal::EMPTY);
	return status == 0;
}

}}}} // namespace flame_ide::os::threads::thread
