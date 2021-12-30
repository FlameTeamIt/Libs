#ifndef THREADFUNCTIONS_HPP
#define THREADFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

Status createThread(ThreadContext &context
		, ThreadTaskTrait::TaskType &task
		, ThreadTaskTrait::ArgumentType &argument);

Status joinThread(ThreadContext &context);

Status detachThread(ThreadContext &context);

}} // namespace flame_ide::os

#endif // THREADFUNCTIONS_HPP
