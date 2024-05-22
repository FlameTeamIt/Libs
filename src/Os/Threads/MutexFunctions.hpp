#ifndef MUTEXFUNCTIONS_HPP
#define MUTEXFUNCTIONS_HPP

#include <FlameIDE/../../src/Os/Threads/Common.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace mutex
{

os::Status init(os::MutexContext &context) noexcept;

os::Status destroy(os::MutexContext &context) noexcept;

os::Status lock(os::MutexContext &context) noexcept;

TryLockStatus tryLock(os::MutexContext &context) noexcept;

os::Status unlock(os::MutexContext &context) noexcept;

}}}} // namespace flame_ide::os::threads::mutex

#endif // MUTEXFUNCTIONS_HPP
