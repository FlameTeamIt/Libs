#include <FlameIDE/../../src/Os/Threads/ThreadFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#define GET_LAST_ERROR \
		-static_cast<flame_ide::os::Status>(::GetLastError())

namespace flame_ide
{namespace os
{namespace threads
{namespace thread
{

os::Status init(os::ThreadContext &context) noexcept
{
	context = os::ThreadContext{
			os::THREAD_CONTEXT_INITIALIZER.object, windows::OS_THREAD_ID_DETACHED
	};
	return os::STATUS_SUCCESS;
}

os::Status destroy(os::ThreadContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	if (windows::OS_THREAD_ID_DETACHED == context.id)
	{
		return status;
	}
	if (os::THREAD_CONTEXT_INITIALIZER == context)
	{
		return os::STATUS_FAILED;
	}

	if (!::CloseHandle(context.object.handle))
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

os::Status create(os::ThreadContext &context, os::ThreadTaskTrait::Task task
		, os::ThreadTaskTrait::Argument arg) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	context.object.handle = ::CreateThread(nullptr, 0, task, arg, 0, &context.id);

	if (!context.object.handle)
	{
		status = GET_LAST_ERROR;
	}

	return status;
}

os::Status detach(os::ThreadContext &context) noexcept
{
	os::Status status = destroy(context);
	if (status == os::STATUS_SUCCESS)
	{
		context.id = windows::OS_THREAD_ID_DETACHED;
	}
	return status;
}

os::Status join(os::ThreadContext &context
		, os::ThreadTaskTrait::Return &ret) noexcept
{
	const auto result = ::WaitForSingleObject(context.object.handle, windows::OS_INFINITE_WAIT);
	os::Status status = os::STATUS_SUCCESS;
	switch (result)
	{
		case WAIT_OBJECT_0:
		{
			if (!::GetExitCodeThread(context.object.handle, &ret))
			{
				status = GET_LAST_ERROR;
			}
			break;
		}

		case WAIT_ABANDONED:
		{
			status = os::STATUS_FAILED;
			break;
		}

		case WAIT_FAILED:
		default:
		{
			status = GET_LAST_ERROR;
			break;
		}
	}
	return status;
}

}}}} // namespace flame_ide::os::threads::thread
