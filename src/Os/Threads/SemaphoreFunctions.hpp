#ifndef SEMAPHOREFUNCTIONS_HPP
#define SEMAPHOREFUNCTIONS_HPP

#include <FlameIDE/../../src/Os/Threads/Common.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace semaphore
{

os::Status init(os::SemaphoreContext &context, os::SemaphoreValue value) noexcept;

os::Status destroy(os::SemaphoreContext &context) noexcept;

os::Status wait(os::SemaphoreContext &context) noexcept;

TryLockStatus tryWait(os::SemaphoreContext &context) noexcept;

os::Status post(os::SemaphoreContext &context) noexcept;

os::SemaphoreValue value(os::SemaphoreContext &context) noexcept;

}}}} // namespace flame_ide::os::threads::semaphore

#endif // SEMAPHOREFUNCTIONS_HPP
