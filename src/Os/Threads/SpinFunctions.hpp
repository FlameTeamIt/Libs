#ifndef SPINFUNCTIONS_HPP
#define SPINFUNCTIONS_HPP

#include <FlameIDE/../../src/Os/Threads/Common.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace spin
{

os::Status init(os::SpinContext &context) noexcept;

os::Status destroy(os::SpinContext &context) noexcept;

os::Status lock(os::SpinContext &context) noexcept;

TryLockStatus tryLock(os::SpinContext &context) noexcept;

os::Status unlock(os::SpinContext &context) noexcept;

}}}} // namespace flame_ide::os::threads::spin

#endif // SPINFUNCTIONS_HPP
