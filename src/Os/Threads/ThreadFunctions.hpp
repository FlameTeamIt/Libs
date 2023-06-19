#ifndef THREADFUNCTIONS_HPP
#define THREADFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace thread
{

os::Status init(os::ThreadContext &thread) noexcept;

os::Status destroy(os::ThreadContext &thread) noexcept;

os::Status create(os::ThreadContext &thread, os::ThreadTaskTrait::Task task
		, os::ThreadTaskTrait::Argument arg) noexcept;

os::Status detach(os::ThreadContext &thread) noexcept;

os::Status join(os::ThreadContext &thread, os::ThreadTaskTrait::Return &ret) noexcept;

}}}} // namespace flame_ide::os::threads::thread

#endif // THREADFUNCTIONS_HPP
