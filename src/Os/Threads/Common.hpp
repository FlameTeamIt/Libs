#ifndef COMMON_HPP
#define COMMON_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

enum TryLockStatus: os::Status
{
	TRY_LOCK_BUSY = -EBUSY
	, TRY_LOCK_INVLID_VALUE = -EINVAL
	, TRY_LOCK_DEAD_LOCK = -EDEADLK
	, TRY_LOCK_RECURSIVE_EXCEEDED = -EAGAIN
	, TRY_LOCK_PERMISSION_DENIED = -EPERM
	, TRY_LOCK_INTERRUPT = -EINTR
	, TRY_LOCK_UNKOWN = flame_ide::NumberLimitTrait<os::Status>::MIN_VALUE
	, TRY_LOCK_OK = 0
};

}}} // namespace flame_ide::os::threads

#endif // COMMON_HPP
